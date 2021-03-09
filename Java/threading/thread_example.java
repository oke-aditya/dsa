// package threading;

class SimpleThread5 extends Thread
{
    @Override
    public void run()
    {
        for(int i=1; i<=5; i++)
        {
            try
            {
                Thread.sleep(500);
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
            System.out.println(i);
        }
    }
}

public class thread_example
{
    public static void main(String[] args)
    {
        SimpleThread5 th = new SimpleThread5();

        th.start();
        // The join() method waits for a thread to die. In other words,
        // it causes the currently running threads to stop executing until
        // the thread it joins with completes its task.

        try 
        {
            // th.join();
            // public void join(long milliseconds)throws InterruptedException
            // th.join(1500);
            System.out.println("Technical");
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
    }
}
