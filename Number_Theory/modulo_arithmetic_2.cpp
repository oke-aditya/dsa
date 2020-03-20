#include<iostream>
using namespace std;

/*

Modulo Arithmetic introduction

a and b are congruent to each other under modulo N, if they leave same remainder
when divided by N.

E.g

13 cong 41 (mod 7)
13 mod 7 = 6
41 mod 7 = 6


Working  with multiplication

(13 * 4) % 7 = 3
(41 * 4) % 7 = 3

Working with addition.

(13 + 4) % 7 = 3
(41 + 4) % 7 = 3

E.g.
(13 + 35 + 5) % 7 = 53 % 7 = 4
= (13 % 7 + 35 % 7 + 5 % 7) % 7
= (6 + 0 + 5) % 7
= 11 % 7 = 4

Working with division
We use modulo multiplicative inverse

if a cong b  (mod N)
then
a - b is divisible by N

Hence a = N * k + b
also b = N * k + a

E.g. 13 and 41 are congruent
Hence 41 - 13 = 28 is divisible by 7

Working with equations

if a * b = c

Useful when we have to calculate very long integer values.

then (a % N * b % N) % (N) == c % N

E.g. 13 * 9 = 117
then ((13 % 5) * (9 % 5)) % 5 = (117 % 5)

=> (3 * 4) % 5 = 2
=> 2 == 2

*/

int main()
{
    std::cout << "Hello" << '\n';
    return(0);
}
