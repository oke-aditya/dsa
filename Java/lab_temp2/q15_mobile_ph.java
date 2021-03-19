import java.util.Scanner;

class MobilePhone
{
    String ModelName, CompanyName, YearofManf;
    int price;

    void set_mobile_details(String ModelName, String CompanyName, String YearofManf, int price)
    {
        this.ModelName = ModelName;
        this.CompanyName = CompanyName;
        this.YearofManf = YearofManf;
        this.price = price;
    }

    static void sort_mobile_details(MobilePhone [] mb_arr)
    {
        // Sort according to company name
        // Bubble sort the company name;
        // Bubble sort the array

        MobilePhone temp;

        for (int k = 0; k < mb_arr.length - 1; k++)
        {
            for (int j = 0; j < mb_arr.length - k - 1; j++)
            {
                if ((mb_arr[j].CompanyName).compareTo(mb_arr[j + 1].CompanyName) > 0)
                {
                    temp = mb_arr[j];
                    mb_arr[j] = mb_arr[j + 1];
                    mb_arr[j + 1] = temp;
                }
            }
        }
    }

    static void display_mobile_details(MobilePhone [] mb_arr)
    {
        for(int i=0; i<mb_arr.length; i++)
        {
            System.out.println(mb_arr[i].ModelName);
            System.out.println(mb_arr[i].CompanyName);
            System.out.println(mb_arr[i].YearofManf);
            System.out.println(mb_arr[i].price);
        }

    }
}



public class q15_mobile_ph
{
    public static void main(String[] args)
    {
        MobilePhone mb_arr[] = new MobilePhone[5];
        Scanner scanner = new Scanner(System.in);
        
        for(int i=0; i<5; i++)
        {
            MobilePhone mb = new MobilePhone();
            // Read input from user.
            String ModelName = scanner.nextLine();
            String CompanyName = scanner.nextLine();
            String YearofManf = scanner.nextLine();
            int price = scanner.nextInt();

            mb.set_mobile_details(ModelName, CompanyName, YearofManf, price);

            mb_arr[i] = mb;
        }

        MobilePhone.sort_mobile_details(mb_arr);
        MobilePhone.display_mobile_details(mb_arr);
        scanner.close();
    }
    
}
