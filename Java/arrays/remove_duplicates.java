import java.util.*;
import java.util.Arrays;  

public class remove_duplicates
{
    public static void main(String[] args)
    {
        int arr[] = {1, 2, 1, 2, 3, 4, 5};
        Arrays.sort(arr);
        int n = arr.length, j = 0;
        
        for(int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }

        System.out.println();

        for(int i=0; i<n-1; i++)
        {
            if(arr[i] != arr[i+1])
            {
                arr[j] = arr[i];
                j += 1;
            }
        }
        arr[j] = arr[n-1];

        for(int i=0; i<j; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
