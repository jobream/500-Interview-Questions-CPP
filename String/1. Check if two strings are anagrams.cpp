
/*
Name : Aman jain
Date: 16-06-20

Question : Check if two strings are anagrams
Problem Link : https://leetcode.com/problems/valid-anagram/

Solution to leetcode :

*/


Method 1: O((n+m)log(n+m)) A simple approach would be to sort both the strings and if they become equal then they are anagrams





Method 2: O(n+m) (Hashing)



class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        if(s.length()!=t.length())
            return false;
        for(int i=0; i<s.length() ;i++){
            mp[s[i]]++;
        }
        
        for(int i=0; i<t.length() ; i++){
            mp[t[i]]--;
        }
        
    for(auto itr=mp.begin() ; itr!=mp.end() ;itr++){
        if(itr->second>0)
            return false;
    }
     return true;
        
    }
};