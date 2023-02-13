class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n= arr.size();
        vector<int> ans;
        for(int i = 0  , j =n-1; i<j ; ){
            if(arr[i] + arr[j] < target){
                i++;
            }
            else if(arr[i] + arr[j] > target){
                j--;
            }
            else{
                ans.push_back( i+1 ) ;
                ans.push_back ( j+1 );
                i++;
                j--;
            }
        }
        return ans;
    }
};