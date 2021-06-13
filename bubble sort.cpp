#include<iostream>
using namespace std;
void bubblesort(int arr[],int start,int end)
{
    int p=end;
    while(p)
    {
        for(int i=0;i<p;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        p--;
    }
}
int main()
{
    int arr[]={2,5,1,6,9,0,11,71,44,-99,99};
    bubblesort(arr,0,(sizeof(arr)/sizeof(arr[0]))-1);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        cout<<arr[i]<<" ";
    return 0;
}

