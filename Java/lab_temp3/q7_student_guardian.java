class Guardian
{
    String name, gender;

    public Guardian(String name, String gender)
    {
        this.name = name;
        this.gender = gender;
    }

    public void display()
    {
        System.out.println(this.name + " " + this.gender);
    }
}

class Student
{
    String name, id;
    Guardian g1, g2, g3;

    public Student(String name, String id, String g1_name, String g1_gender,
                   String g2_name, String g2_gender, String g3_name, String g3_gender)
    {
        this.name = name;
        this.id = id;
        this.g1 = new Guardian(g1_name, g1_gender);
        this.g2 = new Guardian(g2_name, g2_gender);
        this.g3 = new Guardian(g3_name, g3_gender);
    }

    public void display()
    {
        System.out.println(this.name + " " + this.id);
        this.g1.display();
        this.g2.display();
        this.g3.display();
    }
}


class q7_student_guardian
{
    public static void main(String[] args)
    {
        Student s1 = new Student("jim", "2", "mom", "F", "sister", "F", "son", "M");
        s1.display();

        Student s2 = new Student("oke", "1", "mom", "F", "dad", "M", "brother", "M");
        s2.display();

    }
}