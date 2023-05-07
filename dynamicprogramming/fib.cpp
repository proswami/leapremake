#include <iostream>
using namespace std;

//this version of fib has a time complexity of O(2^n). this is unoptimized.
int fib(int n){ //find the nth term of the fibonacci sequence
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}

//memoization: an object where keys are arguments to function and the value will be the return value
//with memoization we can improve the runtime drastically
int term[1000];

int optfib(int n){
    if ( n <= 2 ) return 1; //base case. fib(2) and fib(1) returns 1

    if (term[n] != 0){ //if there exists a recorded value of fib(n), fib(n) is returned without running the function again
        return term[n];
    }

    term[n] = optfib(n-1) + optfib(n-2); //if n != 2 or 1, and there does not exist a value for fib(n) in the term map, add the value to term and return value
    return term[n];

}

int main(){
    cout << optfib(7);
}