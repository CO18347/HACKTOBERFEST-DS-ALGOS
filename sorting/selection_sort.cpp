#include<iostream>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}
int main()
{
    int number;
    cin>>number;
    int arr[number];
    for(int i=0;i<number;i++)
    {
        cin>>arr[i];
    }
    int i,j,min_idx;
    for(i=0;i<number-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<number;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        swap(&arr[min_idx],&arr[i]);
    }
    for(i=0;i<number;i++)
    {
        cout<<arr[i]<<" ";
    }
}