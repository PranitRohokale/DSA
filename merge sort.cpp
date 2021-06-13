#include<iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub)
{
    int i=0,j=0,k=lb;
    int L[mid-lb+1],R[ub-mid];
    for(int p=0;p<=mid-lb;p++)
        L[p]=arr[p+lb];
    for(int p=0;p<ub-mid;p++)
        R[p]=arr[mid+p+1];

    while(i<=mid-lb && j<ub-mid)
    {
        if(L[i]<R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<=mid-lb)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<ub-mid)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
    int arr[]={2,5,1,-1,5,8,0,11,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

