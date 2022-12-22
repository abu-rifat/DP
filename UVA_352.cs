using System;

namespace UVA{
    class UVA_352{
        static int n,t = 0;
        static int[] dx = {0,0,1,-1,1,-1,1,-1}, dy = {1,-1,0,0,1,-1,-1,1};
        static bool[,] visited = new bool[30,30];
        static string[] image = new string[30];

        static void init(){
            for(int i=0;i<30;i++){
                for(int j=0;j<30;j++)visited[i,j]=false;
            }
        }

        static void go_visit(int x, int y){
            visited[x,y]=true;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<n){
                    if(image[nx][ny]=='1'&&!visited[nx,ny]){
                        go_visit(nx,ny);
                    }
                }
            }
        }

        public static void Main(string[] args){
            string line;
            while((line=Console.ReadLine())!=null){
                n=Convert.ToInt32(line);
                for(int i=0;i<n;i++){
                    image[i]=Console.ReadLine();
                }
                init();
                int ans=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(image[i][j]=='1'&&!visited[i,j]){
                            ans++;
                            go_visit(i,j);
                        }
                    }
                }
                t++;
                Console.WriteLine($"Image number {t} contains {ans} war eagles.");
            }
        }
    }
}