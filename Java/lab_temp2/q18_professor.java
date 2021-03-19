abstract class person
{
    protected String name;
    protected String address;

    abstract public void display_professor();

    public person(String name, String address)
    {
        this.name = name;
        this.address = address;
    }
}

class faculty extends person
{
    public String empid;

    public faculty(String name, String address, String empid)
    {
        super(name, address);
        this.empid = empid;
    }

    @Override
    public void display_professor()
    {
        System.out.println(name + address + empid);
    }

}

class professor extends faculty
{
    public String cabinno;

    public professor(String name, String address, String empid, String cabinno)
    {
        super(name, address, empid);
        this.cabinno = cabinno;
    }

    @Override
    public void display_professor()
    {
        System.out.println(name + address + empid + cabinno);
    }
}


public class q18_professor
{
    public static void main(String[] args)
    {
        professor satish = new professor("satish", "vellore", "111", "a06");
        satish.display_professor();
    }
}
