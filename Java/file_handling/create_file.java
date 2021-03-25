// package file_handling;
import java.io.File;
import java.io.IOException;


public class create_file
{
        public static void main(String[] args)
    {
        // Java Program to create a file
        try
        {
            // Create file object 
            File obj = new File("somename.txt");

            // Create a file
            if(obj.createNewFile())
            {
                System.out.println("File is created " + obj.getName());
            }

            // File exists
            else
            {
                System.out.println("File already exists");
            }
        }
        catch (IOException e)
        {
            System.out.println("IO Exception occured");
            System.out.println(e.getStackTrace());
            System.out.println(e.getMessage());
        }
    }
}
