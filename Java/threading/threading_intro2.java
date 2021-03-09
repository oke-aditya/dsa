import java.util.*;

// Thread can be craeted in 2 ways
// extending the Thread class
// implementing the Runnable interface

class SimpleThread extends Thread
{
    public void run()
    {
        System.out.println("Thread is running");
    }
}


public class threading_intro2
{
    public static void main(String[] args)
    {
        SimpleThread newt = new SimpleThread();
        newt.start();
        // Cannot restart the thread again once started
        // newt.start();
        newt.run();
        newt.run();

    }

}
