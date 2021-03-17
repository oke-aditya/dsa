// package threading;
import java.util.*;

class SimpleThread3 extends Thread
{
    public void run()
    {
        System.out.println("Thread started + " + Thread.currentThread());
    }
}


public class threading_priority
{
    public static void main(String[] args)
    {
        SimpleThread3 sp3 = new SimpleThread3();
        sp3.start();
        sp3.setPriority(6);
        sp3.setName("th");

        System.out.println(sp3.getPriority());
        System.out.println(sp3.getId());
        System.out.println(sp3.getName());



    }

}
