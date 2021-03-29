// package lab_temp3;

class Brand
{
    String brand_name;

    public Brand(String brand_name)
    {
        this.brand_name = brand_name;
    }    

    static void brand_sort(Brand br [])
    {
        Brand temp = new Brand("temp");

        for(int i=0;i<br.length-1;i++)
        {
            for(int j=0;j<br.length-1-i;j++)
            {
                if(br[j].brand_name.compareTo(br[j+1].brand_name) < 0)
                {
                    temp = br[j];
                    br[j] = br[j+1];
                    br[j+1] = temp;            
                } 
            }  
        } 
    }

    static void display_brands(Brand br [])
    {
        for(Brand b : br)
        {
            System.out.print(b.brand_name + " ");
        }
    }

}

public class q9_car_brands
{
    public static void main(String[] args)
    {
        Brand brands[] = new Brand[6];
        brands[0] = new Brand("Honda");
        brands[1] = new Brand("Kia");
        brands[2] = new Brand("Maruti");
        brands[3] = new Brand("Toyota");
        brands[4] = new Brand("Hyundai");
        brands[5] = new Brand("Nissan");
        
        System.out.println();
        Brand.display_brands(brands);
        
        System.out.println();
        Brand.brand_sort(brands);
        
        System.out.println();
        Brand.display_brands(brands);

        System.out.println();
    }
}
