//Johnny Catullo - Data Algorithim Implementation Internship
//----------------------------------------------------------
//https://leetcode.com/problems/implement-queue-using-stacks/
//----------------------------------------------------------

/* 
    ==GOAL==
   Implement a first in first out (FIFO) queue using only two stacks. 
   The implemented queue should support all the functions of a normal queue 
   (push, peek, pop, and empty).

   Input
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]

   Output
    [null, null, null, 1, 1, false]


    Time Complexity:
        Insertion: Avg - 0(1) Worst - 0(1)
        Deletion: Avg - 0(1) Worst - 0(1)

    Space Complexity: Worst - O(n)

    Implemntation: 

*/

#include <iostream>
#include <stack>



class MyQueue {
private: 
    std::stack<int> s1;
    std::stack<int> s2;
    int size;
public:
    
    /** Initialize your data structure here. */
    //Initlialize by setting size = 0
    MyQueue() {
       size = 0;
    }
    
    /** Push element x to the back of queue. */
    /*
        For pushing, we check to see if the first stack is empty.
        If it isnt, then we push the top of stack one to stack two, then pop the element from stack one.
        Then we push the element to stack one and then push the contents of stack two to stack one while popping them.
        If it is empty, then we just push the element to stack one and increase the size. 
    */
    void push(int x) {

        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        size++;

    }
    
    /** Removes the element from in front of queue and returns that element. */
    /* 
        We first check to see the front using peek()
        Then we pop the first element from stack one and reduce the size.
        Finally, we return the front of the stack.
    */
    int pop() {

        int front = peek();
        s1.pop();
        size--;
        return front;
            
    }
    
    /** Get the front element. */
    //Returns the top of stack one.
    int peek() {
        return s1.top();        
    }
    
    /** Returns whether the queue is empty. */
    //Checks to see if both stacks are empty.
    bool empty() {
        return (s1.empty()&&s2.empty());
    }

   
};
 //Test out all functions in main and create a new queue.
 int main(){

        MyQueue* obj = new MyQueue();
        obj->push(1);
        obj->push(2);
        std::cout << obj->peek() << std::endl;
        obj->pop();
        std::cout << obj->empty() << std::endl;


        return 0;
    }


