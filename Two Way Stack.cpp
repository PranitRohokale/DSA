#include<iostream>
using namespace std;
template<class T>
class TwoWayStack
{
private:
    int top1,top2,capacity;
    T *array;
public:
    TwoWayStack(int cap):capacity(cap),top1(-1),top2(cap){
        array=new T[cap];
    }
    void push1(T item);
    void push2(T item);
    void pop1();
    void pop2();
    void displayStack();
    T peek1();
    T peek2();
    ~TwoWayStack()
    {

    }
};
template<class T>
void TwoWayStack<T>::push1(T item)
{
    if(top1+1==top2)
        cout<<"\noverflow.";
    else
        array[++top1]=item;
}
template<class T>
void TwoWayStack<T>::push2(T item)
{
    if(top1+1==top2)
        cout<<"\noverflow.";
    else
        array[--top1]=item;
}
template<class T>
void TwoWayStack<T>::pop1()
{
    if(top1==-1)
        cout<<"\nunderflow.....";
    else
        top1--;
}
template<class T>
void TwoWayStack<T>::pop2()
{
    if(top2==capacity)
        cout<<"\nunderflow.....";
    else
        top2++;
}
template<class T>
T TwoWayStack<T>::peek1()
{
    T temp;
    if(top1==-1)
        cout<<"empty....";
    else
        temp=array[top1--];
    return temp;
}
template<class T>
T TwoWayStack<T>::peek2()
{
    T temp;
    if(top2==capacity)
        cout<<"empty....";
    else
        temp=array[top2++];
    return temp;
}
template<class T>
void TwoWayStack<T>::displayStack()
{
    int front=-1,back=top2;
    cout<<"\n-->";
    if(top1!=-1)
    {
        while(front!=top1)
             cout<<" "<<array[++front];
    }
    else
        cout<<"Empty stack 1";
    cout<<"<--||-->";
    if(top2!=capacity)
    {
        while(front!=top1)
             cout<<" "<<array[back--];
    }
    else
        cout<<"Empty Stack 2";
    cout<<"<--";
}int main()
{
    TwoWayStack<int> obj(5);
    obj.push1(1);
    obj.push1(2);
    obj.push2(99);
    obj.displayStack();
    return 0;
}
