#include<iostream>
#include<string>
using namespace std;
const int maxs=100050;
int nexts[maxs];  ///linked list�H�}�C�覡��@

void process(string str)
{
    for(int i=0;i<maxs;i++) nexts[i]=0;
    str.insert(str.begin(),' ');    ///��r����m��1~N��� 0�h�N��NULL;
    int cur=0, last=0; ///������e���� �H�γ̫���Ц�m�C
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
