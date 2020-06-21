
/*
Name : Aman jain
Date: 21-06-20

Question : Isomorphic strings
Problem Link : https://leetcode.com/problems/isomorphic-strings/

Solution to leetcode :

*/

Method 1 - Using hashing  (O(n))

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256]={0};
        int hash2[256]={0};
        for(int i=0 ; i<s.length() ;i++){
        
            if(hash[s[i]]==0)
                hash[s[i]]=t[i];
            
            else if(hash[s[i]]!=t[i])
                return false;
                   
            if(hash2[t[i]]==0)
                 hash2[t[i]]=s[i];
            
            else if(hash2[t[i]]!=s[i])
                return false;            
        }
        return true;
    }
};


