import java.util.Scanner;

// package lab_temp3;

class Faculty
{
    String nane, empid;

    public Faculty(String nane, String empid)
    {
        this.nane = nane;
        this.empid = empid;
    }
    static class EligibleLeaves
    {
        static int el = 12, ml = 20, cl = 10;

        public void display_leave_category()
        {
            System.out.println(el);
            System.out.println(ml);
            System.out.println(cl);
        }
    }

    EligibleLeaves leaves = new EligibleLeaves();

}

public class q4_faculty_leaves
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        Faculty f_arr[] = new Faculty[3];

        for(int i=0; i<f_arr.length; i++)
        {
            String name = scanner.nextLine();
            String empid = scanner.nextLine();
            f_arr[i] = new Faculty(name, empid);
        }

        for(int i=0; i<f_arr.length; i++)
        {
            f_arr[i].leaves.display_leave_category();
        }
        scanner.close();
    }
}
