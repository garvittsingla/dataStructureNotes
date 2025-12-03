#include <bits/stdc++.h>

using namespace std;

template <class T>
struct IterableStack : public stack<T> {
    using stack<T>::c; 
};
IterableStack<int> insertatbottom(IterableStack<int> st,int value){
    if(st.empty()) {
        st.push(value);
        return st;
    };
    int temp = st.top();
    st.pop();
    insertatbottom(st,value);
    st.push(temp);
    return st;
}
IterableStack<int> reverse(IterableStack<int> st){
    if(st.empty) return st;
    int value = st.top();
    st.pop();
    st = insertatbottom(st,value);
    return st;

};

int main(void){
    IterableStack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    //5321
   for (int x : st.c) {
        cout << x << " ";
    }
    cout << "After ";
    st = reverse(st);
    for (int x : st.c) {
        cout << x << " ";
    }

    
}