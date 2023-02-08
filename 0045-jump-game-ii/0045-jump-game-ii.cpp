//RECURSIVE APPROACH
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         return helper(nums,0);
//     }
//     int helper(vector<int> &nums, int start){
//         if(start >= nums.size()-1) return 0;
        
//         int minjump=100005;
//         for(int i=start + 1 ; i<= start + nums[start] ; i++){
//             minjump= min(minjump , 1 + helper(nums,i));
//         }
//         return minjump;
//     }
// };


//TOP DOWN DP (MEMO)
// 2. Memoization of recursive solution but it may give TLE.

// class Solution {
// public:
 
//    long long int jump(vector<int> &nums , int curr, int dest,vector<int> &dp)
//     {       
//             if(curr==dest) return 0;
//             if(dp[curr]!=-1) return dp[curr];
//             //cout<<curr<<" ";
//             long long int tmp=INT_MAX;
     
//             for(int i=1;i<=nums[curr];i++)
//             {   if(i+curr>dest) break;
//                 tmp=min(tmp,1+jump(nums,curr+i,dest,dp));  
//             }
//          dp[curr]=tmp;
//          return tmp;  
//     }
    
//     int jump(vector<int>& nums) {
//          vector<int> dp(nums.size(),-1);
//          return jump(nums,0,nums.size()-1,dp);
//     }
// };


// 3. O(n) Solution (accepted)

// We run loop from 0 to size()-1 because we have to reach at last index, think just previous stage when we take jump and reach to last index (size()-1) the we have counted our jump previously and we reach to last index hence we end our journey.

class Solution {
public:
    int jump(vector<int>& nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }
        
        return answer;
    }
};