#include<iostream>
#include<string>
using namespace std;
const int maxs=2000;
int nexts[maxs];

void failure(string pat)
{
    for(int i=0;i<maxs;i++) nexts[i]=-1;
    for(int i=1,j=nexts[0]=-1;i<pat.size();i++)
    {
        while(pat[i]!=pat[j+1]&&j>=0)   j=nexts[j];
        if(pat[j+1]==pat[i]) j++;
        nexts[i]=j;
    }
}

int main()
{
    int N; cin >> N;
    while(N--)
    {
        string str; cin >> str;
        failure(str);
        int lim=str.size();
        if(lim%(lim-1-nexts[lim-1])==0) cout << lim-1-nexts[lim-1] << endl;
        else    cout << lim << endl;
        if(N) cout << endl;
    }
}
