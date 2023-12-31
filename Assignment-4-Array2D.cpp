// 💡 Question 1
// Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

// Example 1:
// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
// Output: [1,5]

// Explanation: Only 1 and 5 appeared in the three arrays.

vector<int> array_intersection (int n1, int n2, int n3, vector<int> arr1, vector<int> arr2, vector<int> arr3) {
   // Write your code here
   int i = 0, j = 0, k = 0;
    vector<int> ans;
    while(i < n1 && j < n2 && k < n3) {
        if(arr1[i] == arr2[j] && arr1[i] == arr3[k]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        
        if(arr1[i] < arr2[j] || arr1[i] < arr3[k]) i++;
        if(arr2[j] < arr1[i] || arr2[j] < arr3[k]) j++;
        if(arr3[k] < arr1[i] || arr3[k] < arr2[j]) k++;
    }

    return ans;
}

=========================================================================================================================================================================================================

// 💡 Question 2
// Given two 0-indexed integer arrays nums1 and nums2, return a list* answer *of size* 2 *where:*
// - answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// - answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

// Note that the integers in the lists may be returned in **any** order.

// Example 1:
// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]

// Explanation:
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

==========================================================================================================================================================================================================

// 💡 **Question 3**
// Given a 2D integer array matrix, return *the **transpose** of* matrix.

// The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// **Example 1:**

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};
==========================================================================================================================================================================================================

// 💡 Question 4
// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is **maximized**. Return *the maximized sum*.

// Example 1:
// Input: nums = [1,4,3,2]
// Output: 4

// **Explanation:** All possible pairings (ignoring the ordering of elements) are:
// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4.

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i= 0 ; i< nums.size() ; i+=2) {
            ans += nums[i];
        }
        return ans;
    }
};

========================================================================================================================================================================================================

// 💡 **Question 5**
// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.
// Given the integer n, return *the number of **complete rows** of the staircase you will build*.

// Example 1:
// Input: n = 5
// Output: 2

// **Explanation:** Because the 3rd row is incomplete, we return 2.

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(pow(2*(long)n+0.25 , 0.5)-0.5);
    }
};

=========================================================================================================================================================================================================

// 💡 Question 6
// Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]

// **Explanation:** After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100]

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

=========================================================================================================================================================================================================

// 💡 **Question 7**
// You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.
// Count and return *the number of maximum integers in the matrix after performing all the operations*

// **Example 1:**
// **Input:** m = 3, n = 3, ops = [[2,2],[3,3]]
// **Output:** 4

// **Explanation:** The maximum integer in M is 2, and there are four of it in M. So return 4.

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int x = m , y = n;
        for(int i = 0 ; i < ops.size() ; i++) {
            x = min(ops[i][0],x);
            y = min(ops[i][1],y);
        }
        return x*y;
    }
};

=========================================================================================================================================================================================================

// 💡 **Question 8**

// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
// Return the array in the form* [x1,y1,x2,y2,...,xn,yn].

// **Example 1:**
// **Input:** nums = [2,5,1,3,4,7], n = 3
// **Output:** [2,3,5,4,1,7]
// **Explanation:** Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
   
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        ans.reserve(2*n);
        for(int i = 0; i < n ; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};
