// 💡 Question 1

// Convert 1D Array Into 2D Array
// You are given a **0-indexed** 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using **all** the elements from original.
// The elements from indices 0 to n - 1 (**inclusive**) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (**inclusive**) should form the second row of the constructed 2D array, and so on.
// Return *an* m x n *2D array constructed according to the above procedure, or an empty 2D array if it is impossible*.

// **Example 1:**
// **Input:** original = [1,2,3,4], m = 2, n = 2
// **Output:** [[1,2],[3,4]]

// **Explanation:** The constructed 2D array should contain 2 rows and 2 columns.
// The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
// The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(n*m != original.size()) return {};
        vector<vector<int>> ans(m, vector<int> (n,0));
        int k = 0;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                ans[i][j] = original[k];
                k++;
            }
        }

        return ans;
    }
};

==========================================================================================================================================================================================================

💡 **Question 2**

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.
Given the integer n, return *the number of **complete rows** of the staircase you will build*.
  
**Example 1:**
**Input:** n = 5
**Output:** 2

**Explanation:** Because the 3rd row is incomplete, we return 2.

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(pow(2*(long)n+0.25 , 0.5)-0.5);
    }
};

==========================================================================================================================================================================================================

// 💡 **Question 3**

// Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

// **Example 1:**
// **Input:** nums = [-4,-1,0,3,10]
// **Output:** [0,1,9,16,100]

// **Explanation:** After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        int i = e;
        vector<int> ans(e+1,0);

        while(s <= e) {
            int left_val = pow(nums[s],2);
            int right_val = pow(nums[e],2);

            if(left_val > right_val) {
                ans[i] = left_val;
                s++;
            } else {
                ans[i] = right_val;
                e--;
            }
            i--;
        }

        return ans;
    }
};

========================================================================================================================================================================================================

// 💡 **Question 4**

// Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

// - answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
// - answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

// **Note** that the integers in the lists may be returned in **any** order.

// **Example 1:**
// **Input:** nums1 = [1,2,3], nums2 = [2,4,6]
// **Output:** [[1,3],[4,6]]

// **Explanation:**
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

class Solution {
public:
    vector<int> helper(vector<int> &arr1, vector<int> &arr2) {
        unordered_set<int> in1;
        unordered_set<int> unique;

        for(int i: arr1) in1.insert(i);

        for(int i : arr2) if(in1.find(i) == in1.end()) unique.insert(i);
        return vector<int> (unique.begin(),unique.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {helper(nums2,nums1),helper(nums1,nums2)};
    }
};

=========================================================================================================================================================================================================

// 💡 **Question 5**

// Given two integer arrays arr1 and arr2, and the integer d, *return the distance value between the two arrays*.
// The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

// **Example 1:**
// **Input:** arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
// **Output:** 2

// **Explanation:**

// For arr1[0]=4 we have:
// |4-10|=6 > d=2
// |4-9|=5 > d=2
// |4-1|=3 > d=2
// |4-8|=4 > d=2

// For arr1[1]=5 we have:
// |5-10|=5 > d=2
// |5-9|=4 > d=2
// |5-1|=4 > d=2
// |5-8|=3 > d=2
  
// For arr1[2]=8 we have:
// **|8-10|=2 <= d=2**
// **|8-9|=1 <= d=2**
// |8-1|=7 > d=2
// **|8-8|=0 <= d=2**


=========================================================================================================================================================================================================

💡 **Question 6**

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

**Example 1:**
**Input:** nums = [4,3,2,7,8,2,3,1]
**Output:** [2,3]


class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        for(int i = 0 ; i < arr.size() ; i++) {
            if(arr[abs(arr[i])-1] < 0) {
                ans.push_back(abs(arr[i]));
            } else {
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            }
        }
        return ans;
    }
};
