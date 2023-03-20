class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])]>=0){
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
            else{
                //means it was already marked -ve by someone so repeat caught
                return abs(nums[i]);
            }
        }
        return -1;
    }
};