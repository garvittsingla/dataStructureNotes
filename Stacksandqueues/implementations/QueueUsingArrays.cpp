#include<bits/stdc++.h>

using namespace std;
class Q{
    int start;
    int end;
    int *arr;
    int capacity;
    int currsize;

    public:
        Q(int size=10){
            capacity = size;
            start = -1;
            end = -1;
            arr = new int[capacity];
            currsize = 0;
        }
        void push(int element){
            //if q is full
            if(currsize == capacity){
                cout<<"Queue overflow"<<endl;
                return;
            }
            //if q is empty
            if(end==-1){
                start = 0;
                end = 0;
            }else{
                end = (end+1)%capacity;
            }
            arr[end] = element;
            currsize++;


        }
        int pop(){
            //if q is empty
            if(currsize==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int result = arr[start];
            if(start==end){
                start = -1;
                end = -1;
            }else{
                start = (start+1)%capacity;
            }
            currsize--;
            return result;
        }


};
int main() {
    cout << "Queue using Arrays Implementation" << endl;
    return 0;
}