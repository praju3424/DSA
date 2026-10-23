class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int l = 0;
        int r = k-1;
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<=r; i++){
            sum += arr[i];

        }
        int maxavg = sum/k; 
        int count = 0;
        if(maxavg >= threshold){
            count++;
        }

        while(r<n-1){
            sum = sum - arr[l];
            l++;
            r++;
            sum = sum + arr[r];
            if(sum >=threshold * k){
                count++;
            }

        }
     return count;   
    }
};