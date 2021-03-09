// package threading;

// Runnable interface is a type of functional interface which is designed to
// provide a common protocol for objects that wish to execute code while they are active.

// The Runnable interface should be implemented by any class
// whose instances are intended to be executed by a thread. 
// The class must define a method run. It is used to create thread.

// public void run(): is used to perform action for a thread.

class SimpleThread4
{
    public static void display()
    {
        System.out.println("Hello");
    }

}

class ChildThread1 extends SimpleThread4 implements Runnable
{
    public void run()
    {
        System.out.println("Child Thread");
    }
}

public class child_thread
{
    public static void main(String[] args)
    {
        ChildThread1 th = new ChildThread1();
        SimpleThread4.display();


    }
    
}
