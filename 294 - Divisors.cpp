#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxs=50000;

bool isp[maxs];
map<int,int> maps;
map<int,int>::iterator iter;


void init()
{
    fill(isp,isp+maxs,1);
    isp[0]=false;

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

int getp(int& num)
{
    for(int i=2;i<maxs;i++)
    {
        if(isp[i]&&num%i==0)
        {
            num/=i;
            return i;
        }
    }
    num=1;
    return num;
}

int ans(int num)
{
    maps.clear();
    int temp=num;
    while(temp!=1)
    {
        maps[getp(temp)]++;
    }
    int cnt=1;
    for(iter=maps.begin();iter!=maps.end();iter++)
    {
        cnt*=(iter->second+1);
    }
    return cnt;
}



int main()
{
    init();
    int N; cin >> N;
    while(N--)
    {
        int a , b;
        cin >> a >> b;

        int fmaxs=0 , cur=0;
        for(int i=a;i<=b;i++)
        {
            int temp=ans(i);
            if(fmaxs<temp)  fmaxs=temp , cur=i;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,cur,fmaxs);

    }
    return 0;
}
