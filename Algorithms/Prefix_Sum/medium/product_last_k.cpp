// https://leetcode.com/problems/product-of-the-last-k-numbers/description/?

// Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

// Implement the ProductOfNumbers class:
//     ProductOfNumbers() Initializes the object with an empty stream.
//     void add(int num) Appends the integer num to the stream.
//     int getProduct(int k) Returns the product of the last k numbers in the current list. 
// You can assume that always the current list has at least k numbers.
// The test cases are generated so that, at any time, 
// the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

// Example:

// Input
// ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
// [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

// Output
// [null,null,null,null,null,null,20,40,0,null,32]

// Trick here is to maintain prefix product.
// Reset it to 1 when we see a 0.
// Push back the product with number
// Kth procuct = last product / (n-k) product
// Ensure you track size when you reset such products.
//


#include<bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
public:

    vector<int> prefix_prod;
    int size = 0;

    ProductOfNumbers() {
        prefix_prod.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0)
        {
            prefix_prod = {1};
            size = 0;
        }
        else
        {
            prefix_prod.push_back(prefix_prod[size] * num);
            size += 1;
        }
    }
    
    int getProduct(int k) 
    {
        if(k > size)
        {
            return 0;
        }

        return prefix_prod[size] / prefix_prod[size - k];
    }
};

