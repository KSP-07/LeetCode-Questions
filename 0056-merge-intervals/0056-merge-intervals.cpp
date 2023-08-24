class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1) return intervals;
        vector<vector<int>> ans;
        
        sort(intervals.begin() ,intervals.end());
        
        for(auto interval : intervals ){
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if(ans.empty() || ans.back()[1] < interval[0]){
                ans.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else{
                ans.back()[1] = max(ans.back()[1] , interval[1]);
            }
        }
        return ans;
        
    }
};