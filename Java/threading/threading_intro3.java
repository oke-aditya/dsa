import java.util.*;

class SimpleThread2 extends Thread
{
    public void run()
    {
        try
        {
            System.out.println(Thread.currentThread());
        }
        catch (Exception e)
        {
            System.out.println("Error in Thread");
        }
    }
}

public class threading_intro3
{
    public static void main(String[] args)
    {
        // int n = 5;
        Scanner scnaner = new Scanner(System.in);
        int n = scnaner.nextInt();

        for(int i=0; i<n; i++)
        {
            SimpleThread2 th = new SimpleThread2();
            th.start();
        }
    }
    
}
