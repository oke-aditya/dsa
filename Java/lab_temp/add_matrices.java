package lab_temp;

import java.util.Scanner;

public class add_matrices
{
    public static void main(String[] args)
    {
        int n = 3;
        Scanner scanner = new Scanner(System.in);

        int mat1[][] = new int[n][n];
        int mat2[][] = new int[n][n];
        int res[][] = new int[n][n];

        System.out.println("Enter the first Matrix");

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat1[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter the second Matrix");

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat2[i][j] = scanner.nextInt();
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                res[i][j] = mat1[i][j] + mat2[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                System.out.print(res[i][j] + " ");
            }
            System.out.println();
        }

        scanner.close();

    }
    
}
