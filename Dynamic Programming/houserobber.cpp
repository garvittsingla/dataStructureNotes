#include "bits/stdc++.h"

using namespace std;
int dp(vector<int> &arr){
    vector<int> dparr(arr.size()+1,0);
    dparr[0] = 0; //no elements till now
    dparr[1]= arr[0]; //only one element
    for(int i = 2 ; i <=arr.size() ;i++){
        int take = arr[i-1];
        if(i > 1) take+= dparr[i-2];
        int nottake = dparr[i-1];
        dparr[i] = max(take,nottake);

    }
    return dparr[arr.size()];
}
int main(void){
    vector<int> arr1 = {2,-3,5,-8,7};
    vector<int> arr2 = {2,7,9,3,1};

    cout << dp(arr1) << endl;

}
