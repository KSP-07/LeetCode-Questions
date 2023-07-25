//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way


class Node{
    public:
    int key;
    int val;
    Node *next ;
    Node *prev ;
    
    Node (int k, int v){
        key = k ;
        val = v ;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
    private:
    
    public:
    
    Node *head = new Node(-1 , -1) ;
    Node *tail = new Node (-1 , -1 ) ;
    
    unordered_map<int , Node *> mp;
    int capacity;
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity = cap ; 
        head->next = tail ;
        tail->prev = head ;
    }
    
    
    void addNode ( Node *newNode) {
        Node *temp = head->next ;
        head->next = newNode ;
        newNode->prev = head ;
        
        newNode->next = temp ;
        temp->prev = newNode ;
    }
    
    void delNode( Node *node ) {
        Node *p = node->prev ;
        Node *n = node->next ;
        
        p->next = n;
        n->prev = p;    
        // delete node ;
    }
     
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if( mp.find(key) != mp.end()) {
            Node *res = mp[key] ;
            int val = res->val ;
            mp.erase(key) ;
            delNode( res) ;
            addNode(res) ;
            mp[key] = head->next ;
            return val ;
        }
        return -1;
        
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        if( mp.find(key) != mp.end()) {
            Node *existing = mp[key] ;
            mp.erase(key) ;
            delNode(existing) ;
        }
        else if (mp.size() == capacity) {
            Node *last = tail->prev ;
            int k = last->key ;
            mp.erase(k) ;
            delNode(last) ;
        }
        
        Node *n = new Node (key , value);
        addNode (n);
        
        mp[key] = head->next ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends