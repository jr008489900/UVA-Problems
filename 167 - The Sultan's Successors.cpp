#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
const int maxs=10;
int arr[maxs][maxs];
bool valid[maxs][maxs];

int ans;

bool check(int y,int x)
{
    for(int i=y-1;i>=1;i--)
        if(valid[i][x]) return 0;
    for(int i=y-1,j=x-1;i>=1&&j>=1;i--,j--)
        if(valid[i][j]) return 0;
    for(int i=y-1,j=x+1;i>=1&&j<=8;i--,j++)
        if(valid[i][j]) return 0;
    return 1;
}
void DFS(int i,int sum)
{
    if(i>=9)   ans=max(ans,sum);
    else
    {
        for(int j=1;j<=8;j++)
        {
            if(check(i,j))
            {
                valid[i][j]=1;
                DFS(i+1,sum+arr[i][j]);
                valid[i][j]=0;
            }
        }
    }
}

void init()
{
    for(int i=0;i<maxs;i++)
    {
        for(int j=0;j<maxs;j++)
            valid[i][j]=0;
    }
}

int main()
{
    //ofstream fout("123.txt");
    int N; cin >> N;
    while(N--)
    {
        init();
        int temp;
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                cin >> temp;
                arr[i][j]=temp;
            }
        }
        ans=0;
        DFS(1,0);
        cout << setw(5) << ans << endl;
    }
}
