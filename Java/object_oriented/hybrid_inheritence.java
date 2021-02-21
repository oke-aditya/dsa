//              Class A
//  Class B                     Class C
//              Class D

// Hybrid Inheritance is a combination of both
// Single Inheritance and Multiple Inheritance
// but Hybrid Inheritance doesn’t support in java.

class A
{
    public void dispA()
    {
        System.out.println("Class A");
    }
}

interface B
{
    public void show();
}

interface C
{
    public void show();
}

class D extends A implements B, C
{
    public void show()
    {
        System.out.println("Cracker");
    }
    public void disp()
    {
        System.out.println("Coding");
    }
}


public class hybrid_inheritence
{
    public static void main(String[] args)
    {
        D d_obj = new D();
        d_obj.disp();
        d_obj.show();
    }
}
