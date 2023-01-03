class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int first = peek();
        output.pop();
        return first;
    }
    
    int peek() {
        if (output.empty())
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }

        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
private:
    stack<int> input; 
    stack<int> output;
};