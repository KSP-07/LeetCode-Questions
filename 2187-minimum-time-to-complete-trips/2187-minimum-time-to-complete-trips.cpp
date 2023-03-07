class Solution {
public:
    //ek koi number lenge range mai then dekhenge ki array ke nums se devide krke ki kitne rounds lag skte hai
    //fir agr uska sum total trips se bada hua toh mtlb mid ki value kam krke bhi syd hojay , aur same hua toh bhi min leke ans aur mid ka ek baar limit kam krdenge toh same ke case mai bsearch tuut jaygi
    //aur agr sum kam pada toh mtlb mid bada krne pdega
    long long minimumTime(vector<int>& time, int totalTrips) {
        //sort krne ki jrurat nhi hai , kuki harr baar array mai traverse krke total check krne pdege
        // sort(time.begin() , time.end());
        long long l = 0, r=100000000000000 , ans = r;
        while(l<r){
            long long mid = (l+r)/2;
            long long cnt =0;
            for(int i=0; i< time.size();i++){
                cnt+= (mid/time[i]);   //kitne baar traverl kr skte nikal aayga
            }
            if(cnt >=totalTrips){
                ans = min(ans , mid);
                r=mid;
            }
            else l =mid+1;
        }
        return ans;
    }
};