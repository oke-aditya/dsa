package looping;

import java.util.Scanner;
class first_last
{
    public static void main(final String[] array)
    {
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        int n = i % 10;
        int n2 = 0;
        while (i > 0)
        {
            n2 = i % 10;
            i /= 10;
        }
        System.out.println(" " + n2 + " " + n);
        scanner.close();
    }
}