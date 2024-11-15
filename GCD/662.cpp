/*
    Given n numbers, find the greatest common denominator between them.

    For example, given the numbers [42, 56, 14], return 14

    Tim mau so chung lon nhat.
*/

/*
    gcd(a,b) = gcd(a+kb, b)
    
*/
#include <iostream>

// Hàm tính ước chung lớn nhất của hai số
int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {S
    int numbers[] = {42, 56, 14};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int result = numbers[0];
    for (int i = 1; i < n; ++i) {
        result = gcd(result, numbers[i]);
    }

    std::cout << "Ước chung lớn nhất: " << result << std::endl;

    return 0;
}