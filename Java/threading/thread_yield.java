// package threading;

// The yield() method of thread class causes the currently executing
// thread object to temporarily pause and allow other threads to execute

class SimpleThread7 extends Thread
{
    public void run()
    {
        System.out.print(Thread.currentThread().getName());
    }
}

public class thread_yield
{
    public static void main(String[] args)
    {
        SimpleThread7 th = new SimpleThread7();
        SimpleThread7.yield();
        for(int i=0; i<3; i++)
        {
            System.out.println(Thread.currentThread().getName());
        }
    }
}
