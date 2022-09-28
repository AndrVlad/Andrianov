#include <iostream>
#include <string>

using namespace std;

int main()
{
    short int size_word, check, n, counter, sum, sum_pr, i;
    string input, exit;
    char symbol;
    n = 0;
    check = 0;

    while ((input != "E") || (input != "e")) {
    stop:
    cout << "For exit use 'E' or 'e' \n";
    cout << "Input number: \n";
    cin >> input;
    size_word = input.size();

    if ((input == "E") || (input == "e")) {
        return 0;
    }


        for (i = 0; i < input.size(); i++) {

            if ((input[i] != 'X') && (input[i] != 'V') && (input[i] != 'I'))
            {
                cout << "Input is incorrect, try again \n";
                goto stop;
            }
        }

        counter = 0;
        sum_pr = 0;

        for (i = 0; i < input.size(); i++) {

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

    return 0;
}




