//
// Created by Emir Yigit Akpinar on 24.03.2025.
// Intentionally not used any library or pre-installed function such as stoi etc. I tried to create everthing from rock please enjoy :)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string read_file(const string &filename)
{
    ifstream readobject(filename);
    if (!readobject.is_open())
    {
        cout << "Reading Error" << endl;
        return "";
    }
    else
    {
        string result;
        string line;
        while (getline(readobject, line))
        {
            result += line;
        }
        readobject.close();
        return result;
    }
}

void write_file(const string &filename, const string &content)
{
    ofstream writeobject(filename);
    if (!writeobject.is_open())
    {
        cout << "Writing Error" << endl;
        return;
    }
    else
    {
        writeobject << content;
        writeobject.close();
    }
}

string hex_to_ascii(string hex)
{
    string ascii_text;
    for (int i = 0; i < hex.length(); i += 2)
    {
        int value = 0;
        char first_digit = hex[i];
        char second_digit = hex[i + 1];

        if (first_digit >= '0' && first_digit <= '9') // !Magic Happens Here! digit manipulation on hex to find ascii char value
        {
            value += (first_digit - '0') * 16;
        }
        else if (first_digit >= 'A' && first_digit <= 'F')
        {
            value += (first_digit - 'A' + 10) * 16;
        }
        else if (first_digit >= 'a' && first_digit <= 'f')
        {
            value += (first_digit - 'a' + 10) * 16;
        }
        else
        {
            cout << "Error: Invalid Hexadecimal Character" << endl;
        }

        if (second_digit >= '0' && second_digit <= '9')
        {
            value += (second_digit - '0');
        }
        else if (second_digit >= 'A' && second_digit <= 'F')
        {
            value += (second_digit - 'A' + 10);
        }
        else if (second_digit >= 'a' && second_digit <= 'f')
        {
            value += (second_digit - 'a' + 10);
        }
        else
        {
            cout << "Error: Invalid Hexadecimal Character" << endl;
        }

        ascii_text += char(value);
    }
    return ascii_text;
}

string hex_to_base64(string hex)
{
    const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string base64;
    while (hex.length() % 3 != 0) // padding
    {
        hex += '0';
    }
    for (int i = 0; i < hex.length(); i += 3)
    {
        int value = 0;
        int first_digit = hex[i];
        int second_digit = hex[i + 1];
        int third_digit = hex[i + 2];

        if (first_digit >= '0' && first_digit <= '9') // !Magic Happens Here! digit manipulation on hex to find ascii char value
        {
            value += (first_digit - '0') * 256;
        }
        else if (first_digit >= 'A' && first_digit <= 'F')
        {
            value += (first_digit - 'A' + 10) * 256;
        }
        else if (first_digit >= 'a' && first_digit <= 'f')
        {
            value += (first_digit - 'a' + 10) * 256;
        }
        else
        {
            cout << "Error: Invalid Hexadecimal Character" << endl;
        }

        if (second_digit >= '0' && second_digit <= '9')
        {
            value += (second_digit - '0') * 16;
        }
        else if (second_digit >= 'A' && second_digit <= 'F')
        {
            value += (second_digit - 'A' + 10) * 16;
        }
        else if (second_digit >= 'a' && second_digit <= 'f')
        {
            value += (second_digit - 'a' + 10) * 16;
        }
        else
        {
            cout << "Error: Invalid Hexadecimal Character" << endl;
        }

        if (third_digit >= '0' && third_digit <= '9')
        {
            value += (third_digit - '0');
        }
        else if (third_digit >= 'A' && third_digit <= 'F')
        {
            value += (third_digit - 'A' + 10);
        }
        else if (third_digit >= 'a' && third_digit <= 'f')
        {
            value += (third_digit - 'a' + 10);
        }
        else
        {
            cout << "Error: Invalid Hexadecimal Character" << endl;
        }

        char base64_first_digit;
        char base64_second_digit;
        base64_first_digit = base64_chars[value / 64];
        base64_second_digit = base64_chars[value % 64];
        base64 += base64_first_digit;
        base64 += base64_second_digit;
    }
    return base64;
}

int main()
{
    string text = read_file("input.txt");
    string ascii_text = hex_to_ascii(text);
    cout << "Hex to ASCII: " << ascii_text << endl;
    string base64_text = hex_to_base64(text);
    cout << "Hex to base64: " << base64_text << endl;
    write_file("output.txt", base64_text);
    return 0;
}
