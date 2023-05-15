// https://leetcode.com/problems/maximize-score-after-n-operations/discuss/3521639/Recursion-greaterBoolean-Array-greaterMask-oror-Easy-to-understand-oror-Simple-Code

class Solution {
public:
    
    bool isSet(int &num , int indx ){
        if(num & (1<<indx)) return true;
        return false;
    }
    void setBit(int &num ,int indx){
        num = num | (1<<indx);
    }
    int solve(vector<int>&nums,  unordered_map< int, int> &mp, int visited, int operation)
    {
        if (mp.count(visited)) return mp[visited]; //use stored result
            
        int maxScore = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (isSet(visited , i)) continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (isSet(visited , j)) continue;
                int newVisited = visited;
                setBit(newVisited , i);
                setBit(newVisited , j);
                //=====================================================================
                int currScore = operation * __gcd(nums[i], nums[j]);
                int nextMaxScore = solve(nums, mp, newVisited, operation + 1);
                int totalScore = currScore + nextMaxScore;
                maxScore = max(maxScore, totalScore);
                //======================================================================
                // visited[i] = false;
                // visited[j] = false;
                
                //unSet nhi kr rhee bits kuki newVisited bana ke usme store kraya thaa
            }
        }
        return mp[visited] = maxScore; //store the result
    }
    int maxScore(vector<int>& nums) 
    {
        int n = nums.size();
        // vector<bool>visited(n, false);
        int visited = 0;
        
        unordered_map<int, int> mp;        
        int ans = solve(nums, mp, visited, 1);
        return ans;
        
    }
};