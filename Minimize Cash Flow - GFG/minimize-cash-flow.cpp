//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    void minCashFlow(auto &amount , auto &ans){
    // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //                  (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //                  (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value
    
       int mxCred = max_element(amount.begin(),amount.end()) - begin(amount);
        int mxDebt = min_element(amount.begin(),amount.end()) - begin(amount); //finding the max element and min element in amount
        //so this will be the maximum to be paid and maximum a persong will get
        
        //if both amount are 0 means that it's settled now
        if(amount[mxCred]==0 && amount[mxDebt]==0) return;
        
        //finding min of the two amounts...
        int mn = min(amount[mxCred] , -amount[mxDebt]);
        amount[mxCred]-=mn;
        amount[mxDebt]+=mn;
        
        ans[mxDebt][mxCred]=mn;   //iska mtlb hai ki debt wale ne cred wale ko kitne pay kree
        
        minCashFlow(amount , ans);
        
    }
        vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
        {
            // code here
            vector<int> amount(n,0);  //initalizing amount vec with 0 as to it will store the net amount of ith person
            
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    //[j] [i] iterates over column vertically and i j in row
                    //thus in row is the amount ith person has to pay and vertically is the amt he will get
                    amount[i] += (transaction[j][i] - transaction[i][j]);
                }
            }
            vector<vector<int>> ans(n , vector<int>(n,0));   //for storing ans
            minCashFlow(amount , ans);   //find ing the min cash flow
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
        int n;
        cin>>n;
        vector<vector<int>> g(n,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>g[i][j];
        }
        Solution s;
        vector<vector<int>> r=s.minCashFlow(g,n);
        for(auto j:r)
        {
            for(auto i:j)
                cout<<i<<" ";
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}
// } Driver Code Ends