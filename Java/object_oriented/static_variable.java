class Student
{
    String name, regno;
    int marks;

    static int count = 0;

    public Student(String name, String regno, int marks)
    {
        this.name = name;
        this.regno = regno;
        this.marks = marks;
        count += 1;   // we can't use this here.

    }

    public void display()
    {
        // Again we can't use this for count sicine ti is static
        System.out.println(this.name + " " + this.regno + " " + this.marks + " " + count);
    }

}

public class static_variable
{
    public static void main(String[] args)
    {
        Student s1 = new Student("abc", "23", 10);
        s1.display();

        Student s2 = new Student("abcd", "12", 10);
        s2.display();

        // This is also not allowed.
        // s1.count

        // But we can do. Since these properties are not private.
        System.out.println(s1.name + " " + s1.regno + " " + s1.marks);
        System.out.println(s2.name + " " + s2.regno + " " + s2.marks);

    }
}
