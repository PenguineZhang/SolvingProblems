#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

// pretty slow: 84 ms and 18.3 MB
// string solve(string &s, int numRows)
// {
//     unordered_map<int, vector<int>> dict;    
//     int order = 1;
//     int counter = 0;

//     if (numRows == 1)
//     {
//         return s;
//     }

//     for (int i = 0; i < s.size(); i++)
//     {
//         if(counter == 0)
//         {
//             order = 1;
//         }
//         else if(counter == numRows - 1)
//         {
//             order = -1;
//         }

//         dict[counter].push_back(i);
//         counter += order;
//     }
    
//     string output;
//     for (int i = 0; i < numRows; i++)
//     {
//         for (auto& v : dict[i])
//         {
//             output.push_back(s[v]);
//         }
//     }
//     return output;
// }

string solve(string& s, int numRow)
{
    if(numRow == 1)
    {
        return s;
    }

    if(s.size() <= numRow)
    {
        return s;
    }

    string output(s.size(), ' ');

    int period = 2 * (numRow - 1);
    int n, sub_period;
    int alternater;
    int pos = 0;
    for(int i = 0; i < numRow; i++)
    {
        n = i;
        if( i == 0 || i == numRow - 1)
        {
            do
            {
                output[pos++] = s[n];
                
                n += period;
            } while (n < s.size());
        }
        else
        {
            alternater = 1;
            sub_period = 2*i;
            do
            {
                output[pos++] = s[n];
                n += alternater > 0 ? period-sub_period : sub_period;
                alternater *= -1;
                
            } while (n < s.size());
        }
        
    }
    

    return output;
}

int main(int argc, char** argv)
{
    string input = "PAYPALISHIRING";
    int nrow = 4;
    string output = solve(input, nrow);
    cout << output << endl;
    return 0;
}