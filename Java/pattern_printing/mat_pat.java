import java.io.*;
import java.util.*;

public class mat_pat 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for(int i=1;i<=n; i++)
        {
            int count = i;
            for(int j=1;j<=n;j++)
            {
                System.out.print(count + " ");
                if(count < n)
                {
                    count += 1;
                }
            }
            System.out.println();
        }
    }
    
}
