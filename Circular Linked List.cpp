#include<iostream>
#include<conio.h>
using namespace std;
class node
{
public:
    node *next;
    int item;
    node()
    {
        next=NULL;
    }

};
class CircularList
{
private:
    node *last;
public:
    CircularList()
    {
        last=NULL;
    }
    void insertAtFirst(int value);
    void insertAtLast(int);
    void insertAfter(node*,int);
    void displayList();
    node* Search(int);
    void Delete(node*);
};
void CircularList::insertAtFirst(int value)
{
    node *temp=new node;
    temp->item=value;
    if(last==NULL)
        last=temp;
    else{
        temp->next=last->next;
    }
    last->next=temp;
}
void CircularList::insertAtLast(int value)
{
    node *temp=new node();
    temp->item=value;
    if(last==NULL)
        last=temp;
    else
        temp->next=last->next;
    last->next=temp;
    last=temp;//last=last->next
}
node* CircularList::Search(int value)
{
    if(last==NULL)
        return NULL;
    else if(last->item==value)
        return last;
    else{
            node *temp=last;
        while(temp->next!=last)
        {
            if(temp->item==value)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
}
void CircularList::insertAfter(node *address,int value )
{
    if(address==NULL)
        cout<<"\ngiven value not in list";
    else if(address==last)
    {
        node *temp=new node;
        temp->item=value;
        temp->next=address->next;
        address->next=temp;
        last=temp;
        cout<<"\nvalue "<<temp->item<<" inserted after "<<address->item;
    }
    else{
        node *temp=new node;
        temp->item=value;
        temp->next=address->next;
        address->next=temp;
        cout<<"\nvalue "<<temp->item<<" inserted after "<<address->item;
    }
}
void CircularList::displayList()
{
    if(last==NULL)
        cout<<"\nempty List";
    else{
        node *temp=last->next;
        while(temp!=last)
        {
            cout<<"-->"<<temp->item;
            temp=temp->next;
        }
        cout<<"-->"<<temp->item;
        cout<<"\n......done......";
    }
}
void CircularList::Delete(node *address)
{
    if(last==NULL)
        cout<<"\nEmpty List";
    else if(address==NULL)
         cout<<"\ngiven item not found in list";
    else if(address->next==address)
    {
        delete(address);
        last=NULL;
    }
    else if(address->next==last->next)
    {
        node *temp=address;
        while(temp->next!=address)
            temp=temp->next;
        temp->next=address->next;
        last=temp;
        delete(address);
    }
    else if(address==last->next)
    {
        last->next=address->next;
        delete(address);
    }
    else
    {
        node *temp=address;
        while(temp->next!=address)
            temp=temp->next;
        temp->next=address->next;
        delete(address);
    }
}
int driver()
{
    int choice;
    cout<<"\nwhich operation u want to do : ";
    cout<<"\n1. insert at first";
    cout<<"\n2. insert at last";
    cout<<"\n3. insert after";
    cout<<"\n4. delete";
    cout<<"\n5. display";
    cout<<"\n0. exit";
    cout<<"\nEnter ur choice : ";
    cin>>choice;
    return choice;

}
int main()
{
    int data,afterdata;
    CircularList obj;
    while(1)
    {
        switch(driver())
        {
        case 1:
            cout<<"\nEnter value : ";
            cin>>data;
            obj.insertAtFirst(data);
            break;
        case 2:
            cout<<"\nEnter value : ";
            cin>>data;
            obj.insertAtLast(data);
            break;
        case 3:
            cout<<"\nEnter after value : ";
            cin>>afterdata;
            cout<<"\nEnter value that to be inserting after "<<afterdata<<" : ";
            cin>>data;
            obj.insertAfter(obj.Search(afterdata),data);
            break;
        case 4:
            cout<<"\nEnter value that to be deleted : ";
            cin>>data;
            obj.Delete(obj.Search(data));
            break;
        case 5:
            obj.displayList();
            break;
        case 0:
            cout<<"\nthank you ....press anykey to exit.";
            getchar();
            exit(0);
            break;
        default:
            cout<<"\nInvalid choicee.....press any kay to continue....";
            break;

        }
    }
    return 0;
}
