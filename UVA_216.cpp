#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll fullmask;
ll posx[12],posy[12];
double dp[12][515];
ll par[12][515];
vector<ll>path;

void init(){
	for(ll i=0;i<12;i++){
		for(ll j=0;j<515;j++)dp[i][j]=par[i][j]=-1;
	}
}

double tsp(ll idx, ll mask){
	if(mask==fullmask)return 0;
	double &res = dp[idx][mask];
	if(res!=-1)return res;
	ll taken=-1;
	double dis=DBL_MAX;
	for(ll i=0;i<n;i++){
		ll ck=(1<<i);
		if((mask&ck)==0){
			ll newmask=(mask|ck);
			double x=abs(posx[i]-posx[idx]);
			double y=abs(posy[i]-posy[idx]);
			double val=sqrt((x*x)+(y*y))+(16.0);
			val+=tsp(i,newmask);
			if(dis>val){
				dis=val;
				taken=i;
			}
		}
	}
	par[idx][mask]=taken;
	return res=dis;
}

void get_path(ll idx, ll mask){
	path.push_back(idx);
	ll nxt=par[idx][mask];
	if(nxt==-1)return;
	ll newmask=mask|(1<<nxt);
	get_path(nxt,newmask);
}

void print(ll t){
	cout<<"**********************************************************\n";
	cout<<"Network #"<<t<<"\n";
	double sum=0.0;
	for(ll i=1;i<(ll)path.size();i++){
		ll idx1=path[i-1],idx2=path[i];
		double x=abs(posx[path[i-1]]-posx[path[i]]);
		double y=abs(posy[path[i-1]]-posy[path[i]]);
		double dis=sqrt((x*x)+(y*y))+(16.0);
		sum+=dis;
		cout<<fixed<<setprecision(2)<<"Cable requirement to connect ("<<posx[idx1]<<","<<posy[idx1]<<") to ("<<posx[idx2]<<","<<posy[idx2]<<") is "<<dis<<" feet.\n";
	}
	cout<<fixed<<setprecision(2)<<"Number of feet of cable required is "<<sum<<".\n";
}


int main(){
	ll t=1;
	while(cin>>n){
		if(n==0)break;
		fullmask=((1<<n)-1);
		for(ll i=0;i<n;i++){
			cin>>posx[i]>>posy[i];
		}
		ll stidx=-1;
		double total_dis=DBL_MAX;
		init();
		for(ll i=0;i<n;i++){
			double res=tsp(i,(1<<i));
			if(res<total_dis){
				stidx=i;
				total_dis=res;
			}
		}
		path.clear();
		get_path(stidx,(1<<stidx));
		print(t);
		t++;
	}
	return 0;
}