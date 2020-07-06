#include <iostream>
#include <vector>

using namespace std;


void selectionsort(vector<int> &A)
{
  
  for(int i = 0; i < A.size(); ++i)
  {
    
    //find the smallest number
    int smallestnumber = i;
    for(int j = i + 1; j < A.size(); ++j)
    {
        if(A[smallestnumber] > A[j])
        {
          smallestnumber = j;
        }
    }
    
    swap(A[smallestnumber], A[i]);
  }
  
}


// To execute C++, please define "int main()"
int main() {
 
  
  vector<int> A {10, 8, 2, 4, 5, 3, 12, 21, 25};
  selectionsort(A);
  
  for(auto i : A)
  {
    
    cout << i << " ";
    
  }
  
  
  return 0;
}
