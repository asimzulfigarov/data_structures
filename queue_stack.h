#pragma once

#include <iostream>
#include <stack>
#include <vector>

class MyQueue {
private:
    std::stack<int> inner;
    std::stack<int> outer;

public:
    MyQueue() {

    }

    void push(int x) {
        inner.push(x);
    }

    int pop() {
        int r = peek();
        outer.pop();
        return r;
    }

    int peek() {
        if (outer.empty())
        {
            while (inner.size())
            {
                outer.push(inner.top());
                inner.pop();
            }
        }
        return outer.top();
    }

    bool empty() {
        if (inner.empty() && outer.empty()) return true;
        return false;
    }

};