package arrays;

public class arr_count 
{
    public static void main(String[] args) 
    {
        int [] arr = {1, 2, 3, 4, 5, 1 ,1};
        int se = 1;
        int count = 0;

        for(int i=0; i<arr.length; i++)
        {
            if(arr[i] == se)
            {
                count += 1;
            }
        }
        System.out.print(count);
    }
}
