// #ifndef STACK_H
// #define STACK_H

#include <iostream>
#include <stdexcept>

template<class T>
class Stack {
private:
    class Node {
        public:
        T data;
        Node* next;
    
        Node(T data, Node* next) : data(data), next(next){}
    };
    
    Node* top;

public:  
    //Default Constructor
    Stack(){
        top = nullptr;
    }
    
    bool push(T val){
        top = new Node (val, top);
        return true;
    }
    
    T pop(void){
        if(isEmpty()){
            throw std::runtime_error("Stack is empty! Nothing to pop!");
        }
        Node* t = this->top;
        T popped = this->top->data;
        top = top->next;
        
        delete t;
        t = nullptr;
        
        return popped;
    }
    
    T peek(int position){
        if(position < 0){
            throw std::runtime_error("Invalid position!");
        }
        
        Node* t = top;
        
        for(int i = 0; t && i < position; i++){
            t = t->next;
        }
        if(!t)
            throw std::runtime_error("Invalid position!");
        
        return t->data;
    }
    
    T stackTop(void){
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty!");
        }
        
        return top->data;
    }
    
    bool isEmpty(void){
        return top == nullptr;
    }
};

// #endif
int main(){
    Stack<int> st;
    
    // Test isEmpty on empty stack
    std::cout << "isEmpty: " << (st.isEmpty() ? "true" : "false") << std::endl;
    
    // Test push
    st.push(10);
    st.push(20);
    st.push(30);
    std::cout << "Pushed 10, 20, 30" << std::endl;
    
    // Test isEmpty on non-empty stack
    std::cout << "isEmpty: " << (st.isEmpty() ? "true" : "false") << std::endl;
    
    // Test stackTop
    std::cout << "stackTop: " << st.stackTop() << std::endl; // expected 30
    
    // Test peek
    std::cout << "peek(0): " << st.peek(0) << std::endl; // expected 30
    std::cout << "peek(1): " << st.peek(1) << std::endl; // expected 20
    std::cout << "peek(2): " << st.peek(2) << std::endl; // expected 10
    
    // Test pop
    std::cout << "pop: " << st.pop() << std::endl; // expected 30
    std::cout << "pop: " << st.pop() << std::endl; // expected 20
    std::cout << "pop: " << st.pop() << std::endl; // expected 10
    
    // Test pop on empty stack
    try {
        st.pop();
    } catch (std::runtime_error& e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test with strings
    Stack<std::string> ss;
    ss.push("hello");
    ss.push("world");
    std::cout << "stackTop: " << ss.stackTop() << std::endl; // expected world
    std::cout << "pop: " << ss.pop() << std::endl;           // expected world
    std::cout << "pop: " << ss.pop() << std::endl;           // expected hello
return 0;
}