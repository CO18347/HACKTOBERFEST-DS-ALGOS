#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
       if(nums.size()<4)
           return {};

      int i=0,j,p,q,rem_sum=0,n=nums.size(),k,k1;
        long su=0;sort(nums.begin(),nums.end());vector<vector<int>>v;
        if((nums[0]+nums[1]+nums[2]+nums[3]>target) || (target>(nums[n-1]+nums[n-2]+nums[n-3]+nums[n-4])))
            return {};
        while(i<=n-4)
        {
            j=i+1;
            while(j<=n-3)
            {
                su=nums[i]+nums[j];
                rem_sum=target-su;p=j+1;q=nums.size()-1;
                while(p<q)
                {
                    if(nums[p]+nums[q]==rem_sum)
                    {
                        k=p;k1=q;
                        v.push_back({nums[i],nums[j],nums[p],nums[q]});p++;q--;
                         while(p<q && nums[k]==nums[p])
                        {
                            p++;
                        }
                        while(p<q && nums[k1]==nums[q])
                        {
                            q--;
                        }

                    }
                    else if(nums[p]+nums[q] < rem_sum)
                    {
                        k=p; p++;
                        while(p<q && nums[k]==nums[p])
                        {
                            p++;
                        }
                    }
                    else{
                        k1=q;q--;
                        while(p<q && nums[k1]==nums[q])
                        {
                            q--;
                        }
                }
                }
                k=j;j++;
                while(j<=n-3 && nums[k]==nums[j])
                    j++;
            }
            k=i;i++;
                while(i<=n-4 && nums[k]==nums[i])
                    i++;
        }
        return v;
    }
int main()
    {
        string s;
        cout<<"Size of array :   ";int  n;cin>>n;
        cout<<"\nEnter the elements: ";
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        cout<<"\nEnter the target : ";int target;cin>>target;
        vector<vector<int>>ans=fourSum(v,target);
        for(int i=0;i<ans.size();i++)
        {
            cout<<"["<<ans[i][0]<<", "<<ans[i][1]<<", "<<ans[i][2]<<", "<<ans[i][3]<<"]"<<endl;
        }
    }
