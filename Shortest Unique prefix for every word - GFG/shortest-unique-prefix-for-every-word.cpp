//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class TrieNode{
    public:
    // char data ;
    TrieNode *children[26];
    int ew =0;
};


class Trie{
  public:
  TrieNode *root;
  
  Trie(){
      root= new TrieNode();
  }
  
  void insertUtil(TrieNode *root , string word){
      //base case 
      if(word.size() == 0){
        //   root->isTerminal = true;
          return ;
      }
      
      TrieNode *child;
      int index = word[0] -'a';
      
      if(root->children[index] != NULL){
          child = root->children[index];
          root->ew++;
      }
      else{
          child = new TrieNode();
          root->children[index] = child;
          root->ew++;
      }
      
      insertUtil(child , word.substr(1));
      }
      
      void insert(string &word){
          insertUtil(root , word) ;
      }
      
      void searchUtil( TrieNode *root , string word  , string &ans){
          if(word.size() ==0 ){
              return ;
          }
          
          int index = word[0] - 'a';
          TrieNode *child;
          ans.push_back(word[0]);
          if( root->children[index]->ew ==1){
             return ;
          }
          else{
              child = root->children[index];
          }
          
          return searchUtil(child , word.substr(1) , ans);
      }
      string search(string &word){
          string ans;
          searchUtil(root , word , ans);
          return ans;
      }
      
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        vector<string> ans;
        // string str= ""
        Trie t ;
        
        for( int i = 0 ; i<n ; i++) t.insert(arr[i]);
        for(int i = 0 ; i<n ; i++){
            string str = t.search(arr[i]);
            ans.push_back(str);
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
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends