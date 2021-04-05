import java.io.IOException;
import java.util.Scanner;

public class q5_prof
{
    public static void main(String[] args) throws IOException
    {
        try
        {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < arr.length; i++)
            {
                arr[i] = scanner.nextInt();
                if (arr[i] < 0 || arr[i] > 100)
                {
                    throw new Exception("Invalid marks");
                }
            }
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            scanner.close();
        }
    }
}
