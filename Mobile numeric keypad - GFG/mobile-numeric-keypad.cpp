//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{


	public:
	int mat[4][3]={
	    {1,2,3},
	    {4,5,6},
	    {7,8,9},
	    {-1,0,-1}
	};
	
	
	long long solve(int i,int j,int n,vector<vector<vector<long long>>>&dp)
	{
	    
	    if(i<0 or j<0 or i>=4 or j>=3 or mat[i][j]==-1)
	    return 0;
	    
	    if(n==1)
	    return 1;
	    
	    if(dp[i][j][n]!=-1)
	    return dp[i][j][n];
	    
	    
	    long long a,b,c,d,e;
	    a=solve(i,j,n-1,dp);
	    b=solve(i,j+1,n-1,dp);
	    c=solve(i+1,j,n-1,dp);
	    d=solve(i,j-1,n-1,dp);
	    e=solve(i-1,j,n-1,dp);
	    
	    return dp[i][j][n]=a+b+c+d+e;
	}
	long long getCount(int n)
	{
		// Your code goes here
		long long ans=0;
	    vector<vector<vector<long long >>>dp(4,vector<vector<long long >>(3,vector<long long >(n+1,-1)));
		
		for(int i=0;i<4;i++)
		{
		    for(int j=0;j<3;j++)
		    {
		        if(mat[i][j]!=-1)
		        ans+=solve(i,j,n,dp);
		    }
		}
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
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends