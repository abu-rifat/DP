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
// Problem	: A - Dividing coins
// Contest	: Virtual Judge - Job Preparation Set 1
// URL		: https://vjudge.net/contest/532282#problem/A
// Memory Limit : 1024 MB
// Time Limit	: 3000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll coins[110];
bool dp[110][50010];
ll sum;
ll n;

int main(){
	ll t=1;
	cin>>t;
	for(ll T=1;T<=t;T++){
		sum=0;
		ll ans=0;
		cin>>n;
		if(n<=0){
			cout<<ans<<endl;
			continue;
		}
		for(ll i=0;i<n;i++){
			cin>>coins[i];
			sum+=coins[i];
		}
		for(ll i=0;i<n;i++){
			for(ll j=0;j<=sum;j++)dp[i][j]=false;
		}
		dp[0][0]=true;
		dp[0][coins[0]]=true;
		for(ll i=1;i<n;i++){
			for(ll j=0;j<=sum;j++){
				if(dp[i-1][j]==true){
					dp[i][j]=true;
					dp[i][j+coins[i]]=true;
				}
			}
		}
		ans=sum;
		for(ll i=0;i<=sum;i++){
			if(dp[n-1][i]==true){
				ll dif=abs(sum-(2*i));
				ans=min(ans,dif);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}