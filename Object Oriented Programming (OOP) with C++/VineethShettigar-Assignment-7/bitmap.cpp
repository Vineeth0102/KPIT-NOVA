#include<iostream>
#include"bitmap.h"
using namespace std;

template<typename T> 
Stack<T>::Stack() : arr(nullptr), top(-1), capacity(0) {
}

template<typename T>
Stack<T>::Stack(int s) : capacity(s) {
    arr = new T[capacity];
    top = -1;
}

template<typename T>
void Stack<T>::push(T data) {
    if (isfull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = data;
}
	
template<typename T>
T Stack<T>::pop() {
    if (isempty()) {
        cout << "Stack Underflow" << endl;
        return T(); 
    }
    return arr[top--];
}

template<typename T>
T Stack<T>::peep() {
    if (isempty()) {
        cout << "Stack is empty" << endl;
        return T(); 
    }
    return arr[top];
}
	
template<typename T>
bool Stack<T>::isfull() {
    return top == capacity - 1;
}
	
template<typename T>
bool Stack<T>::isempty() {
    return top == -1;
}
