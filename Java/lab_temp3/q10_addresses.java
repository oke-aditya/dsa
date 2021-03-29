// package lab_temp3;

class Employee
{
    String empid, name;

    public Employee(String empid, String name)
    {
        this.empid = empid;
        this.name = name;
    }

    public void display_details()
    {
        System.out.println(this.empid + " " + this.name + " ");
    }

    class Address
    {
        String street, city, district, state, country, zipcode;

        public Address(String street, String city, String district, String state, String country, String zipcode)
        {
            this.street = street;
            this.city = city;
            this.district = district;
            this.state = state;
            this.country = country;
            this.zipcode = zipcode;
        }

        public void display_add()
        {
            System.out.println(" " + this.street + " " + this.city + " " +
                              this.district + " " + this.state + " " +
                              this.country + " " + this.zipcode);
        }

    }

}

public class q10_addresses
{
    public static void main(String[] args)
    {
        Employee e = new Employee("101", "oke");

        e.display_details();

        Employee.Address add1 = e.new Address("park street", "Menlo", "Cali", "CA", "USA", "001");
        Employee.Address add2 = e.new Address("Home", "Parc de Pra", "Paris", "MA", "FRA", "002");
        
        add1.display_add();
        add2.display_add();

    }    
}
