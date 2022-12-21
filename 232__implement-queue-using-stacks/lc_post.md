C++ || Easy to Understand with In-Depth Explanation and Examples || O(TODO)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
    - [push](#push)
    - [peek](#peek)
    - [pop](#pop)
  - [Example](#example)

# TL;DR

* Have 2 stacks: one for input and one for output
* Push onto input stack
* Pop from output stack
* When the output stack is empty, move elements from input to output (going from LIFO to FIFO)

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(1)$$ amortized for all operations
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to hold 2 stacks where one of them is for whenenver a push occurs (input) and the other is there for pop and peek (output)

## Approach

I will be talking about each function individually

### push

For this, we just want to take the element and push it onto the input stack

**Time Complexity:** $$O(1)$$

### peek

Ideally, we would want to just take the top element from the output stack. However, if the output stack is empty, then we need to move all of the elements from the input stack onto the output stack

The reason why is because when you insert values into `input` then the first on in is the last one out. However, if you flip the stack upside down (aka move all elements to another stack), the first element in becomes the top element, which is exactly what we want

**Time Complexity:** $$O(N)$$ when elements move, but an amortized $$O(1)$$

### pop

We want to run peek first to ensure that we have a value at the top and grab the value that we want to return. After that, we just remove the value and return it

**Time Complexity:** $$O(N)$$ when `pop` moves elements, but an amortized $$O(1)$$

## Example

Let's use **Example 1** from the description. We first push `1` and `2` onto the queue. This means that our input stack will be `bottom [1,2] top`. 

Then we want to peek. Since we have no values on the output stack, we need to move everything over, which then makes the output stack `bottom [2,1] top` since we are just reversing the input stack and get the top element which is now `1` and was the first element inserted into the queue

Then, we want to pop. Since there are values on the output stack, we just call peek on `bottom [2,1] top`, which just returns `1`. Then we pop the element off of the stack which is `1` and return it.

Then, we want to check if it is empty, which can be done by seeing whether or not there are values on either stack. Since the output stack still has one value, we return `false`

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**