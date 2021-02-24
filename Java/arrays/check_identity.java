package arrays;

import java.util.*;

public class check_identity
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

        // To check for identity matrix, we need leading diagonal = 1;
        boolean is_identity = true;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                // Diagonal case
                if(i == j)
                {
                    if(mat[i][j] != 1)
                    {
                        is_identity = false;
                    }
                }
                else
                {
                    if(mat[i][j] != 0)
                    {
                        is_identity = false;
                    }
                }
            }
        }

        if(is_identity)
        {
            System.out.println("Identity Matrix");
        }
        else
        {
            System.out.println("Not identitiy");
        }

        scanner.close();

    }    
}
