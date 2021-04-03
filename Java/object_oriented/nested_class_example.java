// package object_oriented;

class Faculty2
{
    private String name, empid;

    public Faculty2(String name, String empid)
    {
        this.name = name;
        this.empid = empid;
    }

    public class Degree
    {
        public String degree_name, awarded_year, awarded_by;

        // Constructor for inner class.
        Degree(String degree_name, String awarded_year, String awarded_by)
        {
            // Note that use of this here is for Degree. class !
            this.degree_name = degree_name;
            this.awarded_year = awarded_year;
            this.awarded_by = awarded_by;
        }

        public void print_details()
        {
            // We first access the outer class details.
            System.out.println(Faculty2.this.name + " " + Faculty2.this.empid);

            // We can easily acces the inner class details.
            System.out.println(this.degree_name + " " + this.awarded_year + " " + this.awarded_by);
        }

        // Print a degree array. Simple overloaded function.
        public void print_details(Degree degree_arr[])
        {
            for(Degree d : degree_arr)
            {
                System.out.println(d.degree_name + " " + d.awarded_year + " " + d.awarded_by);
            }
        }

    }
}

public class nested_class_example
{
    public static void main(String[] args)
    {
        // Create object for faculty the outer class.
        Faculty2 fac2 = new Faculty2("sat", "101");
       
        // Create object for faculty inner class.
        Faculty2.Degree degobj = fac2.new Degree("BTech", "2010", "VIT");
        degobj.print_details();

        // If we have an array of degrees
        // We fist create array of degrees.
        Faculty2.Degree degarr[] = new Faculty2.Degree[2];

        degarr[0] = fac2.new Degree("M.Tech", "2020", "MIT");
        degarr[1] = fac2.new Degree("B.Tech", "2018", "BIT");

        degobj.print_details(degarr);

    }
    
}
