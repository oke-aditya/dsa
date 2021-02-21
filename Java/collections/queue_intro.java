import java.util.*;

public class queue_intro
{
    public static void main(String[] args)
    {
        Queue <Integer> q1 = new PriorityQueue<Integer> ();
        q1.add(5);
        q1.add(4);
        q1.add(3);
        q1.add(2);
        q1.add(1);

        System.out.println(q1);
        
        q1.remove(3);
        q1.remove(2);

        System.out.println(q1);

        q1.add(2);
        q1.add(3);

        while(!q1.isEmpty())
        {
            System.out.println(q1.poll());
        }

        ArrayDeque <Integer> aq1 = new ArrayDeque <Integer>();

        aq1.add(10);
        aq1.add(20);
        aq1.add(30);
        aq1.add(40);

        System.out.println(aq1);

    }
}
