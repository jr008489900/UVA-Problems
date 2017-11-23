#include<iostream>
#include<string>
using namespace std;
const int maxs=100050;
int nexts[maxs];  ///linked list以陣列方式實作

void process(string str)
{
    for(int i=0;i<maxs;i++) nexts[i]=0;
    str.insert(str.begin(),' ');    ///把字元位置用1~N表示 0則代表NULL;
    int cur=0, last=0; ///紀錄當前指標 以及最後指標位置。
    for(int i=1;i<str.size();i++)
    {
        if(str[i]=='[') cur=0;
        else if(str[i]==']') cur=last;
        else
        {
            nexts[i]=nexts[cur];
            nexts[cur]=i;
            if(cur==last) last=i;
            cur=i;
        }
    }
    for(int i=nexts[0];i!=0;i=nexts[i])
        cout << str[i];
}

int main()
{
    string str;
    while(cin >> str)
    {
        process(str);
        cout << endl;
    }
    return 0;
}
