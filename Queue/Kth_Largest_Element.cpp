#include<bits/stdc++.h>
using namespace std;
//time complexity=O(n logk)
    //space complexity=O(k),for priority queue size 
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;//create a max heap
        for(int i=0;i<a.size();i++)
        {
            if(k>=1)
            {
                pq.push(a[i]);k--;
            }
            else{
                if(pq.top()<a[i])
                {
                    pq.pop();
                    pq.push(a[i]);
                }
            }
        }
        return pq.top();
    }
    int main()
    {
        cout<<"Enter the size of array : ";int n;cin>>n;
        vector<int>v(n,0);
        cout<<"\nEnter the elements : ";
        for(int i=0;i<n;i++)
            cin>>v[i];
        cout<<"\nEnter value of k : ";int k;cin>>k;
        cout<<"\nThe kth largest element in the array is : ";
        cout<<findKthLargest(v,k)<<endl;
    }
