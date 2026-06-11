#include<bits/stdc++.h>

using namespace std;

class minheap{
    int size = 0;
    int arr[100];

    public:
        void insert(int val){
            size++;
            int index = size;
            arr[index] = val;
            while(index > 1){
                int parent = index/2;
                if(arr[parent] > arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        };

        int deleteRoot(){
            if(size == 0) return -1;
            int root = arr[1];
            arr[1] = arr[size];
            size--;
            int index = 1;
            while(true){
                int left = 2*index;
                int right = 2*index + 1;
                int smallest = index;
                if(left <= size && arr[left] < arr[smallest]) smallest = left;
                if(right <= size && arr[right] < arr[smallest]) smallest = right;
                if(smallest != index){
                    swap(arr[index], arr[smallest]);
                    index = smallest;
                } else {
                    break;
                }
            }
            return root;
        };

        void print(){
            for(int i=1; i<=size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    minheap h;
    h.insert(5);
    h.insert(3);
    h.insert(8);
    h.insert(1);
    h.print();
    cout << h.deleteRoot() << endl;
    h.print();
    cout << h.deleteRoot() << endl;
    h.print();
    cout << h.deleteRoot() << endl;


    return 0;
}