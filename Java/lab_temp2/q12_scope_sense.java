import java.util.*;

public class q12_scope_sense
{
    public static void main(String[] args)
    {
        String RegNo [] = new String[5];
        Scanner scanner = new Scanner(System.in);

        for(int i=0; i<5; i++)
        {
            String temp = scanner.nextLine();
            RegNo[i] = temp;
        }

        if(RegNo.length == 0)
        {
            System.out.println("There are no Students from SCOPE and SENSE school");
        }

        else
        {
            int elec_count = 0, cse_count = 0;
            for(int i=0; i<5; i++)
            {
                if(RegNo[i].contains("BEC"))
                {
                    elec_count += 1;
                }
                if(RegNo[i].contains("BCE"))
                {
                    cse_count += 1;
                }
            }
            System.out.println(elec_count);
            System.out.println(cse_count);
        }

        scanner.close();

    }
}
