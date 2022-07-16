#include<bits/stdc++.h>
using namespace std;

int Add(string numbers)
{
    if(numbers.length()==0)
        return 0;
    else{
        if(numbers.find(",") == -1)
            return (stoi(numbers));

        else{
            int sum = 0;
            vector<string> str;
            string temp="";
            int strlen = numbers.length();
            for(int i=0; i<strlen; i++)
            {     
                if(numbers[i] == ',')
                {
                    str.push_back(temp);
                    temp = "";
                    continue;
                }
                temp += numbers[i];
            }
            if(temp!="")
                str.push_back(temp);

            for(auto num: str)
                sum += stoi(num);
            
            return sum;
        }
            
    }
}

int main()
{
    cout << Add("12,13");
    return 0;
}