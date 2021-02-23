package arrays;

import java.util.*;

public class array_search 
{
    public static void main(String[] args) 
    {
        // int arr_size = 5;
        Scanner scanner = new Scanner(System.in);
        int arr_size = scanner.nextInt();
        int arr[] = new int[arr_size];
        int i;

        for(i=0;i<arr_size;i++)
        {
            arr[i] = scanner.nextInt();
        }

        int search_ele = scanner.nextInt();
        int fg=0;
        for(i=0; i<arr_size; i++)
        {
            if(arr[i] == search_ele)
            {
                fg = 1;
                break;
            }
        }
        if(fg == 1)
        {
            System.out.print("Element found");
        }
        else
        {
            System.out.print("Element not found");
        }
        System.out.println();
        scanner.close();
    }
}
