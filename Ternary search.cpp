
#include<iostream>
#include<vector>

using namespace std;

int ternarysearch(int arr[],int left,int right,int key)
{
    if(left<=right)
    {
        int midfirst = left + (right - left)/3;
        int midsecond = midfirst + (right - left)/3;

        if(arr[midfirst] == key)
            return midfirst;
        if(arr[midsecond] == key)
            return midsecond;

        if(arr[midfirst] > key)
            return ternarysearch(arr,left,midfirst-1,key);
        else if(arr[midsecond] < key)
            return ternarysearch(arr,midsecond+1,right,key);
        else
            return ternarysearch(arr,midfirst+1,midsecond+1,key);

    }
    return -1;
}

int main(){

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
        x = ternarysearch(arr,0,n-1,3);
    if(  x == -1)
        cout<<"givenelement is not valid  in array";
    else
        cout<<x;

return 0;
}
