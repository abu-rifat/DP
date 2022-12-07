#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll arr[25];
ll mxmask;

vector<vector<ll>>dp;
vector<ll>pathck;
vector<ll>path;

ll get_ans(ll idx, ll rem){
	if(idx>=m||rem<=0)return 0;
	if(dp[idx][rem]!=-1)return dp[idx][rem];
	ll val=get_ans(idx+1,rem);
	if(rem>=arr[idx]){
		ll val2=arr[idx]+get_ans(idx+1,rem-arr[idx]);
		if(val2>val){
			val=val2;
			pathck[val]=idx;
		}
	}
	return dp[idx][rem]=val;
}

void get_path(ll val){
	if(pathck[val]==-1)return;
	path.push_back(pathck[val]);
	val-=arr[pathck[val]];
	get_path(val);
}

void init(){
	dp.assign(m+5,vector<ll>(n+5,-1));
	pathck.assign(n+5,-1);
	path.clear();
}


int main(){
	while(cin>>n){
		cin>>m;
		for(ll i=0;i<m;i++)cin>>arr[i];
		init();
		ll ans=get_ans(0,n);
		get_path(ans);
		for(ll i=0;i<(ll)path.size();i++)cout<<arr[path[i]]<<" ";
		cout<<"sum:"<<ans<<endl;
	}
	return 0;
}