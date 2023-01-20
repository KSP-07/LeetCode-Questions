
//optimal approach
class Solution
{
    public:
    
    //tree to doubly linked list mai convert kr rhee
    void convertIntoSortedDLL(Node *root , Node *&head){
        //base
        if(root==NULL) return NULL;
        
        convertIntoDLL(root->right , head);  //root ke right pe call krdia
        
        //ab recursion right se ans laa dega toh fir root ke right mai usse laga denge
        root->right=head;
        
        //agar ans jo aaya wo null hai, to uska kuch left to hoga nhi
        if(head!=NULL) {
            head->left=root;
        }
        
        head=root; //head ko ab root pe point krderhe hai kuki ab left side pe ans nikalenge to uske liye
        //curr right side hogi
        
        convertIntoDLL(root->left, head);
    }
    
    Node* mergeLinkedList(Node *head1 , Node *head2){
        Node *head=NULL;
        Node *tail=NULL;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data < head2->data){
                if(head==NULL){
                    head=head1;
                    tail=head1;
                    head1=head1->right;
                }
                else{
                    tail->right=head1;
                    head1->left=tail;
                    tail= head1;
                    head1= head1->right;
                }
            }
            else{
                if(head==NULL){
                    head=head2;
                    tail=head2;
                    head2=head2->right;
                }
                else{
                    tail->right=head2;
                    head1->left=tail;
                    tail= head2;
                    head2= head2->right;
                }
            }
        }
        
        while(head1 != NULL){
            tail->right=head1;
            head1->left=tail;
            tail= head1;
            head1= head1->right;
        }
        while(head2!=NULL){
            tail->right=head2;
            head1->left=tail;
            tail= head2;
            head2= head2->right;
        }
        return head;
    }
    
    int countNodes(Node * head){
        int cnt=0;
        Node* temp=head;
        while(temp!=NULL){
            cnt++;
            temp= temp->right;
        }
        return cnt;
    }
    
    Node *sortedLLtoBST(Node *&head, int n){
        //basecase
        if(n<=0 || root==NULL){
            return NULL;
        }
        
        Node* left= sortedLLtoBST(head,n/2);
        
        Node* root=head;
        root->left=left;
        
        head=head->next;
        
        root->right= sortedLLtoBST(head,n- (n/2) -1);
        return root;
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
    //   vector<int> ans;
    //   if(!root1==NULL || !root2==NULL) return ans;
    
    
    //step1 : convert BST into sorted DLL(in place)
    Node* head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left=NULL;
    
    Node* head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left=NULL;
    
    //step 2: merge sorted linked list
    Node* head=mergeLinkedList(head1,head2);
    
    //step 3 : convert sortedLL to BST
    return sortedLLtoBST(head,countNodes(head)); 
       
    }
};


//naive solution
class Solution
{
    public:
    
    void in1(Node *root, vector<int> &a)
    {
        if(!root) return;
        in1(root->left,a);
        a.push_back(root->data);
        in1(root->right,a);
    }
    void in2(Node *root, vector<int> &b)
    {
        if(!root) return;
        in2(root->left,b);
        b.push_back(root->data);
        in2(root->right,b);
        
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> a,b;
        in1(root1,a);
        in2(root2,b);
        
        int s1 = a.size()-1 , s2 = b.size()-1;        
        vector<int> s;
        int i=0,j=0;
        while(i<=s1  && j<=s2)
        {
            if(a[i]<b[j])
            {
                s.push_back(a[i++]);
                
            }
            else
            {
                s.push_back(b[j++]);
            }
        }
        while(i<=s1)
        {
            s.push_back(a[i++]);
        }
        while(j<=s2)
        {
            s.push_back(b[j++]);
        }
        return s;
        
    }
    
};
