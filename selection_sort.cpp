#include<iostream>
using namespace std;
void swap(int *a1,int *a2)
{
    int temp=*a1;
    *a1=*a2;
    *a2=temp;
}
int find_min(int arr[],int i,int j)
{
    int min_index=i;
    for(int p=i+1;p<j;p++)
        if(arr[p]<arr[min_index])
            min_index=p;
    return min_index;
}
void selection_sort(int arr[],int start,int end)
{
    for(int i=start;i<end-1;i++)
    {
        int index=find_min(arr,i,end);
        swap(&arr[i],&arr[index]);
    }
}
int main()
{
    int arr[]={2,5,1,6,9,0,11,-11,49,71,44,-99,99};
    selection_sort(arr,0,(sizeof(arr)/sizeof(arr[0])));
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        cout<<arr[i]<<" ";
    return 0;
}
