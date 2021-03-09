// package threading;

// Thread can be craeted in 2 ways
// extending the Thread class
// implementing the Runnable interface

import java.lang.Thread;

public class threading_intro
{
    public static void main(String[] args)
    {
        Thread th = Thread.currentThread();
        System.out.println("Current Thread : " + th);

        try
        {
            Thread.sleep(1);
        }
        catch (InterruptedException e)
        {
            System.out.println("Main thread Interrupted");
        }

    }
    
}
