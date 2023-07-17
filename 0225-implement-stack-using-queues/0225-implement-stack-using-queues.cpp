class MyStack {
public:
    
    queue<int> q1 , q2;
    int ind = 0 ;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        ind++;
    }
    
    int pop() {
        int i , val ;
        
        for ( i=0 ; i < ind-1 ; i++){
            int temp = q1.front(); q1.pop();
            q2.push(temp);
        }
        
        val = q1.front(); q1.pop() ;
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        ind--;
        
        return val;
    }
    
    int top() {
        int i , val ;
        
        for ( i=0 ; i < ind ; i++){
            val = q1.front(); q1.pop();
            q2.push(val);
        }
        
        // val = q1.front(); q1.pop() ;
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        // ind--;
        
        return val;
    }
    
    bool empty() {
       if(q1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */