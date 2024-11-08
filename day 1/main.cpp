#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//O(n^2)
bool checkEqual(vector<int> &arr, int k){
    int n = arr.size();
    for(int i = 0; i < n/2; i++){
        for(int j = i; j < n; j++){
            if(arr[i] == k - arr[j]) return true;
        }
    }
    return false;
}

//O(n)
bool innovation(vector<int> &arr, int k){
    unordered_set<int> result;
    for(int num : arr){
        int phandu = k - num;

        if(result.find(phandu) != result.end()){
            return true;
        }

        result.insert(num);
    }
    return false;
}

int main(){
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(15);
    arr.push_back(3);
    arr.push_back(7);
    int k = 19;

    if(checkEqual(arr, k)) cout << "True" << endl;
    else cout << "False" << endl;

    if(innovation(arr, k)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}