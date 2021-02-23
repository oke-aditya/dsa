package input_output;

import java.util.*;

public class armstrong {
    public static void main(String argv[])
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int copy_n = n;
        int result = 0;
        while(n > 0)
        {
            int dig = n % 10;
            result += (dig * dig * dig);
            n = n / 10;
        }
        if(result == copy_n)
        {
            System.out.println("Armstrong Number");
        }
        else
        {
            System.out.println("Not armstrong Number");
        }
        scanner.close();
    }
}


    
