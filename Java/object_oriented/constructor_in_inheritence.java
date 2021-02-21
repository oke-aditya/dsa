class Superclass
{
    protected int a;

    public Superclass()
    {
        System.out.println("Super Class constructer is called");
    }
}

class Subclass extends Superclass
{
    private int b;
    public Subclass()
    {
        System.out.println("Sub Class constructor is called");

    }
}


public class constructor_in_inheritence
{
    public static void main(String[] args)
    {
        // Output will be
        // First the super class constructor is called.
        // Now the subclass consturctor is called.
        Subclass obj = new Subclass();

    }
}
