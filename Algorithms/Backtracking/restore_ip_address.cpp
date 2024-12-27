// Restore IP addresses
// A valid IP address consists of exactly four integers separated by single dots. 
// Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

//  For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and 
// "192.168@1.1" are invalid IP addresses.

// Given a string s containing only digits, return all possible valid IP addresses that can be 
// formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. 
// You may return the valid IP addresses in any order.

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]

#include<bits/stdc++.h>
using namespace std;

void print_vs(vector<string> vv)
{
    for(auto s: vv)
    {
        cout<<s<<", ";
    }
}

bool is_valid_ip(string s)
{   
    // segment length should be between 1 and 3
    if(s.size()>3 || s.size()==0) 
        return false;
    
    // segment should not start with 0, unless it is a single digit
    if(s.size()>1 && s[0]=='0')   
        return false; 
    
    // segment should not be greater than 255
    if(s.size() && stoi(s)>255) 
        return false; 
    
    return true;

}

// THis is actually bit trick with backtracking.
// Since we know the limited number of options, we can simply use 4 loops

vector<string> restoreIpAddresses(string s) 
{
    vector<string> res;
    int n = s.size();
    
    // Iterate over all possible ways to split the string into 4 parts
    for (int i = 1; i < n - 2 && i < 4; i++) { // First segment (1-3 characters)
        for (int j = i + 1; j < n - 1 && j < i + 4; j++) { // Second segment (1-3 characters)
            for (int k = j + 1; k < n && k < j + 4; k++) { // Third segment (1-3 characters)
                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i);
                string s3 = s.substr(j, k - j);
                string s4 = s.substr(k); // Remaining part for fourth segment
                
                // Check if all parts are valid
                if (is_valid_ip(s1) && is_valid_ip(s2) && is_valid_ip(s3) && is_valid_ip(s4)) {
                    res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }
    }
    
    return res;
    
}


int main(int argc, char const *argv[])
{
    auto res = restoreIpAddresses("25525511135");
    print_vs(res);

    return 0;
}


