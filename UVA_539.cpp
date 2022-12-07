#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<vector<ll>>adj;
map<pair<ll,ll>,ll>edgemp;
vector<pair<ll,ll>>edges;
vector<bool>visited;
ll mx_ans=0;

void init(){
	adj.clear();
	edgemp.clear();
	edges.clear();
	visited.clear();
	mx_ans=0;
}

ll get_len(ll s){
	ll len=adj[s].size();
	ll val=0;
	for(ll i=0;i<len;i++){
		ll u=s;
		ll v=adj[s][i];
		if(u>v)swap(u,v);
		ll idx=edgemp[{u,v}];
		if(!visited[idx]){
			visited[idx]=true;
			ll val2=1+get_len(adj[s][i]);
			if(val2>val){
				val=val2;
			}
			visited[idx]=false;
		}
	}
	return val;
}

int main(){
	while(true){
		init();
		cin>>n>>m;
		if(n==0&&m==0)break;
		adj.assign(n+5,vector<ll>(0));
		ll u,v;
		for(ll i=0;i<m;i++){
			cin>>u>>v;
			if(u==v)continue;
			else if(u>v)swap(u,v);
			if(!edgemp[{u,v}]){
				edgemp[{u,v}]=edges.size();
				edges.push_back({u,v});
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		m=edges.size();
		for(ll i=0;i<n;i++){
			visited.assign(m+5,false);
			ll ans=get_len(i);
			mx_ans=max(mx_ans,ans);
		}
		cout<<mx_ans<<endl;
	}
	return 0;
}