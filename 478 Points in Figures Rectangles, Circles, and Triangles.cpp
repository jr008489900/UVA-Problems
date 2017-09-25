#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

struct Point
{
    double x , y;
};
struct Shape
{
    Shape(){point.clear();radius=0;}
    char type;
    vector<Point> point;
    double radius;
};
vector<Shape> arr;
Point temp;

bool read_shape()
{
    Shape s;
    cin >> s.type;
    if(s.type=='*') return 0;
    if(s.type=='r')
    {
        Point p;
        cin >> p.x >> p.y; s.point.push_back(p);
        cin >> p.x >> p.y; s.point.push_back(p);
    }
    else if(s.type=='t')
    {
        Point p;
        cin >> p.x >> p.y; s.point.push_back(p);
        cin >> p.x >> p.y; s.point.push_back(p);
        cin >> p.x >> p.y; s.point.push_back(p);
    }
    else
    {
        Point p;
        cin >> p.x >> p.y; s.point.push_back(p);
        cin >> s.radius;
    }
    arr.push_back(s);
    return 1;
}
bool read_point()
{
    cin >> temp.x >> temp.y;
    if(temp.x==9999.9&&temp.y==9999.9)    return 0;
    return 1;
}

double area(Point a,Point b,Point c)
{
    return (fabs((a.x*b.y+b.x*c.y+c.x*a.y)-(b.x*a.y+c.x*b.y+a.x*c.y)))/2;
}

void test(int cnt)
{
    bool check=0;
    for(int i=0;i<arr.size();i++)
    {
        bool s_check=0;
        if(arr[i].type=='r')
        {
            if(temp.x>arr[i].point[0].x&&temp.x<arr[i].point[1].x&&temp.y<arr[i].point[0].y&&temp.y>arr[i].point[1].y)
                {check=1; s_check=1;}
        }
        else if(arr[i].type=='t')
        {
            double t_area=area(arr[i].point[0],arr[i].point[1],arr[i].point[2]);
            double a1 = area(arr[i].point[0],arr[i].point[1],temp);
            double a2 = area(arr[i].point[0],arr[i].point[2],temp);
            double a3 = area(arr[i].point[1],arr[i].point[2],temp);
            if(fabs(t_area-a1-a2-a3)<0.00001) {s_check=1; check=1;}
        }
        else
        {
            double distance=sqrt((temp.x-arr[i].point[0].x)*(temp.x-arr[i].point[0].x)+(temp.y-arr[i].point[0].y)*(temp.y-arr[i].point[0].y));
            if(distance<arr[i].radius) {s_check=1; check=1;}
        }
        if(s_check)
        {
            printf("Point %d is contained in figure %d\n",cnt,i+1);
        }
    }
    if(!check)
        printf("Point %d is not contained in any figure\n",cnt);
}

int main()
{
    while(read_shape());
    int cnt=0;
    while(read_point())
    {
        test(++cnt);
    }
    return 0;
}
