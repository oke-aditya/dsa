import java.io.*;
import java.util.*;

public class lower_triangle 
{
    public static void main(final String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k;

        for(int i=1; i<=n; i++)
        {
            if(i % 2 == 1)
            {
                k = 1;
            }
            else
            {
                k = 2;
            }
            for(int j=1; j<=i; j++)
            {
                System.out.print(k + " ");
                k += 2;
            }
            System.out.println();
        }        
    }
}
