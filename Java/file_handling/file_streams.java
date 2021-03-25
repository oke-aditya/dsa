// package file_handling;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.File;

public class file_streams
{
    public static void main(String[] args) throws IOException
    {
        File obj = new File("dummy.txt");

        System.out.println(obj.getName());

        FileInputStream fs = new FileInputStream(obj);

        int data = fs.read();
        System.out.println(data);

        // Read characters
        System.out.println((char) data);

        // Get file channel
        System.out.println(fs.getChannel());

        // Get file descriptor
        System.out.println(fs.getFD());


        while((data = fs.read()) != -1)
        {
            System.out.print((char) data);
        }

        System.out.println();

        

    }
}
