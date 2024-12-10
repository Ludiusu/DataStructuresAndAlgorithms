#include <iostream>
#include <vector>

using namespace std;

class PreSum
{
private:
    
    void InitSum(vector<int> nums)
    {
        size = nums.size();
        sum.resize(size);
        sum[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            sum[i] = sum[i - 1] + nums[i];
        }
    }
public:
    vector<int> sum;
    int size;
    PreSum(vector<int> nums) {PreSum::InitSum(nums);}
    ~PreSum() {}
    vector<int> GetPreSum(){ return sum; }
    string ToString()
    {
        string str = "";
        str += "Sum: [";
        for (int i = 0; i < size; i++)
        {
            str += to_string(sum[i]);
            str += i == size - 1 ? "]\n" : ", ";
        }
        return str;
    }
};

// Test
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    PreSum ps(nums);
    cout << ps.ToString();
    return 0;
}