class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        
        unordered_map<int,int> mp , mp2;
        vector<int> a1 , a2;
        for(auto i: nums1){
            if(!mp[i]) mp[i]++;
        }
        for(auto i: nums2){
            if(!mp2[i]) mp2[i]++;
            if(!mp[i]) {a2.push_back(i);mp[i]++;}
        }
        
        for(auto i :nums1){
            if(!mp2[i]) {a1.push_back(i);mp2[i]++;}
        }
        
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};