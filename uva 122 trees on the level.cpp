#include<iostream>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Node
{
public:
    Node(){value=-1; left=NULL; right=NULL;}
    int value;
    Node* left ;
    Node* right;
};

class Btree
{
public:
    Btree();
    void addNode(int,string);
    void bfs();
    void cleared(Node*);
    Node *ptr, *head;
private:
    bool check;
};

Node* newnode()
{
    return new Node;
}

int main()
{
    Btree b;
    string str;
    while(cin >> str )
    {
        if(str=="()")
        {
            b.bfs();
            Node* t=b.head;
            b.cleared(t);
            b.head=newnode();
        }
        else
        {
            int temp = str.find(',');
            string n="";
            for(int i=1;i<temp;i++)
                n+=str[i];
            string lr="";
            for(int i=temp+1;i<str.size()-1;i++)
                lr+=str[i];
            stringstream ss(n);
            int num; ss >> num;
            b.addNode(num,lr);
        }
    }
    return 0;
}
void Btree::bfs() ///利用queue進行BFS走訪
{
    queue<Node*> que;
    que.push(head);
    queue<int> arr;
    while(!que.empty())
    {
        ptr=que.front();
        if(ptr==NULL)
        {
            que.pop();
            continue;
        }
        if(ptr->value==-1)
        {
            check=0;
            break;
        }
        arr.push(ptr->value);
        que.pop();
        que.push(ptr->left); que.push(ptr->right);
    }
    if(check)
    {
        while(!arr.empty())
        {
            cout << arr.front();
            arr.pop();
            if(!arr.empty())
                cout << ' ' ;
        }
    }
    else
        cout << "not complete";
    cout << endl;
    return;
}

void Btree::cleared(Node* h)
{
    if(h==NULL) return;
    cleared(h->left);
    cleared(h->right);
    h->left=NULL;
    h->right=NULL;
    delete h;
    check=1;
    return ;
}

void Btree::addNode(int num,string str)
{
    ptr=head;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='L')
         {
            if(ptr->left==NULL)
                ptr->left=newnode();
            ptr=ptr->left;
        }
        else
        {
            if(ptr->right==NULL)
                ptr->right=newnode();
            ptr=ptr->right;
        }
    }
    if(ptr->value!=-1)  ///如果該節點已有編號 則視為not complete.
        check=0;
    ptr->value=num;
    ptr=head;
}

Btree::Btree()
{
    check=1;
    ptr=head;
    head=newnode();
}
