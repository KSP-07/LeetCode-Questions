//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> stk;
        
        for(int i = 0 ; i < S.size() ; i++ ){
            if(S[i] == '*'){
                int a = stk.top() ; stk.pop() ;
                int b = stk.top() ; stk.pop() ;
                
                int res = b * a ; 
                // cout<<b<<" "<< a<<endl;
                stk.push(res) ;
            }
            else if(S[i] == '/'){
                int a = stk.top() ; stk.pop() ;
                int b = stk.top() ; stk.pop() ;
                
                int res = b / a ; 
                // cout<<res<<endl;
                stk.push(res) ;
            }
            else if(S[i] == '+'){
                int a = stk.top() ; stk.pop() ;
                int b = stk.top() ; stk.pop() ;
            
                int res = b + a ; 
                // cout<<res<<endl;
                stk.push(res) ;
            } 
            else if( S[i] == '-') {
                int a = stk.top() ; stk.pop() ;
                int b = stk.top() ; stk.pop() ;
                
                int res = b - a ; 
                // cout<<res<<endl;
                stk.push(res) ;
            }
            
            else stk.push(S[i] - '0') ;
            // cout<<S[i]<<" endl"<<endl;
        }
        return stk.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends