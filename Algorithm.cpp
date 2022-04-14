#include <iostream>
#include <windows.h>
#include <queue>
#define parent(x) (x-1)/2

using namespace std;
int RandomData[10000];

void ExSort(int arr[], int numlength);
void MergeSort(int arr[], int begin, int end);
void merge(int arr[], int start, int end);
void QuickSort(int arr[], int numlength, int start, int end);
void HeapSort(int arr[], int numlength);
void RadixSort(int arr[], int numlength);


void Eexecution(int testcase);
void Mexecution(int testcase);
void Qexecution(int testcase);
void Hexecution(int testcase);
void Rexecution(int testcase);

int main()
{
    srand(GetTickCount64());
    cout << fixed;
    cout.precision(6);

    Eexecution(100);
    Eexecution(500);
    Eexecution(1000);
    Eexecution(5000);
    Eexecution(10000);
    cout << "---------------------------------------\n";

    Mexecution(100);
    Mexecution(500);
    Mexecution(1000);
    Mexecution(5000);
    Mexecution(10000);
    cout << "---------------------------------------\n";

    Qexecution(100);
    Qexecution(500);
    Qexecution(1000);
    Qexecution(5000);
    Qexecution(10000);
    cout << "---------------------------------------\n";

    Hexecution(100);
    Hexecution(500);
    Hexecution(1000);
    Hexecution(5000);
    Hexecution(10000);
    cout << "---------------------------------------\n";

    Rexecution(100);
    Rexecution(500);
    Rexecution(1000);
    Rexecution(5000);
    Rexecution(10000);
    
    // 100, 500, 1000, 5000, 10000
}
void Eexecution(int testcase) {
    clock_t start, finish;
    double duration;
    double sum = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < testcase; i++) {
            RandomData[i] = rand();
        }
        start = clock();
        ExSort(RandomData, testcase);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        sum += duration;
        cout << duration << "초\n";
    }
    cout << testcase <<" numbers data Exsort run-time avg : " << sum / (double)5 << "\n";
    cout << "\n";
}
void Mexecution(int testcase) {
    clock_t start, finish;
    double duration;
    double sum = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < testcase; i++) {
            RandomData[i] = rand();
        }
        start = clock();
        MergeSort(RandomData, 0, testcase-1);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        sum += duration;
        cout << duration << "초\n";
    }
    cout << testcase << " numbers data Mergesort run-time avg : " << sum / (double)5 << "\n";
    cout << "\n";
}
void Qexecution(int testcase) {
    clock_t start, finish;
    double duration;
    double sum = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < testcase; i++) {
            RandomData[i] = rand();
        }
        start = clock();
        QuickSort(RandomData, testcase, 0 ,testcase - 1);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        sum += duration;
        cout << duration << "초\n";
    }
    cout << testcase << " numbers data QuickSort run-time avg : " << sum / (double)5 << "\n";
    cout << "\n";
}
void Hexecution(int testcase) {
    clock_t start, finish;
    double duration;
    double sum = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < testcase; i++) {
            RandomData[i] = rand();
        }
        start = clock();
        HeapSort(RandomData, testcase);
        for (int k = testcase - 1; k >= 0; k--) {
            int temp = RandomData[k];
            RandomData[k] = RandomData[0];
            RandomData[0] = temp;

            HeapSort(RandomData, k);
        }
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        sum += duration;
        cout << duration << "초\n";
    }
    cout << testcase << " numbers data HeapSort run-time avg : " << sum / (double)5 << "\n";
    cout << "\n";
}
int _max;

void Rexecution(int testcase) {
    clock_t start, finish;
    double duration;
    double sum = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < testcase; i++) {
            RandomData[i] = rand();
            if (_max < RandomData[i]) _max = RandomData[i];
        }
        start = clock();
        RadixSort(RandomData, testcase);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        sum += duration;
        cout << duration << "초\n";
    }
    cout << testcase << " numbers data RadixSort run-time avg : " << sum / (double)5 << "\n";
    cout << "\n";
}
void ExSort(int arr[], int numlength) {
    
    int i, j;
    int temp;
    for (i = 0; i < numlength - 1; i++) {
        for(j = i + 1; j < numlength; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
            }
        }
    }
}
void MergeSort(int arr[], int begin, int end) {
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid + 1, end);
    merge(arr, begin, end);
}
void QuickSort(int arr[], int numlength, int start, int end) {
    if (start >= end) {
        return;
    }
    int p = start;
    int i = p + 1; // 왼쪽 출발
    int j = end; // 오른쪽 출발
    int temp;
    while (i <= j) {
        while (i <= end && arr[i] < arr[p]) {
            i++;
        }
        while (j > start && arr[j] >= arr[p]) {
            j--;
        }
        if (i > j) {
            temp = arr[j];
            arr[j] = arr[p];
            arr[p] = temp;
        }
        else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    QuickSort(arr, numlength, start, j - 1);
    QuickSort(arr, numlength, j+1, end);
}
void HeapSort(int arr[], int numlength) {
    for (int i = 1; i < numlength; i++) {
        int child = i;
        while (child > 0) {
            int root = parent(child);
            if (arr[root] < arr[child]) {
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
         }
    }
}

queue<int> q[10];
void RadixSort(int arr[], int numlength) {
    int radix = 1;
    while (1) {
        if (radix >= _max) break;
        radix = radix * 10;
    }

    for (int i = 1; i < radix; i = i * 10) {
        for (int j = 0; j < numlength; j++) {
            int k;
            if (arr[j] < i)  k = 0;
            else k = (arr[j] / i) % 10;
            q[k].push(arr[j]);
        }
        int index = 0;
        for (int j = 0; j < 10; j++) {
            while (q[j].empty() == 0) {
                arr[index] = q[j].front();
                q[j].pop();
                index++;
            }
        }
    }
}

void merge(int arr[], int start, int end) {
    int temp[10000];
    int mid = (start + end) / 2;
    int lIdx = start, rIdx = mid + 1, k = start;

    while (k <= end) {
        if (lIdx > mid) {
            temp[k++] = arr[rIdx++];
            continue;
        }
        if (rIdx > end) {
            temp[k++] = arr[lIdx++];
            continue;
        }
        if (arr[lIdx] <= arr[rIdx])
            temp[k++] = arr[lIdx++];
        else
            temp[k++] = arr[rIdx++];
    }
    for (int i = start; i <= end; i++) arr[i] = temp[i];
}
