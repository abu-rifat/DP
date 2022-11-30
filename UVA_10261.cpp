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
// Problem	: E - 10261
// Contest	: Virtual Judge - Job Preparation Set 1
// URL		: https://vjudge.net/contest/532282#problem/E
// Memory Limit : 1024 MB
// Time Limit	: 3000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>cars,sum,final_path;
ll len;
ll dp[10005][105];
ll path[10005][105];

ll go_babe(ll siz, ll idx, ll n){
	if(idx>n||siz<=0)return 0;
	if(dp[siz][idx]!=-1)return dp[siz][idx];
	ll val = go_babe(siz, idx + 1, n);
	path[siz][idx]=0;
	if(cars[idx] <= siz){
		ll val2 = cars[idx] + go_babe(siz - cars[idx], idx + 1, n);
		if(val2 > val){
			val = val2;
			path[siz][idx] = 1;
		}
	}
	return dp[siz][idx] = val;
}

void print_path(ll siz, ll idx, ll n){
	if (path[siz][idx] == -1) return;
	if (path[siz][idx]==1){
		final_path.push_back(idx);
		print_path(siz - cars[idx], idx + 1, n);
	}else print_path(siz, idx + 1, n);
}

void init(){
	cars.clear();
	sum.clear();
}

void clean_dp(){
	for(ll i=0;i<10005;i++)for(ll j=0;j<105;j++)dp[i][j]=-1;
}

void clean_path(){
	for(ll i=0;i<10005;i++)for(ll j=0;j<105;j++)path[i][j]=-1;
	final_path.clear();
}

int main(){
	ll t=1;
	cin>>t;
	for(ll T=1;T<=t;T++){
		if(T!=1)cout<<endl;
		init();
		clean_path();
		cin>>len;
		len*=100;
		while(1){
			ll tmp;
			cin>>tmp;
			if(tmp==0)break;
			cars.push_back(tmp);
		}
		if((ll)cars.size()==0){
			cout<<"0\n";
			continue;
		}
		for(ll i=0;i<(ll)cars.size();i++){
			if(i==0)sum.push_back(cars[i]);
			else{
				sum.push_back(cars[i]+sum[i-1]);
			}
		}
		ll l=0,r=cars.size()-1;
		ll max_ct=-1;
		while(l<=r){
			ll mid = l + (r - l) / 2;
			clean_dp();
			ll val = go_babe(len, 0, mid);
			ll val2 = sum[mid] - val;
			if(val2 <= len){
				max_ct = max(max_ct, mid);
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		cout << max_ct+1 << endl;
		if(max_ct>=0){
			clean_dp();
			clean_path();
			ll tmp = go_babe(len, 0, max_ct);
			print_path(len, 0, max_ct);
			bitset<105>bs;
			bs.set();
			for(ll i=0;i<(ll)final_path.size();i++){
				bs[final_path[i]]=0;
			}
			for(ll i=0;i<=max_ct;i++){
				if(bs[i])cout<<"port\n";
				else cout<<"starboard\n";
			}
		}
	}
	return 0;
}