class Solution {
public:
    double average(vector<int>& salary) {
        double sum =0 , cnt = 0;
        int n = salary.size();
        sort(salary.begin() , salary.end());
        
        for(int i = 1 ; i< n-1 ; i++){
            sum += salary[i];
            cnt++;
        }
        return sum/cnt;
    }
};