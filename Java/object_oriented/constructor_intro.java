package object_oriented;

class Student
{
    String regno, name;
    int marks;

    // A very simple constructor.
    // public Student()
    // {
    //     regno = "18bce";
    //     name = "oke";
    //     marks = 20;
    // }

    // A parametrized constructor.
    // public Student(String regno_s, String name_s, int marks_s)
    // {
    //     regno = regno_s;
    //     name = name_s;
    //     marks = marks_s;
    // }

    // If we keep both the above, it is overloaded constructor.

    // A constructor using this keyword
    public Student(String regno, String name, int marks)
    {
        this.regno = regno;
        this.name = name;
        this.marks = marks;
    }

    public void display()
    {
        System.out.println(regno + " " + name + " " + marks);

    }
}

public class constructor_intro
{
    public static void main(String[] args)
    {
        // Default constucutor
        // Student s1 = new Student();
        // s1.display();

        // Paremetrized constructor
        // Student s2 = new Student("18bce030", "oke", 100);
        // s2.display();

        // Constructor using the this keyword
        Student s3 = new Student("18bce03", "oke", 100);
        s3.display();
        
    }

}
