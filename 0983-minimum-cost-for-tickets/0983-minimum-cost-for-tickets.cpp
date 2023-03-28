class Solution {
public:
//     int solve(int index , vector<int> &days , vector<int> &costs , int cnt){
//         if(index==days.size()) return 0;
//         // if(cnt>=days[index]) return solve(index+1 ,days , costs ,cnt-1);
//         if(cnt>= days[index]) return 0;
        
//         int cost =0;
//         int one = costs[0] + solve(index+1 , days , costs , cnt);
//         int seven = costs[1] + solve(index+1 , days , costs , days[index]+7 -1 );
//         int thirty = costs[2] + solve(index+1 , days ,costs , days[index]+30 -1);
        
//         return cost = min(one , min(seven , thirty));
//     }
   /*
   recursion
    int solve(int n , vector<int>&days , vector<int> &cost , int index ){
        if(index >= n) return 0;
        
        //1 day pass
        int option1 = cost[0] + solve(n , days ,cost , index +1);
        
        //7 day pass
        int i;
        for(i = index; i<n && days[i] < days[index] +7 ;i++ );
        
        int option2 = cost[1] + solve(n , days , cost , i);
        
        //30 days pass
        // int i;
        for(i =0;i<n && days[i]<days[index]+30;i++);
        
        int option3 = cost[2] + solve(n , days , cost , i);
        
        return min(option1 , min(option2 , option3));
        // int i;
    }
    
    */
    
     int solveMem(int n , vector<int>&days , vector<int> &cost , int index , vector<int> &dp ){
        if(index >= n) return 0;
        
         if(dp[index]!=-1) return dp[index];
         
        //1 day pass
        int option1 = cost[0] + solveMem(n , days ,cost , index +1 , dp);
        
        //7 day pass
        int i;
        for(i = index; i<n && days[i] < days[index] +7 ;i++ );
        
        int option2 = cost[1] + solveMem(n , days , cost , i , dp);
        
        //30 days pass
        // int i;
        for(i =0;i<n && days[i]<days[index]+30;i++);
        
        int option3 = cost[2] + solveMem(n , days , cost , i , dp);
        
        return dp[index] = min(option1 , min(option2 , option3));
        // int i;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solveMem(n , days , costs , 0 ,dp);
    }
};