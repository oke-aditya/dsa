package looping;

import java.util.Scanner;


class sum_digits
{
    public static void main(final String[] array)
    {
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        int n = 0;
        while (i > 0)
        {
            n += i % 10;
            i /= 10;
        }
        System.out.println(n);
        scanner.close();
    }
}