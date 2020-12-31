// There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed.
// The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise).
// In each step, a certain number of people are skipped and the next person is executed.
// The elimination proceeds around the circle (which is becoming smaller and smaller as the
// executed people are removed), until only the last person remains, who is given freedom.


// Given the total number of persons n and a
// number k which indicates that k-1 persons are skipped and kth person
// is killed in circle. The task is to choose
// the place in the initial circle so that you are the last one remaining and so survive.
// Consider if n = 5 and k = 2, then the safe position is 3.
// Firstly, the person at position 2 is killed,
// then person at position 4 is killed, then person at position 1 is
// killed. Finally, the person at position 5 is killed.
// So the person at position 3

// Solution: -
// After the first person (kth from beginning) is killed, n-1 persons are left.
// So we call josephus(n – 1, k) to get the position with n-1 persons.
// But the position returned by josephus(n – 1, k)
//  will consider the position starting from k%n + 1.
// So, we must make adjustments to the position returned by josephus(n – 1, k).
//   josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
//   josephus(1, k) = 1

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
    {
        // Only one person, so he is left.
        return 1;
    }
    // Else the problem has recurrence relation
    return ((josephus(n - 1, k) + k - 1)) % n - 1;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    int k = 2;

    return 0;
}
