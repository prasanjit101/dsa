void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort
// Algorithm
// Try to push the largest element to the end of the array
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// selection sort
// Algorithm :
// 1. Find the minimum element in unsorted array
// 2. Swap the found minimum element with the first element
// 3. Repeat the above steps for the remaining unsorted array
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// insertion sort
// Time Complexity : O(n^2)
// Space Complexity : O(1)
// Algorithm
// 1. Iterate from arr[1] to arr[n] over the array.
// 2. Compare the current element (key) to its predecessor.
// 3. If the key element is smaller than its predecessor, compare it to the elements before.
// Move the greater elements one position up to make space for the swapped element.
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// merge sort
// Time Complexity : O(nlogn)
// Space Complexity : O(n)
// Algorithm
// 1. Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
// 2. Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
// Merge algorithm
// 1. Compare the first elements of the two sublists.
// 2. Copy the smaller element to the sorted list.
// 3. Repeat until one of the sublists is empty.
// 4. Copy the remaining elements of the other sublist to the end of the sorted list.
void merge(int arr[], int start, int mid, int end)
{
    int s2 = mid + 1;
    if (arr[mid] <= arr[s2])
        return;
    while (start <= mid && s2 <= end)
    {
        if (arr[s2] >= arr[start])
            start++;
        else
        {
            int val = arr[s2];
            int idx = s2;
            while (idx != start)
            {
                arr[idx] = arr[idx - 1];
                idx--;
            }
            arr[start] = val;
            start++;
            mid++;
            s2++;
        }
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - 1) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// quick sort
// Time Complexity : O(nlogn)
// Space Complexity : O(n)
// Algorithm
// 1. Pick an element, called a pivot, from the list.
// 2. Reorder the list so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way).
// After this partitioning, the pivot is in its final position. This is called the partition operation.
// 3. Recursively apply the above steps to the sub-list of elements with smaller values and separately the sub-list of elements with greater values.
void quick_sort(int arr[], int size)
{
    int i = 0, j = size - 1;
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
    if (j > 0)
        quick_sort(arr, j + 1);
    if (i < size)
        quick_sort(arr + i, size - i);
}

// heap sort
// Time Complexity : O(nlogn)
// Space Complexity : O(1)
// Algorithm
// 1. Build a max heap from the input data.
// 2. At this point, the largest item is stored at the root of the heap.
// Replace it with the last item of the heap followed by reducing the size of heap by 1.
// Finally, heapify the root of tree.
// 3. Repeat above steps while size of heap is greater than 1.
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// counting sort
// Time Complexity : O(n+k)
// Space Complexity : O(n+k)
// Algorithm
// 1. Find the largest element in the array.
// 2. Initialize an array of length equal to the largest element with all elements as 0.
// 3. Store the count of each element at their respective index in count array.
// 4. Store cumulative sum of the elements of the count array.
// 5. Find the index of each element of the original array in count array.
// 6. Decrease the count by 1 for each index.
// 7. Place the elements in output array.
// 8. Copy the sorted elements into original array.
void count_sort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    int j = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[j++] = i;
            count[i]--;
        }
    }
}

// radix sort
// Time Complexity : O(nk)
// Space Complexity : O(n+k)
// Algorithm
// 1. Find the largest element in the array.
// 2. Find the number of digits in the largest element.
// 3. Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number.
void rcount_sort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i] / exp]++;
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (max < arr[i])
            max = arr[i];
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        rcount_sort(arr, n, exp);
    }
}

// bucket sort
// Time Complexity : O(n+k)
// Space Complexity : O(n+k)
// Algorithm
// 1. Create n empty buckets (Or lists).
// 2. Do following for every array element arr[i].
// .......a) Insert arr[i] into bucket[n*array[i]]
// 3. Sort individual buckets using insertion sort.
// 4. Concatenate all sorted buckets.
int findMax(int arr[], int n)
{
    int i, max = arr[0], cnt = 0;
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    while (max > 0)
    {
        cnt++;
        max = max / 10;
    }
    return cnt;
}

void bucketSort(int arr[], int *bucket[], int n)
{
    static int i, j[10], k, l, d = 1;
    int c;
    c = findMax(arr, n);
    for (int m = 0; m < c; m++)
    {
        for (i = 0; i < 10; i++)
            j[i] = 0;
        for (i = 0; i < n; i++)
        {
            k = (arr[i] / d) % 10;
            bucket[k][j[k]] = arr[i];
            j[k]++;
        }
        l = 0;
        for (i = 0; i < 10; i++)
            for (k = 0; k < j[i]; k++)
            {
                arr[l] = bucket[i][k];
                l++;
            }
        d *= 10;
    }
}