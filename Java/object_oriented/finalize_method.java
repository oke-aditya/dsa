package object_oriented;

public class finalize_method
{
    public static void main(String[] args) 
    {
        Student s2 = new Student("18bc", "sat", 100);

        // This works fine
        s2.display();

        // Now once we set to to null
        s2 = null;

        // This will raise a NullPointerExceptionError
        // s2.display();

        // To cleaup the s2 variable which is currently set to null
        // We have to do garabge cleaning, which is done automatically.
        // Cleanup grabge using System.gc
        System.gc();

        // This will internally invoke the finalize method in Student which always included.
        
        // Alternatively.
        // Runtime.getRuntime().gc();

        // Finalize method is not visible so we cannot call it.
        // s2.finalize();

    }
    
}
