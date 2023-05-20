//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

	/*
class Solution{

	public:
	bool solve(int n , int x , int y , int steps , vector<int> &dp){
	    if((steps&1) && n == 0) return true;
	   //if(n == 1 || n== x || n == y) return true;
	    if(n <= 0) return true;
	    
	   // if(dp[n] != -1) return dp[n];
	   
	    return dp[n] = !(solve(n-1 , x , y , steps + 1 , dp) || solve(n-x , x, y , steps +1 , dp) || solve(n-y ,x , y , steps+1 , dp));
	}
	
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		vector<int> dp(N, -1 );
		int steps = 0;
		return solve(N , X , Y , steps , dp) ;
	}
	

};

*/

class Solution{

	public:
	int winner(int N, int X, int Y, vector<int> &t)
	{
	    if(N == 1 || N == X || N == Y)
	        return 1;
	    
	    if(t[N] != -1)
	        return t[N];
	    
	    bool x = N >= X ? winner(N - X, X, Y, t) : true;
	    bool y = N >= Y ? winner(N - Y, X, Y, t) : true;
	    bool r = N >= 1 ? winner(N - 1, X, Y, t) : true;
	    
	    return t[N] = (!x || !y || !r);
	}
	
	int findWinner(int N, int X, int Y)
	{
	    vector<int> t(N + 1, -1);
	    return winner(N, X, Y, t);
	}

};
		
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends