#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxs=100050;
int fail[maxs];

void failure(string pat)
{
    for(int i=1,j=fail[0]=-1;i<pat.size();i++)
    {
        while(j>=0&&pat[j+1]!=pat[i])   j=fail[j];

        if(pat[j+1]==pat[i]) j++;

        fail[i]=j;
    }
}

string ans(string str)
{
    string pat=str;
    reverse(pat.begin(),pat.end());
    failure(pat);
    int i=0 , j=0;
    while(i!=str.size()&&j!=pat.size())
    {
        if(pat[j]==str[i]) {i++;j++;}
        else if(j==0)i++;
        else j=fail[j-1]+1;
    }
    for(j;j<pat.size();j++)
    {
        str+=pat[j];
    }
    return str;
}
int main()
{
    string str;
    while(cin >> str)
    {
        cout << ans(str) << endl;
    }
    return 0;
}
