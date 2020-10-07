// time complexity in worst case o(n^2)
#include<iostream>
using namespace std;
int main()
{
    int number;
    cout<<"enter the number of element in the array";
    cin>>number;
    int arr[number];
    for(int i=0;i<number;i++)
    {
        cin>>arr[i];
    }
    int i,key,j;
    for(i=0;i<number;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    cout<<"array is sorted using insertion sort";
    for(i=0;i<number;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}