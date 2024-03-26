#include <iostream>

template <typename T>
class Stack {
private:
  T *elements;  // array to store the stack elements
  int size;     // size of the array
  int top;      // index of the top element in the stack

public:
  // constructor that takes an optional size parameter
  Stack(int k = 50) {
    size = k;
    elements = new T[size];
    top = -1;
  }

  // copy constructor
  Stack(const Stack<T> &s) {
    size = s.size;
    top = s.top;
    elements = new T[size];
    for (int i = 0; i <= top; i++) {
      elements[i] = s.elements[i];
    }
  }

  // destructor
  ~Stack() {
    delete[] elements;
  }

  // check if the stack is empty
  bool empty() {
    return top == -1;
  }

  // check if the stack is full
  bool full() {
    return top == size - 1;
  }

  // add an element to the stack
  void push(T element) {
    if (!full()) {
      elements[++top] = element;
    } else {
      std::cout << "Stack full!" << std::endl;
    }
  }

  // remove an element from the stack
  void pop() {
    if (!empty()) {
      top--;
    } else {
      std::cout << "Stack empty!" << std::endl;
    }
  }

  // get the value of the top element in the stack
  T peek() {
    if (!empty()) {
      return elements[top];
    } else {
      std::cout << "Stack empty!" << std::endl;
      return T();
    }
  }

  // assignment operator
  Stack<T>& operator=(const Stack<T> &s) {
    if (this != &s) {
      delete[] elements;
      size = s.size;
      top = s.top;
      elements = new T[size];
      for (int i = 0; i <= top; i++) {
        elements[i] = s.elements[i];
      }
    }
    return *this;
  }

  // stream output operator
  friend std::ostream& operator<<(std::ostream &out, const Stack<T> &s) {
    out << "[";
    for (int i = 0; i <= s.top; i++) {
      out << s.elements[i];
      if (i < s.top) {
        out << ", ";
      }
    }
    out << "]";
    return out;
  }
};
