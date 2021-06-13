#include<iostream>
#include<string>
using namespace std ;

class Queue
{
private:
    int capacity;
    int front,rear;
    string *array;
public:
    Queue(int cap):capacity(cap),front(-1),rear(-1)
    {
        array=new string[cap];
    }
    void enqueue(string value);
    string dequeue();
    ~Queue()
    {
        while(front!=-1)
            dequeue();
    }
};
void Queue::enqueue(string value)
{
    if(front==(rear+1)%capacity)
        cout<<"\noverflow.....";
    else if(rear==-1 && front==-1)
    {
        front++;
        array[++rear]=value;
    }
    else if(rear==capacity-1)
    {
        rear=(rear+1)%capacity;
        array[rear]=value;
    }
    else
        array[++rear]=value;
}
string Queue::dequeue()
{
    string temp;
    if(rear==-1 && front==-1)
        cout<<"\nunderflow....";
    else if(front==rear)
    {
        temp=array[front];
        front=-1;
        rear=-1;
    }
    else if(front==capacity-1)
    {
        temp=array[front];
        front=(front+1)%capacity;
    }
    else{
        temp=array[front];
        front++;
    }
    return temp;
}

int main()
{
    Queue obj(3);
    int n;
    obj.enqueue("\nSTOP->RED LIGHT ON...\n");
    obj.enqueue("\nWAIT->YELLOW LIGHT ON...\n");
    obj.enqueue("\nGO->GREEN LIGHT ON...\n");
    cout<<"Enter time interval between two colour signal for traffic control system : ";
    cin>>n;
   int i=3;
   while(i)
   {
        string temp=obj.dequeue();
        obj.enqueue(temp);
        for(int j=n;j>0;j--)
            cout<<temp<<" "<<j<<"sec are remaing...\n";
        i--;
   }
   return 0;

}

