#include<iostream>
using namespace std;
template<class T>
class node
{
public:
    T item;
    node *next;
    node *prev;
public:
    node(node *n=NULL,node *p=NULL):next(n),prev(p){}
};
template<class T>
class List
{
public:
    node<T> *head;
public:
    List()
    {
        head=NULL;
    }
    void insertAtLast(T data);
    void insertAtFirst(T data);
    void insertAfter(node<T>*,T data);
    void displayList();
    void displayReverseList(node<T> *);
    node<T>* Search(T value);
    bool isEmpty();
};
template<class T>
bool List<T>::isEmpty()
{
    if(head==NULL)
        return true;
    return false;
}
template<class T>
node<T>* List<T>::Search(T value)
{
    if(head==NULL)
        return NULL;
    else{
        node<T>* temp=head;
        while(temp->next!=NULL)
        {
            if(temp->item==value)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
}
template<class T>
void List<T>::displayReverseList(node<T> * temp)
{
    if(temp==NULL)
        return
    displayReverseList(temp->next);
    cout<<temp->item<<"<--";
}
template<class T>
void List<T>::displayList()
{
    if(head==NULL)
        cout<<"\nList is Empty";
    else{
        node<T> *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->item<<"-->";
            temp=temp->next;
        }
    }
}
template<class T>
void List<T>::insertAtLast(T data)
{
    node<T> *temp=new node<T>;
    temp->item=data;
    if(isEmpty())
        head=temp;
    else{
        node<T> *p=head;
        while(p->next)
            p=p->next;
        p->next=temp;
        temp->prev=p;
    }
    endl(cout);
    cout<<"insert at last ";
}
template<class T>
void List<T>::insertAtFirst(T data)
{
    node<T> *temp=new node<T>;
    temp->item=data;
    if(isEmpty())
        head=temp;
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    cout<<"\ninsert at first";
}
template<class T>
void List<T>::insertAfter(node<T> *addres,T data)
{
    if(head==NULL || addres==NULL)
        cout<<"\n After element is not in List.....";
    else{
        node<T> *temp=new node<T>;
        temp->item=data;
        temp->next=addres->next;
        temp->prev=addres;
        if(addres->next!=NULL)
            addres->next->prev=temp;
        addres->next=temp;
    }
}
int driver()
{
    int choice;
    cout<<"\n\nwhich operation u want to do : ";
    cout<<"\n1. insert at first";
    cout<<"\n2. insert at last";
    cout<<"\n3. insert after";
    //cout<<"\n4. delete";
    cout<<"\n5. display";
    cout<<"\n6. display reverse List";
    cout<<"\n0. exit";
    cout<<"\nEnter ur choice : ";
    cin>>choice;
    return choice;

}
template<class T>
T get_afterdata()
{
    T afterval;
    cout<<"\nEnter after value : ";
    cin>>afterval;
    return afterval;
}
template<class T>
T get_data()
{
    T val;
    cin>>val;
    return val;
}
int main()
{
    List<int> obj;
    while(1)
    {
        switch(driver())
        {
        case 1:
            cout<<"\nEnter value : ";
            obj.insertAtFirst(get_data<int>());
            break;
        case 2:
            cout<<"\nEnter value : ";
            obj.insertAtLast(get_data<int>());
            break;
        case 3:
            cout<<"\nEnter value that to be inserting  : ";
            obj.insertAfter(obj.Search(get_afterdata<int>()),get_data<int>());
            break;
        case 6:
            cout<<"\nThe reverse List is :\n\t ";
            obj.displayReverseList(obj.head);
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

