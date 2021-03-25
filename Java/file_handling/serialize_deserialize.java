import java.io.*;

// Serialization converts the object to binary file.
// Deserialization converts the object file back to file object.

class Student implements Serializable
{
    String name, regno;

    public Student(String name, String regno)
    {
        this.name = name;
        this.regno = regno;
    }

    public void display_details()
    {
        System.out.println(this.name);
        System.out.println(this.regno);
    }

}

class serialize_deserialize
{
    public static void main(String[] args)
    {
        try
        {
            // Serializing to file.
            Student s = new Student("oke", "18bc");
            File obj = new File("saved_student.bin");

            ObjectOutputStream objout = new ObjectOutputStream(new FileOutputStream(obj));
            objout.writeObject(s);
            objout.close();

            // Deserializing from file.
            File obj2 = new File("saved_student.bin");
            ObjectInputStream objin = new ObjectInputStream(new FileInputStream(obj2));
            Student s2 = null;
            s2 = (Student) objin.readObject();
            objin.close();

            s2.display_details();

        }
        catch (Exception e)
        {
            System.out.println("Some error occured");
        }
    }
}