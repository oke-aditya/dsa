import java.io.*;
import java.util.*;

public class sort_collections
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList <String> al1 = new ArrayList <String>();

        for(int i=0; i<n; i++)
        {
            al1.add(scanner.next());
        }

        System.out.println("Before Sorting");
        for(String s : al1)
        {
            System.out.print(s + " ");
        }
        System.out.println();
        Collections.sort(al1, Collections.reverseOrder());
        System.out.println("After Reverse Sorting");
        for(String s : al1)
        {
            System.out.print(s + " ");
        }

        System.out.println();
        Collections.sort(al1);
        System.out.println("After Sorting");
        for(String s : al1)
        {
            System.out.print(s + " ");
        }
        System.out.println();
    }
}
