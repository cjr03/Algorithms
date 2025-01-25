#include <cmath>

class MinStack {
private:
    stack<int> * minStack;
    vector<int> *  minElements;
public:
    MinStack() {
        minStack = new stack<int>();
        minElements = new vector<int>();
        minElements->push_back(pow(2, 31) - 1);
    }
    
    void push(int val) {
        if(val <= minElements->back()){
            minElements->push_back(val);
        }
        minStack->push(val);
    }
    
    void pop() {
        if(minStack->top() == minElements->back()){
            minStack->pop();
            minElements->erase(minElements->end());
        } else {
            minStack->pop();
        }
    }
    
    int top() {
        if(minElements->size() > 0){
            return minStack->top();
        } else {
            return int();
        }
    }
    
    int getMin() {
        return minElements->back();
    }
};
