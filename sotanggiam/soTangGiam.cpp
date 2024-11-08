/*
    Một số được gọi là số tăng giảm nếu các chữ số trong số này tạo thành một dãy số giảm dần 
    (số đứng sau luôn nhỏ hơn hoặc bằng số đứng trước) hoặc dãy số tăng dần 
    (số đứng sau luôn lớn hơn hoặc bằng số đứng trước). 
    Ví dụ:

    Các số tăng giảm: 7, 22, 6522, 4667, 9651, 7899, ...
    Các số không phải là số tăng giảm: 121, 486, 9878, ...
    Cho trước số nguyên n, bạn hãy viết hàm trả về số tăng giảm nhỏ nhất 
    mà lớn hơn hoặc bằng n.

    Ví dụ:

    Với n = 8 thì output là findNumber(n) = 8.
    Với n = 565 thì output là findNumber(n) = 566.
*/

#include <iostream>

using namespace std;

bool checkTang(int n){
     while (n > 9){
        int k = n % 10;
        n /= 10;
        if (k < n % 10) return 0;
    }
    return 1;
}

bool checkGiam(int n){
    while (n > 9) { // đảm bảo hàm while chừa số sau cùng
        int k = n % 10;
        n /= 10;
        if (k > n % 10) return 0;
    }
    return 1;
}

int findNumber(int n){
    if(checkTang(n) || checkGiam(n)) return n;
    else {
        n++;
        return findNumber(n);
    }
}
int main(){

    int n;
    cin >> n;
    
    cout << 19/10;

    //cout << findNumber(n);
    return 0;

}