#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// generate rotated matrix by 90 degreee

void rotatedMatrix(vector<vector<int>>&matrix){
    //first transpose the matrix and then reverse it ;
           int n = matrix.size();
           for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j>i){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
           }

           for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                reverse(matrix[i].begin(), matrix[i].end());
            }
           }
};

int main(){
    vector<vector<int>>matrix = {{4,5,6},{9,8,6}, {1,3,9}};
    rotatedMatrix(matrix);
    for(auto row: matrix){
        for(auto val: row){
            cout<< val << " ";
        }
        cout<< endl;
    }
    return 0;
}