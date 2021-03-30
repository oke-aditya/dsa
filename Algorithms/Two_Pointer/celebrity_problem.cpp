// https://www.geeksforgeeks.org/the-celebrity-problem/
// A celebrity is a person who is known to all
// but does not know anyone at a party.
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to
// represent people at the party such that if
// an element of row i and column j
// is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.

// Input:
// MATRIX = { {0, 0, 1, 0},
//            {0, 0, 1, 0},
//            {0, 0, 0, 0},
//            {0, 0, 1, 0} }
// Output:id = 2
// Explanation: The person with ID 2 does not
// know anyone but everyone knows him

// Input:
// MATRIX = { {0, 0, 1, 0},
//            {0, 0, 1, 0},
//            {0, 1, 0, 0},
//            {0, 0, 1, 0} }
// Output: No celebrity
// Explanation: There is no celebrity.

// Solution: -
// Naive solution: -
// Traverse through the matrix.
// Find row which is all 0. That is this person knows no-one.
// He must be celebrity.

// Optimized solution: -
// Two pointer approach.
// If a knows b. Then a is not celebrity. B caan be a celebrity.
// Vice versa.
// If b is known a. Then b maybe a celebrity but a is not.

#include <bits/stdc++.h>
using namespace std;

#define N 4

bool knows(bool mat[N][N], int a, int b)
{
    // Checks if a knows b.
    return mat[a][b];
}

int find_celebrity(bool mat[N][N], int n)
{
    // First and last person.
    // These are two pointer, we will move them till
    // They don't become same. 
    int left = 0, right = n - 1;

    while(left < right)
    {
        if(knows(mat, left, right))
        {
            left += 1;
        }
        else
        {
            right -= 1;
        }
    }

    // This will end up giving us someone who is not known!
    // Left contains the person.
    // Now check if this person really is celebrity.

    for(int i=0; i<n; i++)
    {
        // If that person knows left or left knows know him.
        // Then he is not a celebrity.
        if((i != left) && (knows(mat, left, i) || (!knows(mat, i, left))))
        {
            return -1;
        }
    }
    return left;
}

int main(int argc, char const *argv[])
{
    bool MATRIX1[N][N] = {{0, 0, 1, 0},
                         {0, 0, 1, 0},
                         {0, 0, 0, 0},
                         {0, 0, 1, 0}};

    
    bool MATRIX2[N][N] = {{0, 0, 1, 0},
                         {0, 0, 1, 0},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0}};

    int id = find_celebrity(MATRIX1, N);
    if(id == -1)
    {
        cout<<"No celebrity"<<endl;
    }
    else
    {
        cout<<" Celeberity id = "<<id<<endl;
    }

    int id2 = find_celebrity(MATRIX2, N);
    if(id2 == -1)
    {
        cout<<"No celebrity"<<endl;
    }
    else
    {
        cout<<" Celeberity id = "<<id2<<endl;
    }

    return 0;
}
