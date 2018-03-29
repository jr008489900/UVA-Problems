#include<iostream>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull num;
    while(cin >> num && num)
    {
        int cnt=0;
        for(int i=9;i>=0;i--)
        {
            if((num-i)%9==0)
            {
                if(cnt) cout << " ";
                cout << (num-i)/9*10+i ;
                cnt=1;
            }
        }
        cout << endl;
    }
}
