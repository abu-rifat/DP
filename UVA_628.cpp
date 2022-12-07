#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<string>dic,rules,ans;

void init(){
	dic.clear();
	rules.clear();
	ans.clear();
}

void gen_pass(string pass, string rule, ll idx, ll len){
	if(idx>=len){
		ans.push_back(pass);
		return;
	}
	if(rule[idx]=='#'){
		for(ll i=0;i<n;i++){
			gen_pass(pass+dic[i],rule,idx+1,len);
		}
	}else{
		for(ll i=0;i<10;i++){
			char ch='0'+i;
			gen_pass(pass+ch,rule,idx+1,len);
		}
	}
}

int main(){
	while(cin>>n){
		init();
		for(ll i=0;i<n;i++){
			string tmp;
			cin>>tmp;
			dic.push_back(tmp);
		}
		cin>>m;
		for(ll i=0;i<m;i++){
			string tmp;
			cin>>tmp;
			rules.push_back(tmp);
		}
		for(ll i=0;i<m;i++){
			ll len=rules[i].size();
			gen_pass("",rules[i],0,len);
		}
		cout<<"--\n";
		for(ll i=0;i<(ll)ans.size();i++){
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}