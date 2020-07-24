class Solution {
    double power_util(double x, long  n) {
        double result = 0;
        
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n < 0) return power_util(1/x, -n);
        
        result = power_util(x*x, n/2);
        
        if(n%2) result *= x;
        
        return result;
        
        /*
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n < 0) return power_util(1/x, -n);
        
        double result = power_util(x * x, n/2);
        if(n%2) result *= x;
        return result;
        */
        
    }
public:
    double myPow(double x, int n) {
        return power_util(x, n);
    }
};
