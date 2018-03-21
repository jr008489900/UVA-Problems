#include<iostream>
#include<algorithm>
using namespace std;

struct Point
{
    Point()
    {
        ranks=0;
    }
    Point (int X,int Y)
    {
        x=X;y=Y;
        ranks=0;
    }
    int x , y , ranks;
};

const int maxs=10050;
Point arr[maxs];
int index[maxs];
int tindex[maxs];


bool cmp(int a,int b)
{
    if(arr[a].x!=arr[b].x)
        return arr[a].x<arr[b].x;
    else
        return arr[a].y>arr[b].y;
}

void RF(int l,int r)
{
    if(r<=l) return ;
    else
    {
        int m=(l+r)/2;
        RF(l,m);
        RF(m+1,r);

        int i=l , j=m+1 , cnt=0 , cur=0;
        while(i<=m&&j<=r)
        {
            if(arr[index[j]].y>arr[index[i]].y) {tindex[cur++]=index[i++];cnt++;}
            else    {tindex[cur++]=index[j++];arr[tindex[cur-1]].ranks+=cnt;}
        }
        while(i<=m) {tindex[cur++]=index[i++];}
        while(j<=r) {tindex[cur++]=index[j++];arr[tindex[cur-1]].ranks+=cnt;}

        for(int i=0;i<cur;i++)  index[l++]=tindex[i];
    }
}

void init()
{
    for(int i=0;i<maxs;i++)
    {
        index[i]=i;
        tindex[i]=i;
    }
}

int main()
{
    int N;

    while(cin >> N)
    {
        init();

        int tx , ty;
        for(int i=0;i<N;i++)
        {
            cin >> tx >> ty;
            arr[i]=Point(tx,ty);
        }

        sort(index,index+N,cmp);

        RF(0,N-1);

        for(int i=0;i<N;i++)
        {
            cout << arr[i].ranks << endl;
        }
    }
    return 0;
}
