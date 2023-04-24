//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class TrieNode{
  public:
  TrieNode *children[26] ;
  bool isTerminal = false;
};

class Trie{
    public:
    TrieNode *root = new TrieNode();
    
    
    void insertUtil ( TrieNode *root , string word){
        if(word.size() == 0 ){
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode * child;
        
        if(root->children[index] != NULL ){
            child = root -> children[index];
        }
        else{
            child = new TrieNode();
            root-> children[index] = child;
        }
        
        insertUtil(child , word.substr(1));
    }
    void insert(string &word){
        insertUtil( root , word);
    }
    
    bool searchUtil( TrieNode *root , string word){
        if(word.size() == 0){
            return root->isTerminal;
        }
        
        int index = word[0] -'a';
        TrieNode *child;
        
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else return false;
        
        return searchUtil(child , word.substr(1));
    }
    bool search(string &word){
        return searchUtil(root , word);
    }
};
class Solution
{
public:

    int solve( string word, Trie *t ){
        if(word.size() == 0) return 0;
        if(t->search(word)) return 1;
        for(int i = 1 ; i <= word.size() ; i++){
            string s1 = word.substr(0 , i);
            string s2 = word.substr(i , word.size() - i);
            // if(t->search(s1) && t->search(s2)) cout<<s1 <<" "<<s2<<endl;
            if(t->search(s1) && solve( s2, t)) return true;
            // else if(t->search(s1)) return solve( s2, t);
        } 
        return false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie *t = new Trie();
        for(auto i: B){
            t->insert(i);
        }
        return solve(A , t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends