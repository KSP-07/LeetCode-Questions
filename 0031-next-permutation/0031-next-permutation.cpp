class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind=-1;
        for(int i=n-1 ;i>0;i--){
            if(nums[i] > nums[i-1]){
                ind = i-1;
                break;
            }
        }
        // cout<<ind<<endl;
        if(ind!=-1){
            for(int i=n-1;i>ind;i--){
                if(nums[i]>nums[ind]){
                    // cout<<nums[i]<<" "<<nums[ind]<<endl;
                    swap(nums[i] , nums[ind]);
                    break;
                }
            }
        }
        reverse(nums.begin() + ind+1 , nums.end() );
    }
};