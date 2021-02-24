package object_oriented;

class Student3
{
    private static int count = 0;
    public String name, regno;
    public static String univeristy_name = "vellore VIT";

    // Note that since university_name is static variable
    // We cannot use it in constructor.

    Student3(String name, String regno)
    {
        this.name = name;
        this.regno = regno;
        count += 1;
    }

    // We can use the static variable in non static functions.
    // But we cannot use this with it. Instead we need to use the class name.

    public void print_details()
    {
        // System.out.println(this.regno + " " + this.name + " "  + Student3.univeristy_name);
        
        // Alternatively we can direct use static variable in class declarations.
        System.out.println(this.regno + " " + this.name + " "  + univeristy_name);

    }

    // Static method has access to static variables.
    // It does not have acess to non static class based methods.
    public static void student_count()
    {
        System.out.println(count);
        // Error
        // System.out.println(this.name);
    }

}

public class static_methods2
{
    public static void main(String[] args)
    {
        Student3 st3 = new Student3("oke", "18bc");
        Student3 st4 = new Student3("sat", "12bc");
        Student3 st5 = new Student3("ming", "11bc");
        
        st3.print_details();

        st4.print_details();

        st5.print_details();
        
        // We cannot do
        // st3.univeristy_name

        // But we can definetely do
        System.out.println(Student3.univeristy_name);

        // Static method can be used only with class not with object
        // This is right.
        Student3.student_count();

        // Wrong way
        // st3.student_count();

    }
}
