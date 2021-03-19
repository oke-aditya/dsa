import java.util.Scanner;

class Course
{
    String CourseName, CourseId, CourseType, OfferedBy;

    static int pe_count = pc_count = ue_count = 0;

    void set_course_details(String CourseName, String CourseId,
                            String CourseType, String OfferedBy)
    {
        this.CourseName = CourseName;
        this.CourseId = CourseId;
        this.CourseType = CourseType;
        this.OfferedBy = OfferedBy;
    }

    static void search_course_details(Course arr[])
    {
        for(int i=0; i<arr.length; i++)
        {
            if(arr[i].CourseType.equals("PE"))
            {
                pe_count += 1;
            }
            else if(arr[i].CourseType.equals("PC"))
            {
                pc_count += 1;
            }
            else if(arr[i].CourseType.equals("UE"))
            {
                ue_count += 1;
            }
        }
    }

    static void display_course_details(Course arr[])
    {
        System.out.println("PE Courses =" + pe_count);
        System.out.println("PC Courses =" + pc_count);
        System.out.println("UE Courses =" + ue_count);
    }
}


public class q16_course_details
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        Course course_arr[] = new Course[5];
        
        for(int i=0; i<5; i++)
        {
            String CourseName = scanner.nextLine();
            String CourseId = scanner.nextLine();
            String courseType = scanner.nextLine();
            String OfferedBy = scanner.nextLine();

            Course temp = new Course();
            temp.set_course_details(CourseName, CourseId, CourseType, OfferedBy);
            
            course_arr[i] = temp;
        }
        Course.search_course_details(course_arr);
        Course.display_course_details(course_arr);

        scanner.close();

    }
}
