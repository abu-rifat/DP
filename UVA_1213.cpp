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
// Problem	: C - Sum of Different Primes
// Contest	: Virtual Judge - Job Preparation Set 1
// URL		: https://vjudge.net/contest/532282#problem/C
// Memory Limit : 1024 MB
// Time Limit	: 3000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>primes;
bitset<1200>bs;
ll psize;
ll dp[1125][190][15];

void sieve(ll ub){
	bs.set();
	bs[0]=bs[1]=0;
	primes.push_back(2);
	for(ll i=4;i<=ub;i+=2)bs[i]=0;
	for(ll i=3;i<=ub;i++){
		if(bs[i]){
			primes.push_back(i);
			for(ll j=i*i;j<=ub;j+=i)bs[j]=0;
		}
	}
	psize=primes.size();
}

ll go_babe(ll idx, ll n, ll k){
	//cout<<primes[idx]<<" "<<n<<" "<<k<<endl;
	if(n==0&&k==0)return 1;
	if(idx>=psize||n<=0||k<=0||primes[idx]>n)return 0;
	if(dp[n][idx][k]!=-1)return dp[n][idx][k];
	ll val1=go_babe(idx+1,n,k);
	ll val3=go_babe(idx+1,n-primes[idx],k-1);
	return dp[n][idx][k]=val1+val3;
}

int main(){
	ll t=1;
	//cin>>t;
	for(ll T=1;T<=t;T++){
		sieve(1130);
		//cout<<primes.size()<<endl;
		ll n,k;
		while(1){
			cin>>n>>k;
			if(n==0&&k==0)break;
			for(ll i=0;i<1125;i++){
				for(ll j=0;j<190;j++){
					for(ll k=0;k<15;k++)dp[i][j][k]=-1;
				}
			}
			ll ans=go_babe(0,n,k);
			cout<<ans<<endl;
		}
	}
	return 0;
}