#include<bits/stdc++.h>
using namespace std;


//ye ek trie ki node bnane ke liye
class TrieNode{
    public:

    //declaring the req datatypes
    char data;
    TrieNode *children[26];
    bool isTerminal;

    //initialising all the data variables
    TrieNode(char ch){
        data = ch;  //here
        for(int i =0 ; i<26 ; i++){
            children[i] = NULL;   //here
        }
        isTerminal = false;   //here
    }

};

class trie{
    public:

    TrieNode *root;

    //intialising with constructor
    trie(){
        root = new TrieNode('\0');
    }

    void insertUtil( TrieNode *root , string word){

        //base case
        if(word.length() == 0 ){
            root->isTerminal = true;
            return ;
        }

        //assumption word will not be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        //present 
        if(root -> children[index] != NULL){
            child = root-> children[index];  //present hai to bas simply aage badh jayge
        }
        else{
            //absent hai to fir new node create krke root se link krdia
            child = new TrieNode(word[0]);

            root->children[index] = child;
        }

        //recursion for the rest of the word
        insertUtil(child , word.substr(1));   ///abb curr child hii to new root ban jayga agle ke liye
    }

    void insertWord(string word){
        insertUtil(root , word);
    }


    //search util function
    bool searchUtil( TrieNode *root , string word ){

        //base case
        if(word.length() == 0 ){
            return root->isTerminal; 
        }

        int index = word[0] - 'a';
        TrieNode *child;

        //is present
        if( root->children[index] != NULL){
            child = root->children[index];
        }
        else return false;   // if absent 

        return searchUtil( child , word.substr(1)) ;    //calling recursion to search the next index

    }

    //search function
    bool search( string word ){
        return searchUtil(root , word);
    }

    //del word util
    void delUtil(TrieNode *root , string word){
        
        //base case 
        if(word.length() == 0 ){
            if( root ->isTerminal ){
                root->isTerminal = false;
                delete root;
            }
            return;
        }
        TrieNode *child;
        int index = word[0] - 'a';

        if(root->children[index] != NULL) child = root->children[index] ; 
        else return;

        delUtil( child , word.substr(1));
    }
    void delWord(string word){
        delUtil ( root , word) ;
    }

};

int main(){
    trie *t = new trie();

    t->insertWord("abcd");

    cout<< t->search("abcd")<<endl<< t->search("ab")<<endl << t->search("ke")<<endl;

    t->delWord("abcd");
    cout<< t->search("abcd")<<endl<< t->search("ab")<<endl << t->search("ke")<<endl;

    return 0; 
}
