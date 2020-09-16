import java.io.*;
import java.util.*;

public class triangle_numbers 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for(int i=1; i<=n; i++)
        {
            int count = i;
            for(int j=i;j<=n; j++)
            {
                System.out.print(count + " ");
                count += 1;
            }
            System.out.println();
        }
    }
    
}
