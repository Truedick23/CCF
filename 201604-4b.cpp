#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int x;
    int y;
    int time;
}nod;
struct dead
{
    int start;
    int end;

}dead[105][105]={0};
int n,m,t;
queue<node>q;
int path[4][2]={1,0,0,1,0,-1,-1,0};
int flag[105][105][305]={0};
bool issaf(int a,int b,int t)
{
    if((a>=1 && a<=n && b>=1 && b<=m) && t<=300 && (t<dead[a][b].start || t>dead[a][b].end) && (flag[a][b][t]==0))
    {
        return true;
    }
    return false;
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    int r,c,a,b;
    for(int i=0;i<t;++i)
    {
        scanf("%d%d%d%d",&r,&c,&a,&b);
        dead[r][c].start=a;
        dead[r][c].end=b;
    }
    int x=0,y=0;
    node nd;
    nd.x=nd.y=1;
    nd.time=0;
    q.push(nd);
    int now=0;
    while(!q.empty())
    {
        nd=q.front();
        q.pop();
        if(nd.x==n && nd.y==m)
        {
            break;
        }
        now=nod.time=nd.time+1;
        for(int i=0;i<4;++i)
        {
            x=nod.x=nd.x+path[i][0];
            y=nod.y=nd.y+path[i][1];
            if(issaf(x,y,now))
            {
                q.push(nod);
                flag[x][y][now]=1;
            }
        }
    }
    printf("%d",nd.time);
    return 0;
}
