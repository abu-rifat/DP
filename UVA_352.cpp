#include<iostream>
using namespace std;
typedef long long ll;

ll n,t=0;
string image[30];
bool visited[30][30];
ll dx[]={0,0,1,-1,1,-1,1,-1};
ll dy[]={1,-1,0,0,1,-1,-1,1};

void init(){
    for(ll i=0;i<30;i++){
        for(ll j=0;j<30;j++)visited[i][j]=false;
    }
}

void go_visit(ll x, ll y){
    visited[x][y]=true;
    for(ll i=0;i<8;i++){
        ll nx=x+dx[i];
        ll ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n){
            if(image[nx][ny]=='1'&&!visited[nx][ny]){
                go_visit(nx,ny);
            }
        }
    }
}

int main(){
    while(cin>>n){
        for(ll i=0;i<n;i++)cin>>image[i];
        init();
        ll ans=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(image[i][j]=='1'&&!visited[i][j]){
                    ans++;
                    go_visit(i,j);
                }
            }
        }
        t++;
        cout<<"Image number "<<t<<" contains "<<ans<<" war eagles.\n";
    }
    return 0;
}