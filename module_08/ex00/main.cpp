#include "easyfind.hpp"

int main()
{
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);

    try
    {
        ::easyfind(nums,10);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}