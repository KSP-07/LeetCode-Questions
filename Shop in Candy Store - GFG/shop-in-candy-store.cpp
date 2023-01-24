//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        
        // 1 2 3 4
        // 0 1 2 3
        // Write Your Code here
        
        //base case
        if(k==0){
            int sum=0;
            for(int i=0;i<n;i++) sum+=candies[i];
            return {sum ,sum};
        }
        
        sort(candies , candies+n);
        
        int i=0; //to keep pointer on min value;
        int j=n-1;  // to keep pointer on max value;
        
        int mini=0;
        //indexing ki vjh se i==j wala consider kr kr rhee
        while(i<=j){   //j slide krte rhenge jaise jaise i candy buy hogi , aur agr i==j hota to mtlb jth to already bought hai4
            mini+=candies[i];
            // money-=candies[i];
            j-=(k);     
            i++;
        }
        
        int maxi=0;
        i=0,j=n-1;
        while(i<=j){    //
             maxi+=candies[j];
            // money-=candies[j];
            j--;
            i+=(k);
        }
        return {mini ,maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends