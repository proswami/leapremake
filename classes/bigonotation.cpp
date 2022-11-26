#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int constant(int n){ //this function has a big O of O(n)
    for (int i = 0; i < n; i++){
        cout << i << " "; //this is a constant. an action that doesn't scale with input
    }
    cout << endl;
    return 1;
}

int quadratic(int n){ //this functiohn has a big O of O(n^2)
    for (int i = 0; i < n; i++){ //O(n)
        for (int v = 0; v < n; v++){ //O(n)
            cout << i << ", " << v << endl; //O(1) constant, that is excecuted n*n times
        }
    }
}

int cubic(int n) { //this function has a big O of O(n^3) 
    for (int i = 0; i < n; i++){ //O(n)
        for (int v = 0; v < n; v++){ //O(n)
            for (int x = 0; x < n; x ++){ //O(n)
                cout << i << ", " << v << endl; //O(1) constant, that is excecuted n*n*n times
            }      
        }
    }
}

void logarithmic(int n) { //this function has a big O of O(log n)
    if (n == 0){ cout << "done";
    }
    n = floor(n/2); 
    return logarithmic(n); //this action is called log n times. i.e. if n = 8, its called 3 times
}

int log2(int n){ //also has big O of O(log n)
    while (n>1){
        n = floor(n/2);
    }
    return 1;
}

void nLogN(int n){
    int y = n;
    while (n > 1){
        n = floor(n/2);
        for(int i = 1; i <= y; i++){
            cout << i;
        }
    }
}

int arr[1024];


bool binarySearch(int* list, int start, int end, int target){
    if (start > end){
        return false;
    }
    int midIndex = floor((start + end)/2);
    if (list[midIndex] == target) {
        return true;
    }
    if (list[midIndex] > target){
        return binarySearch(list,start,midIndex-1,target);
    } else {
        return binarySearch(list,midIndex+1, end,target);
    }
}

int main(){
   cout << binarySearch(arr,0,8,8);
}