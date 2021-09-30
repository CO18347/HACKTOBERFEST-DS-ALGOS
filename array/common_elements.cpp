#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector <int> v;
            int i,j,count1,count2;
            
            for(int k=0;k<n1;k++){
                
                i=0,j=0,count1=0,count2=0;
                if(k>=1 && A[k]==A[k-1]){
                    continue;
                }
                while(i<n2){ //checking for the second array
                    if(B[i]>A[k]){
                        break;
                    }else{
                        if(A[k]==B[i]){
                            count1++;
                           // cout<<"A[k]: "<<A[k]<<count<<endl;
                        }
                        i++;
                    }
                    
                }
                
               
                while(j<n3){//checking for the third array
                    if(C[j]>A[k]){
                        break;
                    }else{
                        if(A[k]==C[j]){
                            if(count1>=1){
                                
                                count2++;
                                 //cout<<"A[k]: "<<A[k]<<count<<endl;

                            }
                        }
                        j++;
                    }
                    
                }
                if(count1>0 && count2>0){
                    v.push_back(A[k]);
                }
            }
           
            return v;
        }

};
int main(){
    int t; cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        int A[n1];
        int B[n2];
        int C[n3];
        for(int i=0;i<n1;i++) cin>>A[i];
        for(int i=0;i<n1;i++) cin>>B[i];
        for(int i=0;i<n1;i++) cin>>C[i];
        Solution ob;
        vector <int> res= ob.commonElements(A,B,C,n1,n2,n3);
        if(res.size()==-0){
            cout<<-1;
        }
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";

        }
        cout<<endl;


    }
    return 0;
}