import java.util.*;

public class sum_5
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n, sum=0;
        for(int i=0; i<5; i++)
        {
            n = scanner.nextInt();
            if(n % 2 == 0)
            {
                continue;
            }
            sum += n;
        }
        System.out.println("Sum = " + sum);
        scanner.close();
    }

}

