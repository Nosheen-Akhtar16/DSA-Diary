#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//next permutation 
vector<int> nextPermutation(vector<int>& nums){
    vector<int> original = nums;
    vector<vector<int>> all;
    sort(nums.begin(), nums.end());
    do{
        all.push_back(nums);
    }while(next_permutation(nums.begin(), nums.end()));

    for(size_t i = 0; i < all.size(); i++){
        if(all[i] == original){
            if(i == all.size() - 1)
                return all[0];
            return all[i + 1];
        }
    }
    return original;
}
// pascal triangle 
void pascalTriangle(int n){
    vector<vector<int>> pascal(n);     
    for(int i=0; i<n; i++){
        vector<int>row;
        long long val = 1;
        for(int j=0; j<=i; j++){
            row.push_back(val);
            val = val * (i-j) / (j+1);
        }

        pascal.push_back(row);
    }
    for(auto row: pascal){
        for(auto val: row){
            cout<< val << " ";
        }
        cout<< endl;
    }
}
void setMatrix0(vector<vector<int>>& matrix) {
    int m = matrix.size();//row
    int n = matrix[0].size(); //col
    vector<int>row(m,false);
    vector<int>col(n,false);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==0){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
    }

    // time complexity would become O(m*n) 
    //space complexity would be O(m+n) bcz we are using 2 extra arrays;
}
int main(){
    // set all elements to zero
    vector<vector<int>> matrix={{1,3,0},{0,2,3},{5,6,3}};
    setMatrix0(matrix);
    for(auto row: matrix){
        for(auto val: row){
            cout<< val << " ";
        }
        cout<< endl;
    }
    // print pascal triangle
    cout << "Pascal Triangle:" << endl;
    pascalTriangle(5);


    cout<< "Next permutation:  " <<endl;
    vector<int>nums = {1,4,5};
    vector<int>next_perm = nextPermutation(nums);
    for(auto val: next_perm){
        cout<< val << " ";
    }
    cout<< endl;
}