class Trie {
public:
    
    vector<string> v;
    Trie() {
        
    }
    
    void insert(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        if(find(v.begin(),v.end() ,word)!=v.end()) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        for(int i=0 ; i<v.size();i++){
            string words = v[i];
            string word = words.substr(0, n);    //ye check kr rha ki vector se ek word nikla toh prefix n length ki hai , toh utna match kr rha ya nhi
            if(word==prefix) return true;
        }
        return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */