class Customer
{
    String name;
    String fav_food [] = new String [3];

    public Customer(String name, String[] fav_food)
    {
        this.name = name;
        this.fav_food = fav_food;
    }

    public static String[] find_common_food(Customer c1, Customer c2)
    {
        int i=0, j=0, k=0;
        String[] common_food = new String[10];

        for(i=0;i<c1.fav_food.length; i++)
        {
            for(j=0; j<c2.fav_food.length; j++)
            {
                if(c1.fav_food[i].equals(c2.fav_food[j]))
                {
                    common_food[k] = c1.fav_food[i];
                    k += 1;
                }
            }
        }
        return common_food;
    }
}


class q1_customers
{
    public static void main(String[] args)
    {
        String fav_food1[] = new String[3];
        fav_food1[0] = "apple";
        fav_food1[1] = "banana";
        fav_food1[2] = "cherry";
        

        String fav_food2[] = new String[3];
        fav_food2[0] = "apple";
        fav_food2[1] = "mango";
        fav_food2[2] = "dates";
        

        Customer c1 = new Customer("oke", fav_food1);
        Customer c2 = new Customer("oke2", fav_food2);

        String common_food[] = Customer.find_common_food(c1, c2);
        
        for(int i=0; i<common_food.length; i++)
        {
            System.out.println(common_food[i]);
        }

    }
}