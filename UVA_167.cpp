#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll board[10][10];
ll taken[10];
ll ans=0;

bool valid(ll col, ll row){
	for(ll i=0;i<col;i++){
		if((taken[i]==row)||abs(taken[i]-row)==abs(i-col))return false;
	}
	return true;
}

void calc(){
	ll sum=0;
	for(ll i=0;i<8;i++)sum+=board[i][taken[i]];
	ans=max(ans,sum);
}

void nqueen(ll idx){
	for(ll i=0;i<8;i++){
		if(valid(idx,i)){
			taken[idx]=i;
			if(idx==7)calc();
			else nqueen(idx+1);
		}
	}
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ans=0;
		for(ll i=0;i<8;i++){
			for(ll j=0;j<8;j++)cin>>board[i][j];
		}
		nqueen(0);
		printf("%5lld\n",ans);
	}
	return 0;
}