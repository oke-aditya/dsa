import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;

class data_stream
{
    public static void main(String[] args) throws IOException
    {

        try
        {
            // Data output stream lets application read primitive data types.
            File obj = new File("dummy4.bin");
            FileOutputStream fout = new FileOutputStream(obj);
            DataOutputStream dout = new DataOutputStream(fout);
            
            dout.writeBoolean(true);
            dout.writeInt(0);
            dout.writeInt(2);
            dout.writeUTF("who are you?");

            fout.close();
            dout.close();

            FileInputStream fin = new FileInputStream(obj);
            DataInputStream din = new DataInputStream(fin);

            boolean f = din.readBoolean();
            int k = din.readInt();
            int j = din.readInt();
            String q = din.readUTF();

            System.out.println(f);
            System.out.println("" + k + " " + j + " ");
            System.out.println(q);

            fin.close();
            din.close();
        }

        catch (Exception e)
        {
            System.out.println(e.getMessage());
            System.out.println(e.getStackTrace());
        }

    }
}