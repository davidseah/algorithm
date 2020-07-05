#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void merge(vector<int>& A, int low, int mid, int high)
{
    int size1 = mid - low+1;
    int size2 = high - mid;
    
    vector<int> con1(size1);
    //copy the container
    for(int i = 0; i < size1; ++i)
    {
        con1[i] = A[low + i];
    }
    
    vector<int> con2(size2);
    for(int j = 0; j < size2; ++j)
    {
        con2[j] = A[mid + 1 + j];
    }

    
    int i{};
    int j{};
    for(int k = low; k < high+1; ++k)
    {
        //meaning we already empty out the first container
        //only feel up using the second container
        if(i >= size1)
        {
            A[k] = con2[j];
            ++j;
