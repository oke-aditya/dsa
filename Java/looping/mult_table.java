package looping;

import java.util.Scanner;

class mult_table 
{
    public static void main(final String[] array)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 1; i <= 10; ++i)
        {
            System.out.println(" " + i + "x  " + n + " " + (n * i));
        }
        scanner.close();
    }
}