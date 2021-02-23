package object_oriented;

class SuperClass
{
    protected int a;

    public SuperClass(int input)
    {
        a = input;
        System.out.println("Super Class constructer is called");
    }
}

class SubClass extends SuperClass
{
    protected int b;
    public SubClass(int input1, int inp)
    {
        // Super keyword assings the input1 paramter to SuperClass parameter.
        super(input1);
        b = inp;
        System.out.println("Sub Class constructor is called");

    }
}


public class super_keyword
{
    public static void main(String[] args)
    {
        SubClass obj = new SubClass(123, 12);
        System.out.println(obj.a);
        System.out.println(obj.b);

    }
    
}
