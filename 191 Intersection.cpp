#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
using namespace std;

struct Point
{double x , y;};

struct Line
{Point a , b;};

struct Rec
{
    Line line;
};

double cross(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

bool isInRec(Rec r,Line li)
{
    return max(li.a.x,li.b.x) <= max(r.line.a.x, r.line.b.x)
        && min(li.a.x,li.b.x) >= min(r.line.a.x, r.line.b.x)
        && min(li.a.y,li.b.y) >= min(r.line.a.y, r.line.b.y)
        && max(li.a.y,li.b.y) <= max(r.line.a.y, r.line.b.y);
}

bool intersect(Line line,Point p) ///Are the line and the point intersect?
{
    return  p.x>=min(line.a.x,line.b.x)
            && p.x<=max(line.a.x,line.b.x)
            && p.y>=min(line.a.y,line.b.y)
            && p.y<= max(line.a.y,line.b.y);
}

bool intersect(Line line1,Line line2)   ///Are the line and the other line intersect?
{
    double a1=cross(line1.a,line1.b,line2.a);
    double a2=cross(line1.a,line1.b,line2.b);
    double a3=cross(line2.a,line2.b,line1.a);
    double a4=cross(line2.a,line2.b,line1.b);
    if(a1*a2<0&&a3*a4<0) return 1; ///

    ///端點共線情形
    if(a1==0&&intersect(line1,line2.a)) return 1;
    if(a2==0&&intersect(line1,line2.b)) return 1;
    if(a3==0&&intersect(line2,line1.a)) return 1;
    if(a4==0&&intersect(line2,line1.a)) return 1;
    return 0;
}

bool intersect(Rec r,Line li)
{
  ///Are the Rectangle and the line intersect.
    Line l1,l2,l3,l4;
    l1.a.x=min(r.line.a.x, r.line.b.x); l1.a.y=max(r.line.a.y, r.line.b.y);
    l1.b.x=max(r.line.a.x, r.line.b.x); l1.b.y= l1.a.y;

    l2.a.x=max(r.line.a.x, r.line.b.x); l2.a.y=max(r.line.a.y, r.line.b.y);
    l2.b.x=max(r.line.a.x, r.line.b.x); l2.b.y=min(r.line.a.y, r.line.b.y);

    l3.a.x=l1.a.x; l3.a.y=l2.b.y;
    l3.b.x=l2.b.x; l3.b.y=l2.b.y;

    l4.a=l1.a; l4.b=l3.a;
    return  ((((intersect(l1,li)
            ||intersect(l2,li))
            ||intersect(l3,li))
            ||intersect(l4,li))
            ||isInRec(r,li));
}


int main()
{
   int N;
    cin >> N;
    //ofstream oo; oo.open("123.txt");
    while(N--)
    {
        Line l1;
        Rec r;
        cin >> l1.a.x >> l1.a.y >> l1.b.x >> l1.b.y;
        cin >> r.line.a.x >> r.line.a.y >> r.line.b.x >> r.line.b.y;
        if(intersect(r,l1))
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
    return 0;
}
