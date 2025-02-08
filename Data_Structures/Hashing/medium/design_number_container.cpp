// // https://leetcode.com/problems/design-a-number-container-system/description/?

// Design a number container system that can do the following:

//     Insert or Replace a number at the given index in the system.
//     Return the smallest index for the given number in the system.

// Implement the NumberContainers class:

//     NumberContainers() Initializes the number container system.
//     void change(int index, int number) Fills the container at index with the number. 
//     If there is already a number at that index, replace it.
//     int find(int number) Returns the smallest index for the given number, or -1 if 
//     there is no index that is filled by number in the system.

 

// Example 1:

// Input
// ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
// [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
// Output
// [null, -1, null, null, null, null, 1, null, 2]




#include<bits/stdc++.h>
using namespace std;


class NumberContainers {
public:
    
    // useful to know number at all indices.
    unordered_map<int, set<int>> finder_map;
    unordered_map<int, int> index_map;
    
    NumberContainers() {
        // this->finder_map = mp_find;

        // // store at what index we have which number.
        // this->index_map  = mp_index;
    }
    
    void change(int index, int number) 
    {
        // if number is already present.
        if(this->index_map.find(index) != this->index_map.end())
        {
            // find the previous number are erase it
            int previous_number = this->index_map[index];
            
            // we need to update the finder map
            finder_map[previous_number].erase(index);

            // now there is no previous number left at all
            // we don't need to store this mapping.
            if(finder_map[previous_number].size() == 0)
            {
                finder_map.erase(previous_number);
            }

            // now update
            this->index_map[index] = number;
            finder_map[number].insert(index);

        }

        else
        {
            // this works for new number
            this->index_map[index] = number;
            // this number is at these indices.
            finder_map[number].insert(index);
        }
        
        return;
    }
    
    int find(int number) {

        // if we have it
        if(this->finder_map.find(number) != this->finder_map.end())
        {
            // set<int> all_indices = this->finder_map[number];
            // minimum occurence in set can be found like this.
            return *this->finder_map[number].begin();
        }

        else
        {
            return -1;
        }

    }
};

