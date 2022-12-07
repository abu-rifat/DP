#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
vector<vector<ll>>adj;
vector<string>ans;
map<string,bool>ckans;
vector<bool>visited;

void init(){
	adj.clear();
	ans.clear();
	ckans.clear();
	adj.assign(n+5,vector<ll>(0));
	visited.assign(n+5,false);
}

void gen_ans(string path, ll node, ll rem){
	if(rem==0){
		if(!ckans[path]){
			ans.push_back(path);
			ckans[path]=true;
		}
	}
	for(ll i=0;i<(ll)adj[node].size();i++){
		ll u=adj[node][i];
		if(!visited[u]){
			visited[u]=true;
			char ch = '0'+u;
			gen_ans(path+ch,u,rem-1);
			visited[u]=false;
		}
	}
}

int main(){
	ll dd=0;
	while(cin>>n){
		if(n==-9999)cin>>n;
		cin>>k;
		init();
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				ll tmp;
				cin>>tmp;
				if(tmp){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		visited[0]=true;
		gen_ans("0",0,k);
		ll len=ans.size();
		if(dd==0)dd=1;
		else cout<<endl;
		if(len<=0)cout<<"no walk of length "<<k<<endl;
		else{
			for(ll i=0;i<(ll)ans.size();i++){
				cout<<"(";
				for(ll j=0;j<(ll)ans[i].size();j++){
					if(j!=0)cout<<",";
					ll val=ans[i][j]-'0';
					val++;
					cout<<val;
				}
				cout<<")\n";
			}
		}
		
	}
	return 0;
}