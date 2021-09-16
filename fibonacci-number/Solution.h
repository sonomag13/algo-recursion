// LeetCode 509. Fibonacci Number
// Easy

#include <unordered_map>

using namespace std; 

class Solution {
public:
    int fib(int n) {        
        unordered_map<int, int> m;         
        return _fib(n, m);         
    }
    
private:
    int _fib(int n, unordered_map<int, int>& m) {
        if (n == 0) {
            return 0; 
        }
        if (n == 1) {
            return 1;
        }
        
        if (m.find(n) != m.end()) {            
            return m[n];            
        }
        
        int result = _fib(n - 1, m) + _fib(n - 2, m); 
        m.insert(make_pair(n, result));
        
        return result; 
    } 
};