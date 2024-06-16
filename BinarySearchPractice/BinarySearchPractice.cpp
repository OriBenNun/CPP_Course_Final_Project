// C++ code to linearly search x in arr[].

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int x)
{
    if (high < low)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;
    
    if (arr[mid] == x)
    {
        return mid;
    }

    if (arr[mid] < x)
    {
        return recursiveBinarySearch(arr, mid + 1, high, x);
    }

    return recursiveBinarySearch(arr, low, mid - 1, x);
}

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++) {
        if (arr[i] > x) return -1;
        if (arr[i] == x) return i;
    }
    return -1;
}

// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = std::size(arr);

    // Function call
    int result = recursiveBinarySearch(arr, 0, N, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}