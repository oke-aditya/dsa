package object_oriented;

// In this we will have a look at static nested class.

class Outer2
{
    // Some data members 
    public String var1;
    private String var2;
    protected String var3;
    public static int count = 1;

    // A simple constructor 
    public Outer2()
    {
        this.var1 = "abc";
        this.var2 = "cde";
        this.var3 = "gef";
    }

    // Now we have a nested class inside the Outer
    class Nested2
    {
        public String nested_var1;

        // A simple constructor for Nested2 class.
        public Nested2()
        {
            nested_var1 = "xyz";
        }

        public void display()
        {
            // Here we will try to access outer class variables.
            // We can access all the variables. Private, public as well as Protected.
            System.out.println(var1 + var2 + var3);

            // Referring `this` will redirect to Nested2 class
            // This will cause error. this does not have access to Outer class.
            // It has access to inner class
            // System.out.println(this.var1 + this.var2 + this.var3);

            // Alternatively we can use this with Outer class context.
            System.out.println(Outer2.this.var1 + Outer2.this.var2 + Outer2.this.var3);
        }
    }


}


public class nested_classes_intro2
{
    public static void main(String[] args)
    {
        // Creating an object of outer class.
        Outer2 outobj = new Outer2();

        // Creating an object of nested class.
        Outer2.Nested2 nested_obj = outobj.new Nested2();

        nested_obj.display();

    }    

}
