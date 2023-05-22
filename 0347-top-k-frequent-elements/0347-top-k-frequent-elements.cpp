class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> temp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto i:mp){
            temp.push_back({i.second , i.first});
        }
        sort(temp.begin() , temp.end() , greater<pair<int,int>>());
        
        vector<int> ans;
        int i= 0;
        while(i<k){
            ans.push_back(temp[i].second);
            i++;
        }
        return ans;
    }
};