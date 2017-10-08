#include<iostream>
#include<cmath>

using namespace std;

const double pi= 2*acos(0);
double a1,b1,t1,a2,b2,t2, t;
void process()
{
    t2=sqrt(t1*t1/a1/a1/a1*a2*a2*a2);/*�ھ��D�ةҵ����D�X�g��t2*/
    t=fmod(t,t2);
    t=t/t2;
    double c2area=a2*b2*pi*t;   /* ��P2��Ӷ�(�J�I)¶��Ҩ������n :��ꭱ�n* */
    double lower=0 , upper=2*pi , mid;
    double c = sqrt(a2*a2-b2*b2); /*��ꤤ�߹D�J�I�Z����sqrt(a^2-b^2);*/

    int cnt=500;
    while(cnt--)
    {
        mid=(lower+upper)/2.0;
        double carea=a2*b2*mid/2-b2*c*sin(mid)/2;
        if(c2area<carea)   upper=mid;
        else lower=mid;
    }
    cout << a2*cos(mid) << " " << b2*sin(mid) <<endl;
}

bool read()
{
    cin >> a1 >> b1 >> t1 >> a2 >> b2 >> t;
    if(!a1&&!b1&&!t1) return 0;
    return 1;
}
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    int cnt=0;
    while(read())
    {
        cout << "Solar System " <<  ++cnt <<  ": ";
        process();
    }
    return 0;
}
