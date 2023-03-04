//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
//first pos pe rk ke , aage check kr rhee ki max kaha hai ab  , fir swap krke dekh lerhe , agr banta hai to thik nhi toh backtrack
    void solve(string str , int k ,string &ans ,int i , int n){
        
        ans = max(ans , str);
        if(k==0 || i==n) return;
        
        for(int ind=i+1 ;ind<n;ind++){
            if(str[i] < str[ind]){
                swap(str[i] , str[ind]);
                solve(str, k -1 , ans, i+1 ,n);
                swap(str[i] , str[ind]);
            }
        }
        //not pick
        solve(str ,  k , ans , i+1 , n);
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans="";
       int n = str.size();
       solve(str , k ,ans,0,n);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends