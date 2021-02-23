package collections;

import java.util.*;

public class linkedlist_intro 
{
    public static void main(String[] args) 
    {
        LinkedList<Integer> l1 = new LinkedList<Integer>();
        l1.add(20);
        l1.add(30);
        l1.add(40);
        System.out.println(l1);

        LinkedList <String> l2 = new LinkedList<String>();
        l2.add("Hello");
        l2.add("World");

        System.out.println(l2);
        System.out.println(l2.size());

        l2.add(0, "First");
        System.out.println(l2);
        
        if(l2.contains("Hello"))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("NO");
        }

        ArrayList <String> a1 = new ArrayList<String>();
        a1.add("Array");
        a1.add("Hello");

        a1.addAll(l2);

        System.out.println(a1);
        
        LinkedList <String> l3 = new LinkedList<String>();
        l3.add("ONE");
        l3.add("TWO");
        l3.add("THREE");
        l3.add("FOUR");
        l3.add("FIVE");

        System.out.println(l3);

        l3.poll();
        l3.remove();
        System.out.println(l3);

        l3.pollLast();
        l3.removeLast();
        System.out.println(l3);

    }
}
