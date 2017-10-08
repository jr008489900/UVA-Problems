#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

struct data
{
    int a;
    int b;
    int tsum;
};
vector<int> arr;
vector<data> sum;

void initial()
{
    arr.clear();
    sum.clear();
}

bool cmp(data a,data b)
{
    return a.tsum<b.tsum;
}

bool read()
{
    int s; cin >>s;
    if(s==0) return 0;
    initial();
    while(s--)
    {
        int t; cin >> t;
        arr.push_back(t);
    }
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            data t; t.a=arr[i]; t.b=arr[j]; t.tsum=t.a+t.b;
            sum.push_back(t);
        }
    }
    sort(sum.begin(),sum.end(),cmp);
    sort(arr.begin(),arr.end());
    return 1;
}


bool found(int d,int c)
{
    int lower=0 , upper=sum.size(),mid;
    bool check=0;
    while(lower<upper)
    {
        mid=(lower+upper)/2;
        if(d-c==sum[mid].tsum&&d!=sum[mid].a&&d!=sum[mid].b&&c!=sum[mid].a&&c!=sum[mid].b) {check=1;break;}
        if(sum[mid].tsum>d-c) upper=mid;
        else lower=mid+1;
    }
    return check;
}


int ans()
{
    int answer=-999999999;
    for(int i=arr.size()-1;i>=0;i--)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(i==j) continue;
            if(found(arr[i],arr[j])&&arr[i]>answer){ answer=arr[i]; break;}
        }
    }
    return answer;
}

int main()
{
    //ofstream oo; oo.open("123.txt");
    while(read())
    {
        int d=ans();
        if(d!=-999999999)
            cout << d << endl;
        else
            cout << "no solution" << endl;
    }
}
