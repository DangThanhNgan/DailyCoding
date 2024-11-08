#include <iostream>
#include <vector>

using namespace std;

int dem_phan_tu(const vector<vector<int>>& ma_tran, int i1, int j1, int i2, int j2){
    int so_hang = ma_tran.size();
    int so_cot = ma_tran[0].size();

    int so_nho = ma_tran[i1][j1];
    int so_lon = ma_tran[i2][j2];

    int so_dem = 0;

    for(int i = 0; i < so_hang; i++){
        for(int j = 0; j < so_cot; j++){
            if(ma_tran[i][j] < so_nho || ma_tran[i][j] > so_lon){
               so_dem++;
            }
        }
    }
    return so_dem;
}

int main(){
    vector<vector<int>> ma_tran = {
        {1, 3, 7, 10, 15, 20},
        {2, 6, 9, 14, 22, 25},
        {3, 8, 10, 15, 25, 30},
        {10, 11, 12, 23, 30, 35},
        {20, 25, 30, 35, 40, 45}
    };

    int i1 = 1, j1 = 1, i2 = 3, j2 = 3;
    int ket_qua = dem_phan_tu(ma_tran, i1, j1, i2, j2);

    cout << ket_qua << endl;  // Kết quả: 15

    return 0;
}