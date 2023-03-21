class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0 , numsub=0;
        for(auto num : nums){
            if(num==0) numsub++;
            else{
                numsub=0;
            }
            // cout<<numsub;
            ans+= numsub;
        }
        return ans;
    }
};