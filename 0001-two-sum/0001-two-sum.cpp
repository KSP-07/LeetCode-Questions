class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> mp;
        vector<int>ans;   //to store and return ans array
        for(int i=0;i<nums.size();i++){
            //we are not storing absolute value as -ve value can form the sum
            int x=target-nums[i];       //we are storing diff of target and curr value , so that we can 
                                        //check that x is in map...x will be in map if that value was visited   
            if(mp.find(x)!=mp.end()){
                ans.push_back(mp[x]);    //if x is in map , then we first store index of x as it was visited first
                ans.push_back(i);  // curr value's index is stored afterwards as it is being visited later
            }
            mp[nums[i]]=i;   //with each traversal we store curr value with index in map
        }
        return ans;
        
        //same value will not be repeated as we form pair as soon as we found match and if same value appears lateron , it will be paired with the one index(cuur index)
    }
};