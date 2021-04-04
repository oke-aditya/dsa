// In C++, files are mainly dealt by using three classes fstream, ifstream, ofstream available in fstream headerfile.
// ofstream: Stream class to write on files
// ifstream: Stream class to read from files
// fstream: Stream class to both read and write from/to files.

// Now the first step to open the particular file for read or write operation. We can open file by
// 1. passing file name in constructor at the time of object creation
// 2. using the open method
// ifstream	ios::in
// ofstream	ios::out
// fstream	ios::in | ios::out

#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    // ofstream object
    ofstream fout;

    string line="hello world";

    // by default ios::out mode, automatically deletes
    // the content of file. To append the content, open in ios:app
    // fout.open("sample.txt", ios::app)
    
    fout.open("hello.txt");

    // While the file is open
    while(fout)
    {
        // Write line to the file
        fout<<line<<endl;
        // Close the file
        fout.close();
    }

    // Creation of istream class to read the file
    ifstream fin;

    fin.open("hello.txt");

    // Execute till endo of file is reached.
    while(fin)
    {
        // Read line from the file
        getline(fin, line);

        cout<<line<<endl;
    }

    // Close the file.
    fin.close();

    return 0;
}


