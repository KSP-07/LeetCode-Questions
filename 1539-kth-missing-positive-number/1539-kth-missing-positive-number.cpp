// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         unordered_map<int,int> mp;
//         for(auto i:arr) mp[i]++;
        
//         int i=1 ,ans=0;
//         while(k){
//             if(mp[i]) i++;
//             else{
//                 ans=i;
//                 i++;
//                 k--;
//             }
//         }
//         return ans;
//     }
// };
    
    class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0, end = n-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] - (mid + 1) < k)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start + k;
    }
};