class Product
{
    String product_id, product_name, product_company, manufacturing_date;
    int serial_number, product_price;

    Product(String product_id, String product_name, int serial_number,
            String product_company, String manufacturing_date, int product_price)
    {
        this.product_id = product_id;
        this.product_name = product_name;
        this.serial_number = serial_number;
        this.product_company = product_company;
        this.manufacturing_date = manufacturing_date;
        this.product_price = product_price;
    }

    public static void display_products(Product prod_arr[])
    {
        for(Product p : prod_arr)
        {
            System.out.println(p.product_id);
            System.out.println(p.product_name);
            System.out.println(p.serial_number);
            System.out.println(p.product_company);
            System.out.println(p.manufacturing_date);
            System.out.println(p.product_price);
        }
    }
}

public class q10_product
{
    public static void main(String[] args)
    {
        Product prod_arr[] = new Product[4];

        prod_arr[0] = new Product("001", "laptop", 123, "samsung", "27july2020", 30000);
        prod_arr[1] = new Product("002", "mobile", 124, "mi", "12july2021", 20030);
        prod_arr[2] = new Product("003", "laptop", 125, "lg", "02may2020", 13000);
        prod_arr[0] = new Product("004", "tv", 126, "lg", "03mar2021", 500);

        Product.display_products(prod_arr);

    }   
}
