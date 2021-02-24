package object_oriented;

public class overload_main
{
    // We can use the String args to invoke a command line argument from terminal.

    public static void main(String[] args)
    {
        for(int i=0; i<args.length; i++)
        {
            System.out.println(args[i]);
        }

        overload_main.main(2, 3);
    }

    // This is overloaded main method which will print sum of a and b.

    public static void main(int a, int b)
    {
        System.out.println((a + b));
    }
    
}
