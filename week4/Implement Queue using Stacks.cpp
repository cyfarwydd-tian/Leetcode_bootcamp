
#include <stack>
class MyQueue {
private:
    std::stack<int> inputStack;   // Stack used for enqueue (push)
    std::stack<int> outputStack;  // Stack used for dequeue (pop/peek)

    // Helper function to move elements from inputStack to outputStack
    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        inputStack.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        transferIfNeeded();
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    // Get the front element
    int peek() {
        transferIfNeeded();
        return outputStack.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
