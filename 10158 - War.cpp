#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
const int maxs=20005;
int parents[maxs];
int N ;
ofstream fout("123.txt");
void initial()
{
   for(int i=0;i<maxs;i++)  parents[i]=i;
}

int finds(int e);
void setFriend(int,int);
void setEnemies(int,int);
bool areFriend(int,int);
bool areEnemies(int,int);

int main()
{

    initial();
    cin >> N;
    int a , b , c ;
    while(cin >> a >> b >> c && a )
    {
        if(a==1)    setFriend(b,c);
        else if(a==2)   setEnemies(b,c);
        else if(a==3)   cout << areFriend(b,c) << endl;
        else    cout << areEnemies(b,c) << endl;
    }
    return 0;
}
int finds(int e)
{
    if(e==maxs) return maxs;
    return parents[e]==e ? e: parents[e]=finds(parents[e]);
}

bool areFriend(int a,int b)
{
    a=finds(a); b=finds(b);
    return a==b ? 1:0;
}

bool areEnemies(int a,int b)
{
    int ena=finds(a+N),enb=finds(b+N);
    return ena==finds(b)&&enb==finds(a) ? 1:0;
}

void setFriend(int e1,int e2)
{
    int r1=finds(e1),r2=finds(e2);
    int b1=finds(e1+N),b2=finds(e2+N);
    if(r1!=b2)
    {
       parents[r2]=r1;
       parents[b2]=b1;
    }
    else cout << -1 << endl;///如果r1那群的人是r2的敵人，就無法成立。
}

void setEnemies(int e1,int e2)
{
    int r1=finds(e1),r2=finds(e2);
    int b1=finds(e1+N),b2=finds(e2+N);
    if(r1!=r2)
    {
        parents[b1]=r2;
        parents[b2]=r1;
    }
    else cout << -1 << endl;
}
