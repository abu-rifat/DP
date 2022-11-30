// /*******Bismillahir-Rahmanir-Rahim**********/
// 
// Name         : Abu Rifat Muhammed Al Hasib
// Institution  : University of Barisal, Bangladesh
// Github       : https://github.com/abu-rifat
// website	: https://aburifat.com
// 
// Codeforces   : https://codeforces.com/profile/ARMaster
// lightoj      : https://lightoj.com/user/abu-rifat
// AtCoder      : https://atcoder.jp/users/aburifat
// codechef     : https://www.codechef.com/users/aburifat
// SPOJ         : https://www.spoj.com/users/abu_rifat
// UvaOJ        : https://uhunt.onlinejudge.org/id/889274
// 
// facebook     : https://facebook.com/AbuRifatM
// linkedin     : https://www.linkedin.com/in/aburifat
// Email        : rifat.cse4.bu@gmail.com
// 		  armalhasib@gmail.com
// 		  abu.rifat.m@gmail.com
// 
// Problem	: B - Diving for Gold
// Contest	: Virtual Judge - Job Preparation Set 1
// URL		: https://vjudge.net/contest/532282#problem/B
// Memory Limit : 1024 MB
// Time Limit	: 3000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,vector<ll>> dp[35][1005];
ll t,w,n;
ll cost[35],coin[35];

pair<ll,vector<ll>> ctDp(ll idx,ll rem){
	vector<ll>v;
	if(idx>=n)return {0,v};
	if(dp[idx][rem].first!=-1)return dp[idx][rem];
	pair<ll,vector<ll>> val=ctDp(idx+1,rem);
	if(rem>=cost[idx]){
		pair<ll,vector<ll>> val2=ctDp(idx+1,rem-cost[idx]);
		val2.first+=coin[idx];
		val2.second.push_back(idx);
		if(val2.first>val.first){
			val=val2;
		}
	}
	return dp[idx][rem]=val;
}

int main(){
	bool ck=false;
	while(cin>>t){
		if(ck){
			cout<<endl;
		}else ck=true;
		cin>>w;
		cin>>n;
		vector<ll>v;
		for(ll i=0;i<35;i++){
			for(ll j=0;j<1005;j++){
				dp[i][j]={-1,v};
			}
		}
		for(ll i=0;i<n;i++){
			cin>>cost[i]>>coin[i];
			cost[i]=cost[i]*3*w;
		}
		pair<ll,vector<ll>> pr=ctDp(0,t);
		ll ans=pr.first;
		vector<ll>path=pr.second;
		cout<<ans<<endl;
		cout<<path.size()<<endl;
		sort(path.begin(),path.end());
		for(ll i=0;i<(ll)path.size();i++){
			cout<<cost[path[i]]/(3*w)<<" "<<coin[path[i]]<<endl;
		}
	}
	return 0;
}