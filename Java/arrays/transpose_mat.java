import java.util.*;

public class transpose_mat
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
        System.out.println();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                System.out.print(mat[j][i] + " ");
            }
            System.out.println();
        }
        scanner.close();
    }
}
