#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream myInputFile(argv[1]);

    if(myInputFile.is_open())
    {
        string input;

        while(getline(myInputFile,input))
        {
            cout << input << endl;
        }
    }
    else
    {
        cout << "Check input file!" << endl;
    }

    return 0;
}
