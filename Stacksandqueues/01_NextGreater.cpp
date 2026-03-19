#include<bits/stdc++.h>
using namespace std;
 vector<int> nextLargerElement(vector<int>& arr) {
        vector<int> ans(arr.size(),-1);
        stack<int> st;
        for(int i = arr.size()-1 ; i >= 0 ; i--){
            int element = arr[i];
            while(!st.empty()){
                if(st.top() <= element){
                    st.pop();
                }else{
                    ans[i] = st.top();
                    break;
                }
            }
            st.push(arr[i]);
            
        }
        return ans;
    }

int main(){
    vector<int> arr = {4,5,2,10,8};
    vector<int> result = nextLargerElement(arr);
    for(int val : result){
        cout << val << " ";
    }
    
}