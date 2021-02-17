import java.util.*;

public class sum_rows
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a 3x3 Matrix");
        int n = 3;

        int mat[][] = new int[n][n];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat[i][j] = scanner.nextInt();
            }
        }

        for(int i=0; i<n; i++)
        {
            int row_sum = 0;
            for(int j=0; j<n; j++)
            {
                row_sum += mat[i][j];
            }
            System.out.println("Sum in row = " + row_sum);
        }

        scanner.close();

    }
    
}
