#include<bits/stdc++.h>
using namespace std;
//max heap
class maxHeap{
    public:
        int arr[100];
        int size =0 ;
        //find the parent of the node, check if it is smaller , if yes just wsap it
        void insert(int val){

            size++;
            int index = size;
            arr[index] = val;
            while(index>1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }
        //deleting means root node
        // swap with last node, then delete last node, then heapify
        void deleteRoot(){
            if(size == 0) return;
            arr[1] = arr[size];
            size--;
            int index = 1;
            while(index <= size){
                int left = 2*index;
                int right = 2*index + 1;
                if(left < size && arr[index] < arr[left] ){
                    swap(arr[index], arr[left]);
                    index = left;
                }
                else if(right < size && arr[index] < arr[right]){
                    swap(arr[index], arr[right]);
                    index = right;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1; i<=size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;
    if(left < n && arr[largest]<arr[left]){
        largest= left;
    }
    if(right < n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main(){
    maxHeap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.print();
    h.insert(60);
    h.print();
    h.deleteRoot();
    h.print();


    int arr[6] = {-1, 50, 55, 53, 54, 50};
    int n = 5;
    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr, n, i);
    }
    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
