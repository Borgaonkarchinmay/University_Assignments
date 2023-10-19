import java.util.*;

public class QuickSortRandomPivot {
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    public static int partition(int[] arr, int low, int high) {
        // Generate a random index between low and high
        Random rand = new Random();
        int randomIdx = rand.nextInt(high - low + 1) + low;

        // Swap the random pivot with the last element
        int temp = arr[randomIdx];
        arr[randomIdx] = arr[high];
        arr[high] = temp;

        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp2 = arr[i];
                arr[i] = arr[j];
                arr[j] = temp2;
            }
        }

        int temp3 = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp3;

        return i + 1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Original array: " + Arrays.toString(arr));
        quickSort(arr, 0, arr.length - 1);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    
}

/*
 * Input -->
 * N = 6
 * arr = [9,3,4,1,6,5]
 */