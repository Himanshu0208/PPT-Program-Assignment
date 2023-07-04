
💡 **Question 1**

Given two strings s1 and s2, return *the lowest **ASCII** sum of deleted characters to make two strings equal*.

**Example 1:**
**Input:** s1 = "sea", s2 = "eat"
**Output:** 231

**Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.


class Solution {
public:
    
    int solveMemo(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=s1[i]+solveMemo(s1,s2,i+1,j+1,dp);
        }else{
            ans=max(solveMemo(s1,s2,i+1,j,dp),solveMemo(s1,s2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
	int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            sum+=s1[i];
        }
        for(int i=0;i<m;i++){
            sum+=s2[i];
        }
        return sum-(2*(solveMemo(s1,s2,0,0,dp)));
    }
};
========================================================================================================================================================================================================

💡 **Question 2**

Given a string s containing only three types of characters: '(', ')' and '*', return true *if* s *is **valid***.
The following rules define a **valid** string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

**Example 1:**
**Input:** s = "()"
**Output:** true

class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, high = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            lo += s[i] == '(' ? 1 : -1;
           high += s[i] != ')' ? 1 : -1;
           if (high < 0) break;
           lo = max(lo,0);
        }

        return lo == 0;
    }
};


========================================================================================================================================================================================================

💡 **Question 3**

Given two strings word1 and word2, return *the minimum number of **steps** required to make* word1 *and* word2 *the same*.
In one **step**, you can delete exactly one character in either string.
  
**Example 1:**
**Input:** word1 = "sea", word2 = "eat"
**Output:** 2
  
**Explanation:** You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        return dfs(s);
    }

    TreeNode* dfs(string s) {
        if (s == "") return nullptr;
        int p = s.find("(");
        if (p == s.npos) return new TreeNode(stoi(s));
        TreeNode* root = new TreeNode(stoi(s.substr(0, p)));
        int start = p;
        int cnt = 0;
        for (int i = p; i < s.size(); ++i) {
            if (s[i] == '(')
                ++cnt;
            else if (s[i] == ')')
                --cnt;
            if (cnt == 0) {
                if (start == p) {
                    root->left = dfs(s.substr(start + 1, i - start - 1));
                    start = i + 1;
                } else
                    root->right = dfs(s.substr(start + 1, i - start - 1));
            }
        }
        return root;
    }
};

========================================================================================================================================================================================================

💡 **Question 4**

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
You always start to construct the **left** child node of the parent first if it exists.

**Input:** s = "4(2(3)(1))(6(5))"
**Output:** [4,2,6,3,1,5]

========================================================================================================================================================================================================

💡 **Question 5**

Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of **consecutive repeating characters** in chars:

- If the group's length is 1, append the character to s.
- Otherwise, append the character followed by the group's length.
  
The compressed string s **should not be returned separately**, but instead, be stored **in the input character array chars**. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done **modifying the input array,** return *the new length of the array*.
You must write an algorithm that uses only constant extra space.

**Example 1:**
**Input:** chars = ["a","a","b","b","c","c","c"]
**Output:** Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
  
**Explanation:**
The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";

        int count = 1;
        char prev = chars[0];
        for(int i = 1 ; i < chars.size() ; i++) {
            if(prev == chars[i]) count++;
            else {
                if(count == 1) {
                    ans += prev;
                } else {
                    ans += prev + to_string(count);
                }
                count = 1;
            }
            prev = chars[i];
        }

        if(count == 1) ans += prev;
        else ans += prev + to_string(count);

        int a = ans.size();

        for(int i = 0 ; i < a ; i++) {
            chars[i] = ans[i];
        }

        return a;
                
    }
};
========================================================================================================================================================================================================

💡 **Question 6**

Given two strings s and p, return *an array of all the start indices of* p*'s anagrams in* s. You may return the answer in **any order**.
An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**
**Input:** s = "cbaebabacd", p = "abc"
**Output:** [0,6]

**Explanation:**
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
  
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-p_len+1);
        }
        return ans;
    }
};
========================================================================================================================================================================================================

💡 **Question 7**

Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.

**Example 1:**
**Input:** s = "3[a]2[bc]"
**Output:** "aaabcbc"

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch: s){
            if(ch==']'){
                string stringtorepeat="";
                while(!st.empty()&& st.top()!="["){
                    string top=st.top();
                    stringtorepeat+=top;
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top()[0])){
                    string top=st.top();
                    num+=st.top();
                    st.pop();
                }
                
                reverse(num.begin(),num.end());
                int n=stoi(num);
            

                
                string currdecode="";
                while(n--){
                    currdecode+=stringtorepeat;
                }
                st.push(currdecode);
            }
            else 
            {
                string temp(1,ch);
                st.push(temp);
            }
        }
        
                string ans="";
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                return ans;
    }
};
========================================================================================================================================================================================================

💡 **Question 8**

Given two strings s and goal, return true *if you can swap two letters in* s *so the result is equal to* goal*, otherwise, return* false*.*
Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
- For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

**Example 1:**
**Input:** s = "ab", goal = "ba"
**Output:** true

**Explanation:** You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int count = 0;
        bool flag = false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i = 0; i < s.length() ; i++) {
            if(s[i] != goal[i]) count++;
            v1[s[i]-'a']++;
            v2[goal[i]-'a']++;
            if(v1[s[i]-'a'] >= 2) flag = true;
        }

        for(int i = 0 ; i < 26 ; i++) {
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return count == 2 || (count == 0 && flag);
    }
};
