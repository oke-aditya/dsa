// Getters and Settters

class Person
{
    int age;
    int id;

    // Constructor for it
    void set_age(int age)
    {
        this.age = age;
    }

    void set_id(int id)
    {
        this.id = id;
    }

    int get_age()
    {
        return this.age;
    }
    int get_id()
    {
        return this.id;
    }

}

class Emp extends Person
{
    String name;
    void set_name(String name)
    {
        this.name = name;
    }

    String get_name()
    {
        return this.name;
    }

}

public class get_set
{
    public static void main(String[] args)
    {
        Emp e = new Emp();
        e.set_age(20);
        e.set_id(101);
        e.set_name("Saran");

        System.out.println(e.get_name());
        System.out.println(e.get_age());
        System.out.println(e.get_id());
        
    }
    
}
