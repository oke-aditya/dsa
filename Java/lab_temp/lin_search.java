import java.util.Scanner;

public class lin_search
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of elements");
        int n = scanner.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter the array");

        for(int i=0; i<n; i++)
        {
            arr[i] = scanner.nextInt();
        }

        System.out.println("Enter the search element");        

        int se = scanner.nextInt();
        boolean flag = false;

        for(int i=0; i<arr.length; i++)
        {
            if(arr[i] == se)
            {
                flag = true;
            }
        }
        if(flag)
        {
            System.out.println("Element is found");
        }
        else
        {
            System.out.println("Element not found");
        }

        scanner.close();

    }
    
}
