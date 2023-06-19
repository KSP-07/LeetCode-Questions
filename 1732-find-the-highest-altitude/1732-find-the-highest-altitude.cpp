class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> arr(n+1, 0);
        // arr.push_back(0);
        for(int i = 0 ; i < n ; i++){
            arr[i+1] = gain[i] + arr[i];
        }
        int ans = *max_element(arr.begin() ,arr.end());
        return ans;
    }
};