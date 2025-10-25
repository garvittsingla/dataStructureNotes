#include <iostream>

void print(int n){
    if(n == 0) return; //Base case that tells when to terminate the recursion
    
    std::cout << "Hey i am a function \n";
    print(n-1); //Recurssive call 
}


int main(void){
    print(10); // calling function the first time
}