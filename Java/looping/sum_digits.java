import java.util.Scanner;


class sum_digits
{
    public static void main(final String[] array)
    {
        int i = new Scanner(System.in).nextInt();
        int n = 0;
        while (i > 0)
        {
            n += i % 10;
            i /= 10;
        }
        System.out.println(n);
    }
}