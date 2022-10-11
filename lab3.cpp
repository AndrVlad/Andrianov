#include <iostream>

using namespace std;

int main()
{
    short int m, n, M, N, elem, size_arr, i, j, k, l, I, J, result, counter, num, compare, res_el, new_el1, new_el2;
    int arr_1D[10], arr_2D[10][10], arr_2D1[10][10];
    string msg1, msg2, msg3, msg4;
    char choose;

    while (choose != 'X') {

        cout << "\n" << "Choose NUMBER of program: \n" << "For exit write X \n";
        cout << "1. Sum of elements in 1D array; \n" << "2. Multiplication of elements in 1D array; \n";
        cout << "3. Sum of elements on main diagonale \n" << "4. Sum of elements under main diagonale \n";
        cout << "5. Sum of elements over main diagonale \n" << "6. Sum of elements on side diagonale \n";
        cout << "7. MAX elements on CHETNICH strings \n" << "8. MIN elements on NECHETNICH columns \n";
        cout << "9. Multiplication of two matrix \n \n";

        cin >> choose;

        if (choose == 'X') {
            return 0;
        } else {

        msg1 = "Input size of array \n";
        msg2 = "Input elements \n";
        msg3 = "Input num of strings \n";
        msg4 = "Input num of columns \n";

        switch (choose) {
            case '1':
                {
                    cout << msg1;
                    cin >> size_arr;
                    cout << msg2;

                        for (i = 0; i < size_arr; i++) {
                            cin >> arr_1D[i];
                            result += arr_1D[i];
                        }
                            cout << "Array = { ";

                            for (i = 0; i < size_arr; i++) {
                                cout << arr_1D[i] << " ";
                            }

                            cout << "}";
                            cout << "Result = " << result << " \n ";
                            break;
                }

            case '2':
                {
                    cout << msg1;
                    cin >> size_arr;
                    cout << msg2;
                    result = 1;

                        for (i = 0; i < size_arr; i++) {
                            cin >> arr_1D[i];
                            result = arr_1D[i] * result;
                        }
                            cout << "Array = { ";

                            for (i = 0; i < size_arr; i++) {
                                cout << arr_1D[i] << " ";
                            }

                            cout << "}";
                            cout << "Result = " << result << " \n ";
                            break;
                }

            case '3':
                {
                    cout << msg3;
                    cin >> m;
                    cout << msg4;
                    cin >> n;

                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++){
                                cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                cin >> arr_2D[i][j];
                                cout << "\n";
                            }
                        }
                            // ВЫВОД МАССИВА

                            for (i = 0; i < m; i++) {
                                for (j = 0; j < n; j++){
                                    cout << arr_2D[i][j] << "  ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                            // ПОДСЧЕТ СУММЫ ЗНАЧЕНИЙ ПО ДИАГОНАЛИ
                                for (i = 0; i < m; i++) {
                                    for (j = 0; j < n; j++){
                                        if (i == j) {
                                            result += arr_2D[i][j];
                                            //cout << "\n" << result << endl;
                                        }
                                    }
                                }

                                cout << "Result: " << result << endl;
                                result = 0;
                                break;
                            }
            case '4':
                {
                    cout << msg3;
                    cin >> m;
                    cout << msg4;
                    cin >> n;

                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++){
                                cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                cin >> arr_2D[i][j];
                                cout << "\n";
                            }
                        }
                            // ВЫВОД МАССИВА

                            for (i = 0; i < m; i++) {
                                for (j = 0; j < n; j++){
                                    cout << arr_2D[i][j] << "  ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                            // ПОДСЧЕТ СУММЫ ЗНАЧЕНИЙ
                                for (j = 0; j < n; j++) {
                                    for (i = 0; i < m; i++){
                                        if (counter == 1) {
                                            result += arr_2D[i][j];
                                        }
                                        if (i == j) {
                                            counter = 1;
                                        }
                                    }
                                    counter = 0;
                                }

                                cout << "Result: " << result << endl;
                                result = 0;
                                break;
                }
            case '5':
                {
                    cout << msg3;
                    cin >> m;
                    cout << msg4;
                    cin >> n;

                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++){
                                cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                cin >> arr_2D[i][j];
                                cout << "\n";
                            }
                        }
                            // ВЫВОД МАССИВА

                            for (i = 0; i < m; i++) {
                                for (j = 0; j < n; j++){
                                    cout << arr_2D[i][j] << "  ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                            // ПОДСЧЕТ СУММЫ ЗНАЧЕНИЙ
                                for (i = 0; i < m; i++) {
                                    for (j = 0; j < n; j++){

                                        if (counter == 1) {
                                            result += arr_2D[i][j];
                                        }
                                        if (i == j) {
                                            counter = 1;
                                        }
                                    }
                                    counter = 0;
                                }

                                cout << "Result: " << result << endl;
                                result = 0;
                                break;
                }
            case '6':
                {
                    cout << msg3;
                    cin >> m;
                    cout << msg4;
                    cin >> n;

                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++){
                                cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                cin >> arr_2D[i][j];
                                cout << "\n";
                            }
                        }
                            // ВЫВОД МАССИВА

                            for (i = 0; i < m; i++) {
                                for (j = 0; j < n; j++){
                                    cout << arr_2D[i][j] << "  ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                            // ПОДСЧЕТ СУММЫ ЗНАЧЕНИЙ

                                for (i = 0; i < m ; i++) {
                                    for (j = 0; j < n; j++){
                                        if (i+j == n - 1) {
                                            result *= arr_2D[i][j];
                                        }
                                    }

                                }

                                cout << "Result: " << result << endl;
                                result = 0;
                                break;
                }
            case '7':
                {
                    cout << msg3;
                    cin >> m;
                    cout << msg4;
                    cin >> n;

                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++){
                                cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                cin >> arr_2D[i][j];
                                cout << "\n";
                            }
                        }
                            // ВЫВОД МАССИВА

                            for (i = 0; i < m; i++) {
                                for (j = 0; j < n; j++){
                                    cout << arr_2D[i][j] << "  ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                            // ПОДСЧЕТ

                                for (i = 0; i < m ; i++) {
                                    compare = 0;
                                    if (i % 2 != 0) {
                                        for (j = 0; j < n; j++) {
                                            if (compare <= arr_2D[i][j])
                                            {
                                                compare = arr_2D[i][j];

                                            }
                                        }
                                        cout << "MAX on " << i+1 << " string is: " << compare << endl;
                                    }
                                }
                                break;
                }
            case '8':
                {
                    cout << msg3;
                    cin >> m;
                    cout << msg4;
                    cin >> n;

                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++){
                                cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                cin >> arr_2D[i][j];
                                cout << "\n";
                            }
                        }
                            // ВЫВОД МАССИВА

                            for (i = 0; i < m; i++) {
                                for (j = 0; j < n; j++){
                                    cout << arr_2D[i][j] << "  ";
                                }
                                cout << endl;
                            }
                            cout << endl;
                            // ПОДСЧЕТ МИНИМУМА

                                for (j = 0; j < n; j++) {
                                    if (j % 2 == 0) {
                                        compare = arr_2D[0][j];

                                        for (i = 0; i < m; i++) {

                                            if (compare >= arr_2D[i][j])
                                            {
                                                compare = arr_2D[i][j];
                                            }
                                        }
                                        cout << "MIN on " << j+1 << " column is: " << compare << endl;
                                    }
                                }


                                break;
                }
            case '9':
                {
                    cout << "\n" << "Input size of FIRST matrix \n";
                    cout << msg3;
                    cin >> m;
                    cout << msg4;
                    cin >> n;

                    cout << "\n" << "Input size of SECOND matrix \n";
                    cout << msg3;
                    cin >> M;
                    cout << msg4;
                    cin >> N;

                    if (n != M) {
                        cout << "\n" << "\n" << "One of the matrix has incorrect size. Try again \n";
                        break;
                    } else {

                        cout << "\n" << "Input elements of FIRST matrix \n";

                        for (i = 0; i < m; i++) {
                            for (j = 0; j < n; j++){
                                cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                cin >> arr_2D[i][j];
                                cout << "\n";
                            }
                        }

                        cout << "Input elements of SECOND matrix \n";

                            for (i = 0; i < M; i++) {
                                for (j = 0; j < N; j++){
                                    cout << "Input a(" << i+1 << "," << j+1 << "): ";
                                    cin >> arr_2D1[i][j];
                                    cout << "\n";
                                }
                            }

                                int arr_proizv[m][N];

                                    for (i = 0; i < m; i++) {
                                        for (j = 0; j < N; j++) {
                                                arr_proizv[i][j] = 0;
                                            for (k = 0; k < n; k++) {
                                                arr_proizv[i][j] += arr_2D[i][k] * arr_2D1[k][j];
                                            }
                                                cout << arr_proizv[i][j] << "  ";
                                        }

                                        cout << endl;
                                    }


                    }


                    break;
                } // end of case
        } //end of switch



    } // end of if-else
    } // end of While


}

