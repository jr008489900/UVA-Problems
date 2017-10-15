#include<iostream>
#include<vector>
#include<fstream>
using namespace std ;

const int maxs=12;
bool H[maxs][maxs];
bool V[maxs][maxs];

void initial()
{
    for(int i=0;i<maxs;i++)
        for(int j=0;j<maxs;j++)
            {
                H[i][j]=0;
                V[i][j]=0;
            }
}

bool read()
{
    initial();
    int N ; cin >> N >> N;
    if(cin.eof()) return 0;
    while(N--)
    {
        char t; cin >> t;
        int x,y; cin >> x >> y;
        if(t=='H')
        {
            H[x][y]=1;
        }
        else
         {
             V[y][x]=1;
        }
    }
    return 1;
}

int fsq(int n)
{
    int sum=0;
    for(int i=1;i<maxs-n;i++)
    {
        for(int j=1;j<maxs-n;j++)
        {
            bool c=1;
            for(int k=0;k<n;k++)
            {
                if(!((H[i][j+k]&&H[i+n][j+k])&&V[i+k][j]&&V[i+k][j+n]))
                {
                    c=0; break;
                }
            }
            if(c) sum++;
        }
    }
    return sum;
}

void ans()
{
    bool flag=0;
    vector<int> arr;
    for(int i=1;i<=8;i++)
    {
        arr.push_back(fsq(i));
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=0)
        {
            cout << arr[i] << " square (s) of size " << i+1 << endl;
            flag=1;
        }
    }
    if(!flag)   cout << "No completed squares can be found."  << endl;
    return ;
}



int main()
{
    int cnt=1;
    bool flag=0;
    while(read())
    {
        if(flag) cout << endl;
        if(flag) cout << "**********************************" << "\n" << endl;
        cout << "Problem #" << cnt++ << endl;
        cout << endl;
        ans();
        flag=1;
    }
    return 0;
}
