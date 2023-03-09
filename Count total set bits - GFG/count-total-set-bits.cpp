//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        
        if( n <=1) return n;
        
        int x = log2(n);    //this will give the highest power of 2 less than n
        
       //(2^(x-1))*x  //sum of bits of numbers less than highest power of two in n 
        int first= (1<<(x-1))*x;  
        //count number of biggest set bits from highest power of 2 to n
        int second=n-(1<<x)+1;
        //solve for for n-highest_power_of_two
        int third=n-(1<<x);
        return first+second+countSetBits(third);

    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends