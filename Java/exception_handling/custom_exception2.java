import java.util.Scanner;

// package exception_handling;

// Inheriting from custom exceptions.

class CustomException extends Exception
{
    public CustomException(String s)
    {
        super(s);
    }
}

class Number13Exception extends CustomException
{
    public Number13Exception(String s)
    {
        super(s);
    }
}

class Number15Exception extends CustomException
{
    public Number15Exception(String s)
    {
        super(s);
    }
}

// A child class excpetion can be handled by a parent class.

public class custom_exception2
{

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        try
        {

            if(n == 13)
            {
                throw new Number13Exception("I don't like number 13");
            }

            if(n == 15)
            {
                throw new Number15Exception("I don't like number 15");
            }
        }

        catch (Exception e)
        {
            if(e instanceof Number13Exception)
            {
                System.out.println("I don't like number 13");
            }
            if(e instanceof Number15Exception)
            {
                System.out.println("I don't like number 15");
            }
        }

        // catch (Number15Exception e)
        // {
        //     System.out.println(e.getMessage());
        // }

        // catch (Number13Exception e)
        // {
        //     System.out.println(e.getMessage());
        // }

        catch (CustomException e)
        {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }
}
