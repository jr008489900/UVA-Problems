#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;
const int maxs=1000;
int sum[maxs];

void initial()
{
    fill(sum,sum+maxs,0);
}

void read(int n)
{
    int root;   cin >> root ;
    if(root==-1) return ;
    sum[n]+=root;
    read(n-1);
    read(n+1);
    return ;
}

int main()
{
    bool check;
    int cnt=0;
    //ofstream oo("123.txt");
    ostream& fout(cout);
    while(1)
    {
        check=1;
        initial();
        read(500);
        vector<int> arr;
        for(int i=0;i<maxs;i++)
            if(sum[i]>0)  arr.push_back(sum[i]);
        if(arr.empty()) break;
        else
        {
            //if(cnt) fout << endl;
            fout << "Case " << ++cnt << ":" << endl;
            for(int i=0;i<arr.size();i++)
            {
                fout << arr[i];
                if(i!=arr.size()-1) fout << ' ';
            }
            fout << endl << endl;
        }
    }
    return 0;
}
