import java.util.*;
class OptimalStorageOnTapes {
    static void findOrderMRT(int[] files, int n) {
        Arrays.sort(files);
        System.out.print("Optimal order in which files are to be stored is: ");
        for (int i = 0; i < n; i++)
            System.out.print(files[i] + " ");

        // MRT - Minimum Retrieval Time
        double MRT = 0;
        for (int i = 0; i < n; i++) {
            // int sum = 0;
            // for (int j = 0; j <= i; j++)
            //     sum += files[j];
            // MRT += sum;
            MRT += (n-i) * files[i];
        }
        MRT /= n;
        System.out.println("\nMinimum Retrieval Time of this order is " + MRT);
    }
    public static void main(String[] args) {
        int[] files = {2, 5, 4, 7};
        int n = files.length;
        findOrderMRT(files, n);
    }
}