//test file for linked list stack class
#include "LinkedListStack.hpp"
#include <iostream>
using namespace std;

int main() {
    LinkedListStack<int> stack;

    // Test push
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top: " << stack.peek() << endl; // Expected: 30
    cout << "Length: " << stack.getLength() << endl; // Expected: 3

    // Test pop
    stack.pop();
    cout << "Top after pop: " << stack.peek() << endl; // Expected: 20
    cout << "Length after pop: " << stack.getLength() << endl; // Expected: 2

    // Test clear
    stack.clear();
    cout << "Length after clear: " << stack.getLength() << endl; // Expected: 0
    cout << "Is empty after clear: " << (stack.isEmpty() ? "Yes" : "No") << endl; // Expected: Yes

    // Test underflow error on peek
    try {
        stack.peek();
    } catch (const std::underflow_error& e) {
        cout << "Caught exception on peek from empty stack: " << e.what() << endl;
    }

    // Test underflow error on pop
    try {
        stack.pop();
    } catch (const std::underflow_error& e) {
        cout << "Caught exception on pop from empty stack: " << e.what() << endl;
    }

    return 0;
}