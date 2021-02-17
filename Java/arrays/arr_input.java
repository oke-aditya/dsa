import java.util.*;

public class arr_input
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int arr [] = new int[n];

        for(int i=0; i<n; i++)
        {
            arr[i] = scanner.nextInt();
        }

        // Print the array
        for(int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        scanner.close();
    }
}
