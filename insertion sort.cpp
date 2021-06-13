#include<iostream>
using namespace std;
void insertion_sort(int arr[],int lb,int ub)
{
    for(int i=lb+1;i<ub;i++)
    {
        int pivote=arr[i];
        
        int j=i-1;
        while(j>=0 && arr[j]>pivote)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=pivote;
    }
}
/* time complexivity
    1.best case=O(n)
    2.worst case=O(n^2)
    */
int main()
{
    int arr[]={2,5,1,-1,5,8,0,11,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,0,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
