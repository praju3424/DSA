class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();

        int l=0;
        int r = k-1;
       
           int count = 0;
            for(int i=0; i<=r; i++){
           
                if(s[i] =='a' || s[i]=='i' || s[i]=='e'|| s[i]=='o'|| s[i]=='u'){
                    count ++;

                }
            }
            int maxcount = count ;


        while(r<=n-1){
            if(s[l] =='a' || s[l]=='i' || s[l]=='e'|| s[l]=='o'|| s[l]=='u' ){
                count--;
            }
            l++;
            r++;
             if(s[r] =='a' || s[r]=='i' || s[r]=='e'|| s[r]=='o'|| s[r]=='u' ){
                count++;
            }
              
              maxcount = max(maxcount , count);
          
            

        }
        
        
        return maxcount;
    }
};