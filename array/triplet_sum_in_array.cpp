#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool find3numbers(int arr[], int N, int X){ //maybe it works for all test cases
       int curr_sum=0,count=0;
        
        for(int i=0;i<N;i++){
            int curr_sum=X-arr[i];
            if(curr_sum<0){
                continue;
            }
            int j=0,k=N-1,flag=0;
            while(j<N && k>0 & j!=k){
                if(j==i){
                    j++;
                    flag++;
                    
                }
                if(k==i){
                    k--;
                    flag++;
                }
                if(arr[i]+arr[j]>X || arr[j]>=curr_sum){
                    j++;
                    flag++;
                }
                if(arr[i]+arr[k]>X || arr[k]>=curr_sum){
                    k--;
                    flag++;
                }
                
                if(arr[j]+arr[k]==curr_sum){
                    return 1;
                    
                }else{
                  if(flag==0){
                       k--; 
                  }
                  
                }
               
                
            
                
        }
        
    }
    return 0;

    }


};
int main(){
 int t;
    cin>>t;
    while(t--){
        int n,sum;
        cin>>n>>sum;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        
        }
       
      Solution ob;
      cout<< ob.find3numbers(a,n,sum)<<endl;
        
    }
     return 0;
}