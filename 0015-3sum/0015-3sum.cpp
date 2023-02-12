class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // vector<vector<int>> ans;
        // for(int i=0;i<nums.size();i++){
        //     int temp = 0-nums[i];
        //     // mp[nums[i]]=i;
        //     vector<int> tans;
        //     for(int j=i+1;j<nums.size();j++){
        //         int x = temp-nums[j];
        //         if(mp[x]!=0) {
        //             tans.push_back(nums[i]);
        //             tans.push_back(nums[mp[x]]);
        //             tans.push_back(nums[j]);
        //             // mp[x]=0;
        //         }
        //         mp[nums[j]]=j;
        //     }
        //     if(tans.size()) ans.push_back(tans);            
        // }
        // return ans;
        
     
        //two pointer approach
        
        int n=nums.size();
        
        if(n < 3) return {};
        
        sort(nums.begin() , nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            int j=i+1 , k=n-1;
            if(i>0 && nums[i]==nums[i-1]) continue;  //checking duplicate for ith value
            while(j<k){
                if(nums[i]+nums[j] + nums[k] ==0){
                    ans.push_back({{nums[i]} , {nums[j]} , {nums[k]}});
                    
                    //dupli chck 1
                    while(j<k && nums[j]==nums[j+1]) j++;
                    
                    //dupli chck 2
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++,k--;
                    
                }
                else if(nums[i]+nums[j] + nums[k] < 0) j++;
                else k--;
            }
        }
        return ans;
    }
};