import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

class buffered_reader
{
    public static void main(String[] args)
    {
        try 
        {
            File obj = new File("dummy5.txt");

            // Buffered output stream
            FileOutputStream fout = new FileOutputStream(obj);
            BufferedOutputStream bout = new BufferedOutputStream(fout);
            bout.write(104);
            bout.close();
            fout.close();

            // Read from saved file
            FileInputStream fin = new FileInputStream(obj);
            BufferedInputStream bin = new BufferedInputStream(fin);
            int data = bin.read();
            System.out.println((char) data);

            bin.close();
            fin.close();

            
        
        }

        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }

    }
}