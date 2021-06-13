#include<bits/stdc++.h>
#include<iostream>
//#include "Queue.h"
//using namespace Queue;
using namespace std;
struct Node
{
    struct Node *left=NULL,*right=NULL;
    int item;
};
class BST
{
public:
    struct Node *root;
public:
    BST():root(NULL){}
    struct Node* insert(struct Node*,int val);
    void preorder(struct Node*);
    void inorder(struct Node*);
    void postorder(struct Node*);
    void levelOrderTravalsal();          //by using queue
    struct Node* deleteNode(struct Node*,int data);
    int inorderPredececcer(struct Node*);
    int maxLevelSum(Node *);
    Node* binaryTreeToBST (Node *root);
};
struct Node* BST::insert(struct Node *temp,int val)
{
    if(temp==NULL)
    {
        temp=new struct Node;
        temp->item=val;
        return temp;
    }
    else if(temp->item>val)
        temp->left=insert(temp->left,val);
    else if(temp->item<val)
        temp->right=insert(temp->right,val);
    else
        //duplicate element do nothing
    return temp;
}
int BST::inorderPredececcer(struct Node *temp)
{
    while(temp)
        temp=temp->right;
    return temp->item;
}
struct Node* BST::deleteNode(struct Node *temp,int data)
{
    struct Node *P;
    if(temp==NULL)
        return NULL;
    else{
        if(data<temp->item)
            temp->left=deleteNode(temp->left,data);
        else if(data> temp->item)
            temp->right=deleteNode(temp->right,data);
        else{
            if(temp->left==NULL && temp->right==NULL)
            {
                delete(temp);
                return NULL;
            }
            else if(temp->left==NULL)
            {
                struct Node *p=temp;
               // delete(p);
                return temp->right;
            }
            else if(temp->right==NULL)
            {
                struct Node *p=temp;
               // delete(p);
                return temp->left;
            }
            else{
                 temp->item=inorderPredececcer(temp->left);
                 temp->left=deleteNode(temp->left,temp->item);
            }
        }
    }
    return temp;
}
void BST::inorder(struct Node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout<<"\t"<<temp->item;
    inorder(temp->right);
}
void BST::postorder(struct Node *temp)
{
    if(temp==NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout<<"\t"<<temp->item;
}
void BST::preorder(struct Node *temp)
{
    if(temp==NULL)
        return;
            cout<<"\t"<<temp->item;
    postorder(temp->left);
    postorder(temp->right);
}/*
void BST::levelOrderTravalsal()
{
    if(root==NULL)
        return;
    else
    {
        Q p;
        p.enqueue(root);
        while(!p.isempty())
        {
            struct Node *temp=p.dequeue();
            cout<<" "<<temp->item;
            if(temp->left!=NULL)
                p.enqueue(temp->left);
            if(temp->right!=NULL)
                p.enqueue(temp->right);
        }
    }
}*/
void getvalue(Node *root,vector<int>&v)
{
    if(!root)return ;

    getvalue(root->left,v);
    v.push_back(root->item);
    getvalue(root->right,v);
}
void assignvalue(Node *root,vector<int>&v)
{
    if(root)
    {
        assignvalue(root->left,v);
        root->item=v.back();
        v.pop_back();
        assignvalue(root->right,v);
    }
}
Node* BST::binaryTreeToBST (Node *root)
{
    //Your code goes here
    vector<int>v;
    getvalue(root,v);
    sort(v.begin(),v.end());
    assignvalue(root,v);
    return root;
}
int BST::maxLevelSum(Node* root) {
    // Your code here
    int max=0;
    if(!root)return 0;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        int sum=0;
        while(count--)
        {
            Node *temp=q.front();
            q.pop();
            sum+=temp->item;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        if(sum>max)
            max=sum;
    }
    return max;
}
int driver()
{
    int choice;
    cout<<"\n BST OPERATIONS : ";
    cout<<"\n1. insert";
    cout<<"\n2. inorder";
    cout<<"\n3. postorder";
    cout<<"\n4. preorder";
    cout<<"\n5. delete value";
    cout<<"\n6. convert BST";
    cout<<"\n0. exit";
    cout<<"\n\enter your choice : ";
    cin>>choice;
    return choice;
}
int main()
{
    BST obj;
    int value;
    while(1)
    {
        switch(driver())
        {
        case 1:
            cout<<"\nEnter value : ";
            cin>>value;
            obj.root=obj.insert(obj.root,value);
            break;
        case 2:
            cout<<"\n inorder traversal-->";
            obj.inorder(obj.root);
            break;
        case 3:
            cout<<"\npostoeder traversal-->";
            obj.postorder(obj.root);
            break;
        case 4:
            cout<<"\npreorder traversal-->";
            cout<<obj.maxLevelSum(obj.root);
            //obj.preorder(obj.root);
            break;
        case 5:
            cout<<"\nenter the value that to be deleted : ";
            cin>>value;
            obj.root=obj.deleteNode(obj.root,value);
            break;
        case 6:
            cout<<"\n covet BST : ";
            obj.root=obj.binaryTreeToBST(obj.root);
            break;
        case 0:
            exit(1);
        default:
            cout<<"\n........invalid choice.......";
            break;
        }
    }
    return 1;
}
