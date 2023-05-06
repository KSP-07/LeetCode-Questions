
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int count = 0;
        int n = nums.size(); 
        int start = 0;
        int end = n - 1;
        int mod = 1e9 + 7;

        vector<int> pows(n, 1);   // store the power

        for (int i = 1 ; i < n ; ++i){
            pows[i] = pows[i - 1] * 2 % mod;
        }

        while (start <= end) {
            if (nums[start] + nums[end] > target) {
                end--;
            } else {
                count = (count + pows[end - start]) % mod;
                start++; 
            }
        }
        return count;
    }
};