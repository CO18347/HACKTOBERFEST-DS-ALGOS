#include<bits/stdc++.h>
using namespace std;// of unsorted arrays 
int unionarray(int arr[],int n,int arr1[], int m){ //execution time is high // hashmaps approach is same
 map<int , int > mp;
 for(int i=0;i<n;i++){
   mp.insert({arr[i],i});
 }
 for(int i=0;i<m;i++){
   mp.insert({arr1[i],i});
 }

 for(auto itr=mp.begin(); itr!= mp.end();itr++){
    cout<<itr->first<<" ";
 }  

 return 0;       
        

}
int intersectionarray(int arr[], int n, int arr1[], int m){

  /*map<int, int>mp;
 
  for(int i=0;i<n;i++){
    mp.insert({arr[i],i});
  }
  

  for(int i=0;i<m;i++){
    if(mp.find(arr1[i])!=mp.end()){
      cout<<arr1[i]<<" ";
    }

  }*/
  set<int> hs;
  set<int> hs1;
  for(int i=0;i<n;i++){
    hs.insert(arr[i]);
  }
  for(int i=0;i<m;i++){
    hs1.insert(arr1[i]);
  }
  for(auto itr=hs.begin();itr!=hs.end();itr++){
    if(hs1.find(*itr)!=hs.end()){
          cout<< *itr<<" ";
    }
  }

  
  return 0;

}
int union_not_distinct1(int arr[], int n, int arr1[],int m){
  int array[n+m];
  for(int i=0;i<n;i++){
    array[i]=arr[i];
  }
  int k=1;
  for(int i=0;i<m;i++){
    int flag=0;
    for(int j=0;j<n;j++){
           if(arr1[i]==arr[j]){
             flag++;
             break;
           }
    }
    if(flag==0){
    array[(n-1) + k]=arr1[i];
    k++;}

  }
  int size_array= sizeof(array)/sizeof(int);
  for(int i=0;i<size_array;i++ ){
    cout<<array[i]<<" ";
  }
  return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int m;
        cin>>m;
        int arr[n];
        int arr1[m];
        for(int i=0;i<n;i++){
          cin>>arr[i];
        }
        for(int i=0;i<m;i++){
          cin>>arr1[i];
        }
        //unionarray(arr,n, arr1, m);
        //cout<<endl;
        //intersectionarray(arr,n,arr1, m);
        union_not_distinct1(arr,n,arr1,m);
        cout<<endl;
    }
    return 0;
}