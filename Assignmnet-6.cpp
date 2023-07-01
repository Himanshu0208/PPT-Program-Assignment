
// 💡 Question 1

// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
// - s[i] == 'I' if perm[i] < perm[i + 1], and
// - s[i] == 'D' if perm[i] > perm[i + 1].
// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

// Example 1:
// Input: s = "IDID"
// Output: [0,4,1,3,2]

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        ans.reserve(s.length()+1);
        int begin = 0, end = s.length();
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == 'I') {
                ans.push_back(begin);
                begin++;
            } else {
                ans.push_back(end);
                end--;
            }
        }
        if(s[s.length()-1] == 'D') ans.push_back(end);
        else ans.push_back(begin);
        return ans;
    }
};
  
============================================================================================================================================================================================================


// 💡 Question 2

// You are given an m x n integer matrix matrix with the following two properties:
// - Each row is sorted in non-decreasing order.
// - The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.
// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
    }
};
===========================================================================================================================================================================================================

// 💡 Question 3
// Given an array of integers arr, return *true if and only if it is a valid mountain array*.
// Recall that arr is a mountain array if and only if:
// - arr.length >= 3
// - There exists some i with 0 < i < arr.length - 1 such that:
//     - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//     - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Example 1:
// Input: arr = [2,1]
// Output: false

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() > 1 && arr[0] > arr[1]) return false;
        int change = 0;
        for(int i = 1 ; i < arr.size()-1 ; i++) {
            if(arr[i] == arr[i+1] || arr[i] == arr[i-1]) return false;
            if((arr[i] > arr[i+1] && arr[i-1] < arr[i]) || (arr[i] < arr[i+1] && arr[i-1] > arr[i])) {
                change++;
                if(change > 1) return false;
            }
        }
        if(change == 1) return true;
        return false;
    }
};

==========================================================================================================================================================================================================


// 💡 Question 4
// Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.
  
// Example 1:
// Input: nums = [0,1]
// Output: 2

// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0, maxlen = 0;
        unordered_map<int,int> ump;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == 1) count++;
            else count--;
            if(ump.find(count) != ump.end()) {
                maxlen = max(maxlen , i-ump[count]);
            } else {
                ump[count] = i;
            }
        }
        return maxlen;
    }
};

==========================================================================================================================================================================================================

// 💡 Question 5
// The **product sum** of two equal-length arrays a and b is equal to the sum of a[i] * b[i] for all 0 <= i < a.length (**0-indexed**).
// - For example, if a = [1,2,3,4] and b = [5,2,3,1], the **product sum** would be 1*5 + 2*2 + 3*3 + 4*1 = 22.
// Given two arrays nums1 and nums2 of length n, return *the **minimum product sum** if you are allowed to **rearrange** the **order** of the elements in* nums1.

// Example 1:
// Input: nums1 = [5,3,4,2], nums2 = [4,2,2,5]
// Output: 40

// Explanation: We can rearrange nums1 to become [3,5,4,2]. The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.

long long int minValue(int A[], int B[], int n) {

    sort(A, A + n);
    sort(B, B + n);
   
    long long int result = 0;
    for (int i = 0; i < n; i++)
        result += (A[i] * B[n - i - 1]);
   
    return result;
}

==========================================================================================================================================================================================================4


// 💡 Question 6
// An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.
// Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

// Example 1:
// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]

// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].
  
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n= changed.size();
        if (n&1)return {};
        vector<int> ans;
        map<int,int> mp;
        sort(changed.begin(),changed.end(),greater<int>());
        for (int i=0; i<n; i++){
            if (mp.find(changed[i]*2)!=mp.end()){
                if (mp[changed[i]*2]>0){mp[changed[i]*2]--;}
                ans.push_back(changed[i]);
                if (mp[changed[i]*2]==0) {mp.erase(changed[i]*2);}
                }
            else {mp[changed[i]]++;}
        }
        for (auto val: mp){
            if (val.second!=0)return {}; 
        }
        return ans;
    }
};

============================================================================================================================================================================================================


// 💡 Question 7

// You are given an m x n integer matrix matrix with the following two properties:
// - Each row is sorted in non-decreasing order.
// - The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.
// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
    }
};

============================================================================================================================================================================================================


// 💡 Question 8

// Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

// Example 1:
// Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
// Output: [[7,0,0],[-7,0,3]]

vector<vector<int>> multiplyMatrices(vector<vector<int>> &mat1,
                                     vector<vector<int>> &mat2) {
    int n = mat1.size();
    int m = mat1[0].size();
    int p = mat2[0].size();

    // Resultant matrix to store product of the mat1 and mat2. 
    vector<vector<int>> mat3(n, vector<int>(p, 0));

    // Mutliplying mat1 and mat2 and storing result in mat3.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            int sum = 0;
            for (int k = 0; k < m; ++k) {
                sum = sum + mat1[i][k] * mat2[k][j];
            }

            mat3[i][j] = sum;
        }
    }

    return mat3;
}
