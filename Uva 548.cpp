#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
class Node
{
public:
    Node(){value=-1; left=NULL; right=NULL;}
    Node *left, *right;
    int value;
};

Node* newNode() {return new Node;}

class Btree
{
public:
    Btree(){}
    ~Btree();
    Node* buildtree(vector<int>,int start,int ends,vector<int>& post);///建樹
    void dfs(Node*,int); ///深度走訪
    Node *head; ///root
private:
    void del(Node*); ///釋放空間
};

int ans,best_sum;

int main()
{
    ///ofstream oo; oo.open("123.txt");
    string str1 , str2;
    while(getline(cin,str1))
    {
        getline(cin,str2);
        vector<int> inorder , postorder;
        stringstream ss; int temp;
        ss << str1;
        while(ss>>temp) { inorder.push_back(temp);}
        ss.clear();
        ss << str2;
        while(ss>>temp) { postorder.push_back(temp);}
        Btree b;
        b.head=b.buildtree(inorder,0,inorder.size(),postorder);
        ans=999999; best_sum=10000000;
        int sum=0;
        b.dfs(b.head,sum);
        cout << ans << endl;
    }
}
void Btree::dfs(Node* root,int sum)     ///找尋該路徑權重最小的路徑後 輸出該路徑的葉子權重即可 如果路徑權重相同 應尋找葉子權重最低的
{
    if(root==NULL) return;
    sum+=root->value;
    if(root->left==NULL&&root->right==NULL)
    {
        if((sum<best_sum) || (sum==best_sum&&ans<root->value)) {ans=root->value; best_sum=sum;}
    }
    //cout << root->value << " ";
    dfs(root->left,sum);
    //cout << root->value << ' ';
    dfs(root->right,sum);
    return ;
}

Btree::~Btree()
{
    del(head);
}

void Btree::del(Node* root)
{
    if(root==NULL) return ;
    del(root->left);
    del(root->right);
    root->left=NULL;
    root->right=NULL;
    delete root;
}

Node* Btree::buildtree(vector<int> inorder,int s,int e,vector<int>& post) ///藉由中序以及後序建樹
{
    if(post.empty())
        return  NULL;
    int i;
    for(i=s;i<e;i++)
        if(inorder[i]==post.back()) break;
    if(i>=e) return NULL;
    Node* root=newNode();
    root->value=post.back();    post.pop_back();
    root->right=buildtree(inorder,i+1,e,post);
    root->left=buildtree(inorder,s,i,post);
    return root;
}
