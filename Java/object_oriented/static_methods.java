// package object_oriented;

class Student
{
    String name, regno;
    int marks;
    public static int count = 0;

    Student(String name, String regno, int marks)
    {
        this.name = name;
        this.regno = regno;
        this.marks = marks;
    }

    public static void sort(Student s[])
    {
        Student temp = new Student("temp", "temp", -1);

        for(int i=0; i<s.length-1; i++)
        {
            for(int j=0; j<s.length-i-1; j++)
            {
                if(s[j].marks > s[j+1].marks)
                {
                    temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                }
            }
        }
    }

    public void display()
    {
        System.out.println(this.regno + " " + this.name + " " + this.marks);

    }

}


public class static_methods
{
    // Sort an array of objects, based on
    // marks in ascending order.
    // Use static method in a class.

    public static void main(String[] args)
    {
        Student s[] = new Student[3];

        s[0] = new Student("abc", "18bce03", 17);
        s[1] = new Student("def", "18bce04", 12);
        s[2] = new Student("ghi", "18bce06", 14);

        for(int i=0; i<3; i++)
        {
            s[i].display();
        }

        System.out.println();
        Student.sort(s);

        for(int i=0; i<3; i++)
        {
            s[i].display();
        }
    }
    
}
