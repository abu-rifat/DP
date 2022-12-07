#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,no=1;

ll ans[10];

bool check_valid(ll idx, ll i, ll j){
	if(ans[j]==i)return false;
	if(abs(idx-j)==abs(i-ans[j]))return false;
	return true;
}

void print_ans(){
	printf("%2lld     ",no);
	for(ll i=0;i<8;i++){
		cout<<" ";
		cout<<ans[i]+1;
	}
	cout<<endl;
	no++;
}

void get_ans(ll idx){
	if(idx==8)print_ans();
	if(idx==n)get_ans(idx+1);
	else{
		for(ll i=0;i<8;i++){
			bool ck=true;
			if(i==m)continue;
			for(ll j=0;j<idx;j++){
				ck=check_valid(idx,i,j);
				if(!ck)break;
			}
			if(ck)ck=check_valid(idx,i,n);
			if(ck){
				ans[idx]=i;
				get_ans(idx+1);
			}
		}
	}
}

int main(){
	ll t;
	cin>>t;
	bool ck=true;
	while(t--){
		no=1;
		for(ll i=0;i<10;i++)ans[i]=-1;
		cin>>m>>n;
		n--,m--;
		ans[n]=m;
		if(ck)ck=false;
		else cout<<endl;
		cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		get_ans(0);
	}
	return 0;
}