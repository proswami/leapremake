#include <iostream>
#include <vector>
using namespace std;

bool canSum(int targetSum, vector <int> numbers){
    if (targetSum == 0) {
        return true;
    }
    if (targetSum < 0) {
        return false;
    }
    for (int i = 0; i < numbers.size(); i ++){
        int remainder = targetSum - numbers[i];
        if (canSum(remainder, numbers) == true){
            return true;
        }
    }
    return false;
}

vector<int> howSum(int targetSum, vector<int> numbers){
    if (targetSum == 0){ vector<int> v; return v; }
    if (targetSum < 0){ NULL; }

    for (int i = 0; i <= numbers.size(); i++){
        int remainder = targetSum - numbers[i];
        vector<int> remainderResult = howSum(remainder, numbers);
    }
}