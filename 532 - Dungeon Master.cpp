#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
const int maxs=35;
int dun[maxs][maxs][maxs];
bool check[maxs][maxs][maxs];

struct Coor
{
    int z,y,x;
    Coor(){};
    Coor(int p,int q,int r)
    {
        z=p;y=q;x=r;
    }
};

Coor S , E;

void initial()
{
    for(int i=0;i<maxs;i++)
        for(int j=0;j<maxs;j++)
            for(int k=0;k<maxs;k++)
            {
                dun[i][j][k]=0;
                check[i][j][k]=0;
            }
}

void read(int z,int y ,int x)
{
    char temp;
    for(int i=1;i<=z;i++)
    {
        for(int j=1;j<=y;j++)
        {
            for(int k=1;k<=x;k++)
            {
                cin >> temp;
                if(temp=='.')check[i][j][k]=1;
                else if(temp=='S'){S.z=i;S.y=j;S.x=k; }
                else if(temp=='E'){E.z=i;E.y=j;E.x=k; check[i][j][k]=1;}

            }
        }
    }

}



int BFS(int z,int y,int x)
{
    queue<Coor> que;
    que.push(S);
    while(!que.empty())
    {
        Coor temp=que.front(); que.pop();
        if(temp.x==E.x&&temp.y==E.y&&temp.z==E.z) break;

        if(check[temp.z-1][temp.y][temp.x]) ///up
        {
            dun[temp.z-1][temp.y][temp.x]=dun[temp.z][temp.y][temp.x]+1;
            que.push(Coor(temp.z-1,temp.y,temp.x));
            check[temp.z-1][temp.y][temp.x]=0;
        }
        if(check[temp.z+1][temp.y][temp.x])   ///down
        {
            dun[temp.z+1][temp.y][temp.x]=dun[temp.z][temp.y][temp.x]+1;
            que.push(Coor(temp.z+1,temp.y,temp.x));
            check[temp.z+1][temp.y][temp.x]=0;
        }
        if(check[temp.z][temp.y-1][temp.x])   ///North
        {
            dun[temp.z][temp.y-1][temp.x]=dun[temp.z][temp.y][temp.x]+1;
            que.push(Coor(temp.z,temp.y-1,temp.x));
            check[temp.z][temp.y-1][temp.x]=0;
        }
        if(check[temp.z][temp.y+1][temp.x])   ///South
        {
            dun[temp.z][temp.y+1][temp.x]=dun[temp.z][temp.y][temp.x]+1;
            que.push(Coor(temp.z,temp.y+1,temp.x));
            check[temp.z][temp.y+1][temp.x]=0;
        }
        if(check[temp.z][temp.y][temp.x-1])   ///West
        {
            dun[temp.z][temp.y][temp.x-1]=dun[temp.z][temp.y][temp.x]+1;
            que.push(Coor(temp.z,temp.y,temp.x-1));
            check[temp.z][temp.y][temp.x-1]=0;
        }
        if(check[temp.z][temp.y][temp.x+1])   ///East
        {
            dun[temp.z][temp.y][temp.x+1]=dun[temp.z][temp.y][temp.x]+1;
            que.push(Coor(temp.z,temp.y,temp.x+1));
            check[temp.z][temp.y][temp.x+1]=0;
        }
    }
    return dun[E.z][E.y][E.x];
}

int main()
{
    int z , y , x ;
    while(cin >> z >> y >> x &&z && y && x)
    {
        initial();
        read(z,y,x);
        int ans=BFS(z,y,x);
        if(ans) cout << "Escaped in " << ans << " minute(s)."<< endl;
        else cout << "Trapped!" << endl;
    }
}
