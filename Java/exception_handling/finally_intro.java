// package exception_handling;

// A finally block contains all the crucial statements that must be executed whether
// an exception occurs or not. The statements present in this block will always
// execute, regardless an exception occurs in the try block
// or not such as closing a connection, stream etc.
// Finally block is optional, as we have seen in previous tutorials that a
// try-catch block is sufficient for exception handling,
// however if you place a finally block then it will always run after the execution of try block.

// Cannot run Finally block when
// Death of thread
// System.exit() method and try block does not raise any error.
// Exception in finally block.

public class finally_intro
{
    public static void main(String[] args)
    {
        int x = 19, y = 0;
        try
        {
            int z = x / y;
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
        finally
        {
            System.out.println("finally block is executed");
        }

        // Continue the next code here.
    }
}
