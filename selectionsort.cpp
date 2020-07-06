#include <iostream>
#include <vector>
using namespace std;

void selectionsort(vector<int>&A)
{
  
  for(int i = 0; i < A.size(); ++i)
  {
    
    int largestnumber = 0;
    //find the largest number and place it at the back
    for(int j = 0; j < A.size()-i; ++j)
    {
      if(A[largestnumber] < A[j])
      {
        
        largestnumber = j;
      }
    }
         
    swap(A[largestnumber], A[A.size()-i-1]);
  }
  
}


// To execute C++, please define "int main()"
int main() {
  vector<int> A {10, 20, 1, 3, 7, 2, 9, 8, 4, 20, 15 };
  
  selectionsort(A);
  
  for(auto i : A)
  {
    
    cout << i << " ";  
  }
  
  return 0;
}

