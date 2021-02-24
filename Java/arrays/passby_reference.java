package arrays;

public class passby_reference 
{
    public static void change_arr(int m[])
    {
        m[1] = 999;
    }

    public static void main(String[] args)
    {
        int arr[] = {2, 3, 4};
        change_arr(arr);
        for(int x : arr)
        {
            System.out.print(x + " ");
        }
        System.out.println();
    }
    
}
