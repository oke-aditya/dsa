// package object_oriented;

class Student
{
    private int marks;
    public String regno;
    protected String name;

    Student(String regno, String name, int marks)
    {
        this.regno = regno;
        this.name = name;
        this.marks = marks;
    }

    public void display()
    {
        System.out.println(this.regno + " " + this.name + " " + this.marks);

    }

}

public class access_specifiers
{
    public static void main(String[] args)
    {
        Student s1 = new Student("18bce0", "oke", 12);

        // We can do
        // s1.name, s1.regno

        // But we cannot do
        // s1.marks

        s1.display();

    }
    
}
