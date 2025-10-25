#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n <=1) return n;
    int last = fibonacci(n-1);
    int secondlast = fibonacci(n-2);
    return last+secondlast;

}
int main(void){
    cout << fibonacci(4);
}