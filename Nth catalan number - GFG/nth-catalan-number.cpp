//{ Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        vector<cpp_int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for(int i = 2 ; i<=n ; i++){
            cpp_int sum = 0 ;
            int l = 0 , h = i-1;
            
            while(l <= h){
                if(l==h) sum += ( dp[l] * dp[h] );
                else sum += (2 * (dp[l] * dp[h]));
                l++ ; h--;
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends