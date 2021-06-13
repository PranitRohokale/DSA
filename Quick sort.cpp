void swap(char *a1,char *a2)
{
    char temp=*a1;
    *a1=*a2;
    *a2=temp;
}
int quick(char arr[],int lb,int ub)
{
   int pivote=arr[lb],start=lb;
   while(lb<ub)
   {
       while(pivote>=arr[lb])
        lb++;
       while(pivote<arr[ub])
        ub--;
       if(lb<ub)
       {
           swap(arr[lb],arr[ub]);
       }
   }
   swap(arr[ub],arr[start]);
   return ub;
}
void quicksort(char arr[],int start,int end)
{
    if(start<end)
    {
        int p=quick(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}
