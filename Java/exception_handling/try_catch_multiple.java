// package exception_handling;

// Try catch for multiple blokcs

// Remember the rule

// The order of catch blocks should be from most specific to most general ones.
// i.e Sub classes of Exception must come first and super classes later.
// If you keep the super classes first and sub classes later,
// you will get compile time error : Unreachable Catch Block.

public class try_catch_multiple
{
    public static void main(String[] args)
    {
        int arr[] = {1, 2, 3, 4};
        int i = 5;
        int k = 3;
        int z = 0;
        try
        {
            int x = arr[i];
            // This won't run if exception will be raised from top.
            int l = k / z;
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Tried to access wrong array position");
        }
        catch(ArithmeticException e)
        {
            System.out.println("Check arithmetic operations");
        }
        catch (Exception e)
        {
            System.out.println("Some other exception");
        }
    }
}
