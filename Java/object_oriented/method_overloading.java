class SuperClass1
{
    protected int a;

    public SuperClass1()
    {
        System.out.println("Super Class constructer is called");
    }

    // Simple method overloading for function add.
    // Method Overloading happens at the compilation time.
    // We cannot overload variables. Only functions are allowerd.

    public void add(int inp1, int inp2)
    {
        System.out.println(inp1 + inp2);
    }

    public void add(int inp1, int inp2, int inp3, int inp4)
    {
        System.out.println(inp1 + inp2 + inp3 + inp4);
    }

    public void display()
    {
        System.out.println("Print from the Super class");
    }

}

class SubClass1 extends SuperClass1
{
    public SubClass1()
    {
        System.out.println("Sub Class constructor is called");
    }

    // Use @Override to make code clear.
    @Override
    public void display()
    {
        System.out.println("Print from the Sub Class");
    }

}


public class method_overloading
{
    public static void main(String[] args)
    {
        SuperClass1 obj1 = new SuperClass1();
        obj1.add(10, 30);
        obj1.add(10, 40, 20, 30);

        SubClass1 obj2 = new SubClass1();
        obj1.display();
        obj2.display();

    }
    
}
