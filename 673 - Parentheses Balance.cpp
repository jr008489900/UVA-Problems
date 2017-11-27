#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool ismatch(string str)
{
    stack<char> sta;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==')')
        {
            if(!sta.empty()&&sta.top()=='(')    sta.pop();
            else    sta.push(str[i]);
        }
        else if(str[i]==']')
        {
            if(!sta.empty()&&sta.top()=='[')    sta.pop();
            else    sta.push(str[i]);
        }
        else
            sta.push(str[i]);
    }
    return sta.empty();
}

int main()
{
    int N ; cin >> N;
    cin.ignore();
    while(N--)
    {
        string str ;
        getline(cin,str);
        if(ismatch(str)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
