#include<iostream>
using namespace std;
typedef long long ll;

ll n,t=0;
ll dx[]={-1,-1,0,0,1,1};
ll dy[]={-1,0,-1,1,0,1};
string board[210];
bool visited[210][210];
ll st_w[210],ct_w=0;

bool ck_win(ll x, ll y){
    visited[x][y]=true;
    if(y==n-1)return true;
    bool ck=false;
    for(ll i=0;i<6;i++){
        ll newx=x+dx[i];
        ll newy=y+dy[i];
        if(newx>=0&&newx<n&&newy>=0&&newy<n){
            if(board[newx][newy]=='w'&&!visited[newx][newy]){
                ck|=ck_win(newx,newy);
                if(ck)break;
            }
        }
    }
    return ck;
}

void init(){
    for(ll i=0;i<210;i++){
        for(ll j=0;j<210;j++)visited[i][j]=false;
    }
}

int main(){
    while(cin>>n){
        if(n==0)break;
        ct_w=0;
        for(ll i=0;i<n;i++){
            cin>>board[i];
        }
        for(ll i=0;i<n;i++){
            if(board[i][0]=='w'){
                st_w[ct_w]=i;
                ct_w++;
            }
        }
        bool win_w=false;
        for(ll i=0;i<ct_w;i++){
            init();
            win_w|=ck_win(st_w[i],0);
            if(win_w)break;
        }
        t++;
        if(win_w)cout<<t<<" W\n";
        else cout<<t<<" B\n";
    }
    return 0;
}