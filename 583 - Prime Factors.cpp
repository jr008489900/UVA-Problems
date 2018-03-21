#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxs=50000;

bool isp[maxs];

void init()
{
    fill(isp,isp+maxs,true);
    isp[0]=isp[1]=false;

    for(int i=2;i<maxs;i++)
    {
        if(isp[i])
        {
            for(int j=i+i;j<maxs;j+=i)
            {
                isp[j]=0;
            }
        }
    }
}
int get(int& n)
{
    for(int i=0;i<maxs;i++)
    {
        if(isp[i]&&n%i==0)
        {
            n/=i;
            return i;
        }
    }
    int t=n;
    n=1;
    return t;
}

int main()
{
    init();
    int N ;
    while(cin >> N && N)
    {
        vector<int> tar;
        int n=N,temp;
        if(n<0) {n*=-1; tar.push_back(-1);}
        while(n!=1)
        {
            temp=get(n);
            tar.push_back(temp);
        }
        cout << N << " = ";
        for(int i=0;i<tar.size();i++)
        {
            cout <<tar[i];
            if(i!=tar.size()-1) cout << " x ";
        }
        cout << endl;
    }
}
