package object_oriented;

// Abstract class gives partial implementation of object
// We cannot instantiate abstract class.
// We can only inherit and use in subclass.

// An Abstract class for any shape.

abstract class Shape
{
    protected double area;
    
    // This is not abstract method.
    public void print_area()
    {
        System.out.println(area);
    }

    // This is an abstract method in Shape class.
    // We do not implement this, instead just leave it. 
    public abstract double area();

}


// Now we simply inherit the abstract class.
class Square extends Shape
{
    public double side;

    // Constructor for the side.
    public Square(double side)
    {
        this.side = side;
    }

    // It is compulsory to implement the abstract methods.
    // So we need to implement area

    @Override
    public double area()
    {
        // We are acessing the area varaible of shape abstract class
        area = this.side * this.side;
        return (area);
    }
}

class Circle extends Shape
{
    public double radius;

    // Constructor for radius
    public Circle(double radius)
    {
        this.radius = radius;
    }

    @Override
    public double area()
    {
        // We are acessing the area varaible of shape abstract class
        area = Math.PI * this.radius * this.radius;
        return(area);
    }

}

public class abstract_classes_intro
{
    public static void main(String[] args)
    {
        // We cannot instantiate shape so
        // Definetely error
        // Shape shape = new Shape()

        Square sq = new Square(10.0);
        double area = sq.area();
        System.out.println(area);

        // We can still call the dsiplay method which is in Shape
        sq.print_area();

        Circle cc = new Circle(2.0);
        double area2 = cc.area();
        System.out.println(area2);

        // We can access the method present in Shape class too.
        cc.print_area();

        // We could create an array of Shape class
        Shape s[] = new Shape[2];

        // Each object is instantiated as it's own Class.
        s[0] = new Square(5.0);
        s[1] = new Circle(3.0);

        // This is an example of dynamic polymorphism.
        // Here `print_area()` works as area is calculated from respective array object.
        // This type of polymorphism works during run time not during compilation time.

        for(int i=0; i<s.length; i++)
        {
            double area_calc = s[i].area();
            s[i].print_area();
        }

    }
    
}
