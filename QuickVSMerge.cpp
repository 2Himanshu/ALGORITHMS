#include <bits/stdc++.h>
using namespace std;

class Timer {
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() { return std::chrono::duration_cast<second_> (clock_::now() - beg_).count(); }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
} timer;

static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

const int int_min = -1e9,
          int_max = +1e9;

const int N = 1e8;

int arr[N], a1[N], a2[N], helper[N];

int partition(int arr[], int low, int high) {
    int randomNumberBetweenLowAndHigh = low + rand() % (high - low);
    swap(arr[low], arr[randomNumberBetweenLowAndHigh]);
    int pivot = arr[low];
    
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int l1, l2, i;
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (arr[l1] <= arr[l2])
            helper[i] = arr[l1++];
        else
            helper[i] = arr[l2++];
    }
    while (l1 <= mid)
        helper[i++] = arr[l1++];
    while (l2 <= high)
        helper[i++] = arr[l2++];
    for (i = low; i <= high; i++)
        arr[i] = helper[i];
}

void mergeSort(int arr[], int begin, int end) {
    if (begin >= end)
        return;
    auto m = begin + (end - begin) / 2;
    mergeSort(arr, begin, m);
    mergeSort(arr, m + 1, end);
    merge(arr, begin, m, end);
}

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void randomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand_int(int_min, int_max);
}

void sortedArrayNonDecreasing(int arr[], int n) {
    randomArray(arr, n);
    sort(arr, arr + n);
}

void sortedArrayNonIncreasing(int arr[], int n) {
    randomArray(arr, n);
    sort(arr, arr + n, greater<int>());
}

void almostSortedArray(int arr[], int n) {
    sortedArrayNonDecreasing(arr, n);
    double percentageMisplaced = 5;
    int m = n / 100.0 * percentageMisplaced / 2;
    for (int i = 0; i < m; i++) {
        int x = rand_int(0, n - 1),
            y = rand_int(0, n - 1);
        swap(arr[x], arr[y]);
    }
}

void arrayWithManyDuplicates(int arr[], int n) {
    double percentageUnique = 10;
    int m = n / 100.0 * percentageUnique;
    randomArray(arr, m);
    for (int i = 0; i < n; i++)
        arr[i] = arr[i % m];
    shuffle(arr, arr + n, rng);
}

void arrayWithOnlyOneUnique(int arr[], int n) {
    arr[0] = rand_int(int_min, int_max);
    for (int i = 0; i < n; i++)
        arr[i] = arr[0];
}

void generateTimes(int n) {
    srand(time(NULL));
    timer.reset();
    quickSort(a1, 0, n - 1);
    double quickSortTime = timer.elapsed();
    timer.reset();
    mergeSort(a2, 0, n - 1);
    double mergeSortTime = timer.elapsed();
    cout << "Taking size of array = ";
    cout << n << '\n';
    cout << fixed << setprecision(3);
    cout << "Time taken by Quick Sort: ";
    cout << quickSortTime << '\n';
    cout << "Time taken by Merge Sort: ";
    cout << mergeSortTime << '\n';
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        assert(arr[i] == a1[i] && arr[i] == a2[i]);
    // printarr(a1, n);
    // printarr(a2, n);
}

void main() {
    vector<string> t = {"randomArray", "sortedArrayNonDecreasing", "sortedArrayNonIncreasing", "almostSortedArray", "arrayWithManyDuplicates", "arrayWithOnlyOneUnique"};
    vector<int> m = {250000, 500000, 1000000};
    for (string s : t) {
        for (int n : m) {
            if (s == "randomArray")
                randomArray(arr, n);
            if (s == "sortedArrayNonDecreasing")
                sortedArrayNonDecreasing(arr, n);
            if (s == "sortedArrayNonIncreasing")
                sortedArrayNonIncreasing(arr, n);
            if (s == "almostSortedArray")
                almostSortedArray(arr, n);
            if (s == "arrayWithManyDuplicates")
                arrayWithManyDuplicates(arr, n);
            if (s == "arrayWithOnlyOneUnique")
                arrayWithOnlyOneUnique(arr, n);
            for (int i = 0; i < n; i++)
                a1[i] = a2[i] = arr[i];
            //printarr(arr, n);
            cout << s << '\n';
            generateTimes(n);
            cout << '\n';
        }
        cout << "\n\n";
    }
}
