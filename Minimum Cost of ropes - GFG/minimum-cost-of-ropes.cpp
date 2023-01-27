//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if(n<=1) return 0;
        
        //priority queue se top 2 element leke sum krke waps push krskte
        priority_queue<long long , vector<long long>, greater<long long>> pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long total=0;
        
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            total+=(a+b);
            // cout<<total<<endl;
            pq.push(a+b);
        }
        return total;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends