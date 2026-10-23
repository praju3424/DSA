class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        bool sorted = true;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                sorted = false;
            }
            
        }
        if(sorted){
            return 0;
        }
        int k = -1;

        vector<int>copy = nums;
        sort(copy.begin(),copy.end());

        for(int i=0; i<n; i++){

            if(copy[i] != nums[i]){
                k &= nums[i];
                
            }
        }


      return k;  
    }
};