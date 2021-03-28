import java.util.Scanner;

// package lab_temp3;

public class q2_overload_main
{
    public static boolean is_prime(int num)
    {
        boolean flag = true;
        for(int i=2; i<num; i++)
        {
            if((num % i) == 0)
            {
                flag = false;
                return flag;
            }
        }
        return flag;
    }

    public static int[] main(int arr[])
    {
        int result[] = new int[2];
        int prime_count = 0, comp_count = 0;

        for(int i=0; i<arr.length; i++)
        {
            if(is_prime(arr[i]))
            {
                prime_count += 1;
            }
            else
            {
                comp_count += 1;
            }
        }

        result[0] = prime_count;
        result[1] = comp_count;

        return result;

    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int arr[] = new int [n];
        int i=0;
        while(n > 0)
        {
            arr[i] = scanner.nextInt();
            i += 1;
            n -= 1;
        }

        int res[] = main(arr);
        System.out.println("Prime Count " +  res[0]);
        System.out.println("Comp Count " + res[1]);

    }    
}
