#include <iostream>
#include <vector>
#include <climits>

using namespace std;


struct largestsubarray
{
    largestsubarray(int l, int h, int s):
    low(l),
    high(h),
    sum(s)
    {}
    
    //default constructor
    largestsubarray() :
    low(0),
    high(0),
    sum(0)
    {
    
    }
    
    //copy constructor
    largestsubarray(const largestsubarray& copy):
    low(copy.low),
    high(copy.high),
    sum(copy.sum)
    {
    
    }
    
    largestsubarray& operator=(const largestsubarray& assign)
    {
        low = assign.low;
        high = assign.high;
        sum = assign.sum;
        return *this;
    }
    void Print()
    {
        cout<< "low: " << low << "\n";
        cout<< "high: " << high << "\n";
        cout<< "sum: " << sum << "\n";
    }
    
    int low;
    int high;
    int sum;
};

largestsubarray findmaxcrosssubarray(vector<int> A, int low, int middle, int high)
{
    int leftlargestsum = INT_MIN;
    int leftlargestindex {};
    int sum = 0;
    for(int i = middle; i > low; --i)
    {
        sum += A[i];
        if(sum > leftlargestsum)
        {
            leftlargestsum = sum;
            leftlargestindex = i;
        }
    }
    
    sum = 0;
    int rightlargestsum = INT_MIN;
    int rightlargestindex {};
    for(int i = middle + 1; i < high; ++i)
    {
        sum += A[i];
        if(sum > rightlargestsum)
        {
            rightlargestsum = sum;
            rightlargestindex = i;
        }
    }
    
    return largestsubarray(leftlargestindex, rightlargestindex, leftlargestsum + rightlargestsum );
}

largestsubarray findmaxsubarray(vector<int> A, int low, int high)
{

//base conditions 
if(low == high)
{
    return largestsubarray(low, high, A[low]);
}
else
{   
    int mid = low + (high-low)/2;
    largestsubarray left, right, cross;
    left = findmaxsubarray(A, low, mid);
    right = findmaxsubarray(A, mid+1, high);
    cross = findmaxcrosssubarray(A, low, mid, high);


    if(left.sum > right.sum && left.sum > cross.sum)
    {
        return left;
    }
    else if(right.sum > left.sum && right.sum > cross.sum)
    {
        return right;
    }
    else
    {
        return cross;
    }
}

}

int main()
{

  vector<int> con {13,-3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  largestsubarray lsa = findmaxsubarray(con, 0, con.size()-1);
   cout << "low: " << lsa.low << "\n";
   cout << "high: " << lsa.high << "\n";
   cout << "sum " << lsa.sum << "\n";
  
  return 0;
}
