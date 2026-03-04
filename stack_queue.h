#pragma once

#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> stack;

public:
    MyStack() {
        
    }

    void push(int x) {
        stack.push(x);
        for (int i = 0; i < stack.size() - 1; i++)
        {
            stack.push(stack.front());
            stack.pop();
        }
    }

    int pop() {
        int r = stack.front();
        stack.pop();
        return r;
    }

    int top() {
        return stack.front();
    }

    bool empty() {
        if (stack.empty()) return true;
        return false;
    }
};