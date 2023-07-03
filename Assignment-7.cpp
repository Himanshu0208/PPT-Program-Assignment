
💡 **Question 1**

Given two strings s and t, *determine if they are isomorphic*.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**
**Input:** s = "egg", t = "add"
**Output:** true

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> ump;

        for(int i = 0 ; i < s.size() ; i++) {
            if(ump.find(s[i]) == ump.end()) {
                ump[s[i]] = t[i];
                s[i] = t[i];
            } else {
                if(ump[s[i]] != t[i]) return false;
                s[i] = ump[s[i]];
            }
        }

        unordered_set<int> us;
        int count = 0;
        for(auto i : ump) {
            us.insert(i.second);
            count++;
        }

        return us.size() == count;
    }
};

=======================================================================================================================================================================================================
  
💡 **Question 2**

Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.
A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).

**Example 1:**
**Input:** num = "69"
**Output:** true

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> lut{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        for (int l = 0, r = num.size() - 1; l <= r; l++, r--) {
            if (lut.find(num[l]) == lut.end() || lut[num[l]] != num[r]) {
                return false;
            }
        }
        return true;
    }
};

=======================================================================================================================================================================================================
  
💡 **Question 3**

Given two non-negative integers, num1 and num2 represented as string, return *the sum of* num1 *and* num2 *as a string*.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

**Example 1:**
**Input:** num1 = "11", num2 = "123"
**Output:** "134"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length()-1 , j = num2.length()-1;
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j]-'0') + carry;
            carry = sum/10;
            sum = sum % 10;
            num1[i] = (char)(sum+'0');
            i--;
            j--;
        }

        while(j >= 0) {
            int sum = (num2[j]-'0') + carry;
            carry = sum/10;
            sum = sum % 10;
            num1.insert(0,1,(char)(sum+'0'));
            j--;
        }

        while(i >= 0) {
            int sum = (num1[i]-'0') + carry;
            carry = sum/10;
            sum = sum % 10;
            num1[i] = (char)(sum+'0');
            i--;
        }

        if(carry != 0) return (char)(carry+'0')+num1;

        return num1;
    }
};

=======================================================================================================================================================================================================

💡 **Question 4**

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**
**Input:** s = "Let's take LeetCode contest"
**Output:** "s'teL ekat edoCteeL tsetnoc"

class Solution {
public:
    string reverseWords(string s) {
        int j = -1;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                int start = j + 1;
                int end = i - 1;
                while (start < end) {
                    char temp = s[start];
                    s[start] = s[end];
                    s[end] = temp;
                    start++;
                    end--;
                }
                j = i;
            }
        }
        return s;
    };
};

=======================================================================================================================================================================================================

💡 **Question 5**

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

**Example 1:**
**Input:** s = "abcdefg", k = 2
**Output:**"bacdfeg"

class Solution {
public:
    string reverseStr(string S, int k) {
        int n = S.length();
        for(int i = 0 ; i < S.length() ; i += 2*k) {
            int s = i , e = min(i+k-1,n-1);
            while(s < e) {
                char temp = S[s];
                S[s++] = S[e];
                S[e--] = temp;
            }
        }

        return S;
    }
};

=======================================================================================================================================================================================================

💡 **Question 6**

Given two strings s and goal, return true *if and only if* s *can become* goal *after some number of **shifts** on* s.
A **shift** on s consists of moving the leftmost character of s to the rightmost position.

- For example, if s = "abcde", then it will be "bcdea" after one shift.

**Example 1:**
**Input:** s = "abcde", goal = "cdeab"
**Output:** true

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string check = s+s;
        return check.find(goal) != string::npos;
    }
};


=======================================================================================================================================================================================================

💡 **Question 7**

Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

**Example 1:**
**Input:** s = "ab#c", t = "ad#c"
**Output:** true

**Explanation:**
Both s and t become "ac".

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> a;
        vector<char> b;
        a.reserve(s.size());
        b.reserve(t.size());

        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '#' && a.size() != 0) {
                a.pop_back();
            } else if(s[i] != '#'){
                a.push_back(s[i]);
            }
        }

        for(int i = 0 ; i < t.size() ; i++) {
            if(t[i] == '#' && b.size() != 0) {
                b.pop_back();
            } else if(t[i] != '#') {
                b.push_back(t[i]);
            }
        }

        if(a.size() != b.size()) return false;

        for(int i = 0 ; i < a.size() ; i++) {
            if(a[i] != b[i]) return false;
        }   
        return true;
    }
};

=======================================================================================================================================================================================================

💡 **Question 8**

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

**Example 1:**

**Input:** coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
**Output:** true

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int dx = c[1][0]-c[0][0];
        int dy = c[1][1]-c[0][1];

        if(dx == 0) {
            for(vector<int> i : c) {
                if(i[0] == c[0][0]) continue;
                else return false;
            }
        } else if (dy == 0) {
            for(vector<int> i : c) {
                if(i[1] == c[0][1]) continue;
                else return false;
            }
        } else {
            float m = (float)dy/(float)dx;
            int inter = c[0][1] - m*c[0][0];
            for(vector<int> i : c) {
                if(i[1] == m*i[0] + inter) continue;
                else return false;
            }
        }
        

        return true;
    }
};
