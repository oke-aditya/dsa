import java.util.*;

public class q11_switch
{
    public static void main(String[] args)
    {

        Scanner scanner = new Scanner(System.in);
        String country_name = scanner.nextLine();

        country_name.toLowerCase();

        switch (country_name) {
            case "india":
                System.out.println("Delhi");
                break;
            
            case "uk":
                System.out.println("London");
                break;
            
            case "us":
                System.out.println("Washington DC");
                break;
            
            case "france":
                System.out.println("Paris");
                break;
            
            case "germany":
                System.out.println("Munich");
                break;

            default:
                System.out.println("Please check your Country Name");
        }
        scanner.close();
    }    
}
