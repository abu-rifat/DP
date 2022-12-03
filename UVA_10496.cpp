#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll posx[15],posy[15];
ll dis[15];
ll n;
ll fullmask;
ll dp[12][2050];

void init(){
	for(ll i=0;i<12;i++){
		for(ll j=0;j<2050;j++)dp[i][j]=-1;
	}
}

ll tsp(ll idx, ll mask){
	if(mask==fullmask)return dis[idx];
	ll &res=dp[idx][mask];
	if(res!=-1)return res;
	ll minval=LONG_LONG_MAX;
	for(ll i=1;i<n;i++){
		ll ck=(1<<i);
		if((mask&ck)==0){
			ll newmask=(mask|ck);
			ll val=abs(posx[idx]-posx[i])+abs(posy[idx]-posy[i]);
			val+=tsp(i,newmask);
			minval=min(minval,val);
		}
	}
	return res=minval;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll X,Y;
		cin>>X>>Y;
		cin>>posx[0]>>posy[0];
		cin>>n;
		for(ll i=1;i<=n;i++)cin>>posx[i]>>posy[i];
		for(ll i=0;i<=n;i++)dis[i]=abs(posx[i]-posx[0])+abs(posy[i]-posy[0]);
		n++;
		fullmask=((1<<n)-1);
		init();
		ll val=tsp(0,1);
		cout<<"The shortest path has length "<<val<<endl;
	}
	return 0;
}