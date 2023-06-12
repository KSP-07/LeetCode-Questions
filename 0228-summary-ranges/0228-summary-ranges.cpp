class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(-INT_MAX);
        
        int n = nums.size();
        
        vector<string> ans;
        for(int i = 0 , j = 1; j<n ; j++){
            if(nums[j]-1 != nums[j-1]  ){
                string a = to_string(nums[i]);
                string b = to_string(nums[j-1] );
                string temp = a + "->" + b;
                if((j-1) == i){
                    ans.push_back(a);                    
                }
                else{
                    // cout<<"test\n";
                    ans.push_back(temp);
                }
                i=j;
            }
            
        }
        return ans;
    }
};