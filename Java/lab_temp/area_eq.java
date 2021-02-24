package lab_temp;

import java.util.Scanner;

public class area_eq
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        double s = scanner.nextInt();
        double area = ((s * s) / 4) * Math.sqrt(3);

        System.out.println("Area = " + area);
        scanner.close();
    }   
}
