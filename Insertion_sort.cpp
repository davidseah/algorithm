#include <iostream>
#include <vector>

using namespace std;

int main()
{

  vector<int> con {2,1, 6, 7, 8, 4, 3, 9, 5};
  
  for(int i = 1; i < con.size(); ++i)
  {
    int j{};
    int key = con[i];
    
    for( j = i - 1;  j >= 0 && con[j] > key; --j)
    {
      con[j+1] = con[j];
    }
    con[j+1] = key;
  } 
  
  
  for(auto i : con)
  {
    cout << i << ", ";
  }
}
