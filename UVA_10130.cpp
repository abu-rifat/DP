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
// Problem	: D - 10130 SuperSale
// Contest	: Virtual Judge - Job Preparation Set 1
// URL		: https://vjudge.net/contest/532282#problem/D
// Memory Limit : 1024 MB
// Time Limit	: 3000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,g;
ll price[1005],weight[1005];
ll capacity[105];
ll dp[1005][32]; //number of items, capacity

ll go_babe(ll idx, ll cap){
	if(idx>=n||cap<=0)return 0;
	ll &res = dp[idx][cap];
	if(res!=-1)return res;
	ll val=go_babe(idx+1,cap);
	if(weight[idx]<=cap)val=max(val,price[idx]+go_babe(idx+1,cap-weight[idx]));
	return res=val;
}

void init(){
	for(ll i=0;i<1005;i++){
		for(ll j=0;j<32;j++)dp[i][j]=-1;
	}
}

int main(){
	ll t=1;
	cin>>t;
	for(ll T=1;T<=t;T++){
		cin>>n;
		for(ll i=0;i<n;i++)cin>>price[i]>>weight[i];
		cin>>g;
		for(ll i=0;i<g;i++){
			cin>>capacity[i];
		}
		ll ans=0;
		for(ll i=0;i<g;i++){
			init();
			ans+=go_babe(0,capacity[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}