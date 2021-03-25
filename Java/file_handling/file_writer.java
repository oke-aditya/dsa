// package file_handling;

import java.io.FileWriter;
import java.io.IOException;

// File writer can read only utf-8 encoding data
// It cannot read utf-16 or other encodings.

public class file_writer
{
    public static void main(String[] args)
    {
        try
        {
            // Crreate fileWriter object
            FileWriter fwriter = new FileWriter("somename.txt");
            // Write content to file
            fwriter.write("Writing this line to the file");
            fwriter.close();
            System.out.println("Successfully wrote to the file");

        }
        catch (Exception e)
        {
            System.out.println("An error occured");
            System.out.println(e.getMessage());
            System.out.println(e.getStackTrace());
        }
    }
}
