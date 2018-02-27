#include<iostream>
#include<cmath>
using namespace std;
const int maxs=10005;
const int minin=-99999999;
int sets[maxs];

int dcmax(int lefts,int mid,int rights)
{
    int lmax=minin , rmax=minin ;
    int lsum=0 , rsum=0;
    for(int i=mid ;i>=lefts;i--)
    {
        lsum+=sets[i];
        lmax=max(lsum,lmax);
    }
    for(int i=mid+1 ;i<=rights;i++)
    {
        rsum+=sets[i];
        rmax=max(rsum,rmax);
    }
    return max(max(lmax,rmax),lmax+rmax);
}

int dcmax(int lefts,int rights)
{
    if(lefts==rights) return sets[lefts];
    else
    {
        int mid=(lefts+rights)/2;
        int lmax=dcmax(lefts,mid);
        int rmax=dcmax(mid+1,rights);
        int cmax=dcmax(lefts,mid,rights);
        return max(max(lmax,rmax),cmax);
    }
}


int main()
{
    int N ;
    while(cin >> N && N)
    {
        int temp;
        for(int i=0;i<N;i++)
        {
            cin >> temp;
            sets[i]=temp;
        }
        int money=dcmax(0,N-1);
        if(money>0) cout << "The maximum winning streak is " << money << "." << endl;
        else cout << "Losing streak." << endl;
    }
}
