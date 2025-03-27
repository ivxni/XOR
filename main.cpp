#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    char buffer;
    int key;
    cout << "Enter Key:";
    cin >> key;
    cout << key << endl;

    input.open("file.bin", ios::binary);

    if (input.is_open() == true)
    {
        cout << "File opened" << endl;
    } else
    {
        cerr << "File not opened" << endl;
        return 1;
    }

    output.open("output.bin", ios::binary);

    if (output.is_open() == true)
    {
        cout << "File opened" << endl;
    } else
    {
        cerr << "File not opened" << endl;
        return 1;
    }

    while (input.get(buffer))
    {
        char xorResult = buffer ^ key;
        output.put(xorResult);
    }

    input.close();
    output.close();

    cout << "Inputs and outputs closed" << endl;

    return 0;
}