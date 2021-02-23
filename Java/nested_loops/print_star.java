// Print this pattern for n lines  

// *
// **
// ***
// ****

package nested_loops;

import java.util.*;

class print_star
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of lines");
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
