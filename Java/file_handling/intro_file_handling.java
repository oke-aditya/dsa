import java.io.File;
import java.io.IOException;

// package file_handling;

public class intro_file_handling
{
    public static void main(String[] args)
    {
        // Path can be relative or absolute.
        File obj = new File("file_handling/dummy.txt");
        System.out.println(obj.getName());
        System.out.println(obj.getAbsolutePath());
        
        // Boolean attributes for files.

        // obj.canRead();
        // obj.canWrite();
        // obj.canExecute();
        // obj.exists()

        // Print all files in directory

        File obj2 = new File(".");
        File names [] = obj2.listFiles();

        for(File f: names)
        {
            System.out.println(f.getName());
        }

    }
}
