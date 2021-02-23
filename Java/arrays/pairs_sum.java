package arrays;

import java.util.Scanner;

public class pairs_sum 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int [] arr = new int[n];
        
        for(int i=0; i<n; i++)
        {
            arr[i] = scanner.nextInt();
        }

        int ps = scanner.nextInt();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if((arr[i] + arr[j]) == ps)
                {
                    count += 1;
                    System.out.println(arr[i] + " " + arr[j]);
                }
            }
        }
        System.out.print(count);
        scanner.close();
    }
}
