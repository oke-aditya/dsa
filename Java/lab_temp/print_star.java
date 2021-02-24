package lab_temp;

// Print this pattern for n lines  

// *
// **
// ***
// ****

import java.util.*;

class print_star
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter num4ber of lines");
        int n = scanner.nextInt();

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        scanner.close();
    }

}
