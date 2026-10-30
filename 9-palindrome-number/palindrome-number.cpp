class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        int rev = 0;
        while(n){
    int lastdigit =  n%10;
      if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0;
            }
            
    rev = rev*10 + lastdigit;
    n = n/10;
        }
        if(rev >=0){
        return rev==x;
        }else {
            return false ;
        }
        
    }
};