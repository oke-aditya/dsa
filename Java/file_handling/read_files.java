import java.util.Scanner;
import java.io.File;

// package file_handling;

// Note: There are many available classes in the Java API
// that can be used to read and write files in Java: FileReader, BufferedReader,
// Files, Scanner, FileInputStream, FileWriter, BufferedWriter, FileOutputStream, etc
//  Which one to use depends on the Java version you're working
// with and whether you need to read bytes or characters, and the size of the file/lines etc.

public class read_files
{
    public static void main(String[] args)
    {
        try {
            File obj = new File("somename.txt");
            Scanner scanner = new Scanner(obj);

            while(scanner.hasNextLine())
            {
                String data = scanner.nextLine();
                System.out.println(data);
            }

            scanner.close();
        
        }
        
        catch (Exception e)
        {
            System.out.println("An error occured");
            System.out.println(e.printStackTrace());
            System.out.println(e.getMessage());
        }
    }
}
