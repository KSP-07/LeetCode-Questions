class Solution {
public:
    int singleNumber(vector<int>& nums) {
           int res= 0;
        for(int i=0;i<32;i++){
            int countones = 0;
            for(int j=0;j<nums.size();j++){
                countones =countones+ ((nums[j]>>i)&1);
            }
            countones = countones % 3;
            res = (res | countones << i);
        }
        return res;
    }
};