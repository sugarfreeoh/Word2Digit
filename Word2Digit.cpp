#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

unsigned int StringToInt(string input)
{
    unsigned int val = 99;

    if( input.compare("zero") == 0 )
    {
        val = 0;
    }
    else if( input.compare("one") == 0 )
    {
        val = 1;    
    }
    else if( input.compare("two") == 0)
    {
        val = 2;
    }
    else if( input.compare("three") == 0)
    {
        val = 3;
    }
    else if( input.compare("four") == 0)
    {
        val = 4;
    }
    else if( input.compare("five") == 0)
    {
        val = 5;
    }
    else if( input.compare("six") == 0)
    {
        val = 6;
    }
    else if( input.compare("seven") == 0)
    {
        val = 7;
    }
    else if( input.compare("eight") == 0)
    {
        val = 8;
    }
    else if( input.compare("nine") == 0)
    {
        val = 9;
    }
    else
    {
        cout << "Error parsing string value" << endl;
        val = 99;
    }

    return val;
}

int main(int argc, char* argv[])
{
    ifstream myInputFile(argv[1]);

    if(myInputFile.is_open())
    {
        string input;

        while(getline(myInputFile,input))
        {
            //cout << input << endl;

            int currToken = 0;
            unsigned int index = 0;
            unsigned int digit = 0;

            string subInput;

            while(index != input.length())    
            {
                if(input[index] == ';' || index == input.length()-1)
                {
                    //cout << "    Current Token: " << input[index] << endl;
                    //cout << "    Current Token Index: " << index << endl;
                    //cout << "    Last Token Index: " << currToken << endl;
                    //cout << "    Length of string: " << index - currToken - 1 << endl;

                    if(currToken == 0)
                    {
                        subInput = input.substr(currToken, index - currToken);
                    }
                    else if(index == input.length()-1)
                    {
                        subInput = input.substr(currToken+1,index - currToken);
                    }
                    else
                    {
                        subInput = input.substr(currToken+1,index - currToken - 1);       
                    }

                    digit = StringToInt(subInput);

                    cout << digit;

                    currToken = index;  

                    //cout << "    " << subInput << endl;
                }

                ++index;
            }

            cout << endl;

            index = 0;
        }
    }
    else
    {
        cout << "Check input file!" << endl;
    }

    return 0;
}
