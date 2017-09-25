#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
struct Point
{
    char type;
    double x , y;
};

vector<Point> arr;

bool read()
{
    int N; cin >> N;
    arr.clear();
    if(N==0) return 0;
    while(N--)
    {
        Point p;
        cin >> p.type >> p.x >> p.y;
        arr.push_back(p);
    }
    return 1;
}

double area(Point a,Point b,Point c)
{
    return fabs((a.x*b.y+b.x*c.y+c.x*a.y)-(b.x*a.y+c.x*b.y+a.x*c.y))/2;
}

double sum ;
vector<char> ans;

void process()
{
    for(int i=0;i<arr.size()-2;i++)
    {
        for(int j=i+1;j<arr.size()-1&&j!=i;j++)
        {
            for(int k=j+1;k<arr.size()&&k!=j&&k!=i;k++)
            {
                double t_area=area(arr[i],arr[j],arr[k]);
                bool check=1;
                for(int x=0;x<arr.size();x++)
                {
                    if(x==i||x==j||x==k) continue;
                    double a1=area(arr[x],arr[i],arr[j]);
                    double a2=area(arr[x],arr[i],arr[k]);
                    double a3=area(arr[x],arr[j],arr[k]);
                    if(fabs(t_area-(a1+a2+a3))<0.00001)
                    {
                        check=0; break;
                    }
                }
                if(check)
                {
                    if(t_area>sum)
                    {
                        sum=t_area;
                        ans.clear();
                        ans.push_back(arr[i].type); ans.push_back(arr[j].type); ans.push_back(arr[k].type);
                    }
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout << ans[i];
    cout << endl;
}

int main()
{
    while(read())
    {
        sum=0;
        process();
    }
}
