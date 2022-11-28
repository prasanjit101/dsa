#include <bits/stdc++.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

// binary search
int binary_search(int *arr, int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ternary search
int ternary_search(int *arr, int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid1, mid2;
    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;
        if (arr[mid1] == key)
            return mid1;
        else if (arr[mid2] == key)
            return mid2;
        else if (arr[mid1] > key)
            high = mid1 - 1;
        else if (arr[mid2] < key)
            low = mid2 + 1;
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}

// exponential search
// Algorithm
// 1. Find range where element is present
// 2. Do Binary Search in above found range.
int exponential_search(int *arr, int size, int key)
{
    if (arr[0] == key)
        return 0;
    int i = 1;
    while (i < size && arr[i] <= key)
        i *= 2;
    return binary_search(arr, i, key);
}

// interpolation search
int interpolation_search(int *arr, int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// jump search
int jump_search(int *arr, int size, int key)
{
    int step = sqrt(size);
    int prev = 0;
    while (arr[min(step, size) - 1] < key)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }
    while (arr[prev] < key)
    {
        prev++;
        if (prev == min(step, size))
            return -1;
    }
    if (arr[prev] == key)
        return prev;
    return -1;
}

// fibonacci search
// Algorithm
// 1. Find the smallest Fibonacci number that is greater than or equal to the length of the given array.
// 2. Let the found Fibonacci number be fibMm1 (m’th Fibonacci number). Let fibMm2 be the (m-1)’th Fibonacci number.
// 3. While the array has elements to be inspected:
// a) Check if fibMm2 is a valid location. If yes, compare arr[fibMm2] with x. If x matches, return fibMm2.
// b) Else If x is greater than the value at index fibMm2, cut the subarray array from offset fibMm2 to size.
// c) Else (x is smaller) cut the subarray after offset fibMm2.
// d) Update fibMm1, fibMm2 for the next iteration.
int fibonacci_search(int *arr, int size, int key)
{
    int fibMm2 = 0;
    int fibMm1 = 1;
    int fibM = fibMm2 + fibMm1;
    while (fibM < size)
    {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset + fibMm2, size - 1);
        if (arr[i] < key)
        {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        }
        else if (arr[i] > key)
        {
            fibM = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        }
        else
            return i;
    }
    if (fibMm1 && arr[offset + 1] == key)
        return offset + 1;
    return -1;
}

// linear search
int linear_search(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}