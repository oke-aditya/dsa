// package file_handling;

import java.io.FileOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class file_stream2
{
    public static void main(String[] args) throws IOException
    {
        File obj = new File("dummy.txt");

        System.out.println(obj.getName());

        FileOutputStream fout = new FileOutputStream(obj);

        fout.write(104);
        fout.write(101);
        fout.write(108);
        fout.write(108);
        fout.write(111);
        fout.close();


        FileInputStream fin = new FileInputStream(obj);
        int data;

        while((data = fin.read()) != -1)
        {
            System.out.print((char) data);
        }

        System.out.println();

    }
}
