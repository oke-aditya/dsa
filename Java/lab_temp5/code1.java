import java.io.*;
import java.util.*;
import java.lang.*;

class code1
{
    public static void main(String args[])
    {
        Thread thr1 = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                System.out.println("Hello!!");
            }
        }
        );

        Thread thr2 = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                System.out.println("World!");
            }
        });

        thr1.start();
        thr2.start();

        try
        {
            thr1.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        try
        {
            thr2.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("End of main..");
    }
}
