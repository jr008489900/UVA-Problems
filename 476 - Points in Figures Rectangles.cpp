#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
struct point
{
    double x , y;
};
vector<point> reclt , recrb;
point temp;
bool read_rec()
{
    char a ; cin >> a ;
    if(a=='*') return 0;
    cin >>  temp.x >> temp.y;
    reclt.push_back(temp);
    cin >>  temp.x >> temp.y;
    recrb.push_back(temp);
    return 1;
}
bool read_point()
{
    cin >> temp.x >>temp.y;
    if(temp.x==9999.9&&temp.y==9999.9)  return 0;
    return 1;
}
void p_test(int n)
{
    bool check=0;
    ofstream oo; oo.open("123.txt",ios::app);
    for(int i=0;i<recrb.size();i++)
    {
        if(temp.x>reclt[i].x &&temp.x<recrb[i].x && temp.y <reclt[i].y&& temp.y>recrb[i].y)
        {
            //oo << "Point " << n << " is contained in figure " << i+1 << endl;
            printf("Point %d is contained in figure %d\n",n,i+1);
            check=1;
        }
    }
    if(!check)
    {
        printf("Point %d is not contained in any figure\n",n);
        //oo << "Point " << n << " is not contained in any figure"  << endl;
    }
}
int main()
{
    while(read_rec());
    int cnt=0;
    while(read_point())
        p_test(++cnt);
    return 0;
}
