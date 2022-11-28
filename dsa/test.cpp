#include <bits/stdc++.h>
using namespace std;

void bucket_sort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (max < arr[i])
            max = arr[i];
    int bucket[max + 1];
    for (int i = 0; i <= max; i++)
        bucket[i] = 0;
    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;
    int j = 0;
    for (int i = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}