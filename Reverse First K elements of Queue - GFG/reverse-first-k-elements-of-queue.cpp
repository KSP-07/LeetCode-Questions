//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++


void solve(queue<int> &q , int k) {
    if( k == 0) return ;
    
    int val = q.front() ; q.pop() ;
    
    solve(q , k-1) ;
    
    q.push(val) ;
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    solve(q , k);
    int rem = q.size() -k ;
    while(rem-- ){
        int val = q.front() ; q.pop() ;
        q.push(val);
    }
    return q;
}