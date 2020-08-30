#include <bits/stdc++.h>

using namespace std;

string solve(string &s)
{
    string output = "";
    if(s.size() == 0)
    {
        return output;
    }

    vector<pair<int, int>> candidates;

    for( int i = 0; i < s.size(); i++ )
    {
        if(i + 2 < s.size())
        {
            if (s[i] == s[i+2])
            {
                candidates.push_back(make_pair(i, i+2));
            }
        }

        if(i + 1 < s.size())
        {
            if(s[i] == s[i+1])
            {
                candidates.push_back(make_pair(i, i+1));
            }
        }
    }

    if(candidates.empty())
    {
        output = s.front();
        return output;
    }

    int head_idx = 0;
    int head = 0, tail = 0;    
    int longest = -1;
    int length = 0;

    for(auto& pair: candidates)    
    {
        head = pair.first;
        tail = pair.second;
        
        while (head > 0 && tail < s.size()-1)
        {   
            head--;
            tail++;

            if (s[head] != s[tail])
            {
                head++;
                tail--;
                break;
            }

        }

        length = tail - head + 1;
        if ( length > longest )
        {
            longest = length;
            head_idx = head;            
        }
    }

    output = s.substr(head_idx, longest);

    return output;
}

int main(int argc, char** argv)
{
    string input("aaaa");
    string output = solve(input);
    cout << output << endl;

    return 0;
}

