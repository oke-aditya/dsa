// Variadic templates are template that take a
// variable number of arguments.
// Variadic function templates are functions which can take multiple number of arguments.

// Syntax for a variadic function template: :

//     template(typename arg, typename... args)
//     return_type function_name(arg var1, args... var2)

// Note :, typename arg, typename... args must be
// inside angular brackets. 

// https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/

#include<bits/stdc++.h>
using namespace std;

// Let’s start by implementing a variadic sum – it’ll take a bunch of arguments,
// and just attempt to add them all up. We’ll assume that the function returns a
// double for now, although in practice you’d probably like the result to
// depend on the input types (e.g. adding two ints should probably return an int).

// When it comes to handling variadic functions, you can’t
// think in the standard ‘iterative’ C++ style. You need
// to write such functions recursively – with a ‘base’
// case, and a ‘recursive’ case that reduces, eventually,
// into a ‘base’ case. This implies a separate function for each case.

// Base case: Single number.

template <typename T>
double sum(T t)
{
    return t;
}

// The recursive case: we take a number, alongside
// some other numbers, and produce their sum.

// Think like
// template<typename t(1), typename ... t(n)>

template <typename T, typename ... Rest>
double sum(T t, Rest ... rest)
{
    return t + sum(rest...);
}

// We have our ‘base’ case, accepting one argument T, and our
// ‘recursive’ case, accepting one or more arguments T and Rest. (Recall that a template parameter pack can be empty!)

// How exactly does this work? Let’s trace what happens when
// we try to call, for example, sum(1.0, 2.0, 3.0).
// This is going to be a bit repetitive, but it’s worth it to walk through the process at least once.

// The compiler generates code for sum(1.0, 2.0, 3.0).
// There are two competing overloads for sum here: the base case,
// and the recursive case. Since we’re passing in three arguments,
// the base case does not apply (it only accepts a single argument), so we select the recursive case.

// Type deduction is performed – the compiler deduces T = double,
// and puts the rest in our parameter pack, with Rest = <double, double>.

// The compiler generates code for t + sum(rest...). It sees the
// recursive call to sum(rest...). Note the use of ... to ‘unpack’
// the template argument – this has the effect of transforming sum(rest...) to sum(2.0, 3.0).

// The compiler generates code for sum(2.0, 3.0). As in the first case,
// there are two competing overloads: the base case, and the recursive
// case. The base case once again does not apply as we have more than one argument, so we select the recursive case.

// Type deduction is performed – the compiler deduces T = double,
// and Rest = <double>. It’s subtle, but notice that we have now
// unpacked our original <double, double> pack to T = double and Rest = <double>.

// The compiler generates code for t + sum(rest...). It sees
// the recursive call to sum(rest...) – this time, with
// sum(rest...) expanding to simply sum(3.0).

// The compiler generates code for sum(3.0). We have now finally
// hit our base case: the overload taking only T is more specialized,
// relative to the overload taking both T and Ts.... The compiler
// generates code for the base case, and we’re done with the recursion.


// Power sum template
template <typename T>
// Square a value
T square(T t)
{
    return (t * t);
}

// Add value
template <typename T>
double power_sum(T t)
{
    return t;
}

// Recusive case
template <typename T, typename ... Rest>
double power_sum(T t, Rest ... rest)
{
    return t + power_sum(square(rest) ...);

}

// ... operator will expand an entire expression, so for
// example, when it’s called with square(4.0, 6.0)...,
// the compiler expands this as square(4.0), square(6.0)

// power_sum(2.0, 4.0, 6.0);
// 2.0 + power_sum(square(rest)...);
// 2.0 + power_sum(square(4.0), square(6.0));
// 2.0 + (square(4.0) + power_sum(square(rest)...))
// 2.0 + (square(4.0) + power_sum(square(square(6.0)));
// 2.0 + (square(4.0) + (square(square(6.0))))

int main(int argc, char const *argv[])
{
    
    return 0;
}


