//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
  //ye function batayga ki kitne bracket remove krne ki jrurat hai
  int minR(string s){
      stack<char> st;
      
      for(char i:s){
          if(i=='(') st.push(i);
          else if(i==')' && !st.empty() && st.top()=='(' ) st.pop(); 
          else if(i==')') st.push(i);
      }
      return st.size();
  }
  
  void solve(string s , unordered_set<string> &st , vector<string> &ans , int R){
      if(R==0){
          if(minR(s)==0){
              ans.push_back(s);
              return;
          }
      }
      for(int i=0;i<s.size(); i++){
          //for any letters
          if(s[i]!='(' && s[i]!=')'){
              continue;
          }
          else{
              //ek char hata ke dekh rhee
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            if(st.find(left + right)==st.end()) {
                solve(left+right , st,ans , R-1);
                st.insert(left+right);
            }
          }
      }
  }
  
    vector<string> removeInvalidParentheses(string s) {
        // code here
        int minRemoval = minR(s);
        // cout<<minRemoval<<endl;
        unordered_set<string> set;
        vector<string> ans;

        solve(s , set,ans , minRemoval);
        sort(ans.begin() , ans.end());   //kuki ans sorted order mai dena hai
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends