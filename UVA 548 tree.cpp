#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
const int maxs=10010;
int Left[maxs]={0} , Right[maxs]={0};

int  best_sum , ans;
vector<int> inorder , postorder;
int build_tree(int s,int e);
void dfs(int,int);

int main()
{
    string str1,str2;
    while(getline(cin,str1))
    {
        for(int i=0;i<maxs;i++)
        {
            Left[i]=0; Right[i]=0;
        }
        getline(cin,str2);
        inorder.clear();    postorder.clear();
        stringstream ss;
        int temp ;
        ss << str1; while(ss >> temp) inorder.push_back(temp);
        ss.clear();
        ss << str2; while(ss >> temp) postorder.push_back(temp);
        int root=build_tree(0,inorder.size());
        int sum=0;
        best_sum=99999999; ans=99999;
        dfs(root,sum);
        cout << ans << endl;
    }

}
int build_tree(int s,int e)
{
    if(postorder.empty()) return 0;
    int i;
    for(i=s;i<e;i++)
        if(inorder[i]==postorder.back()) break;
    if(i>=e) return 0; ///NULL;

    int root=postorder.back(); postorder.pop_back();
    Right[root]=build_tree(i+1,e); /// 因為給的是中序以及後序，所以必須先遞迴建立右子樹，才能建立左子樹。
    Left[root]=build_tree(s,i);
    return root;
}

void dfs(int root,int sum)  ///preorder
{
    sum+=root;
    if(!Left[root]&&!Right[root])
    {
        if(sum<best_sum||((sum==best_sum)&&(ans<root)))
        {
            ans=root; best_sum=sum; return;
        }
    }
    if(Left[root])dfs(Left[root],sum);
    if(Right[root])dfs(Right[root],sum);
    return ;
}
