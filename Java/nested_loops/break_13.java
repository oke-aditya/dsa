package nested_loops;

import java.util.*;

public class break_13
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int lucky_num = 0;
        boolean is_lucky = false;
        for(int i=0; i<5; i++)
        {
            lucky_num = scanner.nextInt();
            if(lucky_num == 13)
            {
                System.out.println("You are lucky");
                is_lucky = true;
                break;
            }
        }
        if(!is_lucky)
        {
            System.out.println("Not Lucky");
        }
        scanner.close();
    }
}

