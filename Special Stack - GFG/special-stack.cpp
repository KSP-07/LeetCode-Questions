//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

stack<int> mini;
void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
	if(mini.empty() || mini.top() > s.top() ) mini.push(s.top());
	else mini.push(mini.top()) ;
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return (s.size() == n);
	
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty() ;
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.empty()) return -1;
	int val = s.top();
	s.pop();
	mini.pop();
	return val;
}

int getMin(stack<int>& s){
	// Your code goes here
	if(mini.empty()) return -1;
	return mini.top();
}