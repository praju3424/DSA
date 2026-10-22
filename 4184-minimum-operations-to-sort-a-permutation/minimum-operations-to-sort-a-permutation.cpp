class Solution {


public:
    int solve(vector<int>&nums){
        vector<int>ans = nums;
        int n  = nums.size();

        for(int it : nums){
            ans.push_back(it);
        }
        int count = 1;
    // for increasing 
        for(int i =1; i<ans.size(); i++){

            if(ans[i]<ans[i-1]){
                count = 1;
            }else{

                 count++;

            if(count == n) return i+1-n; 


            }

           

        }

        //for decreasing sequence 
            count = 1;
        for(int i=1; i<ans.size(); i++){
            if(ans[i]>ans[i-1]){
                count = 1;
            }else{

            
            count++;
            if(count == n) return i+2 - n;

            }
        }

        
       return 1e9; 
    }
    int minOperations(vector<int>& nums) {

        if(nums.size() == 1) return 0;

        int result = solve(nums);
        reverse(nums.begin(),nums.end());
        result = min(result , solve(nums)+1);
        return result == 1e9 ? -1 : result;

        

     
        
        
    }
};