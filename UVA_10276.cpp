#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans[55],top[55];

ll rec(ll num, ll n){
	ll mx=num-1;
	for(ll i=1;i<=n;i++){
		ll tmp=top[i];
		if(tmp==-1){
			top[i]=num;
			ll val=rec(num+1,n);
			mx=max(mx,val);
			break;
		}else{
			ll num2=num+tmp;
			ll sq=sqrt(num2);
			if((sq*sq)==num2){
				top[i]=num;
				ll val=rec(num+1,n);
				mx=max(mx,val);
				top[i]=tmp;
				break;
			}
		}
	}
	return mx;
}

void gen_ans(ll n){
	for(ll i=0;i<=n;i++)top[i]=-1;
	ll val=rec(1,n);
	ans[n]=val;
}

void init(){
	for(ll i=1;i<=50;i++){
		gen_ans(i);
	}
}

int main(){
	init();
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll tmp;
		cin>>tmp;
		cout<<ans[tmp]<<endl;
	}
	return 0;
}