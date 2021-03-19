import java.util.*;

public class q8_find_name
{
    public static void main(String[] args)
    {
        String arr[] = new String[5];
        Scanner scanner = new Scanner(System.in);

        for(int i=0; i<5; i++)
        {
            arr[i] = scanner.nextLine();
        }

        String s_name = scanner.nextLine();
        for(int i=0; i<arr.length; i++)
        {
            if(arr[i].contains(s_name))
            {
                System.out.println("Name found");
                System.exit(0);
            }
        }
        System.out.println("Name not found");
        scanner.close();
    }
}
