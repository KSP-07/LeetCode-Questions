class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        } 
        sort(v.rbegin(),v.rend());
        long long res = 0;
        long long curr = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        while(i<nums1.size()){
            curr+=v[i].second;
            pq.push(v[i].second);
            if(i>=k-1){
                res=max(res,curr*v[i].first);  //yaha pe desc order mai hai, to k ki value ke hisab se max among min aajayag
                curr-=pq.top();   //agar nums1 mai koi bddi value hi bhut, jo ki multiply krne se bhi jada ho...to wo to reh jaygii naa, fir chahe chote num se ku na multiply horha ho baad mai
                
                //or ofcourse, agr hum nums2 ke min ki side jarhe, toh hum apna nums 1 ka sum toh max hii rkhna chahege
                pq.pop();
            }
            i++;
        }
        return res;

    }
};