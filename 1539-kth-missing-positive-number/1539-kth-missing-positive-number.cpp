class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;
        
        int i=1 ,ans=0;
        while(k){
            if(mp[i]) i++;
            else{
                ans=i;
                i++;
                k--;
            }
        }
        return ans;
    }
};