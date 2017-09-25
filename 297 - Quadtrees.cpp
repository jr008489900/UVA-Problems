#include<iostream>
using namespace std;
string str;
const int len=32;
bool state[len][len];
int cnt;
void draw(int& s,int y,int x,int wid)
{
    if(s>=str.size())   return;
    if(str[s]=='p')
    {
        draw(++s,y,x+wid/2,wid/2);
        draw(++s,y,x,wid/2);
        draw(++s,y+wid/2,x,wid/2);
        draw(++s,y+wid/2,x+wid/2,wid/2);
    }
    else if(str[s]=='f')
    {
        for(int i=y;i<y+wid;i++)
            for(int j=x;j<x+wid;j++)
            {
                if(!state[i][j])
                {
                    cnt++;
                    state[i][j]=1;
                }
            }
    }
    else return;
}
void initial()
{
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            state[i][j]=0;
    cnt=0;
}
int main()
{
    int N; cin >> N;
    while(N--)
    {
        cin  >> str;
        initial();
        int temp=0;
        draw(temp,0,0,len);
        cin >> str;
        temp=0;
        draw(temp,0,0,len);
        cout << "There are "<< cnt << " black pixels." << endl;
    }
    return 0;
}
