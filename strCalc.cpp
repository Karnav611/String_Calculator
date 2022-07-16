#include <bits/stdc++.h>
using namespace std;

int Add(string numbers)
{
    int strlen = numbers.length();
    if (strlen == 0)
        return 0;
    else
    {
        if (numbers.find(",") == -1)
            return (stoi(numbers));

        else
        {
            int sum = 0;
            vector<string> str;
            string temp = "";
            
            for (int i = 0; i < strlen; i++)
            {
                if((i+1) < strlen && numbers[i] == ',' && numbers[i+1] == '\n')
                {
                    cout << "Invalid input";
                    exit(0);
                }
                if(numbers[i] == '\n' && temp!="")
                {
                    str.push_back(temp);
                    temp="";
                    continue;
                }
                if (numbers[i] == ',')
                {
                    str.push_back(temp);
                    temp = "";
                    continue;
                }
                temp += numbers[i];
            }
            if (temp != "")
                str.push_back(temp);

            for (auto num : str)
                sum += stoi(num);

            return sum;
        }
    }
}

int main()
{
    cout << Add("1\n2,3");
    return 0;
}