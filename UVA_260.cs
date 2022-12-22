using System;

namespace UVA{
    class UVA_260{
        static int n,t=0,ct_w=0;
        static int[] dx={-1,-1,0,0,1,1},dy={-1,0,-1,1,0,1},st_w=new int[210];
        static string[] board=new string[210];
        static bool[,] visited=new bool[210,210];

        static bool ck_win(int x, int y){
            visited[x,y]=true;
            if(y==n-1)return true;
            bool ck=false;
            for(int i=0;i<6;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newx<n&&newy>=0&&newy<n){
                    if(board[newx][newy]=='w'&&!visited[newx,newy]){
                        ck|=ck_win(newx,newy);
                        if(ck)break;
                    }
                }
            }
            return ck;
        }

        static void init(){
            for(int i=0;i<210;i++){
                for(int j=0;j<210;j++)visited[i,j]=false;
            }
        }

        public static void Main(string[] args){
            while(true){
                n=Convert.ToInt32(Console.ReadLine());
                if(n==0)break;
                ct_w=0;
                for(int i=0;i<n;i++){
                    board[i]=Console.ReadLine();
                }
                for(int i=0;i<n;i++){
                    if(board[i][0]=='w'){
                        st_w[ct_w]=i;
                        ct_w++;
                    }
                }
                bool win_w=false;
                for(int i=0;i<ct_w;i++){
                    init();
                    win_w|=ck_win(st_w[i],0);
                    if(win_w)break;
                }
                t++;
                if(win_w){
                    Console.WriteLine($"{t} W");
                }
                else Console.WriteLine($"{t} B");
            }
        }
    }
}