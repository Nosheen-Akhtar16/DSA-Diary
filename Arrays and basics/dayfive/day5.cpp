#include <bits/stdc++.h>
using namespace std;
//power(x, n)
double power(double x, int n){
    double ans=1.0;
    long long power = n;
    if(power<0){
        power = -power;
    }
    if(power == 0){
        return 1;
    }
    if(x ==0){
        return 0;
    }
    while(power >0){
        if(power%2==0){
            x = x*x;
            power = power/2;

        }else{
            ans = ans*x;
            power = power-1;
        }
    }
    return ans;
}
int majority(vector<int>&nums){
    int cnt =0;
    int el;
    for (int i = 0; i < nums.size(); i++){
        if(cnt == 0){
            el = nums[i];
        }
        if(nums[i] == el){
            cnt++;
        }else{
            cnt--;
        }
    }
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] == el){
            cnt++;
        }
    }
    if(cnt > nums.size()/3){
        return el;
    }
    return -1;
}
// majority element in an array in
int majority2(vector<int>&nums2){
    int cnt =0;
    int cnt2 =0;
    int el1;
    int el2;
        for (int i = 0; i < nums2.size(); i++){
            if(cnt == 0 && nums2[i] != el2){
                el1 = nums2[i];
                cnt =1;
            }else if(cnt2 == 0 && nums2[i] != el1){
                el2 = nums2[i];
                cnt2 =1;
            }else if(nums2[i] == el1){
                cnt++;
            }else if(nums2[i] == el2){
                cnt2++;
            }else{
                cnt--;
                cnt2--;
            }
        }
    for(int i=0; i<nums2.size();i++){
        if(nums2[i]==el1){
            cnt++;

        }else if(nums2[i]==el2){
            cnt2++;
        }
    }
    if(cnt > nums2.size()/3){
    
        return  el1;;
    }
    if(cnt2 > nums2.size()/3){
       return el2;
    }
    return -1;
}
int searchin2d(vector<vector<int>>&matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();
    int low =0; int high = row*col-1;

    while(low<=high){
        int mid=low+(high - low)/2;
        int r = mid/col;
        int c = mid%col;
        if(matrix[r][c]==target){
            cout << r << " " << c << endl;
            return true;
        }

        if(matrix[r][c]<target){
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int>nums = {1,2,9,9,9,6,9,9,9,9};
    vector<int>nums2 = {1,2,3,4,5,6,7,8,9,10,2,4};
   
    int majorityElement = majority(nums);
    cout << "Majority element in the array: " << majorityElement << endl;
    int target = 9;
    if(searchin2d(matrix,target)){
        cout << "Element found in the matrix." << endl;
    }else {
        cout << "Element not found in the matrix." << endl;
    }

    int n = 8;
    double x= 299;
    double result = power(x, n);
    cout << x << " raised to the power of " << n << " is: " << result << endl;
    
    int majorityElement2 = majority2(nums2);
    cout << "Majority element 2 in the array: " << majorityElement2 << endl;
}