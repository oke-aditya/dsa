// package lab_temp3;

import java.util.*;

class SuperClass
{
    int a;

    public SuperClass(int a)
    {
        System.out.println("Constructor for a called ");
        this.a = a;
    }

}

class SubClass1 extends SuperClass
{
    int b;

    public SubClass1(int a, int b)
    {
        super(a);
        System.out.println("Constructor for b called ");
        this.b = b;
    }

}

class SubClass2 extends SubClass1
{
    int c;
    public SubClass2(int a, int b, int c)
    {
        super(a, b);
        System.out.println("Constructor for c called ");
        this.c = c;
    }
}

public class q6_construct
{
    public static void main(String[] args)
    {
        SubClass2 sb2 = new SubClass2(1, 2, 3);
    }

}
