#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q;
ll num[205];

ll dp[205][15][25];

void init(){
    for(ll i=0;i<205;i++){
        for(ll j=0;j<15;j++){
            for(ll k=0;k<25;k++)dp[i][j][k]=-1;
        }
    }
}

ll go_babe(ll idx, ll taken, ll presum, ll d, ll m){
    ll &res = dp[idx][taken][presum];
    if(taken==m){
        if(presum==0){
            return 1;
        }
        else return 0;
    }
    if(idx>=n||taken>m)return 0;
    if(res!=-1)return res;
    ll val1=go_babe(idx+1,taken,presum,d,m);
    ll sum=(presum+num[idx])%d;
    sum=(sum+d)%d;
    ll val2=go_babe(idx+1,taken+1,sum,d,m);
    return res = val1 + val2;
}

int main(){
    ll t=1;
    while(t){
        cin>>n>>q;
        if(n==0&&q==0)break;
        for(ll i=0;i<n;i++){
            cin>>num[i];
        }
        ll que[q+5][2];
        for(ll i=0;i<q;i++){
            cin>>que[i][0]>>que[i][1];
        }
        cout<<"SET "<<t<<":\n";
        for(ll i=0;i<q;i++){
            init();
            ll ans=go_babe(0,0,0,que[i][0],que[i][1]);
            cout<<"QUERY "<<i+1<<": "<<ans<<"\n";
        }
        t++;
    }
}