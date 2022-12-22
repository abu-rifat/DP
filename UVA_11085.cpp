#include<iostream>
using namespace std;
typedef long long ll;

ll pos[8],arr[8],ans;

bool valid(ll col, ll row){
	for(ll i=0;i<col;i++){
		if(pos[i]==row||abs(pos[i]-row)==abs(i-col))return false;
	}
	return true;
}

void go_babe(ll idx,ll val){
	if(idx==8){
		ans=min(ans,val);
		return;
	}
	for(ll i=0;i<8;i++){
		if(valid(idx,i)){
			pos[idx]=i;
			go_babe(idx+1,val+(arr[idx]!=pos[idx]));
		}
	}
}

int main(){
	ll tcase=0;
	while(cin>>arr[0]){
		for(ll i=1;i<8;i++)cin>>arr[i];
		for(ll i=0;i<8;i++)arr[i]--;
		ans=8;
		go_babe(0,0);
		tcase++;
		cout<<"Case "<<tcase<<": "<<ans<<endl;
	}
	return 0;
}