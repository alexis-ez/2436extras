// 20. Valid Parentheses - leetcode easy
class Solution {
public:
    bool isValid(string s) {
                stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
// 232. Implement Queue using Stacks - leetcode easy
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
    
    void transferIfNeeded() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
    
public:
    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
        transferIfNeeded();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

