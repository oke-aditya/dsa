import java.util.Scanner;

// Throws keyword

// The Java throws keyword is used to declare an exception.
// It gives an information to the programmer or caller
// method that there may occur an exception so it
// is better for the programmer or caller method to provide
// the exception handling code so that normal flow can be maintained.

// Throws is used to declare an exception
// Checked exceptions can be propogated.
// Can declare multiple exceptions.


public class throws_intro
{

    public static void process_input() throws ArrayIndexOutOfBoundsException, ArithmeticException
    {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        if(b == 0)
        {
            throw new ArithmeticException("B cannot be 0");
        }

        if(a > 5)
        {
            throw new ArrayIndexOutOfBoundsException("Index cannot be > 5");
        }

    }

    public static void main(String[] args)
    {
        try
        {
            process_input();    
        }
        catch (ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e.getMessage());
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
