#include<bits/stdc++.h>
using namespace std;
typedef long ll;

string key="IEHOVA";
ll m,n;
vector<string>puzzle,dir;
map<char,bool>mp;

ll dx[]={-1,0,0};
ll dy[]={0,-1,1};

void get_dir(ll x, ll y){
	bool ck=false;
	for(ll i=0;i<3;i++){
		ll nx=x+dx[i];
		ll ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(puzzle[nx][ny]=='#'){
				if(i==0)dir.push_back("forth");
				else if(i==1)dir.push_back("left");
				else dir.push_back("right");
				return;
			}
		}
	}
	for(ll i=0;i<3;i++){
		ll nx=x+dx[i];
		ll ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			for(ll j=0;j<6;j++){
				if(puzzle[nx][ny]==key[j]&&!mp[key[j]]){
					mp[key[j]]=true;
					if(i==0)dir.push_back("forth");
					else if(i==1)dir.push_back("left");
					else dir.push_back("right");
					get_dir(nx,ny);
					ck=true;
					break;
				}
			}
		}
		if(ck)break;
	}
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		puzzle.clear();
		dir.clear();
		mp.clear();
		cin>>n>>m;
		for(ll i=0;i<n;i++){
			string tmp;
			cin>>tmp;
			puzzle.push_back(tmp);
		}
		ll ix,iy;
		bool ck=false;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				if(puzzle[i][j]=='@'){
					ix=i;
					iy=j;
					break;
					ck=true;
				}
			}
			if(ck)break;
		}
		get_dir(ix,iy);
		for(ll i=0;i<(ll)dir.size();i++){
			if(i!=0)cout<<" ";
			cout<<dir[i];
		}
		cout<<endl;
	}
	return 0;
}