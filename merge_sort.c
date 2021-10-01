#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int arr[30],n,i;
    printf("Enter number of elements\n");
    scanf ("%d",&n);
    printf ("Enter the elements\n");
    for (i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    printf ("The array due to random function is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf ("sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf ("%d\n",arr[i]);
    }
}
merge_sort(int arr[],int p, int r)
{
    int q;
    if (p<r)
    {
        q=(p+r)/2;
        printf ("index value of middle elemennt(q) is %d\n",q);
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
merge(int arr[], int p, int q, int r)
{
    int i,j,k,n1,n2,L[30],R[30];
    n1=q-p;
    printf ("Value of n1 is %d\n",n1);
    n2=r-q-1;
    printf ("Value of n2 is %d\n",n2);
    L[n1]=1000000;
    R[n2]=1000000;
    for (i=0;i<=n1;i++)
    {
        L[i]=arr[p+i];
        printf ("Element stored in L[i] is %d\n",L[i]);
    }
    for(j=0;j<=n2;j++)
    {
        R[j]=arr[q+j+1];
        printf ("Element stored in R[j] is %d\n",R[j]);
    }
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<R[j])
        {
            printf ("Value of L[i] is %d\n",L[i]);
            printf ("value of i is %d\n",i);
            printf ("Value of R[j] is %d\n",R[j]);
            printf ("value of j is %d\n",j);
            arr[k]=L[i];
            i++;
            printf ("Value coming from L[i] is %d\n",arr[k]);
        }
        else
        {
            arr[k]=R[j];
            j++;
            printf ("value of j is %d\n",j);
            printf ("Value coming from R[j] is %d\n",arr[k]);
        }
        printf ("New array is %d\n",arr[k]);
    }
}
