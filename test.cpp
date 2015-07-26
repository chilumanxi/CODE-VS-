#include<iostream>
using namespace std;
struct data{
        int mp[5][5];//1白棋,2黑棋,0空格

}d[5000];
int next[5000]={1,2};//下一步走黑棋还是白棋,1为白,2为黑
int step[5000];
bool hash[4000000];
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int t=0,w=2,flag=0;
bool equ(int a1,int a2,int a3,int a4){if(a1!=a2||a2!=a3||a3!=a4||a4!=a1)return 0;return 1;}
bool check(){
        for(int i=1;i<=4;i++)
    {
                if(equ(d[w].mp[i][1],d[w].mp[i][2],d[w].mp[i][3],d[w].mp[i][4]))return 1;
                if(equ(d[w].mp[1][i],d[w].mp[2][i],d[w].mp[3][i],d[w].mp[4][i]))return 1;
            
    }
        if(equ(d[w].mp[1][1],d[w].mp[2][2],d[w].mp[3][3],d[w].mp[4][4]))return 1;
        if(equ(d[w].mp[1][4],d[w].mp[2][3],d[w].mp[3][2],d[w].mp[4][1]))return 1;
        return 0;

}
int Hash(){//哈希判重 
              int s=0,k=1;
              for(int i=1;i<=4;i++)
                for(int j=1;j<=4;j++)
                {s+=d[w].mp[i][j]*k;k*=3;}
              s%=3733799;
              if(!hash[s]){hash[s]=1;return 1;}
              return 0;
          }
bool pd(int x,int y){
        int k=next[t];
        if(x>4||y>4||x==0||y==0)return 0;
        else if(d[t].mp[x][y]==k)return 1;
        return 0;

}
void sp(int &a,int &b){int t=a;a=b;b=t;}
void move(int x,int y){
        for(int i=0;i<4;i++)
    {
                int p=x+xx[i],q=y+yy[i];
                if(pd(p,q))
        {
                        for(int j=1;j<=4;j++)
                            for(int k=1;k<=4;k++)
                                d[w].mp[j][k]=d[t].mp[j][k];
                        sp(d[w].mp[x][y],d[w].mp[p][q]);
                        step[w]=step[t]+1;
                        if(check()){cout<<step[w];flag=1;return;}
                        if(Hash())
                        {          
                                        if(next[t]==1)next[w++]=2;
                                        if(next[t]==2)next[w++]=1;
                                    }
                    
        }
            
    }

}
void search(){
        while(t<w)
    {
                for(int i=1;i<=4;i++)
                    for(int j=1;j<=4;j++)
        {
                            if(d[t].mp[i][j]==0)move(i,j);
                            if(flag)return;
                        
        }
                t++;
            
    }

} 
int main(){
        char x;
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
    {
                    cin>>x;
                    if(x=='W')d[0].mp[i][j]=d[1].mp[i][j]=1;
                    else if(x=='B')d[0].mp[i][j]=d[1].mp[i][j]=2;
                
    }
        search();
        return 0;

}
