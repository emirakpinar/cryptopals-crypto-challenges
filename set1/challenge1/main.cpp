//
// Created by Emir Yigit Akpinar on 24.03.2025.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string read_file(string filename)
{
    ifstream readobject (filename);
    if(!readobject.is_open())
    {
        cout << "Reading Error" << endl;
        return NULL;
    }
    else
    {
        string encrypted_text;
        while (getline(readobject, encrypted_text))
        {
        }
        readobject.close();
        return encrypted_text;
    }
}

int main()
{
    string text = read_file("string.txt");
    cout << text << endl;
    return 0;
}
