/*
    Vấn đề này đã được Uber hỏi.

    Cho một mảng số nguyên, trả về một mảng mới sao cho mỗi phần tử ở chỉ mục i của mảng mới là
    tích của tất cả các số trong mảng ban đầu ngoại trừ phần tử ở i .

    Ví dụ: nếu đầu vào của chúng tôi là [1, 2, 3, 4, 5] thì đầu ra dự kiến ​​sẽ là [120, 60, 40, 30, 24]. 
    Nếu đầu vào của chúng tôi là [3, 2, 1] thì đầu ra dự kiến ​​sẽ là [2, 3, 6] .

    Theo dõi: nếu bạn không thể sử dụng phép chia thì sao?
*/

#include <iostream>
#include <vector>

using namespace std;
// Neu duoc dung phep chia thi tinh tich tat ca cac phan tu vaf chia cho vi tri i
// neu khong
vector<int> productExpectSelf(vector<int> &nums){
    int n = nums.size();

    vector<int> result(n, 1);

    int leftProduct = 1;
    for(int i = 0; i < n; i++){
        result[i] *= leftProduct;
        leftProduct *= nums[i];
    }

    int rightProduct = 1;
    for(int i = n - 1; i >= 0; i--){
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}

int main(){
    vector<int> input_array1 = {1, 2, 3, 4, 5};
    vector<int> output_array1 = productExpectSelf(input_array1);

    vector<int> input_array2 = {3, 2, 1};
    vector<int> output_array2 = productExpectSelf(input_array2);

    cout << "Output 1: ";
    for(int num : output_array1) cout << num << " ";
    cout << endl;

    cout << "Output 2: ";
    for(int num : output_array2) cout << num << " ";
    cout << endl;

    return 0;
}