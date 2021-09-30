#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    int t2=t;
    int arr[100],dump[100][100],sum[100],j,k,max,final,finalk[100],l=0,val[100],final_arr[100][100];
    while(t-->0){
            cin>>n;
            j=k=max=0;

            for(int i=0;i<n;i++){

                cin>>arr[i];
                if(arr[i]>0){
                    dump[j][k]=arr[i];
                    sum[j]=sum[j]+arr[i];
                    k++;
                    if(sum[j]>=max){
                        final=j;
                        max=sum[j];
                        finalk[j]=k;//size of array



                    }
                }else{
                    if(k!=0){
                    j++;
                    k=0;
                    sum[j]=0;}
                }

            }
            for(int i=0;i<finalk[final];i++){
                     final_arr[l][i]=dump[final][i];
                     val[l]=i;

}

l++;





    }
t=0;
while(t<l){
    for(int i=0;i<=val[t];i++){
        printf("%d ",final_arr[t][i]);
    }
    printf("\n");
    t++;
}



return 0;
}
