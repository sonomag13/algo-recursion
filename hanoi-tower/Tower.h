#pragma once

#include <iostream>
#include <stack>

struct Tower {
public:
    Tower(const std::string & towerName, std::stack<int> stk):
            towerName(towerName),
            stk(stk) {

    }

    ~Tower() = default;

    void reverseStack() {
        reversedStk = std::stack<int>();
        std::stack<int> copy = stk;
        while (!copy.empty()) {
            reversedStk.push(copy.top());
            copy.pop();
        }
    }

    std::string towerName;
    std::stack<int> stk;
    std::stack<int> reversedStk;
};