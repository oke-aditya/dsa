// package exception_handling;

// User Defined Exception or custom exception is creating your own exception class and throws that exception using ‘throw’ keyword. 
// This can be done by extending the class Exception.
// All exceptions must be a child of Throwable.

// If you want to write a checked exception that is automatically enforced by the Handle or Declare Rule, you need to extend the Exception class.

// If you want to write a runtime exception, you need to extend the RuntimeException class.

// Checked Exception
// If the client is able to recover from the exception, make it a checked exception.
// To create a custom checked exception, extends java.lang.Exception.


// Unchecked Exception
// If the client cannot do anything to recover from the exception, make it an unchecked exception.
// To create a custom unchecked exception, extends java.lang.RuntimeException

import java.util.*;

class InvalidBloodDonorException extends Exception
{
    InvalidBloodDonorException(String s)
    {
        super(s);
    }
}


public class custom_exception
{
    static void validate(int age, int weight) throws InvalidBloodDonorException
    {
        if(age < 18 && weight > 15)
        {
            throw new InvalidBloodDonorException("Not Eligible");
        }
        else
        {
            System.out.println("Can Donate Blood");
        }
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int age = scanner.nextInt();
        int weight = scanner.nextInt();

        try
        {
            validate(age, weight);
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

    }
}
