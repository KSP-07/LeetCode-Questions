class SmallestInfiniteSet {
public:
    
    set<int> st;
    int curr_int;
    SmallestInfiniteSet() {
        curr_int = 1;
    }
    
    int popSmallest() {
        int ans;
        
        if(!st.empty()){
            ans = *st.begin();
            st.erase(st.begin());
        }
        else{
            ans = curr_int;
            curr_int += 1;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(curr_int <= num || st.find(num) != st.end()){
            return ;
        }
        
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */