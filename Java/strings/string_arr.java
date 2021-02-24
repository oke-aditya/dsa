package strings;

import java.util.*;

public class string_arr
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String names[] = new String[5];
        for(int i=0; i<5; i++)
        {
            names[i] = scanner.nextLine();
        }
        Arrays.sort(names);
        for(int i=0; i<5; i++)
        {
            System.out.print(names[i] + " ");
        }
        System.out.println();
        scanner.close();

    }
    
}
