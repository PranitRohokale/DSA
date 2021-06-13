#include<iostream>
#include<string>
#include "selection_sort.cpp"
using namespace std;
int binary_search(int arr[],int len,int x)
{
    int l=0,u=len,mid;
    while(l<=u)
    {
        mid=(l+u)/2;
        if(arr[mid]==x)
            return mid;
        else if(x<arr[mid])
            u=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int main()
{
    int element;
    int arr[]={2,5,8,4,99,44,22,6,0,-1,33};
    int len=(sizeof(arr)/sizeof(arr[0]));
    selection_sort(arr,0,len);
    cout<<"\nEnter element that you want search :";
    cin>>element;
    cout<<binary_search(arr,len-1,element);     //binary_search return the index of that item
    return 0;
}
