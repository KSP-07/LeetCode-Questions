//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        
        //greedy approach ka use kree...phle empty board hoga toh high cost cut wala use krlenge...kuku cut
        //krne pe pieces increase hii honge aur jada cuts krne pdenge
        
        sort(X.begin() , X.end() , greater<int>());
        sort(Y.begin() , Y.end() , greater<int>());
        
        //ab horizontal curs aur vertical cuts ka count measure kr lenge , ki kitne pieces cut krne hai..
        //suru suru mai horizontal aur vertical koi bhi kre ek hii hoga(empty board)..
        //jab vertical krenge  , to fir horizontal ko cut krne ke liye piece increase kr jayga and vice versa
        
        int horizontal=1 , vertical=1;
        int i=0,  j=0;    //i ko point krenge X pe and j ko Y pe
        
        int ans=0;    //total cost nikalne ke liye
        
        //merge sort type ka working hai ab bss
        
        //X is vertical cut and Y is horizontal
        while(i<M-1 && j<N-1){    //M array indexing ke acc 2 jada hai
            if(X[i]>Y[j]){
                ans= ans + (vertical*X[i]);
                horizontal++;   //cut krne ke baad pieces bdhenge...isliye ans phle nikal rhee
                i++;
            }
            else{
                ans= ans +( horizontal*Y[j]);
                vertical++;   
                j++;
            }
        }
        
        //for the remaining in X and Y
        while(i<M-1){
            ans= ans + (vertical*X[i]);
            i++;
        }
        while(j<N-1){
            ans= ans + (horizontal*Y[j]);
            j++;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends