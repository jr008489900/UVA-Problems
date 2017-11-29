#include<iostream>
using namespace std;
const int maxs=100050;
int lnode[maxs] , rnode[maxs];
int head=0;

void initial()
{
    for(int i=0;i<maxs;i++)
    {
        lnode[i]=0; rnode[i]=0;
    }
    head=0;
}

void build(int n)
{
    bool check=1;
    int cur=head;
    while(check)
    {

        if(lnode[cur]&&n<cur)
            {cur=lnode[cur];continue;}
        else if(rnode[cur]&&n>cur)
            {cur=rnode[cur];continue;}
        if(n<cur&&!lnode[cur]) {lnode[cur]=n;check=0;}
        else if(n>cur&&!rnode[cur]) {rnode[cur]=n;check=0;}

    }
    return ;
}

void DFS(int n)
{
    if(lnode[n]) DFS(lnode[n]);
    if(rnode[n]) DFS(rnode[n]);
    cout << n << endl;
    return ;
}

int main()
{
    initial();
    int N;
    bool check=1;
    while(cin >> N)
    {
        if(check) head=N;
        else build(N);
        check=0;
    }
    DFS(head);
    return 0;
}
