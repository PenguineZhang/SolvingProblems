#include <iostream>
#include <vector>

using namespace std;

// super bad solution
// int solve(vector<int>& height)
// {
//     int max = 0;
//     int temp = 1;
//     for(int i = 0; i < height.size(); i++)
//     {
//         for(int j = i + 1; j < height.size(); j++)
//         {
//             temp = height[i] > height[j] ? height[j] : height[i];
//             max = max <= temp * (j - i) ? temp * (j - i) : max;
//         }
//     }

//     return max;
// }

int solve(vector<int>& height)
{

    int max = 0;
    int length_short=0;
    int area=0;
    for(int i = 0, j = height.size() - 1; i < j;)
    {
        length_short = height[j] < height[i] ? height[j] : height[i];
        max = ((j - i) * length_short) > max ?  (j - i) * length_short : max;
        height[j] < height[i] ? j-- : i++;
    }


    return max;
}

int main(int argc, char** argv)
{
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    int output = solve(input);
    cout << output << endl;
}