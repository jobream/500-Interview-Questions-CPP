/*
Name : Aman Jain
Date : 30-6-2020

The trick lies in ASCII codes of 'A-Z' and 'a'-'z' 


'A'- 01000001  'a' - 01100001
'B'- 01000010  'b' - 01100010
.
.
.
.
.
.


we can easily find a letter's position [1-26] in 
the alphabet by taking its AND with ascii 31

for example,


('A' & 31) returns position 1
('c' & 31) returns position 3


*/




#include<bits/stdc++.h>
using namespace std;


int main(){
    char c;
    cin>>c;
    c= c & 31;
    cout<<char(c);
}





