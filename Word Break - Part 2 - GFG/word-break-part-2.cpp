//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void solve(int index , int size,string &s , string temp, unordered_set<string> &st , vector<string> &ans){
        //base case
        //jab index , size ke barabar hojaygi toh iska mtlb pura string traverse hogya , aur aisa tab hoga jab words mil gaye honge
        if(index == size){
            temp.pop_back();   //kuki last mai ek empty space add hojaygii
            ans.push_back(temp);
            return;
        }
        //hr ek letter ko check krte hue agr koi word milra dict mai , toh fir usse str mai add krke , aage check kr rhe
        //aise cat pe aage recursion call hoga , aur loop ki vjh se cats pe bhi
        for(int i=index ; i<size;i++){
            string str = s.substr(index, i - index +1);
            if(st.find(str)!=st.end()){
                solve(i+1 , size , s , temp + str +" " , st , ans);
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_set<string> st;
        vector<string> ans;
        
        //taking dict into set
        for(auto it: dict) st.insert(it);
        
        int size = s.size();
        solve(0 , size , s ,"" , st ,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends