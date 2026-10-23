class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l =0;
        int r = k-1;
        int n = nums.size();
            int sum = 0;
          for(int i=l; i<=r; i++){
                sum += nums[i];
            }
               int maxsum = sum;


        while(r<n-1){
            

            sum = sum -nums[l];
            l++;
            r++;
            sum = sum + nums[r];

            maxsum = max(sum ,maxsum);
          
            
        }
      
        double result = (double)maxsum / k;

        return result;

        
    }
};