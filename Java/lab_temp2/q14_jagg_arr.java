public class q14_jagg_arr
{
    public static void pass_subjects(int jag_arr[][])
    {

        int subjects_passed = 0, subjects_failed=0;

        for(int row[] : jag_arr)
        {
            for(int marks: row)
            {
                if(marks >= 40)
                {
                    subjects_passed += 1;
                }
                else
                {
                    subjects_failed += 1;
                }
            }
        }

        System.out.println("Subjects failed = " + subjects_failed);
        System.out.println("Subjects passed = " + subjects_passed);
    }

    public static void print_jagg_arr(int jag_arr[][])
    {
        for(int row[] : jag_arr)
        {
            for(int marks: row)
            {
                System.out.print(marks + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        int jag_arr [][] = new int[4][];
        jag_arr[0] = new int[] {40, 80, 30, 99};
        jag_arr[1] = new int[] {20, 55};
        jag_arr[2] = new int[] {31, 44, 55, 67};
        jag_arr[3] = new int[] {87, 45, 66};

        print_jagg_arr(jag_arr);
        pass_subjects(jag_arr);


    }
}
