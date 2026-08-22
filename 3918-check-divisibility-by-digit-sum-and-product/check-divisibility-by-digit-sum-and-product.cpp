class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        long long product = 1;
        int num = n;
        while(n > 0)
        {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n = n /10;
        }
        if(num % (sum + product) == 0)
        {
           return true; 
        }else{
            return false;
        }
        return true;
    }
};