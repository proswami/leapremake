/*
Author: Gabriel Hudson
Course: CSCI-136
Instructor: Professor Yi
Assignment: smaller Lab1C

tells if the input year is a leap year or a common year
*/

#include <iostream>
using namespace std;

int main(){
    cout << "input year: " << endl;
    int year;
    cin >> year;
    if (year%4 != 0){  //year is not div by 4
        cout << "Common year" << endl;
    } else if (year%100 != 0){ //year is not div by 100
        cout << "Leap year" << endl;
    } else if (year%400 != 0){ //year is not div by 400
        cout << "Common year" << endl;
    } else {
        cout << "Leap year" << endl;
        cout << "Leap year" << endl;
    }
}

