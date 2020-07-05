 #include <iostream>
#include <vector>
#include <climits>

using namespace std;

int Partition(vector<int>& A, int low, int high )
{
    int partitionnumber = A[high];
    
    int partitionindex = low;
    for(int i = low; i < high; ++i)
    {
        if(A[i] < partitionnumber )
        {
            swap(A[partitionindex], A[i]);
            ++partitionindex;
        }
    }
   
    swap(A[partitionindex], A[high]);
    return partitionindex;
}

void quicksort(vector<int>& A, int low, int high)
{
    if(low < high)
    {
        int i = Partition(A, low, high);
        quicksort(A, low, i-1);
        quicksort(A, i+1, high);
    }
}

int main()
{

  vector<int> con {13,-3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

  quicksort(con, 0, con.size()-1);
  for(auto i : con)
  {
    cout << i << " " ;
  }
  
  return 0;
}
