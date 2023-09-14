//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> dp(N+1 , 0);
        
        for(int i = 2; i <= N ; i++){
            if(dp[i] == 0){
                int num = 2 ;
                int j = i;
                while(j*num <= N){
                    dp[j*num] = 1 ;
                    num++;
                }
            }
        }
        vector<int> ans;
        
        for(int i = 2; i<= N ; i++){
            if(dp[i] == 0){
                ans.push_back(i);
            }
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends