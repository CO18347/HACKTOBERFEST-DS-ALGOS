#include<bits/stdc++.h>

using namespace std;

int max_arr(int size_arr,int arr[],int t){
    int pos=0,max=0,count=0;
    for(int i=t;i<size_arr;i++){
            if(arr[i]>=max){
                    if(arr[i]==max){
                        count++;
                        pos=i;

                    }else {
                       max=arr[i];
                       pos=i;
                       if(count==0){
                          count++;
                       }else{
                           count=1;
                       }


                    }



            }

    }


    for(int i=0;i<count;i++){
      printf("%d ",max);}
      //printf("\n%d %d %d\n",pos,max,count);
      t=pos+1;

     if(t<size_arr){
      max_arr(size_arr,arr,t);}


}


int main(){
int t,n,*size;

scanf("%d",&t);
int *arr[t];
size=(int *)malloc(t*sizeof(int));

for(int i=0;i<t;i++){
    scanf("%d",&n);
    arr[i]=(int *)malloc(n*sizeof(int));
    size[i]=n;

    for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);


    }
}

for(int i=0;i<t;i++){
    int size_arr=size[i];
    int t=0;

    max_arr(size_arr,arr[i],t);
    printf("\n");



}
return 0;}

