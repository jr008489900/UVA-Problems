#include<iostream>
#include<fstream>
using namespace std;
bool isBalance(int& weight)
{
    int W1 , D1 , W2 , D2;
    bool wL=1 , wR=1;
    cin >> W1 >> D1 >> W2 >> D2;
    if(W1==0) wL=isBalance(W1);
    if(W2==0) wR=isBalance(W2);
     cout << W1 << " /// " << W2 << endl;
    weight= W1+W2;
    if(wL&&wR&&W1*D1==W2*D2) return 1;
    else return 0;
}

int main()
{
    //ofstream oo("123.txt");
    ostream& oout(cout);
    int N; cin >> N;
    while(N--)
    {
        int w=0;
        if(isBalance(w)) oout << "YES" << endl;
        else oout << "NO" << endl;
        if(N) oout << endl;
    }
    return 0;
}
