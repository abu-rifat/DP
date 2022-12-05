#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second

//Data Structures
vector<pair<pair<ll,ll>,pair<ll,ll>>>fr;
vector<pair<ll,ll>>call;
vector<ll>lines;
vector<ll>times;
map<ll,ll>linemap;
map<ll,ll>timemap;
map<ll,bool>self_forward;
vector<vector<ll>>forward_table;

//Initializing
void init(){
	fr.clear();
	call.clear();
	lines.clear();
	times.clear();
	linemap.clear();
	timemap.clear();
	lines.push_back(0);
	times.push_back(0);
	timemap[0]=1;
	self_forward.clear();
	forward_table.clear();
}

//Check for unique lines
void ckline(ll a){
	if(!linemap[a]){
		linemap[a]=1;
		lines.push_back(a);
	}
}

//Check for unique times
void cktime(ll a){
	if(!timemap[a]){
		timemap[a]=1;
		times.push_back(a);
	}
}

//Update Function for Forward Table
ll update(ll idx, ll time, ll origin){
	ll val=forward_table[idx][time];
	if(val==idx)return val;
	else if(val==origin)return forward_table[idx][time]=0;
	else return forward_table[idx][time]=update(val,time,origin);
}

//Binary Search on Time Vector
ll bs_le(ll key){
	ll l=0,r=times.size()-1;
	ll idx=0;
	while(l<=r){
		ll mid = l+(r-l)/2;
		if(times[mid]==key)return mid;
		if(times[mid]>key){
			r=mid-1;
		}else{
			idx=mid;
			l=mid+1;
		}
	}
	return idx;
}

int main(){
	cout<<"CALL FORWARDING OUTPUT\n";
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		cout<<"SYSTEM "<<T<<endl;
		init();
		
		//Getting and Mapping Lines and Times
		ll a,b,c,d;
		while(cin>>a){
			if(a==0)break;
			cin>>b>>c>>d;
			if(a!=d){
				ckline(a);
				ckline(d);
				cktime(b);
				cktime(b+c+1);
				fr.push_back({{a,b},{c,d}});
			}else self_forward[a]=true;
		}
		while(cin>>a){
			if(a==9000)break;
			cin>>b;
			call.push_back({a,b});
		}
		
		sort(lines.begin(),lines.end());
		sort(times.begin(),times.end());
		//lines[0]=9999;
		
		linemap.clear();
		timemap.clear();
		
		ll lenline=lines.size();
		ll lentime=times.size();
		
		for(ll i=0;i<lenline;i++)linemap[lines[i]]=i;
		for(ll i=0;i<lentime;i++)timemap[times[i]]=i;
		
		//Initializing Forward Table
		forward_table.assign(lenline+5,vector<ll>(lentime+5,0));
		
		for(ll i=0;i<lenline;i++){
			for(ll j=0;j<lentime;j++){
				forward_table[i][j]=i;
			}
		}
		
		//Updating Forward Table
		for(ll i=0;i<(ll)fr.size();i++){
			ll from=fr[i].F.F;
			ll timest=fr[i].F.S;
			ll timeed=timest + fr[i].S.F + 1;
			ll to=fr[i].S.S;
			
			ll stidx=timemap[timest];
			ll edidx=timemap[timeed];
			
			ll fromidx=linemap[from];
			ll toidx=linemap[to];
			
			for(ll i=stidx;i<edidx;i++){
				forward_table[fromidx][i]=toidx;
			}
		}
		
		//Sync Forward Table
		for(ll i=1;i<lenline;i++){
			for(ll j=0;j<lentime;j++){
				ll val=forward_table[i][j];
				if(val!=i)forward_table[i][j]=update(val,j,i);
			}
		}
		
		//Handling Calls
		for(ll i=0;i<(ll)call.size();i++){
			ll calltime = call[i].F;
			ll callline = call[i].S;
			ll ringline = callline;
			ll lidx = linemap[callline];
			ll tidx = timemap[calltime];
			if(calltime!=0&&tidx==0){
				tidx=bs_le(calltime);
			}
			if(self_forward[callline])ringline=9999;
			if(lidx!=0){
				ll fidx = forward_table[lidx][tidx];
				ringline=lines[fidx];
			}
			if(ringline==0)ringline=9999;
			printf("AT %.4lld CALL TO %.4lld RINGS %.4lld\n",calltime,callline,ringline);
		}
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}