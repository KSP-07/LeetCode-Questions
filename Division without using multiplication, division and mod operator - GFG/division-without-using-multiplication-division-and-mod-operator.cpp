//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long a, long long b) 
    {
        //First step: COnvert the negative number to a positive one.
        
        int sign= ((a<0) ^ (b<0))?-1:1;
        long long dividend=abs(a);
        long long divisor=abs(b);
        
        long long temp=0;
        long long quotient=0;
        // Step two iterate all the 32 bits to find the best power of 2 that satisfies the division
        //NOTE: If in question -10^9<=a<=10^9 then the no of bits is 32, for-10^18<=a<=10^18 the no of bits is 64
        for(int i=31;i>=0;i--)
        {
            if(temp+ (divisor<<i)<=dividend)
            {
                temp+=divisor<<i; 
                // cout<<temp<<" "<< (divisor<<i)<<" "<<(1LL<<i)<<endl;
                quotient+=(1LL<<i);    //With 1LL , you set the type to long long before hand and now it will properly return 2^40.
            }
        }
        
        return quotient*sign;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends