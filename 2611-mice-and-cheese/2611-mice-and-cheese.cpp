class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        priority_queue<int> pq;
        int n = r1.size() , ans =0;
        
        for(auto x : r2) ans+=x;
        
        for(int i = 0 ; i< n; i++){
            pq.push(r1[i] - r2[i]);
        }
        
        int curr = ans;   //ans mai arr2 ke to elements hai hii , to fir jab max select krenge arr1 se, toh uske corresponding arr2 ko subtract kr rhee ,,,,,,kuki agr nhi krra toh fir arr2 ka wo corresponding element do baar add hojaygaa
        for(int i = 0 ; i<k ;i++){
            auto x = pq.top() ; pq.pop();
            curr+=x;
        }
        return curr;
    }
};


