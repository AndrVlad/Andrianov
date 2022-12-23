#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    char in_str[100], read_str[100];
    //string read_str;
    int i = 1, n;
    ofstream file1("lab8.txt");
    cout << "Input strings in file" << endl;

        while (*in_str != ' ') {
            cin.getline(in_str, 100);
            file1 << in_str << "\n";
        }

        file1.close();

        ifstream file2("lab8.txt");

        if (file2.is_open()) {
            cout << "File is open" << endl;
        } else {
            cout << "Error with file";
        }

        ofstream promFile("promfile.txt", ios_base::out);

            while (file2) {
                file2.getline(read_str, 100);
                int sizestr = sizeof(read_str);
                //cout << sizestr;
                //cout << read_str << endl;

                if (read_str[0] == ',') {
                    read_str[0] = ' ';
                    for (i = 0; i < 100; i++) {
                        read_str[i] = read_str[i+1];
                    }

                    //cout << "First ," << endl;
                }



               // do {

               for (i = 0; i < 100; i++) {
                    if (read_str[i] == ',' && read_str[i+1] == ',') {
                        n = 1;
                        int j = i;
                      while (read_str[i+1] == ',') {
                            for (j; j < 100; j++, n++) {
                                read_str[j+n] = read_str[j+1+n];
                            }

                        }

                        cout << "double ,,";
                    }

               }
                   // i++;
                //} while (read_str[i]);

                promFile << read_str << endl;
                n = 1;
                i = 1;


            }

            promFile.close();
            file2.close();

            cout << endl;

                if (remove("lab8.txt")) {
                    cout << "Error with deleting file" << endl;
                } else {
                    cout << "File was deleted" << endl;
                }

                char oldname[] = "promfile.txt";
                char newname[] = "lab8.txt";

                    if (rename(oldname, newname) == 0) {
                        cout << "File was renamed" << endl;
                    } else {
                        cout << "Error with rename file";
                    }

                        ifstream newfile("lab8.txt");

                        if (newfile.is_open()) {
                            cout << "File is open" << endl;

                             while (newfile) {
                                newfile.getline(read_str, 100);
                                cout << read_str << endl;
                             }

                        } else {
                            cout << "Error with file";
                        }







    return 0;
}
