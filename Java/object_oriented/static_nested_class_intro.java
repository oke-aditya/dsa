// package object_oriented;

// package object_oriented;

// Static nested class
// It is a satic class nested withing an Outer Class.

class Faculty3
{
    private String name, empid;
    static int faculty_count;

    public Faculty3(String name, String empid)
    {
        this.name = name;
        this.empid = empid;
        faculty_count += 1;
    }

    // We Make a static nested nested class.
    // Static nested class is created since these properties are
    // common for Faculty.
    
    // We don't need instance of faculty to use Leaves.

    public static class Leaves
    {
        public static int el = 12, ml = 20, cl = 10;

        // A non static var
        public int var;

        // Constructor for var;
        public Leaves()
        {
            var = 1;
        }

        public static void print_leave_details()
        {
            System.out.println(ml + " " + cl + " " + el);
            
            // We Cannot access non static variables in static nested class.
            // Error !
            // System.out.println(Faculty3.this.name);

            // Can Acess static memebrs.
            // System.out.println(Faculty3.faculty_count);
        }
        
        // We can have a non static method in static nested class

        public void print_var()
        {
            System.out.println(var);
        }
    }

    // To access a non static method in static nested class we need to
    // instantiate a static nested class.

    Leaves l1 = new Leaves();

}

public class static_nested_class_intro
{
    public static void main(String[] args)
    {
        // We can easily acess using.
        // OuterClass.innerClass.StatiMethod
        Faculty3.Leaves.print_leave_details();

        Faculty3 f1 = new Faculty3("sat", "22");

        f1.l1.print_var();

    }
}
