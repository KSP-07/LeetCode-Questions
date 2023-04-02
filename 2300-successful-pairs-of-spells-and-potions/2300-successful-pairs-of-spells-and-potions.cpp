class Solution {
public:
    
    int binary_search(vector<int> &potions , int high , int num , long long success){
        int low =0;
        int ans =-1;
        while(low<=high){
            int mid = low + (high -low)/2;
            if((long long) potions[mid]*num >= success ){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        for(int i=0; i<n;i++){
            int index = binary_search(potions , m-1 , spells[i] , success );  //modified bs toh multiply num with elements in potion to find success
            if(index==-1) index=m;  //take care of not found 

            ans.push_back(m-index);
        }
        return ans;
    }
};

