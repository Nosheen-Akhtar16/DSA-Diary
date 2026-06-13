#include <bits/stdc++.h>
using namespace std;
//today we will be doing question regarding dp on arrays 
// approach to find unique paths in matrix
int uniquepath(int row, int col, vector<vector<int>>&dp)
{
    if(row == 0 && col == 0)
        return 1;

    if(row < 0 || col < 0)
        return 0;
    if (dp[row][col] != -1)  return dp[row][col];

    int up = uniquepath(row - 1, col, dp);
    int left = uniquepath(row, col - 1, dp);

    return dp[row][col] = up + left;
}
//longest consecutive sequence 

int longestConsecutiveSeq(vector<int>&nums){
    sort(nums.begin(), nums.end());
    int count = 1;
        int maxi = 1;
    for(int i=0; i<nums.size(); i++){
        
        if(nums[i+1]==nums[i]+1){
            count++;
            maxi = max(count , maxi);
        }else if(nums[i+1]!=nums[i]+1){
            count = 1;
        }
    }
    return maxi;
}

//two sum
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>mp;
    for(int i=0; i<nums.size(); i++){
        int second = target - nums[i];
        if(mp.find(second) != mp.end()){
            return {mp[second], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}
int main(){
    int m = 3, n = 7;
vector<vector<int>> dp(m, vector<int>(n, -1));

cout << uniquepath(m-1, n-1, dp);
cout<<endl;
    vector<int>nums = {1,2,3,4,5,8,5,4,9,8,3};
    int target = 9;
    vector<int>result = twoSum(nums, target);
    if(!result.empty()){
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    int longestSeq = longestConsecutiveSeq(nums);
    cout << "Longest consecutive sequence: " << longestSeq << endl;
}