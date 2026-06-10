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
// merge overlapping subinterval 
//in this question we are given a vector of vector of integers and we have to merge the overlapping 
//intervals and return the merged intervals in sorted order
vector<vector<int>>mergeoverlap(vector<vector<int>>&intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;
    for(int i=0; i<intervals.size(); i++){
        if(ans.empty()|| intervals[i][0]>ans.back()[1]){
            ans.push_back(intervals[i]);
        }else {
            ans.back()[1]= max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

// merge 2 sorted array without extra space 

void mergesortedarray(vector<int > &arr1, vector<int>&arr2){
    int n = arr1.size();
    int m = arr2.size();
    int left =  n-1;
    int right =0;
    while(left>=0 && right <m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right ++;
        }else {
            break;
        }

    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}
int main(){
    vector<vector<int>>matrix = {{4,5,6},{9,8,6}, {1,3,9}};
    rotatedMatrix(matrix);
    for(auto row: matrix){
        for(auto val: row){
            cout<< val << " ";
        }
        cout<< endl;
    }
    vector<int>arr1 = {1, 5, 9, 10, 15, 20};
    vector<int>arr2 = {2, 3, 8, 13};
    mergesortedarray(arr1, arr2);
    for(auto x : arr1) cout << x << " ";
for(auto x : arr2) cout << x << " ";
    vector<vector<int>>intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>>mergedIntervals = mergeoverlap(intervals);
    for(const auto& interval : mergedIntervals){
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}