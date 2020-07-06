#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int> &A)
{
  for(int i = 0; i < A.size(); ++i)
  {
    bool flag = false;
    for(int j = 0; j < A.size()-i-1;++j)
    {
      if(A[j] > A[j+1])
      {
        swap(A[j], A[j+1]);
        flag = true;
      }
    }
    
    if(flag == false)
    {
      break;
    }
  }
}


// To execute C++, please define "int main()"
int main() {
 
  
  vector<int> A {10, 8, 2, 4, 5, 3, 12, 21, 25};
  bubblesort(A);
  
  
  for(auto i : A)
  {
    
    cout << i << " ";
    
  }
  
  
  return 0;
}
