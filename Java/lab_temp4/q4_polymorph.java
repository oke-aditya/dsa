import java.util.Scanner;

abstract class Shape
{
    int a;

    public Shape(int a)
    {
        this.a = a;
    }
    public abstract void computearea();
}

abstract class TwoDimensional extends Shape
{
    public TwoDimensional(int a)
    {
        super(a);
    }
    int x, y;
    public abstract void getLocation(int x,int y);
}


abstract class ThreeDimensional extends Shape
{
    public ThreeDimensional(int a)
    {
        super(a);
    }
    int x, y, z;
    public abstract void getLocation(int x,int y,int z);
}

class Circle extends TwoDimensional
{
    public Circle(int a)
    {
        super(a);
    }
    @Override
    public void getLocation(int x, int y)
    {
        System.out.println("2D Shape Circle");
    }
    @Override
    public void computearea()
    {
        double area = 3.14*a*a;
        System.out.println(area);
    }
}


class Square extends TwoDimensional
{
    public Square(int a)
    {
        super(a);
    }

    @Override
    public void getLocation(int x, int y)
    {
        System.out.println("2d Shape Square");
    }

    @Override
    public void computearea()
    {
        int area = a*a;
        System.out.println(area);
    }
}

class Sphere extends ThreeDimensional
{
    public Sphere(int a)
    {
    super(a);
    }
    @Override
    public void getLocation(int x, int y, int z)
    {
        System.out.println("3D Shape Sphere");
    }
    @Override
    public void computearea()
    {
        double area = 4*3.14*Math.pow(a, 2);
        System.out.println(area);
    }
}


class Cube extends ThreeDimensional
{
    public Cube(int a)
    {
        super(a);

    }
    @Override
    public void getLocation(int x, int y, int z)
    {
        System.out.println("3d Shape Cube");
    }

    @Override
    public void computearea()
    {
        double area = 6*Math.pow(a, 2);
        System.out.println(area);
    }
}

public class q4_polymorph
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        try
        {
            Shape s[] = new Shape[4];
            s[0] = new Circle(2);
            s[1] = new Square(3);
            s[2] = new Sphere(4);
            s[3] = new Cube(5);
            for(int i=0;i<4;i++)
            {
                s[i].computearea();
            }
        }
        catch(ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }
        catch(NullPointerException m)
        {
            System.out.println(m.getMessage());
        }
        scanner.close();
    }
}
