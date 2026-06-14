#include <bits/stdc++.h>
using namespace std;

//today we will be doing optimAL APPROACH OF LONGEST CONSECUTIVE SEQUENCE
int longestconsecutiveseq(vector<int>&nums){
    unordered_set<int>st;
    for(int i:nums){
        st.insert(i);
    }
    int longest = 1;
    for(int i=0; i<nums.size(); i++){
        if(st.find(nums[i]-1)== st.end()){
            int count = 1;
            int it = nums[i];
            while(st.find(it+1) != st.end()){
                count++;
                it++;
            }

            longest = max(longest, count);
        }
    }
    return longest;
}
//4 sum 
vector<vector<int>>fourSum(vector<int>nums, int target){
    vector<vector<int>>ans;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1] ) continue;
            for(int j=i+1; j<n ; j++){
                 if(j >0 && nums[j] == nums[j-1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while(left<right){
                long long sum = nums[i]+nums[j]+nums[left]+nums[right];

                if(sum == target ){
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                right--;

                while(left<right && nums[left] == nums[left-1]){
                    left++;
                }

                while(left<right && nums[right]==nums[right+1]){
                    right--;
                }
                }else if(sum<target){
                    left++;

                
            }else{
                right--;
            }
            }

            
            }
        
    }
    return ans;
    
}

int xorval(vector<int>&nums, int B){
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        int xorvall=0;

   for(int j=i; j<nums.size(); j++){
        xorvall ^= nums[j];

        if(xorvall == B){
            count++;
        }
    }
}
return count;
}

int main(){
    vector<int>nums = {5, 6, 7, 8, 9};
    int result = longestconsecutiveseq(nums);
    cout << "Length of the longest consecutive sequence: " << result << endl;

   
    vector<vector<int>> ans = fourSum(nums, 26);

    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }

    cout<< "solution : " << xorval(nums, 5) <<endl;
    return 0;
    return 0;
   

    
}