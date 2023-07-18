class MinStack {
    int *stk , *minstk,topPtr;
    
public:
    MinStack() {
        stk=new int[10000];
        topPtr=-1;
        minstk=new int[10000];
    }
    
    void push(int val) {
        if(topPtr == -1){
            topPtr++;
            
            stk[topPtr] = val;
            minstk[topPtr] = val ;
        }
        else{
            
            int k = minstk[topPtr] ;
            topPtr++;
            
            stk[topPtr] = val;
            minstk[topPtr] = min( k ,val ) ;
        }
            
            
    }
    
    void pop() {
        if(topPtr == -1 ) return;
        int val = stk[topPtr];
        topPtr--;
        
        // minPtr--;
    }
    
    int top() {
        // if(topPtr == -1 ) return -1;
        return stk[topPtr];
    }
    
    int getMin() {
        // if (minPtr == -1) return -1;
        
        return minstk[topPtr];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */