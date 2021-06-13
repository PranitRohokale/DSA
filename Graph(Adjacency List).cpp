#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
struct node
{
    int v_no;
    struct node *next;
};
class Graph
{
private:
    int total_vertex;
    struct node **G;
public:
    Graph(int v):total_vertex(v)
    {
        G=new struct node*[v];
        for (int i=0;i<v;i++)
                G[i]=NULL;
    }
    void insert(int ,int);
    void displaygraph();
    void Depth_First_Search(int);
    void Breath_first_search(int);
};
void Graph::insert(int p,int q)
{
    struct node *temp,*m;
    temp=new node;
    temp->v_no=q;
    temp->next=NULL;
    if(G[p-1]==NULL)
        G[p-1]=temp;
    else
    {
        m=G[p-1];
        while(m->next!=NULL)
           m=m->next;
        m->next=temp;
    }
}
void Graph::displaygraph()
{
    for(int i=0;i<total_vertex;i++)
    {
        cout<<"\n"<<i+1;
        struct node *m;
        m=G[i];
        while(m)
        {
            cout<<"--> "<<m->v_no;
            m=m->next;
        }
    }
}
void Graph::Depth_First_Search(int n)
{
    stack<int>s;
    vector<bool>v(total_vertex,false);
    if(G[n-1]==NULL)
        return;
    struct node *m;
    s.push(n);
    cout<<"\nDepth_First_Search : ";
    while(!s.empty())
    {
        int p=s.top();s.pop();
        v[p-1]=true;
        cout<<p<<" ";
        m=G[p-1];
        while(m)
        {
            if(v[m->v_no-1]==false){  //if the vertex is already visited then it not insert in stack
                s.push(m->v_no);
                v[m->v_no]=true;
            }
            m=m->next;
        }
    }
}
void Graph::Breath_first_search(int n)
{
    struct node *m;
    int p;
    queue<int>q;
    vector<bool>v(total_vertex,false);
    q.push(n);
    cout<<"\nBreath_first_search : ";
    while(!q.empty())
    {
        p=q.front();q.pop();
        if(!v[p-1])cout<<" "<<p;
        v[p-1]=true;
        m=G[p-1];
        while(m)
        {
            if(v[m->v_no-1]==false)
                q.push(m->v_no);
            m=m->next;
        }
    }
}
int main()
{
    Graph G(6);
    G.insert(1,2);
    G.insert(1,3);
    G.insert(2,4);
    G.insert(3,5);
    G.insert(3,6);
    G.insert(4,5);
    G.insert(6,4);
    G.Depth_First_Search(1);
    G.Breath_first_search(1);
    return 0;
}
