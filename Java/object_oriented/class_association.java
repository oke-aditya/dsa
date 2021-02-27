package object_oriented;

// Two classes are in association relationship if
// Their objects are independent of each other and one object
// uses functionality of other object
// There is no ownership among objects.
// Life cycle of both the objects are independent of each other

class Student4
{
    String name, regno, phno;

    public Student4(String name, String regno, String phno)
    {
        this.name = name;
        this.regno = regno;
        this.phno = phno;
    }
    
    public String getInfo()
    {
        return (name + " " + regno + " " + phno + " ");
    }
}

class Professor
{
    public void viewProfile(Student4 s)
    {
        System.out.println(s.getInfo());

    }

}

public class class_association
{
    public static void main(String[] args)
    {
        Student4 st = new Student4("oke", "18bc", "102");
        Professor pf = new Professor();
        pf.viewProfile(st);
    }
    
}