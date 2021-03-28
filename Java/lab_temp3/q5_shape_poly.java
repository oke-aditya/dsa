abstract class Shape
{
    protected double volume;
    public abstract double volume();

    public void print_volume()
    {
        System.out.println(volume);
    }
}

class Sphere extends Shape
{
    double radius;

    public Sphere(double radius)
    {
        this.radius = radius;
    }

    @Override
    public double volume()
    {
        volume = 4 * ((Math.PI * this.radius * this.radius * this.radius) / 3);
        return volume;
    }
}

class Cylinder extends Shape
{
    double radius, height;

    public Cylinder(double radius, double height)
    {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double volume()
    {
        volume = Math.PI * this.radius * this.radius * this.height;
        return volume;
    }

}

class Cone extends Shape
{
    double radius, height;

    public Cone(double radius, double height)
    {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double volume()
    {
        volume = (Math.PI * this.radius * this.radius * this.height) / 3;
        return volume;
    }
}

class Cube extends Shape
{
    double side;

    public Cube(double side) {
        this.side = side;
    }

    @Override
    public double volume()
    {
        volume = (this.side * this.side * this.side);
        return volume;
    }
}


public class q5_shape_poly
{

    public static void main(String[] args)
    {
        Cube cb = new Cube(10.0);
        double volume = cb.volume();
        cb.print_volume();

        Shape s[] = new Shape[3];
        s[0] = new Cylinder(2.0, 1.0);
        s[1] = new Cone(3.0, 1.0);
        s[2] = new Sphere(3.0);

        for(int i=0; i<s.length; i++)
        {
            double volume_calc = s[i].volume();
            s[i].print_volume();
        }
    }
}
