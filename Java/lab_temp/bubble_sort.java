package lab_temp;

public class bubble_sort
{
    public static void main(String[] args)
    {
        int arr[] = {1, 3, 7, 2, 5, 4, 6};
        int n = arr.length;
        
        for(int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }

        System.out.println();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

    }
    
}
