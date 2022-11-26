using namespace std;
#include <iostream>

/*
pointers are symbolic representations of addresses

-they simulate call-by-references and create and manipulate dynamic data structures
-the main use of pointers is to iterate over elements in arrays or other data structures

the ADDRESS(&) of the variable is assigned to the pointer variable that POINTS(*) to the same data type

HOW TO USE A POINTER
    a. define pointer variable: *ptr
    b. assign address of variable to pinter with &: *ptr = &var
    c. access the value using the * operater to return the value at the address

THERE ARE 3 WAYS TO PASS C++ ARGUMENTS TO A FUNCTION
    call-by-value
    call-by-reference with a pointer argument
    call-by-reference with a reference argument

ADVANTAGES OF POINTERS
    pointers reduce code and improve performance. they retreive larger elements(treees, arrrays, structures, etc.)
    allow us to return multiple values from functions
    allow us to access a memory location in the computer's memory
*/

int var =10;
int* ptr = &var; //ptr is pointing to the address of var

//PASS-BY-VALUE
int square1(int n){
    //addy of n in square1() in this function is not the same as n1 in main()
    cout << "addy of n1 in square1(): " << &n << endl;

    //clone modified in function
    n *= n;
    return n;
}

//PASS-BY-REFERENCE WITH POINTER ARGUMENTS
int square2(int* n){
    //addy of n in square2() is the same as n2 in main()
    cout << "addy of n2 in square2() " << n << endl;

    //explicit de-referencing to get the value pointed to
    *n *= *n;
    return *n;
}

//PASS BY REFERENCE WITH REFERENCE ARGUMENTS
int square3(int &n){
    //addy of n in square3() is the same as n3 in main()
    cout << "addy of n3 in square3() " << &n << endl;

    //implicit de-referncing (without '*')
    n *= n;
    return n;
}


void print(char *C){
    while (*C != '\0'){
        cout << *C;
        C++;
    }
    cout << endl;
}

int main(){

    //cout << ptr << endl; //0x7ff6c0583010
    //cout << var << endl; //10
    //cout << *ptr << endl; //10
    
    //CALL-BY-VALUE
    int n1 = 8;
    cout << "addy of n1 in main(): " << &n1 << endl; //0xd26f5ff83c
    cout << "square of n1: " << square1(n1) << endl; //addy of n1 in square 1: 0xd26f5ff810  square of n1:64 ->
    //NOTICE: the addy of n1 in square is different from the addy of n1 in main

    cout << "No change in n1: " << n1 << endl; //n1 = 8. n1 remains unchanged after the function is called 
    //because the function only deals with the value of the variable, not the variable itself

    //CALL-BY-REFERENCE WITH POINTER ARGUMENTS
    int n2 = 8;
    cout << "addy of n2 in main(): " << &n2 << endl; //0xd26f5ff838, same as addy in square2()
    square2(&n2);
    cout << "Square of n2: " << n2 << endl; 
    cout << "Change reflected in n2: " << n2 << endl; //n2=64. n2 changes after the function is called because 
    //by calling by reference, the variable becomes the argument not just its value.

    //CALL-BY-REFERENCE WITH REFERENCE ARGUMENT
    int n3 = 8;
    cout << "addy of n3 in main(): " << &n3 << endl; //0xd26f5ff834 same as addy in square3()
    square3(n3);
    cout << "square of n3: " << n3 << endl;
    cout << "Change reflected in n3: " << n3 << endl;

    //POINTERS WITH ARRAYS
    int v[3] = {5, 10, 15};
    int*ptr; //declared pointer
    ptr = v; //set pointer to address of v[0]
    for (int i = 0; i < 3; i++){
        cout << "value at ptr = " << ptr << endl; //this iterates through the address of each element of the array
        cout << "value at *ptr= " << *ptr << endl; //this iterates through the3 values at each address the pointer points to
        //as it increments 
        ptr++;
    }

    char C[20] = "Hello";
    print(C);

    //TWO-DIMENTIONAL ARRAY
    int B[2][3]; //two one dimentional arrays of three elements each
    B[0]; //B[0] and B[1] are one dimentional arrays of three elements
    B[1];
    
    //int *p = B; no longer works because p is not pointing to an int, it is pointing to an array[3]
    
    int (*p)[3] = B; //p now points to a 1-D array of 3 integers

    //cout << B << " is the same as " << &B << endl; both would print the address of array B
    //cout << *B << " is the same as " << B[0] << endl; both would print the first element of array B

    //B+1 and &B[1] both return the address of the first element of B's second 2-D array
    //Printing &B[0][0], &B[0], *B and printing B or B[0] will print the address of the first element of B's first array b/c you cannot print a list
    //Printing *(B+1) would give the 


}

/*
EXTRA NOTES

in an example of a linked list, pointers serve as a link between elements


*/