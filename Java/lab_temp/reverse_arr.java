import java.util.*;

public class reverse_arr
{

    public static void main(String[] args)
    {
        int arr[] = {1, 3, 4, 5, 7, 9};
        int n = arr.length;
        int start = 0, end = n-1;

        for(int i=0; i<arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }

        System.out.println();
        while(start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            
            start += 1;
            end -= 1;
        }
        for(int i=0; i<arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
