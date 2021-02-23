package collections;

import java.util.*;

public class vector_intro 
{
    public static void main(String[] args)
    {
        Vector<Integer> v1 = new Vector<Integer>();
        v1.add(60);
        v1.add(30);

        System.out.println(v1);
        
        v1.add(1, 40);
        
        System.out.println(v1);

        System.out.println(v1.elementAt(2));

        Vector<Integer> v2 = new Vector<Integer>();
        v2.add(60);
        v2.add(40);
        v2.add(30);

        if(v2.equals(v1))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }


    }    
}
