//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> numbers;
        int fact =1;
        for(int i=1;i<n;i++){
            fact = fact*i;  //calculating fact for n-1 num .....this indicates the size of set of elements that would be formed
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans="";
        k= k-1;    //for 0 based indexing
        while(1){
            ans = ans + to_string(numbers[k/fact]);    // k/fact-> gives the number that will come first (mathematical)
            numbers.erase(numbers.begin() + k/fact); //removing the selected element from the array
            if(numbers.size()==0) break;
             k = k%fact;   //this will reduce k...and now will have to find just the sequence for reduced k
             fact = fact/numbers.size();   // now the array size is reduced by 1 , so will reduce the size of set in which elements will be devided
             //ex , with 1 we can form 2 types of permutation , with 2 also two types....just an example
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends