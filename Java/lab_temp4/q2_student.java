import java.util.*;

class Student
{
    String Name, RegNo, PhoneNo;

    void getInfo(String Name, String RegNo, String PhoneNo)
    {
        this.Name = Name;
        this.RegNo = RegNo;
        this.PhoneNo = PhoneNo;
    }

    static void objsort(Student [] st_arr)
    {
        // Bubble sort the array
        Student temp;

        for (int k = 0; k < st_arr.length - 1; k++)
        {
            for (int j = 0; j < st_arr.length - k - 1; j++)
            {
                if ((st_arr[j].Name).compareTo(st_arr[j + 1].Name) > 0)
                {
                    temp = st_arr[j];
                    st_arr[j] = st_arr[j + 1];
                    st_arr[j + 1] = temp;
                }
            }
        }
    }

    static void displayInfo(Student [] st_arr)
    {
        for(int i=0; i<st_arr.length; i++)
        {
            System.out.println(st_arr[i].Name);
            System.out.println(st_arr[i].RegNo);
            System.out.println(st_arr[i].PhoneNo);
        }
    }
}

public class q2_student
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        try
        {
            Student s[] = new Student[3];
            for (int i = 0; i < s.length; i++)
            {
                s[i] = new Student();
            }
        
            for (int i = 0; i < s.length; i++)
            {
                String n = scanner.nextLine();
                String r = scanner.nextLine();
                String p = scanner.nextLine();
                s[i].getInfo(n, r, p);
            }
        
            Student.displayInfo(s);
            Student.objsort(s);
            Student.displayInfo(s);

        }
        catch (NullPointerException e)
        {
            System.out.println(e.getMessage());
        }
        catch (InputMismatchException m)
        {
            System.out.println(m.getMessage());
        }
        catch (ArrayIndexOutOfBoundsException t)
        {
            System.out.println(t.getMessage());
        }
        scanner.close();
    }
}
