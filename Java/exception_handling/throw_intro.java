// The Java throw keyword is used to explicitly throw an exception.
// We can throw either checked or unchecked exception in java by throw keyword.
// The throw keyword is mainly used to throw custom exception

// Throw keyword
// Throws an excpetion
// Followed by an instance
// Used within a method
// Cannot throw multiple exceptions.

public class throw_intro
{
    public static void main(String[] args)
    {
        int age = 5;
        if(age < 21 || age > 27)
        {
            throw new ArithmeticException("Invalid age");
        }
    }
    
}

// Throws keyword

// The Java throws keyword is used to declare an exception.
// It gives an information to the programmer or caller
// method that there may occur an exception so it
// is better for the programmer or caller method to provide
// the exception handling code so that normal flow can be maintained.

// Throws is used to declare an exception
// Checked exceptions can be propogated.
// Can declare multiple exceptions.


