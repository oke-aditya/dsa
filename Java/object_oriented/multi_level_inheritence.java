package object_oriented;

class Flower
{
    void color()
    {
        System.out.println("Flower Color");    
    }
}

class RedFlower extends Flower
{
    // Overriding the method
    @Override
    void color()
    {
        System.out.println("Red Color Flower");
    }
}

class BlueFlower extends Flower
{
    @Override
    void color()
    {
        System.out.println("Blue color Flower");
    }
}

class PinkFlower extends RedFlower
{
    @Override
    void color()
    {
        System.out.println("Pink Color Flower");
    }
}

public class multi_level_inheritence
{
    public static void main(String[] args)
    {
        Flower flw = new Flower();
        BlueFlower blu_flw = new BlueFlower();
        RedFlower red_flw = new RedFlower();
        PinkFlower pnk_flw = new PinkFlower();

        flw.color();
        blu_flw.color();
        red_flw.color();
        pnk_flw.color();

    }
    
}
