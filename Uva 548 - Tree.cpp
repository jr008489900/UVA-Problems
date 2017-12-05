#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxs=10050;
vector<int> in,post;
int lnode[maxs] ,rnode[maxs];
int bestsum , ans;
int root;

void initial()
{
    in.clear(); post.clear();
    fill(lnode,lnode,0);
    fill(rnode,rnode,0);
    bestsum=999999999; ans=0;
    root=0;
}

bool read()
{
    initial();
    string str;
    getline(cin,str);
    if(cin.eof()) return 0;
    stringstream ss(str);
    int temp ;
    while(ss>>temp) in.push_back(temp);
    ss.str(""); ss.clear();
    getline(cin,str);
    ss << str;
    while(ss>>temp) post.push_back(temp);
    return 1;
}

int build(int l,int r) ///building a binary tree.
{
    if(l>=r) return 0;  ///如果該區段只剩一筆資料，必須把該NODE接至NULL。
    else
    {
        int subRoot=post.back(); post.pop_back();
        int i;
        for(i=l;i<r;i++)
            if(subRoot==in[i]) break;

        if(i>=r) return 0;
        rnode[subRoot]=build(i+1,r);
        lnode[subRoot]=build(l,i);
        return subRoot;
    }
}

void DFS(int node,int sum)
{
    sum+=node;
    if(lnode[node]) DFS(lnode[node],sum);
    if(rnode[node]) DFS(rnode[node],sum);
    if(!lnode[node]&&!rnode[node]&&sum<bestsum)    {ans=node;  bestsum=sum;}
    return ;
}

int main()
{
    while(read())
    {
        if(cin.eof()) break;
        root=build(0,post.size());
        DFS(root,0);
        cout << ans << endl;
    }
    return 0;
}
