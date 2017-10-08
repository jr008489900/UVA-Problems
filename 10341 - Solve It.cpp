#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<fstream>
#include<vector>
using namespace std;
vector<int> arr;
double fun(double x)
{
    return arr[0]*exp(-x)+arr[1]*sin(x)+arr[2]*cos(x)+arr[3]*tan(x)+arr[4]*x*x+arr[5];
}

bool read()
{
    arr.clear();
    string str;
    stringstream ss;
    getline(cin,str);
    ss << str;
    int t;
    while(ss >> t) arr.push_back(t);
    if(cin.eof()) return 0;
    return 1;
}

double searchs(double lower,double upper,int cnt)
{
    double mid=(lower+upper)/2.0;
    if(!cnt)
    {
        if(fabs(fun(mid))>0.0000000001) return -1;
        else return mid;
    }
    if(fun(mid)>0) return searchs(mid,upper,cnt-1);
    else return searchs(lower,mid,cnt-1);
}
int main()
{
    /*ofstream oo ; oo.open("123.txt");
    oo.setf(ios::fixed);
    oo.setf(ios::showpoint);
    oo.precision(4);*/
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    while(read())
    {
        double ans=searchs(0.0,1.0,100);
        if(ans!=-1)
            cout << ans << endl;
        else
            cout << "No solution" << endl;
    }
}
