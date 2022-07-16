#include <bits/stdc++.h>
using namespace std;

int Add(string numbers)
{
    int strlen = numbers.length();
    if (strlen == 0)
        return 0;
    else
    {
        if (numbers.find(",") == -1 && numbers.find(";") == -1){
            if(numbers[0] == '/' && numbers[1] == '/'){
                string remstr = numbers.substr(4);
                return (stoi(numbers));
            }
            return (stoi(numbers));
        }

        if ((numbers[0] == '/') && (numbers[1] == '/'))
        {
            char delimeter = numbers[2];
            int s = 0;
            string temp1 = "";
            vector<string> vctr;
    
            for (int i = 4; i < strlen; i++)
            {
                if ((i + 1) < strlen && numbers[i] == delimeter && numbers[i + 1] == '\n')
                {
                    cout << "Invalid input";
                    exit(0);
                }
                if (numbers[i] == '\n' && temp1 != "")
                {
                    vctr.push_back(temp1);
                    continue;
                }

                if (numbers[i] == delimeter)
                {
                    vctr.push_back(temp1);
                    temp1 = "";
                    continue;
                }
                if(numbers[i] >= '0' && numbers[i] <= '9')
                    temp1 += numbers[i];
            }
            if (temp1 != "")
                vctr.push_back(temp1);

            for (auto n : vctr)
                s += stoi(n);
            
            return s;
        }
        else
        {
            int sum = 0;
            vector<string> str;
            string temp = "";

            for (int i = 0; i < strlen; i++)
            {
                if ((i + 1) < strlen && numbers[i] == ',' && numbers[i + 1] == '\n')
                {
                    cout << "Invalid input";
                    exit(0);
                }
                if (numbers[i] == '\n' && temp != "")
                {
                    str.push_back(temp);
                    temp = "";
                    continue;
                }
                if (numbers[i] == ',')
                {
                    str.push_back(temp);
                    temp = "";
                    continue;
                }
                if(numbers[i]>='0' && numbers[i]<='9')
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
    cout << Add("1");
    return 0;
}