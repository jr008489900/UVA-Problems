#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxs=90;

int maze[maxs][maxs];

struct Point
{
    int x , y;
    Point(int a,int b) : x(a),y(b){}
    Point(){}
};

void init()
{
    for(int i=0;i<maxs;i++) fill(maze[i],maze[i]+maxs,-2);
}



int main()
{
    int N;  cin >> N;
    while(N--)
    {
        init();
        string str;
        int i=1;
        Point cur;
        while(getline(cin,str))
        {
            bool check=0;
            for(int j=0;j<str.size();j++)
            {
                if(str[j]==' ') maze[i][j+1]=0;
                else if(str[j]=='*') maze[i][j+1]=1, cur.y=i, cur.x=j;
                else if(str[j]<='Z'&&str[j]>='A') maze[i][j+1]=str[j];
                else check=1;
            }
            if(check) break;
            i++;
        }

        /*BFS*/
        queue<Point> que;
        que.push(cur);
        while(!que.empty())
        {
            Point temp=que.front();
            if(!que.empty())que.pop();
            if(maze[temp.y-1][temp.x]==0)   maze[temp.y-1][temp.x]=1, que.push(Point(temp.x,temp.y-1));
            if(maze[temp.y+1][temp.x]==0)   maze[temp.y+1][temp.x]=1, que.push(Point(temp.x,temp.y+1));
            if(maze[temp.y][temp.x-1]==0)   maze[temp.y][temp.x-1]=1, que.push(Point(temp.x-1,temp.y));
            if(maze[temp.y][temp.x+1]==0)   maze[temp.y][temp.x+1]=1, que.push(Point(temp.x+1,temp.y));
        }

        /*print answer*/
        for(int i=0;i<maxs;i++)
        {
            bool c=0;
            for(int j=0;j<maxs;j++)
            {
                if(maze[i][j]<='Z'&&maze[i][j]>='A') c=1,cout << (char)maze[i][j];
                else if(maze[i][j]==0) c=1,cout << " ";
                else if(maze[i][j]==1)  c=1,cout << "#";
            }
            if(c)       cout << endl;
        }
        cout << "_____" << endl;

    }
}
