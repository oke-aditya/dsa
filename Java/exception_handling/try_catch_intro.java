// package exception_handling;
// OTher exceptions are
// NullPointerException
// ArithmeticException
// NumberFormatException

// You can concatenate using |
// NullPointerException | ArithmeticException | NumberFormatException | ArrayIndexOutOfBoundsException

// Do not catch same exceptions repeatedly.

// catch(Exception e)

// catch(NumberFormatException e)

// will give compiler error.

// The order of catch blocks should be from most specific to most general ones. i.e
// Sub classes of Exception must come first and super classes later. If you keep the super
// classes first and sub classes later,
// you will get compile time error : Unreachable Catch Block

// Or use generic
// Exception


import java.util.*;

public class try_catch_intro
{
    public static void main(String[] args)
    {
        int x = 10;
        int y = 0;
        try
        {
            int z = x / y;
        }
        catch (Exception e)
        {
            System.out.println("Cannot divide by zero");
        }

        int arr[] = {1, 2, 3, 4};
        try
        {
            int n = arr[6];
        }

        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Array index out of bound");
        }
    }
}
