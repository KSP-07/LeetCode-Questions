class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k=0,size=nums.size();
        for(k=0;k<size;k++){
            if(nums[k]>=0) break;
        }
        int i=k-1;    // intial index of -ve array as we traverse in reverse order
        int j=k,t=0;  // j is index of +ve array and t of temporary array
        int temp[size];
        
        
        while(i>=0 && j<size){
            if(nums[i]*nums[i]<nums[j]*nums[j]){
                temp[t]=nums[i]*nums[i];
                i--;
            }
            else{
                temp[t]=nums[j]*nums[j];
                j++;
            }
            t++;
        }
        
        while(i>=0){
            temp[t]=nums[i]*nums[i];       //for remaiining elements of -ve array
            i--;t++;
        }
        
        while(j<size){
            temp[t]=nums[j]*nums[j];         //for remaiining elements of +ve array
            j++;t++;
        }
        
        for(int i=0;i<size;i++){
            nums[i]=temp[i];
        }
        
        return nums;
    }
};