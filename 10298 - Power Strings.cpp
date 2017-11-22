#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int maxs=1000050;

int nexts[maxs];

void failure(string pat)
{
    for(int i=1,j=nexts[0]=-1;i<pat.size();i++)
    {
        while(pat[j+1]!=pat[i]&&j>=0) j=nexts[j];

        if(pat[j+1]==pat[i]) j++;

        nexts[i]=j;
    }
}

int KMP(string str)
{
    return str.size()/(str.size()-1-nexts[str.size()-1]);
}

int main()
{
    //ofstream oo("123.txt");
    ostream& oout(cout);
    string str;
    while(cin >> str&&str!=".")
    {
        failure(str);
        oout << KMP(str) << endl;
    }
    return 0;
}
