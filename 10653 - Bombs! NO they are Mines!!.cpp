#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;
const int maxs=1010;
int dun[maxs][maxs];
bool check[maxs][maxs];

struct Grid
{
    int row , col;
    Grid(){}
    Grid(int y,int x)
    {
        row=y; col=x;
    }
};

Grid S , E;

void initial()  ///初始化迷宮
{
    for(int i=0;i<maxs;i++)
    {
        for(int j=0;j<maxs;j++)
        {
            dun[i][j]=0;
            check[i][j]=1;
        }
    }

    for(int i=0;i<maxs;i++) ///邊界建立
    {
        check[i][0]=0;
        check[i][maxs-1]=0;
        check[0][i]=0;
        check[maxs-1][i]=0;
    }
}

void read()
{
    int N ; cin >> N ;
    cin.ignore();
    while(N--)
    {
        string str; getline(cin,str);
        stringstream ss(str);
        int y , x ;
        ss >> y >> x ;
        while(ss >> x)
        {
            check[y+1][x+1]=0;
        }
    }
    int y ,x ;
    cin >> y >> x;
    S.row=y+1; S.col=x+1;
    cin >> y >> x ;
    E.row=y+1; E.col=x+1;
}

int DFS()
{
    queue<Grid> que;
    que.push(S);
    while(!que.empty())
    {
        Grid temp=que.front();
        if(temp.row==E.row && temp.col==E.col) break;
        if(check[temp.row-1][temp.col])   ///North
        {
            check[temp.row-1][temp.col]=0;
            dun[temp.row-1][temp.col]=dun[temp.row][temp.col]+1;
            que.push(Grid(temp.row-1,temp.col));
        }
        if(check[temp.row+1][temp.col])   ///South
        {
            check[temp.row+1][temp.col]=0;
            dun[temp.row+1][temp.col]=dun[temp.row][temp.col]+1;
            que.push(Grid(temp.row+1,temp.col));
        }
        if(check[temp.row][temp.col-1])   ///West
        {
            check[temp.row][temp.col-1]=0;
            dun[temp.row][temp.col-1]=dun[temp.row][temp.col]+1;
            que.push(Grid(temp.row,temp.col-1));
        }
        if(check[temp.row][temp.col+1])   ///East
        {
            check[temp.row][temp.col+1]=0;
            dun[temp.row][temp.col+1]=dun[temp.row][temp.col]+1;
            que.push(Grid(temp.row,temp.col+1));
        }
        que.pop();
    }
    return dun[E.row][E.col];
}

int main()
{
    int y , x;
    while(cin >> y >> x && y && x)
    {
        initial();
        read();
        cout << DFS() << endl;
    }
    return 0;
}
