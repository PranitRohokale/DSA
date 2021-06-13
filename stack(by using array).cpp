#include<iostream>
using namespace std;
#define max 15
class Stack
{
private:
    int top;
    int capacity;
    int *Array;
public:
    Stack(int capacity):top(-1)
    {
        this->capacity=capacity;
        Array=new int[capacity];
    }
    void push(int val);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void display();
    void reverseStack();
    ~Stack()
    {
        while(!isEmpty())
            pop();
    }
};

void Stack::reverseStack()
{
    if(top<=0)
        return;

    int topv=peek();
    pop();

    reverseStack();

    Stack s(max);
    while(!isEmpty())
    {
        s.push(peek());
        pop();
    }
    push(topv);
    while(!s.isEmpty())
    {
        push(s.peek());
        s.pop();
    }
}

bool Stack::isFull()
{
    if(capacity-1==top)
        return true;
    return false;
}
bool Stack::isEmpty(){
    if(top==-1)
        return true;
    return false;
}
void Stack::push(int val)
{
    if(isFull())
        cout<<"\noverflow...";
    else{
        Array[++top]=val;
    }
}
void Stack::display()
{
    int temp=top;
    while(temp!=-1)
        cout<<"\n\t\t"<<Array[temp--];
}
void Stack::pop()
{
    if(isEmpty())
        cout<<"\nunderflow...";
    else
        top--;
}
int Stack::peek()
{
    if(isEmpty())
        return -1;
    else
        return Array[top];
}
int main()
{
    int p;
    cout<<"Enter the size(integer) of Stack : ";
    cin>>p;
    Stack obj(p);
    int data,choice;
    do
    {
        cout<<"\n1. push";
        cout<<"\n2. pop";
        cout<<"\n3. peek";
        cout<<"\n4. isEmpty";
        cout<<"\n5. isFull";
        cout<<"\n6. display stack";
        cout<<"\n7. clear screen";
        cout<<"\n8. revevrseStack";
        cout<<"\n0. exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nenter the value : ";
            cin>>data;
            obj.push(data);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
        	{
            int i=obj.peek();
            if(i==-1)
			cout<<"\nEmpty stack.......";
            else
                cout<<"\n the topmost item : "<<i;
            break;
        }
        case 4:
            obj.isEmpty();
            break;
        case 5:
            obj.isFull();
            break;
        case 6:
            cout<<"\nSTACK IS --> ";
            obj.display();
            break;
        case 7:
            system("cls");
            break;
        case 8:
            obj.reverseStack();
            break;
        case 0:
            exit(1);
            break;
        default:
            cout<<"\ninvalid choice....";
        }
    }while(choice!=0);
}
