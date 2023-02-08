Question =1
/*

#include <bits/stdc++.h>
using namespace std;
 
// Function to count distinct pairs
// in array whose sum equal to K
int cntDisPairs(int arr[],
                int N, int K)
{
    // Stores count of distinct pairs
    // whose sum equal to K
    int cntPairs = 0;
 
    // Sort the array
    sort(arr, arr + N);
 
    // Stores index of
    // the left pointer
    int i = 0;
 
    // Stores index of
    // the right pointer
    int j = N - 1;
 
    // Calculate count of distinct
    // pairs whose sum equal to K
    while (i < j) {
 
        // If sum of current pair
        // is equal to K
        if (arr[i] + arr[j] == K) {
 
            // Remove consecutive duplicate
            // array elements
            while (i < j && arr[i] == arr[i + 1]) {
 
                // Update i
                i++;
            }
 
            // Remove consecutive duplicate
            // array elements
            while (i < j && arr[j] == arr[j - 1]) {
 
                // Update j
                j--;
            }
 
            // Update cntPairs
            cntPairs += 1;
 
            // Update i
            i++;
 
            // Update j
            j--;
        }
 
        // if sum of current pair
        // less than K
        else if (arr[i] + arr[j] < K) {
 
            // Update i
            i++;
        }
        else {
 
            // Update j
            j--;
        }
    }
    return cntPairs;
}
 
// Driver Code
int main()
{
    int arr[] = { 5, 6, 5, 7, 7, 8 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 13;
    cout << cntDisPairs(arr, N, K);
}
*\
Q=2
/*
#include <bits/stdc++.h>
using namespace std;
   
// Function to print all triplets in
// given sorted array that forms AP
void printAllAPTriplets(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n - 1; i++)
    {
    for (int j = i + 1; j < n; j++)
    {
        // Use hash to find if there is
        // a previous element with difference
        // equal to arr[j] - arr[i]
        int diff = arr[j] - arr[i];
        if (s.find(arr[i] - diff) != s.end())
            cout << arr[i] - diff << " " << arr[i]
                 << " " << arr[j] << endl;
    }
    s.insert(arr[i]);
    }
}
   
// Driver code
int main()
{
    int arr[] = { 2, 6, 9, 12, 17, 
                 22, 31, 32, 35, 42 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printAllAPTriplets(arr, n);
    return 0;
}
*\
Q=3
/*
#include <bits/stdc++.h>
using namespace std;
 
// function to count the number of
// unique triplets whose xor is 0
int countTriplets(int a[], int n)
{
    // To store values that are present
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
     
    // stores the count of unique triplets
    int count = 0;
     
    // traverse for all i, j pairs such that j>i
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
 
          // xor of a[i] and a[j]
          int xr = a[i] ^ a[j];
     
          // if xr of two numbers is present,
          // then increase the count
          if (s.find(xr) != s.end() && xr != a[i] &&
                                       xr != a[j])
            count++;
        }
    }
     
    // returns answer
    return count / 3;
}
 
// Driver code to test above function
int main()
{
    int a[] = {1, 3, 5, 10, 14, 15};
    int n = sizeof(a) / sizeof(a[0]);  
    cout << countTriplets(a, n);   
    return 0;
}
*\
Q=4
/*
// giving second array higher priority
#include <bits/stdc++.h>
using namespace std;
 
// Compare function used to sort array
// in decreasing order
bool compare(int a, int b)
{
    return a > b;
}
 
// Function to maximize array elements
void maximizeArray(int arr1[], int arr2[],
                                   int n)
{
    // auxiliary array arr3 to store
    // elements of arr1 & arr2
    int arr3[2*n], k = 0;
    for (int i = 0; i < n; i++)
        arr3[k++] = arr1[i];
    for (int i = 0; i < n; i++)
        arr3[k++] = arr2[i];
 
    // hash table to store n largest
    // unique elements
    unordered_set<int> hash;
 
    // sorting arr3 in decreasing order
    sort(arr3, arr3 + 2 * n, compare);
 
    // finding n largest unique elements
    // from arr3 and storing in hash
    int i = 0;
    while (hash.size() != n) {
 
        // if arr3 element not present in hash,
        // then store this element in hash
        if (hash.find(arr3[i]) == hash.end())
            hash.insert(arr3[i]);
         
        i++;
    }
 
    // store that elements of arr2 in arr3
    // that are present in hash
    k = 0;
    for (int i = 0; i < n; i++) {
 
        // if arr2 element is present in hash,
        // store it in arr3
        if (hash.find(arr2[i]) != hash.end()) {
            arr3[k++] = arr2[i];
            hash.erase(arr2[i]);
        }
    }
 
    // store that elements of arr1 in arr3
    // that are present in hash
    for (int i = 0; i < n; i++) {
 
        // if arr1 element is present in hash,
        // store it in arr3
        if (hash.find(arr1[i]) != hash.end()) {
            arr3[k++] = arr1[i];
            hash.erase(arr1[i]);
        }
    }
 
    // copying 1st n elements of arr3 to arr1
    for (int i = 0; i < n; i++)
        arr1[i] = arr3[i];   
}
 
// Function to print array elements
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";   
    cout << endl;
}
 
// Driver Code
int main()
{
    int array1[] = { 7, 4, 8, 0, 1 };
    int array2[] = { 9, 7, 2, 3, 6 };
    int size = sizeof(array1) / sizeof(array1[0]);
    maximizeArray(array1, array2, size);
    printArray(array1, size);
}
*\
Q=5
/*
 
#include <bits/stdc++.h>
using namespace std;
 
bool subArrayExists(int arr[], int N)
{
    unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
 
// Driver's code
int main()
{
    int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    if (subArrayExists(arr, N))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
*\
Q=6
/*
 
#include <bits/stdc++.h>
using namespace std;
 
bool subArrayExists(int arr[], int N)
{
    unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
 
// Driver's code
int main()
{
    int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    if (subArrayExists(arr, N))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
*\
Q=7
/*
 
#include <bits/stdc++.h>
using namespace std;
 
bool subArrayExists(int arr[], int N)
{
    unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
 
// Driver's code
int main()
{
    int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    if (subArrayExists(arr, N))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
*\
Q=8
/*
 
#include <bits/stdc++.h>
using namespace std;
 
bool subArrayExists(int arr[], int N)
{
    unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
 
// Driver's code
int main()
{
    int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    if (subArrayExists(arr, N))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
*\