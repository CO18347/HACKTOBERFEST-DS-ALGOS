#include <iostream>
using namespace std;

int* insert_at_mid(int n, int a[],int x, int mid)
{
    n++;
    for (int i = n; i >= mid; i--)
        a[i] = a[i - 1];
    a[mid] = x;

    return a;
}
int main()
{
    int a[50];
    int x, mid, n;
    cout<<"Enter the no. of elements in array: ";
    cin>>n;
    cout<<"Enter array: ";
    for (int i = 0; i < n; i++)
        cin>>a[i];
    for (int j = 0; j < n; j++)
        cout << a[j] << " ";
    cout << endl;

    cout<<"Enter no. to be added in middle: ";
    cin>>x;
    mid = n/2;
    insert_at_mid(n, a, x, mid);
    for (int k = 0; k < n + 1; k++)
        cout << a[k] << " ";
    cout << endl;
}
