import java.util.*;

public class set_intro
{
    public static void main(String[] args)
    {
        HashSet <String> hs1 = new HashSet <String>();
        hs1.add("Hello");
        hs1.add("From");
        hs1.add("Hello");
        hs1.add("Set");

        System.out.println(hs1);

        LinkedHashSet <String> lsh1 = new LinkedHashSet <String> ();
        lsh1.add("Hello");
        lsh1.add("From");
        lsh1.add("Linked");
        lsh1.add("Hash");
        lsh1.add("Set");

        System.out.println(lsh1);

        Object arr [] = hs1.toArray();
        for(int j=0; j<arr.length; j++)
        {
            System.out.println(arr[j]);
        }

        SortedSet <String> ss1 = new TreeSet <String>();
        ss1.add("Hello");
        ss1.add("From");
        ss1.add("Sorted");
        ss1.add("Set");

        System.out.println(ss1);

        Object obj [] = ss1.toArray();
        // System.out.println(obj);

        for(int j=0; j<obj.length; j++)
        {
            System.out.println(obj[j]);
        }
    }
    
}
