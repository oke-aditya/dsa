// File handling using fstream

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  // Creation of fstream object
  fstream fio;

  string line = "hello world";

  // by default openmode = ios::in|ios::out mode
  // Automatically overwrites the content of file, To append
  // the content, open in ios:app
  // fio.open("sample.txt", ios::in|ios::out|ios::app)

  fio.open("hello2.txt", ios::trunc | ios::out | ios::in);

  while (fio) {
    fio << line << endl;
    fio.close();
  }

  fio.seekg(0, ios::beg);
  while (fio) {
    getline(fio, line);

    cout << line << endl;

    fio.close();
  }

  return 0;
}
