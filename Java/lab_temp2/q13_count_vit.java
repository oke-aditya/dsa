import java.util.Scanner;

public class q13_count_vit
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);

        String sent = scanner.nextLine();
        String sent_arr[] = sent.split(" ");

        int count = 0;

        for(int i=0; i<sent_arr.length; i++)
        {
            if(sent_arr[i].equals("VIT"))
            {
                count += 1;
            }
        }

        if(count == 0)
        {
            System.out.println("No such word in message");
        }
        else
        {
            System.out.println("Vit has appeared " + count);
        }

        scanner.close();
    }
    
}
