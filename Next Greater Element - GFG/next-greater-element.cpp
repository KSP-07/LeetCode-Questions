//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> stk ;
        vector<long long> ans ;
        stk.push(arr[n-1]);
        ans.push_back(-1);
        
        // long long Last = arr[n-1] ;
        for (int i = n-2 ; i>= 0 ; i--){

            if(arr[i] < stk.top()) {
                ans.push_back(stk.top());
                stk.push(arr[i]);
            }
            else{
                while(!stk.empty() && arr[i] >= stk.top()) stk.pop();
                if(stk.empty()) ans.push_back(-1);
                else ans.push_back(stk.top()) ;
                stk.push(arr[i]);
            }
            
        }
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends