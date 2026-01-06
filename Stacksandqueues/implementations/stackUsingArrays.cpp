#include<bits/stdc++.h>

using namespace std;

class MyStack{
    int* arr;
    int top;
    int capacity;
    public:
        MyStack(int size=10){
            arr = new int[size];
            capacity = size;
            top = -1;
        }
        ~MyStack(){
            delete[] arr;
        }
        void push(int x) {
        if (top >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
        }
        int pop() {
        if (top<0) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        return arr[top--];
    }
        int peek() {
        if (top<0) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return arr[top];
        }
        bool isEmpty() {
        return top<0;
        }
        int size() {
        return top + 1;
        }


};