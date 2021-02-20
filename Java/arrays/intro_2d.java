import java.util.*;

public class intro_2d
{
    public static void print_arr(int arr[][])
    {
        for(int row[]: arr)
        {
            for(int ele: row)
            {
                System.out.print(ele + " ");
            }
            System.out.println();
        }
    }

    public static int [][] return_arr()
    {
        int arr2[][] = new int[][] {{1, 1, 1}, {1, 2, 3}, {3, 4, 5}};
        return arr2;

    }

    public static void main(String[] args)
    {
        int arr[][] = new int[2][2];
        Scanner scanner = new Scanner(System.in);
        int n = 2;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                arr[i][j] = scanner.nextInt();
            }
        }

        // Anonymous arrays.
        print_arr(new int[][] {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}});
        print_arr((x = return_arr()));

        scanner.close();
    }
    
}
