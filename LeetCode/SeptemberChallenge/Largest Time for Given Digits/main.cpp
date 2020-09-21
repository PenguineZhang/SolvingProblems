#include <bits/stdc++.h>

using namespace std;

string largestTimeFromDigits(vector<int>& A)
{
    sort(A.begin(), A.end());

    int hr, min;
    int max = -1;
    do{
        hr = A[0] * 10 + A[1];
        min = A[2] * 10 + A[3];

        if(hr < 24 && min < 60)
        {
            int time = hr*60 + min;
            max = time > max ? time : max;
        }

    }while(next_permutation(A.begin(), A.end()));

    cout << max << endl;

    if(max == -1)
    {
        return "";
    }
    else
    {
        string output("");
        output += max/60 < 10 ? "0" + to_string(max/60) : to_string(max/60);
        output += ":";
        output += max%60 < 10 ? "0" + to_string(max%60) : to_string(max%60);

        return output;
    }

}

int main(int argc, char** argv)
{
    vector<int> input = {2,0,6,6};
    string output = largestTimeFromDigits(input);
    cout << output << endl;

    return 0;
}