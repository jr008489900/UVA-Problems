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

int KMP(string str,string pat)
{
    int i=0, j=0;
    int ans=0;
    while(i!=str.size())
    {
        if(str[i]==pat[j]) {i++;j++;}
        else if(j==0) i++;
        else j=nexts[j-1];

        if(j==pat.size()){j=nexts[j-1];ans++;}
    }
    //cout << ans << endl;
    return ans;
}

int main()
{
    int N; cin >> N;
    while(N--)
    {
        string str; cin >> str;
        for(int i=1;i<=str.size();i++)
        {
            if(str.size()%i==0)
            {
                string pat="";
                for(int j=0;j<i;j++)
                    pat+=str[j];
                failure(pat);
                int result=KMP(str,pat);
                if(result==(str.size()/i))
                {
                    cout << i << endl;
                    break;
                }
            }
        }
        if(N) cout << endl;
    }
}
