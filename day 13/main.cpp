/*
    Vấn đề này đã được Amazon hỏi.

    Cho một số nguyên k và một chuỗi s, hãy tìm độ dài của chuỗi con dài nhất chứa tối đa k ký tự riêng biệt.

    Ví dụ: cho s = "abcba" và k = 2, chuỗi con dài nhất có k ký tự riêng biệt là "bcb".
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
string longestSubstringWithKDistinctChars(string s, int k){
    if(k == 0 || s.empty()) return "Khong hop le";

    unordered_map<char, int> charCount;
    int maxLength = 0;
    int maxLeft = 0;
    int left = 0;
    int right = 0;

    while(right < s.length()){
        charCount[s[right]]++;

        while(charCount.size() > k){
            charCount[s[left]]--;
            if(charCount[s[left]] == 0) charCount.erase(s[left]);
            left++;
        }

        if(right - left + 1 > maxLength){
            maxLength = right - left + 1;
            maxLeft = left;
        }

        right++;
    }

    return s.substr(maxLeft, maxLength);

}
int main(){
    string input = "abcba";
    int  k = 2;

    cout << longestSubstringWithKDistinctChars(input, k) << endl;

    return 0;
}