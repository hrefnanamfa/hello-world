#include <iostream>
#include <fstream>

using namespace std;

void print(int n);

int main()
{
    char inp = 'x';
    bool run = true;
    int n = 0;

    while (run) {
        print(n);
        n += 10;

        while(inp != 'y') {
            cout << "Do you wish to continue(y/n)?";
            cin >> inp;
            if (inp == 'n') {run = false; break;}
        }
        inp = 'x';
    }

    return 0;
}

void print(int n) {
    ifstream fin;
    int counter = 0;
    string s;

    fin.open("text.txt");

    if (fin.is_open()) {
        if (n > 0)
            fin.seekg((n*8)-9, fin.beg);

        while(!fin.eof() && counter < 10) {
            getline(fin, s);
            cout << s << endl;
            counter++;
        }

        fin.close();
        counter = 0;

    }  else {
        cout << "Unable to read file";
    }

}
