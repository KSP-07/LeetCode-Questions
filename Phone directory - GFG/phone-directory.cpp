//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
    class trienode{
    public:
      char data;
      trienode* children[26];
      bool isterminal;
      trienode(char ch){
          data=ch;
         for(int i=0;i<26;i++){
            children[i]=NULL;
         }
         isterminal=false;
      }
};
class trie{
    public:
    trienode* root;
    trie(){
        root=new trienode('\0');
    }
    void insertutil(trienode* root,string word){
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        int index=word[0]-'a';
        trienode* child;
        if(root->children[index]==NULL){
            child=new trienode(word[0]);
            root->children[index]=child;
        }
        else
            child=root->children[index];
        insertutil(child,word.substr(1));
    }
    void insert(string word){
        insertutil(root,word);
    }
    void printval(vector<string> &temp,trienode* curr,string prefix){
        if(curr->isterminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            trienode* next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printval(temp,next,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getsuggest(string str){
        vector<vector<string>> ans;
        string prefix="";
        trienode* prev=root;
        for(int i=0;i<str.length();i++){
            char lastch=str[i];
            prefix.push_back(lastch);
            trienode* curr=prev->children[lastch-'a'];
            if(curr==NULL){
                  break;
            }
            vector<string> temp;
            printval(temp,curr,prefix);
            ans.push_back(temp);
            prev=curr;
        }
        int i;
        if( i < str.size()){
                while( i< str.size()){
                    ans.push_back({"0"});
                    i++;
                }
            }
        return ans;
    }
};
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie* t=new trie();
        for(int i=0;i<n;i++){
            string str=contact[i];
           t->insert(str); 
        }
        return t->getsuggest(s);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends