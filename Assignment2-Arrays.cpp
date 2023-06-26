// 💡 Question 1
// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

// Example 1:
// Input: nums = [1,4,3,2]
// Output: 4

// Explanation: All possible pairings (ignoring the ordering of elements) are:

// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4

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


// 💡 Question 2
// Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 
// The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 
// Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

// Example 1:
// Input: candyType = [1,1,2,2,3,3]
// Output: 3

// Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
class Solution {
public:
    int min(int a, int b) {return a > b ? b : a;}

    int distributeCandies(vector<int>& candyType) {

        // Time => O(n)
        // Space => O(n)

        // unordered_set<int> s;
        // for(int i = 0 ;i < candyType.size() ; i++) {
        //     s.insert(candyType[i]);
        // }
        // return min(s.size(),candyType.size()/2);

        // But in c++ sortin was giving me me more fast results than this
        sort(candyType.begin(),candyType.end());
        int count = 1;
        int prev = candyType[0];

        for(int i = 1 ;i < candyType.size() ; i++) {
            if(candyType[i] != prev) count++;
            prev = candyType[i];
        }
        
        return min(count,candyType.size()/2);

    }
};

// 💡 Question 3
// We define a harmonious array as an array where the difference between its maximum value
// and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence
// among all its possible subsequences.

// A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5

// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        // Time => O(n)
        // Space => O(n)

        unordered_map<int,int> ump;
        for(int i = 0 ; i < nums.size() ; i++) ump[nums[i]]++;

        int ans = 0;
        for(pair<const int,int> &it : ump) {
            if(ump.find(it.first + 1) != ump.end()) {
                ans = max(ans,ump[it.first]+ump[it.first+1]);
            }
        }
        return ans;
    }
};

// 💡 Question 4
// You have a long flowerbed in which some of the plots are planted, and some are not.
// However, flowers cannot be planted in adjacent plots.
// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true

class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        
        // Time => O(n)
        // Space => O(1)

        int size = arr.size();

        // Handling some of the Exceptional cases
        if(size >= 2) {
            if(arr[0] == arr[1] && arr[0]== 0) {
                arr[0] = 1;
                n--;
            }

            if(arr[size-1] == arr[size-2] && arr[size-1] == 0) {
                arr[size-1] = 1;
                n--;
            }
        } else {
            if(arr[0] == 0) n--;
        }

        // if n plants planted by exceptional cases then don't go furthur
        if(n <= 0) return true;
 
        // if n plants are not planted by exceptional cases then go furthur
        int con = 0;
        for(int i = 1 ; i < size ; i++) {
            if(arr[i-1] == arr[i] && arr[i] == 0) {
                con++;
            } else {
                con++;
                if(con >= 3) n = n - (((con-3)/2) + 1);
                con = 0;
                if(n <= 0) return true;
            }
        }

        return n <= 0;
    }
};

// 💡 Question 5
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:
// Input: nums = [1,2,3]
// Output: 6

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        // T.C => O(n)
        // S.C => O(1)

        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN , max3 = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if(nums[i] < min2) {
                min2 = nums[i];
            }
            if(nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] > max3) {
                max3 = nums[i];
            }
        }

        return max(min1*min2*max1 , max1*max2*max3);
    }
};

// 💡 Question 6
// Given an array of integers nums which is sorted in ascending order, and an integer target,
// write a function to search target in nums. If target exists, then return its index. Otherwise,
// return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4

// Explanation: 9 exists in nums and its index is 4

class Solution {
public:
    int search(vector<int>& nums, int target) {
      
        // Time => O(log n)
        // Space => O(1)
      
        int s = 0 , e = nums.size()-1 , m = 0;
        while(s <= e){
            m = (s+e)/2;
            if(nums[m] == target) return m;
            else if(nums[m] > target) e = m-1;
            else s = m + 1;
        }
        return -1;
    }
};

//💡 Question 7
// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
// monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        // Time Complexity => O(n)
        // Space Complexity => O(1)

        if(nums.size() <= 2) return true;
        int a = -1;
        for(int i = 0 ; i < nums.size()-1 ; i++) {
            if(nums[i] == nums[i+1]) continue;
            else {
                if(a == -1) a = (bool)(nums[i] > nums[i+1]);
                else if ((nums[i] > nums[i+1]) != a) return false;
            }
        } 
        return true;
    }
};

// 💡 Question 8
// You are given an integer array nums and an integer k.

// In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

// The score of nums is the difference between the maximum and minimum elements in nums.

// Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

// Example 1:
// Input: nums = [1], k = 0
// Output: 0

// Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {

        // Time => O(n)
        // Space => O(1)

        if(nums.size() == 1) return 0;
        int min1 = nums[0], max1 = nums[0];

        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] > max1) max1 = nums[i];
            if(nums[i] < min1) min1 = nums[i];
        }

        if(max1-min1 <= 2*k) return 0;
        return max1-min1 - 2*k;
    }
};
