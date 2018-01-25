#include<iostream>
#include<sstream>
using namespace std;
const int maxs= 1000000;
int Sets[maxs];
int success, unsuccess;

void initial()
{
    for(int i=0;i<maxs;i++)
    {
        Sets[i]=i;
    }
    success=0; unsuccess=0;
}

int finds(int element) ///找尋該元素所處集合的根
{
    if(Sets[element]==element) return element;
    else return finds(Sets[element]);
}

void unions(int e1,int e2)
{
    Sets[finds(e2)]=finds(e1);
}

void read()
{
    string str;
    while(getline(cin,str))
    {
        if(str=="") return ;
        else
        {
            stringstream ss(str);
            char tempc;
            int i , j;
            ss >> tempc >> i >> j;
            if(tempc=='c')  unions(i,j);
            else
            {
                if(finds(i)==finds(j)) success++;
                else unsuccess++;
            }
        }
    }
}
int main()
{
    int N ; cin >> N;
    while(N--)
    {
        int n; cin >> n;
        cin.ignore();
        initial();
        read();
        cout << success << ',' << unsuccess << endl;
        if(N) cout << endl;
    }
}
