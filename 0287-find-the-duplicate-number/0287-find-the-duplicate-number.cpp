class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //inversion of elemenets approach
        /*
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        
        return duplicate;
        */
        
        //tortoise and hare approach for cycle detection
        int tortoise = nums[0];
        int hare = nums[0];
        
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(hare!=tortoise); 
        
        //now making hare start again at normal pace
        hare = nums[0];
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};