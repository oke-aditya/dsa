package object_oriented;

class Outer
{
    // Some data members 
    public String var1;
    private String var2;
    protected String var3;
    public static int count = 1;

    // A simple constructor 
    public Outer()
    {
        this.var1 = "abc";
        this.var2 = "cde";
        this.var3 = "gef";
    }

    // Now we have a nested class inside the Outer
    // This is a non static class. Hence called as Inner class.
    class Nested
    {
        public String nested_var1;

        // We cannot create Static variables in nested class
        // public static String nested_var2;

        // We cannot instantiate (non static) Nested class without object of outer class.
        // So static declarations are not allowed.

        // Similarly we cannot have static method in nested (non static) class.

        // public static void print()
        // {
        //     System.out.println("A sitatic method");
        // }

        // A simple constructor for Nested class.
        public Nested()
        {
            nested_var1 = "xyz";
        }

        public void display()
        {
            // Here we will try to access outer class variables.
            // We can access all the variables. Private, public as well as Protected.
            System.out.println(var1 + var2 + var3);

            // Referring `this` will redirect to Nested class
            // This will cause error. this does not have access to Outer class.
            // It has access to inner class
            // System.out.println(this.var1 + this.var2 + this.var3);

            // Alternatively we can use this with Outer class context.
            System.out.println(Outer.this.var1 + Outer.this.var2 + Outer.this.var3);
        }
    }

    // We cannot use members of Nested class in Outer Class
    // A nonsense function.
    // public void display_nested()
    // {
    //     // Any of these will not work
    //     System.out.println(Nested.this.nested_var1);
    //     System.out.println(nested_var1);
    // }


}

public class nested_classes_intro
{
    public static void main(String[] args)
    {
        // Creating an object of outer class.
        Outer outobj = new Outer();

        // Creating an object of nested class.
        Outer.Nested nested_obj = outobj.new Nested();

        nested_obj.display();

    }    
}
