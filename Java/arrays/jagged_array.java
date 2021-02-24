package arrays;

public class jagged_array
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

        // for(int i=0; i<arr.length; i++)
        // {
        //     for(int j=0; j<arr[i].length; j++)
        //     {
        //         System.out.print(arr[i][j] + " ");
        //     }
        //     System.out.println();
        // }
    }

    public static void main(String[] args)
    {
        int jagg_arr[][] = {{1, 2, 4}, {1, 2, 3}, {1, 2}};
        print_arr(jagg_arr);
        System.out.println();

        int jagg_arr2[][] = new int[4][];
        jagg_arr2[0] = new int[] {1};
        jagg_arr2[1] = new int[] {2, 2};
        jagg_arr2[2] = new int[] {3, 3, 3};
        jagg_arr2[3] = new int[] {4, 4, 4, 4};

        print_arr(jagg_arr2);

    }
}
