#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// find missing and repeating number in an array
void findmissingandrepeating(vector<int>&nums){
    int n = nums.size();
    int hash[n+1]={0};
    for(int i=0; i<n; i++){
        hash[nums[i]]++;

    }
    int missing = -1 , repeating =-1;
    for(int i=0; i<n; i++){
        if(hash[i]==0){
            missing = i;
        }        if(hash[i]>1){
            repeating = i;
        }
    }
    cout << "Missing: " << missing << ", Repeating: " << repeating << endl;
}
// find the duplicate numbver
void findduplicate(vector<int>&nums){
    unordered_set<int>st;
    for(auto num:nums){
        if(st.find(num)!=st.end()){
            cout << num << " ";
        }
        st.insert(num);
    }
   
}

//count inversion in an array 
int merge(vector<int> &arr, int low, int mid, int high) {
  
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;

    // Merge elements in sorted order and count inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // All remaining left elements are inversions
            right++;
        }
    }

    // If left half still has elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If right half still has elements
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    // Return inversion count
    return cnt;
}

// Merge sort function that counts inversions
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}

// Function to get number of inversions
int numberOfInversions(vector<int>& arr, int n) {
    return mergeSort(arr, 0, n - 1);
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10,2,4};
    findduplicate(arr);
    int low =0;
    int high = arr.size()-1;
    int mid = low + (high - low) / 2;
    int inversions = numberOfInversions(arr, arr.size());
    cout << "Number of inversions: " << inversions << endl;
    vector<int>nums ={1, 2, 2, 4, 5,9,6,5};
    findmissingandrepeating(nums);

}