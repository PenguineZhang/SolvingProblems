#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

vector<int> solve(vector<int> &input, int target)
{
    int first = -1, last = -1;
    int mid;
    int temp_1 = 0, temp_2 = input.size() - 1;
    vector<int> output = {first, last};

    if (input.size() == 0)
    {
        return output;
    }

    // find the first position
    while (1)
    {
        if (temp_1 == temp_2 || temp_2 - temp_1 == 1)
        {
            if (input[temp_1] == target)
            {
                first = temp_1;
            }
            else if(input[temp_2] == target)
            {
                first = temp_2;
            }
            break;
        }
        else
        {
            mid =  (temp_2 + temp_1) / 2;
        }

        if(input[mid] == target)
        {
            temp_2 = mid - 1;
            first = mid;
        }
        else if (input[mid] < target)
        {
            temp_1 = mid + 1;
        }
        else 
        {
            temp_2 = mid - 1;
        }
    }

    if(first != -1)
    {
        temp_1 = first;
    }
    else
    {
        temp_1 = 0;
    }
    
    temp_2 = input.size() - 1;
    while (1)
    {
        if (temp_1 == temp_2 || temp_2 - temp_1 == 1)
        {
            if (input[temp_2] == target)
            {
                last = temp_2;
            }
            else if(input[temp_1] == target)
            {
                last = temp_1;
            }
            break;
        }
        else
        {
            mid =  (temp_2 + temp_1) / 2;
        }

        if(input[mid] == target)
        {
            temp_1 = mid + 1;
            last = mid;
        }
        else if (input[mid] < target)
        {
            temp_1 = mid + 1;
        }
        else 
        {
            temp_2 = mid - 1;
        }
    }

    output[0] = first;
    output[1] = last;
    return output;
}


int main(int argc, char** argv)
{
    vector<int> input = {};
    int target = 8;

    solve(input, target);

    return 0;
}