/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//https://www.youtube.com/watch?v=3MRPQFUpoA0

class Solution {
public:
    Node* connect(Node* root) {
        Node *tRoot = root;
        while(tRoot!=NULL && tRoot->left!=NULL){
            Node* n=tRoot;   //ye isliye kuki ye chlkee khtm hogi to tRoot ki help se ab next node pa jayge
            while(true){
                n->left->next = n->right;
                
                if(n->next==NULL) break;
                 n->right->next = n->next->left;     //agr root ka next null nhi hua mtlb left side mai hai abi..to fir root ke level pe jo right mai hoga uska left lagarhe
                 n= n->next;   //left subtree se right wali node pe jaarhe hai yaha
            }
            tRoot = tRoot->left;
        }
        return root;
    }
};