// package threading;

// Thread Pool

// Java Thread pool represents a group of worker threads that are waiting for the job and reuse many times.

// In case of thread pool, a group of fixed size threads are created. A thread from the thread pool
// is pulled out and assigned a job by the service provider. After completion of the job,
// thread is contained in the thread pool again.

// Thread Group

// The thread group creates a tree in which every thread group except the initial thread group has a parent.

import java.lang.*;

class SimpleThread6 implements Runnable
{
    public void run()
    {
        System.out.println(Thread.currentThread().getName());
    }
}

public class thread_pool
{
    public static void main(String[] args)
    {
        SimpleThread6 simpleth = new SimpleThread6();
        ThreadGroup tg = new ThreadGroup("Parent ThreadGroup");
        
        SimpleThread6 t1 = new SimpleThread6();
        t1.run();
        
        SimpleThread6 t2 = new SimpleThread6();
        t2.run();
        
        SimpleThread6 t3 = new SimpleThread6();
        t3.run();
        
        System.out.println("Thread Group Name: " + tg.getName());
    }
}
