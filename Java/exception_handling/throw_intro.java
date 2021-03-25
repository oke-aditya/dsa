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
    public static void validate(int age)
    {
        if(age < 18 || age > 27)
        {
            throw new ArithmeticException("Invalid Age");
        }
    }

    public static void main(String[] args)
    {
        int age = 5;
        
        try
        {
            validate(age);
        }
        catch (ArithmeticException e)
        {
            System.out.println(e.getMessage());
            System.out.println(e.getCause());
        }
        finally
        {
            System.out.println("For more information do not contact us");
        }
    }
}

