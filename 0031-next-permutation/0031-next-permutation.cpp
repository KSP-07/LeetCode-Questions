class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        //finding a breakpoint index , i.e if from right to left array is not increasing at some point
        int ind=-1;
        for(int i=n-1 ;i>0;i--){
            if(nums[i] > nums[i-1]){
                ind = i-1;
                break;
            }
        }
        // cout<<ind<<endl;
        //this means that we have found one point
        if(ind!=-1){
            //not traversing from back to find element just greater than on the ind element and then swap it
            for(int i=n-1;i>ind;i--){
                if(nums[i]>nums[ind]){
                    // cout<<nums[i]<<" "<<nums[ind]<<endl;
                    swap(nums[i] , nums[ind]);
                    break;
                }
            }
        }
        //now after the breakpoint reversing the array to make all thing in smallest order after breakpoint
        reverse(nums.begin() + ind+1 , nums.end() );
    }
};