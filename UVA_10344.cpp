#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nums[5];
ll maxmask=((1<<5)-1);

ll get_ans(ll res, ll mask){
	if(mask==maxmask){
		if(res==23){
			return true;
		}
		return false;
	}
	bool ans=false;
	for(ll i=0;i<5;i++){
		ll ck=(1<<i);
		if((mask&ck)==0){
			if(mask==0){
				ans=get_ans(nums[i],mask|ck);
			}else{
				ans|=get_ans(res+nums[i],mask|ck);
				ans|=get_ans(res-nums[i],mask|ck);
				ans|=get_ans(res*nums[i],mask|ck);
			}
		}
		if(ans)break;
	}
	return ans;
}

int main(){
	while(1){
		bool ck=false;
		for(ll i=0;i<5;i++){
			cin>>nums[i];
			if(nums[i]!=0)ck=true;
		}
		if(!ck)break;
		bool ans=get_ans(0,0);
		if(ans==true)cout<<"Possible\n";
		else cout<<"Impossible\n";
	}
	return 0;
}