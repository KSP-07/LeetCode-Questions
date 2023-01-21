//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int> stk;
        int root=INT_MIN;
        
        //first iteration ke baad , agr value left side ki hue to simple push hogii bss ,fir right side 
        //ki value aaygi jab , to stk ke last wala root bnega aur arr val push hogii bss,
        //ex ke acc , jab 4 aaaya to root 2 thaa , aur three aaya tbbi bhi root 2 hii thaa
        for(int i=0;i<N;i++){
            if(arr[i]<root) return 0;  //ab agar koi root se bada element aaane ke baad chota aaaya toh bst nhi hopayga fir 
            
            while(!stk.empty() && stk.top()<arr[i]){
                root=stk.top();
                stk.pop();
            }
            stk.push(arr[i]);
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends