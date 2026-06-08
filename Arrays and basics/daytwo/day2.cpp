#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//find max subarray sum using kadanes algorithm
vector<int> kadanes(vector<int>&nums){
    int maximum = INT_MIN;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
       sum += nums[i];
       if(sum>maximum){
        maximum = sum;
       }
       if(sum<0){
        sum =0;
       }
    }
    return vector<int>{maximum};
}
// best time to buy and sell stock 
void buynsell(vector<int>&prices){
    int minprice = INT_MAX;
    int maxprofit =0;
    for(auto price: prices){
        if(price <minprice){
            minprice = price;
        }
        maxprofit = max(price - minprice , maxprofit);
    }
    cout << "Maximum profit: " << maxprofit << endl;
}
// sort an array of 0,1,2
vector<int>zeroonetwo(vector<int>&nums2){
    int low=0; 
    int high = nums2.size()-1;
    int mid=0;
    while(mid <= high) {

        if(nums2[mid] == 0) {
            swap(nums2[low], nums2[mid]);
            low++;
            mid++;
        }
        else if(nums2[mid] == 1) {
            mid++;
        }
        else {
            swap(nums2[mid], nums2[high]);
            high--;
        }
    }

    return nums2;
}
int main(){
    vector<int>nums= {-2,1,-3,4,-1,2,1,-5,4};
    vector<int>nums2 = {2,0,2,1,1,0,0,0,2,1};
    vector<int>prices = {7,1,5,3,6,4};
    buynsell(prices);
    vector<int>maxi = kadanes(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;
    cout << "Maximum sum: " << maxi[0] << endl;
    vector<int>dutchflag = zeroonetwo(nums2);
    for(auto num: dutchflag){
        cout << num << " ";
    }
    cout << endl;
}