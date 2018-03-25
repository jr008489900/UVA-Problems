#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

const int maxs=1050;

bool isp[maxs];
vector<int> prime;

void init()
{
    fill(isp,isp+maxs,1);
    isp[0]=0;
    prime.push_back(1);
    for(int i=2;i<maxs;i++)
    {
        if(isp[i])
        {
            for(int j=i+i;j<maxs;j+=i)
            {
                isp[j]=0;
            }
            prime.push_back(i);
        }
    }
}

int main()
{
    init();
    int N , C ;
   // ofstream fout("123.txt");
    while(cin >> N >> C)
    {
        int low=0,upp=0;
        while(prime[upp]<=N) upp++;
        int mid=upp/2;
        if(upp%2==0)
        {
            low=mid-C;
            mid+=(C-1);
        }
        else
        {
            low=mid-C+1;
            mid+=(C-1);
        }
        if(mid>=upp) mid=upp-1;
        if(low<0) low=0;

        cout << N << " " << C << ": ";
        for(int i=low;i<=mid;i++)
        {
            cout << prime[i];
            if(i!=mid) cout << " ";
        }
        cout << "\n\n";

    }
}
