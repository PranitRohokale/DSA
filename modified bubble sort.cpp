#include<iostream>
using namespace std;
void modified_bubblesort(int arr[],int start,int end)
{
    bool flag=true;
    while(end)
    {
        for(int i=0;i<end;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=false;
            }
        }
        if(flag)
            break;
        end--;
    }
}
int main()
{
    int arr[]={2,5,1,6,9,0,11,71,44,-99,99};
    modified_bubblesort(arr,0,(sizeof(arr)/sizeof(arr[0]))-1);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        cout<<arr[i]<<" ";
    return 0;
}


