import java.util.*;

public class q2_reg_no {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String arr[] = new String[5];

        int idx = 0;

        for (int i = 0; i < 5; i++) {
            String temp = scanner.nextLine();

            if (!temp.contains("BEC")) {
                arr[idx] = temp;
                idx += 1;
            }
        }

        // Bubble sort the array
        String temp = "";
        for (int k = 0; k < arr.length - 1; k++)
        {
            for (int j = 0; j < arr.length - k - 1; j++)
            {
                if (arr[j].compareTo(arr[j + 1]) > 0)
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        for (String k : arr)
        {
            System.out.print(k + " ");
        }
        scanner.close();
    }
}
