#include<iostream>
#include"bitmap.h"
using namespace std;

template<typename T>
Queue<T>::Queue() : arr(nullptr), front(0), rear(-1), capacity(0), count(0) {
}


template<typename T>
Queue<T>::Queue(int s) : capacity(s), front(0), rear(-1), count(0) {
    arr = new T[capacity];
}


template<typename T>
void Queue<T>::insert(T data) {
    if (isfull()) {
        cout << "Queue Overflow" << endl;
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = data;
    count++;
}
	
template<typename T>
T Queue<T>::remove() {
    if (isempty()) {
        cout << "Queue Underflow" << endl;
        return T(); // Return default value of T
    }
    T data = arr[front];
    front = (front + 1) % capacity;
    count--;
    return data;
}

	
template<typename T>
bool Queue<T>::isfull() {
    return count == capacity;
}
	
template<typename T>
bool Queue<T>::isempty() {
    return count == 0;
}
