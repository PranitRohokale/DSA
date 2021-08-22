#include<iostream>
using namespace std;
/*struct array
{
    int capacity;
    int lastindex;
    int *arr;
};
struct array* heap(int cap)
{
    struct array *ptr=new array;
    ptr->capacity=cap;
    ptr->lastindex=-1;
    ptr->arr=new int[cap];
    return ptr;
};
void heapify(struct array *ptr)
{
    int index=ptr->lastindex;
    int parentindex=(index-1)/2;
    int temp=ptr->arr[index];
    while(index!=0 && ptr->arr[parentindex]<temp)
    {
        ptr->arr[index]=ptr->arr[parentindex];
        index=parentindex;
        int parentindex=(index-1)/2;
    }
    ptr->arr[index]=temp;
}
void insert(struct array *ptr,int val)
{
    if(ptr->capacity=ptr->lastindex+1)
        return;
    else
    {
        ptr->lastindex+=1;
        ptr->arr[ptr->lastindex]=val;
        heapify(ptr);
    }
}
int main()
{
    int arr[]={15,20,21,5,2,1,10};
    struct array *ptr=heap(5);
    for(int i=0;i<5;i++)
        insert(ptr,arr[i]);
    for(int i=0;i<5;i++)
        cout<<" "<<ptr->arr[i];
    return 0;
}*/
void insert(int arr[],int lastindex,int value)
{
    int index=++lastindex;
    int parentindex;
    while(index>0)
    {
        parentindex=(index-1)/2;
        if(arr[parentindex]>=value)
        {
            arr[index]=value;
            return;
        }
        arr[index]=arr[parentindex];
        index=parentindex;
    }
    arr[index]=value;
}
void delheap(int arr[],int lastindex,int *ptr)
{
    *ptr=arr[0];
    int lchild=1,rchild=2,index=0;
    int lastvalue=arr[lastindex];
    lastindex--;
    while(lastindex<=rchild)
    {
        if(lastvalue>=arr[lchild] && lastvalue>=arr[rchild])
        {
            arr[index]=lastvalue;
            return;
        }
        if(lastvalue>=arr[lchild])
        {
            arr[index]=arr[lchild];
            index=lchild;
        }
        if(lastvalue>=arr[rchild])
        {
            arr[index]=arr[rchild];
            index=rchild;
        }
        lchild=2*index+1;
        rchild=2*index+2;
    }
    if(lastindex=lchild && lastvalue<=arr[lchild])
    {
        arr[index]=lastvalue;
        index=lchild;
    }
    arr[index]=lastvalue;
}
void heap_sort(int arr[],int start,int end)
{
    for (int i=0;i<end-1;i++)
        insert(arr,i,arr[1+i]);
    int lastvalue;
    while(end>0)
    {
        delheap(arr,end-1,&lastvalue);
        arr[end-1]=lastvalue;
        end--;
    }
}
int main()
{
    int arr[]={2,5,1,-1,5,8,0,11,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr,0,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
