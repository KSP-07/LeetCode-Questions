class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(int i=0;i<=n;i++){
            if(!mp[i]) return i;
        }
        return -1;
    }
};