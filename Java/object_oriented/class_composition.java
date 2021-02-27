package object_oriented;

// Composition is strong association between two classes.
// Denoted by has a relationship.
// Life Time of contained child object depends on parent.
// E.g. every employee has a student
// E.g. every car has an engine
// E.g. Car has a owner.


// E.g. Facutly has a dependent.

class Dependent
{
    String dependent_name, dependent_gender;

    public Dependent(String dependent_name, String dependent_gender)
    {
		this.dependent_name = dependent_name;
		this.dependent_gender = dependent_gender;
	}

    public void print_dependencies()
    {
        System.out.println(this.dependent_name + " " + this.dependent_gender);
    }
}

class Employee
{
    String name, emp_id;
    Dependent dep;

    public Employee(String name, String emp_id, String dep_name, String dep_gender)
    {
        this.name = name;
        this.emp_id = emp_id;
        dep = new Dependent(dep_name, dep_gender);
    }

    public void print_details()
    {
        System.out.println(this.name + " " + this.emp_id);
        dep.print_dependencies();
    }

}


public class class_composition
{
    public static void main(String[] args)
    {
        Employee e1 = new Employee("oke", "01", "okepa", "m");
        e1.print_details();
    }
}
