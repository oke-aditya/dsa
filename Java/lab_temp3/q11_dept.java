// package lab_temp3;

class Department
{
    String name, depid;

    public Department(String name, String depid)
    {
        this.name = name;
        this.depid = depid;
    }

    class Location
    {

        String locationid, location_name, longitude, latitude;

        public Location(String locationid, String location_name, String longitude, String latitude)
        {
            this.locationid = locationid;
            this.location_name = location_name;
            this.longitude = longitude;
            this.latitude = latitude;
        }
        
        public void display_loc()
        {
            System.out.println(this.locationid + " " + this.location_name +
                               " " + this.latitude + " " + this.longitude + " ");
        }
    }

    public void display_dept()
    {
        System.out.println(this.name + " " + this.depid);
    }

}

public class q11_dept
{
    public static void main(String[] args)
    {
        Department d = new Department("transport", "101");
        Department.Location l1 = d.new Location("110", "pune", "201", "203");
        d.display_dept();
        l1.display_loc();

    }

}
