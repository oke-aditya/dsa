// package object_oriented;

import java.util.*;

class Student1
{
    // Data member,
    String name, regno;
    
    public void addinfo()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter name");
        name = scanner.nextLine();

        System.out.println("Enter regno");
        regno = scanner.nextLine();

        if(validate(name, regno))
        {
            System.out.println("Good data");
        }
        else
        {
            System.out.println("Invalid data");
        }
        scanner.close();
    }

    public void viewinfo()
    {
        System.out.println(name + regno);
    }

    public boolean validate (String name, String regno)
    {
        if(name.isEmpty() || regno.isEmpty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

}

public class classes_intro
{
    public static void main(String[] args)
    {
        Student1 s1 = new Student1();
        s1.addinfo();
        s1.viewinfo();

        Student1 all_students[] = new Student1[2];
        for(int i=0; i<2; i++)
        {
            all_students[i] = new Student1();
            all_students[i].addinfo();
            // all_students[i].viewinfo();
        }

    }
}
