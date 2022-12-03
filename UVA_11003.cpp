#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll dp[1010][3010][2];
ll weight[1010],load[1010];

void init(){
	for(ll i=0;i<1010;i++){
		for(ll j=0;j<3010;j++){
			for(ll k=0;k<2;k++)dp[i][j][k]=-1;
		}
	}
}

ll go_babe(ll idx, bool bottom, ll maxw){
	if(idx>=n||maxw<0)return 0;
	if(!bottom&&maxw==0)return 0;
	ll &res = dp[idx][maxw][bottom];
	if(res!=-1)return res;
	ll val = go_babe(idx+1,bottom,maxw);
	if(bottom){
		ll val2=1+go_babe(idx+1,false,load[idx]);
		if(val2>val)val=val2;
	}
	else if(weight[idx]<=maxw){
		ll nextw = min(maxw-weight[idx],load[idx]);
		ll val2 = 1 + go_babe(idx+1,false,nextw);
		if(val2>val)val=val2;
	}
	return res=val;
}

int main(){
	while(1){
		cin>>n;
		if(n==0)break;
		for(ll i=0;i<n;i++){
			cin>>weight[i]>>load[i];
		}
		init();
		ll ans=go_babe(0,true,0);
		cout<<ans<<endl;
	}
	return 0;
}