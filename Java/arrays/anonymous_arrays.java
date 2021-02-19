import java.util.*;

public class anonymous_arrays
{
    public static void print_arr(int arr[])
    {
        for(int x: arr)
        {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public int [] return_arr(int arr[])
    {
        return(new int [] {1, 2, 3, 4});
    }

    public static void main(String[] args)
    {
        print_arr(new int[] {2, 3, 4, 6});


    }
}
