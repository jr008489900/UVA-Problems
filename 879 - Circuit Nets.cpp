#include<iostream>
#include<sstream>
using namespace std;
const int maxs=100000;
int nets[maxs];

void initial()
{
    for(int i=0;i<maxs;i++) nets[i]=i;
}

int finds(int e)
{
    return nets[e]==e? e : nets[e]=finds(nets[e]);
}

void unions(int a,int b,int& group)
{
    int roota = finds(a);
    int rootb = finds(b);
    if(roota!=rootb)
    {
        group--;
        nets[rootb]=roota;
    }
}


int main()
{
    int n ; cin >> n;
    while(n--)
    {
        initial();
        int num; cin >> num;
        int group=num;

        cin.ignore();
        string str;
        while(getline(cin,str)&&str!="")
        {
            stringstream ss(str);
            int ta , tb;
            while(ss >> ta >> tb)   unions(ta,tb,group);
        }

        cout << group << endl;
        if(n) cout << endl;
    }
    return 0;
}
