import java.util.Scanner;

class mult_table 
{
    public static void main(final String[] array)
    {
        int n = new Scanner(System.in).nextInt();
        for (int i = 1; i <= 10; ++i)
        {
            System.out.println(" " + i + "x  " + n + " " + (n * i));
        }
    }
}