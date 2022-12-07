#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
vector<string>ans;
char zero='0',one='1';

void gen_ans(string s, ll idx, ll rem){
	if(idx>=n){
		if(rem==0)ans.push_back(s);
		return;
	}
	gen_ans(s+zero,idx+1,rem);
	if(rem>0)gen_ans(s+one,idx+1,rem-1);
}

int main(){
	ll t;
	cin>>t;
	bool ck=false;
	while(t--){
		ans.clear();
		cin>>n>>k;
		gen_ans("",0,k);
		if(!ck)ck=true;
		else cout<<endl;
		for(ll i=0;i<(ll)ans.size();i++)cout<<ans[i]<<endl;
	}
}