#include <iostream>
#include <fstream>

using namespace std;

void print10();

int main()
{
    char inp = 'x';
    bool run = true;

    while (run) {
        print10();

        while(inp != 'y') {
            cout << "Do you wish to continue(y/n)?";
            cin >> inp;
            if (inp == 'n') {run = false; break;}
        }
        inp = 'x';
    }

    return 0;
}

void print10() {
    ifstream fin;
    int counter = 0;
    string s;

    fin.open("text.txt");

    if (fin.is_open()) {

        while(!fin.eof()) {
            getline(fin, s);
            cout << s << endl;
            counter++;
        } // END STREAM

        fin.close();
        counter = 0;

    }  else {
        cout << "Unable to read file";
    }// END IF
}
