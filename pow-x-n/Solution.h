/*
    50. Pow(x, n)
    Medium

    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

    Example 1:

    Input: x = 2.00000, n = 10
    Output: 1024.00000
    Example 2:

    Input: x = 2.10000, n = 3
    Output: 9.26100
    Example 3:

    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
    

    Constraints:

    -100.0 < x < 100.0
    -231 <= n <= 231-1
    -104 <= xn <= 104
*/

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {                

        double val{_myPow(x, abs(n))};        
        
        return n >= 0 ? val : 1.0 / val;
                
    }
    
private:
    double _myPow(double x, int n) {
        
        if (n == 0) {
            // base case
            return 1.0; 
        }
        
        double val{_myPow(x, n/2)};
        
        if (n%2 == 0) {
            return val * val;
        }
        else {
            return val * x * val;
        }
        
    }
        
};