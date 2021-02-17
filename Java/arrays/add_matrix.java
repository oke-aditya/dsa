import java.util.*;

public class add_matrix
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

        System.out.println("Enter a 3x3 Matrix");

        int mat2[][] = new int[n][n];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat2[i][j] = scanner.nextInt();
            }
        }

        int mat3[][] = new int[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat3[i][j] = mat2[i][j] + mat[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                System.out.print(mat3[i][j] + " ");
            }
            System.out.println();
        }
    }
    
}
