#include<iostream>
using namespace std;
class Node
{
public:
    int item;
    Node *next;
    Node *prev;
};
class CircularDoublyList
{
private:
    Node *head;
public:
    CircularDoublyList():head(NULL){}
    void insertAtFirst(int);
    void insertAtLast(int);
    void insertAfter(Node*,int);
    void displayList();
    Node* Search(int);
};
Node* CircularDoublyList::Search(int val)
{
    if(head==NULL)
        return NULL;
    else
    {
        if(head->item==val)
            return head;
        Node *temp=head->next;
        while(temp!=head)
        {
            if(temp->item==val)
                return temp;
            temp=temp->next;
        }
       return NULL;
    }
}
void CircularDoublyList::inertAfter(Node *address,int val)
{
    if(head==NULL)
        cout<<"\nEmpty list.....";
    else if(address==NULL)
        cout<<"\nafter item is not founded in list....";
    else{
        Node *temp=new Node;
        temp->item=val;
        temp->next=address->next;
        temp->prev=address;
        address->next->prev=temp;
        address->next=temp;
    }
}
void CircularDoublyList::insertAtFirst(int value)
{
    Node *temp=new Node;
    temp->item=value;
    if(head==NULL)
    {
        head=temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else{
        temp->next=head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head-prev=temp;
        head=temp;
    }
}
void CircularDoublyList::insertAtLast(int value)
{
   Node *temp=new Node;
    temp->item=value;
    if(head==NULL)
    {
        head=temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else{
        temp->next=head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head-prev=temp;
    }

}
void CircularDoublyList::displayList()
{
    Node *temp=head;
    if(temp){
        cout<<"\n<-->"<<temp->item;
        temp=temp->next;
    }
    else
        cout<<"\nList is Empty....";
    while(temp!=head)
    {
        cout<<"<-->"<<temp->item;
        temp=temp->next;
    }
}
void CircularDoublyList::deletefirst()
{
    if(head==NULL)
        cout<<"\nempty list";
    else if(head->next==head)
    {
        Node *temp=head;
        head=NULL;
        delete(temp);
    }
    else{
        head->prev->next=head->next;
        head->next->prev=head->prev;
        Node *temp=head;
        head=head->next;
        delete(temp);
    }
}
int main()
{


}
