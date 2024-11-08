/*  
    Vấn đề này đã được Stripe hỏi.

    Cho một mảng các số nguyên, tìm số nguyên dương đầu tiên còn thiếu trong thời gian tuyến tính và không gian không đổi. 
    Nói cách khác, tìm số nguyên dương thấp nhất không tồn tại trong mảng. Mảng có thể chứa các số trùng lặp và số âm.

    Ví dụ: đầu vào [3, 4, -1, 1] sẽ cho kết quả 2 . Đầu vào [1, 2, 0] sẽ cho 3 .

    Bạn có thể sửa đổi mảng đầu vào tại chỗ.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

int findMinInteger(int arr[], int size){
    unordered_set<int> hashSet;

    for(int i = 0; i < size; i++){
        hashSet.insert(arr[i]);
    }

    /*
        co 2 truong hop xay ra:
        - cac so trong arr da duoc dien day du tu 1->size thi result = size + 1 
        - Cac so tu 1 -> size chua duoc dien day du thi result: 1 -> size
    */
    for(int i = 1; i <= size + 1; i++){
        if(hashSet.find(i) == hashSet.end()){
            return i;
        }
    }

    // return -1 neu khong tim thay
    return -1;
}

int findMin(int arr[], int size){
    for(int i = 1; i <= size + 1; i++){
        bool found = false;
        for(int j = 0; j < size; j++){
            if(i == arr[j]) {
                found = true;
                break;
            }
        }
        if(!found) return i;
    }

    return -1;
}

int main(){
    int input1[] = {3, 4, -1, 1};
    int input2[] = {1, 2, 0};

    int size1 = sizeof(input1)/sizeof(input1[0]);
    int size2 = sizeof(input2)/sizeof(input2[0]);

    cout << findMinInteger(input1, size1) << endl;
    cout << findMinInteger(input2, size2) << endl;

    cout << findMin(input1, size1) << endl;
    cout << findMin(input2, size2) << endl;

    return 0;
}