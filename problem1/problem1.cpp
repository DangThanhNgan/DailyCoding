/*
    This problem was recently asked by Google.

    Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

    For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

    Bonus: Can you do this in one pass?
*/
#include <iostream>

using namespace std;

bool checkArray(int *arr, int n, int k){
    for(int i = 0; i < n; i++){
        if(arr[i] == k) return true;
        for(int j = i + 1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(sum == k) return true;
        } 
    }
    return false;
}



int main(){
    int k;
    cin >> k;
    
    int arr[4] = {10, 5 ,3 ,7};
    if(checkArray(arr, 4, k) == true) cout << "True";
    else cout << "False";

    return 0;
}