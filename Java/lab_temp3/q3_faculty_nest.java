// package lab_temp3;

class Faculty
{
    String name, emp_id;

    public Faculty(String name, String emp_id)
    {
        this.name = name;
        this.emp_id = emp_id;
    }

    class Degree
    {
        String degree_name, awarded_year, awarded_by;

        public Degree(String degree_name, String awarded_year, String awarded_by)
        {
            this.degree_name = degree_name;
            this.awarded_year = awarded_year;
            this.awarded_by = awarded_by;
        }
        
        public void display_degree_details()
        {
            System.out.println(this.degree_name);
            System.out.println(this.awarded_year);
            System.out.println(this.awarded_by);
        }

        public void print_details(Degree degree_arr[])
        {
            for(Degree d : degree_arr)
            {
                System.out.println(d.degree_name + " " + d.awarded_year + " " + d.awarded_by);
            }
        }
    }

    public void display_faculty_data()
    {
        System.out.println(this.name);
        System.out.println(this.emp_id);
    }
}

public class q3_faculty_nest
{
    public static void main(String[] args)
    {
        Faculty f1 = new Faculty("satish", "101");
        Faculty.Degree degobj = f1.new Degree("Btech", "2010", "VIT");
        degobj.display_degree_details();

        Faculty.Degree degarr [] = new Faculty.Degree[2];
        degarr[0] = f1.new Degree("MTech", "2020", "MIT");
        degarr[1] = f1.new Degree("BTech", "2018", "BIT");

        f1.display_faculty_data();
        degobj.print_details(degarr);

    }
}
