package arrays;

public class array_basics 
{

    public static int sum(int arr[])
    {
        int total = 0;
        for(int i: arr)
        {
            total += i;
        }
        return total;
    }

    public static void main(String[] args) 
    {
        // System.out.println("Hello World");
        // int [] arr = {1, 2, 3, 4, 5};
        // for(int i=0; i<arr.length; i++)
        // {
        //     System.out.print(arr[i] + " ");
        // }

        // Take integer sized array
        // Scanner scanner = new Scanner(System.in);
        // int n = scanner.nextInt();
        // int arr[] = new int[n];

        // for(int i=0; i<arr.length; i++)
        // {
        //     arr[i] = scanner.nextInt();
        // }
        // for (int i=0; i<arr.length; i++)
        // {
        //     System.out.print(arr[i] + " ");
        // }
        
        // Anonymous array
        int s1 = sum(new int [] {1, 2, 3, 4, 5});
        System.out.print(s1);
    }
}
