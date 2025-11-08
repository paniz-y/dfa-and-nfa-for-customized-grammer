#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

enum State
{
    q0,q1,
    q2,q3,
    q4,q5,
    q6,q7,
    q8,q9,
    q10,q11,
    q12,q13,
    q14,q15,
    q16,q17,
    q18,q19,
    q20,q21,
    q22
};

bool isAccepted(const string &input)
{
    State current = q0;

    for (char c : input)
    {
        switch (current)
        {
        case q0:
            if (c == 'f')
                current = q1;
            else if (isdigit(c))
                current = q9;
            else if (c == 'r')
                current = q11;
            else if (c == '(')
                current = q18;
            else if (c == ')')
                current = q17;
            else if (c == '{')
                current = q19;
            else if (c == '}')
                current = q20;
            else if (c == '=')
                current = q21;
            else if (c == ';')
                current = q22;
            else if (c == ' ')
                current = q0;
            else
                return false;
            break;

        case q1:
            if (c == 'u')
                current = q2;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q2:
            if (c == 'n')
                current = q3;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q3:
            if (c == 'c')
                current = q4;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q4:
            if (c == 't')
                current = q5;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q5:
            if (c == 'i')
                current = q6;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q6:
            if (c == 'o')
                current = q7;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q7:
            if (c == 'n')
                current = q8;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q9:
            if (isdigit(c))
                current = q9;
            else
                return false;
            break;
        case q10:
            if (isdigit(c) || isalpha(c) || c == '_')
                current = q10;
            else
                return false;
            break;
        case q11:
            if (c == 'e')
                current = q12;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q12:
            if (c == 't')
                current = q13;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q13:
            if (c == 'u')
                current = q14;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q14:
            if (c == 'r')
                current = q15;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        case q15:
            if (c == 'n')
                current = q16;
            else if (isalpha(c))
                current = q10;
            else
                return false;
            break;
        }
    }

    return (current == 8 || current == 9 || current == 10 || current == 17 || current == 18 || current == 19 || current == 20 || current == 21 || current == 22);
}
void readInputFromFile(string &inputStr)
{
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cerr << "could not open the input file" << endl;
        return;
    }

    string line;
    while (getline(input, line))
    {
        inputStr += line + '\n';
    }
    input.close();
}

int main()
{
    string inputStr;
    readInputFromFile(inputStr);
    if (isAccepted(inputStr))
        cout << "\"\n"
             << inputStr << "\"\nis accepted by the DFA" << endl;
    else
        cout << "\"\n"
             << inputStr << "\"\nis rejected by the DFA" << endl;

    return 0;
}
