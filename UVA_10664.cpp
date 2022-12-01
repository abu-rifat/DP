#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>weight;
ll n,sum;
ll dp[25][205];

void init(){
	for(ll i=0;i<25;i++){
		for(ll j=0;j<205;j++)dp[i][j]=-1;
	}
}

bool go_babe(ll idx, ll nowsum, ll target){
	//cout<<target<<endl;
	ll &res = dp[idx][nowsum];
	if(nowsum == target)return true;
	if(idx>=n||nowsum>target)return false;
	if(res!=-1)return res;
	return res = go_babe(idx + 1, nowsum, target) | go_babe(idx + 1, nowsum + weight[idx], target);
}

int main(){
	ll t;
	cin>>t;
	getchar();
	while(t--){
		weight.clear();
		sum=0;
		string s;
		getline(cin,s);
		istringstream is(s);
		ll tmp;
		while(is >> tmp){
			weight.push_back(tmp);
			sum+=tmp;
		}
		n = weight.size();
		bool ck = false;
		init();
		if(sum%2==0)ck=go_babe(0,0,sum/2);//idx,sum
		if(ck)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}