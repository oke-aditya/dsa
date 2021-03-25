// package file_handling;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class file_stream3
{
    // Reading utf-16 encoding files.
    public static void main(String[] args) throws IOException
    {
        File obj = new File("dummy2.txt");
        FileInputStream fin = new FileInputStream(obj);
        InputStreamReader iread = new InputStreamReader(fin, "UTF-16");
        int data = iread.read();
        System.out.println((char) data);

        // Writing utf-16 characters to file

        File obj2 = new File("dummy3.txt");
        FileOutputStream fout = new FileOutputStream(obj2);
        OutputStreamWriter iwrite = new OutputStreamWriter(fout, "UTF-16");
        iwrite.write(1011);
        iwrite.write(1012);

    }
}
