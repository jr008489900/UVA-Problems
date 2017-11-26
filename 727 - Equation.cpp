#include<iostream>
#include<stack>
#include<cctype>
#include<map>
#include<fstream>
using namespace std;
map<char,int> opin;
map<char,int> opout;
string read()
{
    string str="";
    char a;
    while(cin.get(a)&&a!='\n')
    {
        cin.ignore();
        str+=a;
    }
    return str;
}

void initial()
{
    opin['+']=1; opin['-']=1;
    opin['*']=2; opin['/']=2;
    opin['(']=0; opout['(']=3;
    opout['+']=1; opout['-']=1;
    opout['*']=2; opout['/']=2;
}

string process(string str)
{
    string ans="";
    stack<char> sta;
    for(int i=0;i<str.size();i++)
    {
        if(isdigit(str[i])) ans+=str[i];
        else if(str[i]==')')
        {
            while(sta.top()!='(')
            {
               ans+=sta.top(); sta.pop();
            }
            sta.pop();
        }
        else
        {
            if(sta.empty()) sta.push(str[i]);
            else
            {
                if(opout[str[i]] > opin[sta.top()] )
                    sta.push(str[i]);
                else
                {
                    while(opout[str[i]]<=opin[sta.top()])
                    {
                        ans+=sta.top(); sta.pop();
                        if(sta.empty()) break;
                    }
                    sta.push(str[i]);
                }
            }
        }
    }
    while(!sta.empty())
    {
        ans+=sta.top();
        sta.pop();
    }
    return ans;
}

int main()
{
    //fstream oo("123.txt");
    ostream& oout(cout);
    initial();
    int N; cin >> N ;
    cin.ignore();
    cin.ignore();
    while(N--)
    {

        string str=read();
        oout << process(str) << endl;
        if(N)
            oout << endl;
    }
}
