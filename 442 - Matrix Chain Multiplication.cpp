#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

struct matrix
{
    int m,n;
    matrix(){};
    matrix(int sm,int sn)
    {
        m=sm; n=sn;
    }
};

map<string,matrix> mymap;

void read(int N)
{
    while(N--)
    {
        string a ;
        int b , c ; cin >> a >> b >> c;
        matrix temp(b,c);
        mymap[a]=temp;
    }
}



int ans(string str)
{
    stack<string> sta;
    int cnt=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==')')
        {
            matrix x , y;
            string name="";
            if(!sta.empty())    {x=mymap[sta.top()];name+=sta.top();sta.pop();}
            if(!sta.empty())    {y=mymap[sta.top()];name+=sta.top();sta.pop();sta.pop();}
            if(x.m!=y.n) {cnt=-1;break;}
            cnt+=x.m*x.n*y.m;
            mymap[name]=matrix(y.m,x.n);
            sta.push(name);
        }
        else
        {
            string s=""; s+=str[i];
            sta.push(s);
        }
    }
    return cnt;
}

int main()
{
    int N;  cin >> N ;
    read(N);
    string str;
    while(cin >> str)
    {
        int sol=ans(str);
        if(sol==-1)
            cout << "error" << endl;
        else
            cout << sol << endl;
    }
    return 0;
}
