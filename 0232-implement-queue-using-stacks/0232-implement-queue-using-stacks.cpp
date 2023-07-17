class MyQueue {
public:
    stack<int> s1 , s2 ;
    int ind = 0 ;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        ind++;
    }
    
    int pop() {
        int val , i ;
        
        for(i = 0 ; i < ind-1 ; i++){
            int temp = s1.top() ; s1.pop() ;
            s2.push(temp) ;
        }
        val = s1.top() ; s1.pop() ;
        ind--;
        
        while(!s2.empty()){
            s1.push(s2.top()) ;
            s2.pop();
        }
        
        return val;
    }
    
    int peek() {
        int val , i ;
        
        for(i = 0 ; i < ind ; i++){
            val = s1.top() ; s1.pop() ;
            s2.push(val) ;
        }
        
        while(!s2.empty()){
            s1.push(s2.top()) ;
            s2.pop();
        }
        
        return val;
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */