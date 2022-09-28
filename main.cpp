#include <iostream>
#include <string>

using namespace std;

int main()
{
    short int n, counter, sum, sum_pr;
    string input, exit;
    char symbol;
    n = 0;

 /*   do
    {
        cout << "Input number: \n";
        cin >> input;
        cout << "For exit write \'E'\ ";

    } while((input != "E") || (input != "e"));

*/



    while ((input != "E") || (input != "e")) {

    cout << "For exit use 'E' or 'e' \n";
    cout << "Input number: \n";
    cin >> input;

    if ((input == "E") || (input == "e")) {
        return 0;
    } else {

        counter = 0;
        sum_pr = 0;

        for (int i = 0; i < input.size(); i++) {

            symbol = input[i];

                switch (symbol)
                {
                    case 'X': {
                        n = 10;
                        break;
                    }
                    case 'V': {
                        n = 5;
                        break;
                    }
                    case 'I': {
                        n = 1;
                        break;
                    }
                }

                if (counter == 0 || counter == n)
                {
                    counter = n;
                    sum += n;
                }

                if (counter < n)
                {
                    //counter = n;
                    sum_pr = (-2 * counter) + n;
                    sum += sum_pr;

                } else if (counter > n)
                    {
                        //counter = n;
                        sum += n;
                    }

            counter = n;
        }

        cout << "Your result number is:  " << sum << "\n";
        sum = 0;

    }


    }
    return 0;
}


