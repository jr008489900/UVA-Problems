#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<fstream>
using namespace std;

vector<double> arr;
double Water;

void read(int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp ;
        arr.push_back(temp);
    }
    cin >> Water;
    Water/=100;
    sort(arr.begin(),arr.end());
}

double ans()
{
    int state=0;
    double temp=Water;
    for(int i=1;i<arr.size();i++)
    {
        temp-=((arr[i]-arr[i-1])*i);
        if(temp<=0)
        {
            return arr[i]+double(temp/i);
        }
    }
    if(temp>=0) return arr[arr.size()-1]+double(temp/arr.size());
}

double percent()
{
    int state=0;
    double temp=Water;
    if(temp==0) return 0.00;
    for(int i=1;i<arr.size();i++)
    {
        temp-=((arr[i]-arr[i-1])*i);
        if(temp<=0)
        {
            return (double)i/arr.size()*100;
        }
    }
    return 100.00;

}

void initial()
{
    arr.clear();
}

int main()
{
    int x , y;
    int cnt=0;
    //ofstream oo; oo.open("123.txt");
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    while(cin >> x >> y &&(x || y))
    {
        initial();
        read(x*y);
        cout << "Region " << ++cnt << endl;
        cout << "Water level is " << ans() << " meters." << endl;
        cout << percent() << " percent of the region is under water." << endl;
        if(cnt) cout << endl;
    }
    return 0;
}
