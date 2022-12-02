#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,t2,n;
vector<pair<ll,ll>>good;
pair<ll,ll> dp[105][10300];

void init(){
	for(ll i=0;i<105;i++){
		for(ll j=0;j<10300;j++)dp[i][j]={-1,-1};
	}
}

pair<ll,ll> go_babe(ll idx, ll bal){
	if(idx>=n||bal<=0)return {0,0};
	pair<ll,ll> &res=dp[idx][bal];
	if(res.first!=-1)return res;
	pair<ll,ll> val=go_babe(idx+1,bal);
	if(bal>=good[idx].first){
		pair<ll,ll> val2=go_babe(idx+1,bal-good[idx].first);
		val2.first+=good[idx].first;
		val2.second+=good[idx].second;
		if(val2.second==val.second){
			if(val2.first>val.first)val=val2;
		}else if(val2.second>val.second)val=val2;
	}
	return res=val;
}

int main(){
	while(cin>>t){
		good.clear();
		if(t+200>2000)t2=t+200;
		else t2=t;
		cin>>n;
		for(ll i=0;i<n;i++){
			ll a,b;
			cin>>a>>b;
			good.push_back({a,b});
		}
		init();
		pair<ll,ll> val1=go_babe(0,t);
		ll ans=val1.second;
		if(t!=t2){
			init();
			pair<ll,ll> val2=go_babe(0,t2);
			if(val2.first>2000&&val2.second>val1.second)ans=val2.second;
		}
		cout<<ans<<endl;
	}
	return 0;
}