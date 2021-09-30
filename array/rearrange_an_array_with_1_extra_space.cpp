#include<bits/stdc++.h>
using namespace std;
/*void arrangeBasic(long long arr[],int n){
         int temp[n];
         for(int i=0;i<n;i++){
             int x=arr[i];
             int y= arr[x];
             temp[i]=y;
             

         }
         for(int i=0;i<n;i++){
           arr[i]=temp[i];
         }
}*/
void arrange(long long arr[],int n){
    for(int i=0;i<n;i++){
        arr[i] +=(arr[arr[i]]%n)*n;
    }
    for(int i=0;i<n;i++){
        arr[i]/=n;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        
        long long A[n];
        
        for(int i=0;i<n;i++){
          cin>>A[i];
        }
        arrange(A,n);
        for(int i=0;i<n;i++){
          cout<<A[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}