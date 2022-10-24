#include <iostream>
#include <string>
#include <cstdlib>

struct Firm {
        unsigned int id;
        std::string FIO;
        float salary;
        char job[15];
        char gender [7];

    };

int main()
{
    char chooseSym;
    std::string FIO_string,str1;
    int i, numMale, numFemale, Fond, FondFemale, FondMale;
    numMale = 0;
    numFemale = 0;
    Firm * pFirm;
    pFirm = new Firm[1];

    std::cout << "Input identificator of worker \n";
    (std::cin >> pFirm[0].id).get();
    std::cout << "Input FIO of worker \n";
    getline(std::cin, str1);
    pFirm[0].FIO = str1;
    std::cout << "Input salary of worker \n";
    std::cin >> pFirm[0].salary;
    std::cout << "Input job of worker \n";
    std::cin >> pFirm[0].job;
    std::cout << "Input gender of worker \n";
    std::cin >> pFirm[0].gender;


    std:: cout << "\t\t Do you want do add more worker? \'y'\ - yes, \'n'\ - no \n";
    std::cin >> chooseSym;

        while ((chooseSym != 'y') && (chooseSym != 'n')) {

            std::cout << "Incorrect input, try again" << std::endl;
            std::cin >> chooseSym;
        }

        if (chooseSym == 'n') {

            std::cout << std::endl << "ID \t" << pFirm[0].id << std::endl << "FIO \t" << pFirm[0].FIO << std::endl;
            std::cout << "Salary \t" << pFirm[0].salary << std::endl << "Job \t" << pFirm[0].job << std::endl;
            std::cout << "Gender \t" << pFirm[0].gender << std::endl;
            return 0;

        } else if (chooseSym == 'y') {

            int numString = 1;

            while (chooseSym != 'x') {

        if (chooseSym == 'y') {

            numString++;
            Firm * pFirmAdd;
            pFirmAdd = new Firm[numString];


                for (int i = 0; i < numString - 1; i++) {
                    pFirmAdd[i] = pFirm[i];
                }

                delete [] pFirm;

                pFirm = pFirmAdd;


            std::cout << "Input identificator of worker \n";
            (std::cin >> pFirm[numString-1].id).get();
            std::cout << "Input FIO of worker \n";
            getline(std::cin, str1);
            pFirm[numString - 1].FIO = str1;
            std::cout << "Input salary of worker \n";
            std::cin >> pFirm[numString-1].salary;
            std::cout << "Input job of worker \n";
            std::cin >> pFirm[numString-1].job;
            std::cout << "Input gender of worker \n";
            std::cin >> pFirm[numString-1].gender;

        } else if (chooseSym == 'n') {

            Fond = 0;
            for (i = 0; i < numString; i++) {

                Fond += pFirm[i].salary;
                std::cout << pFirm[i].salary;

            }

                FondFemale = 0;
                FondMale = 0;

                for (i = 0; i < numString; i++) {

                    if ((*pFirm[i].gender == 'M') || (*pFirm[i].gender == 'm')) {

                        numMale++;
                        FondMale += pFirm[i].salary;

                    } else {

                        numFemale++;
                        FondFemale += pFirm[i].salary;
                    }

                }

            for (i = 0; i < numString; i++) {

                std::cout << std::endl << "ID \t" << pFirm[i].id << std::endl << "FIO \t" << pFirm[i].FIO << std::endl;
                std::cout << "Salary \t" << pFirm[i].salary << std::endl << "Job \t" << pFirm[i].job << std::endl;
                std::cout << "Gender \t" << pFirm[i].gender << std::endl;

            }

            std::cout << std::endl << "Fond of salary in Firm = " << Fond << std::endl;
            std::cout << "Num of Male workers in Firm = " << numMale << std::endl;
            std::cout << "Num of Female workers in Firm = " << numFemale << std::endl;
            std::cout << "Fond of salary of Male workers = " << FondMale << std::endl;
            std::cout << "Fond of salary of Female workers = " << FondFemale << std::endl;

            delete [] pFirm;
            return 0;


        } else {
            std::cout << std::endl << "Error input, try again";
        }

        std:: cout << "\t\t Do you want do add more worker? \'y'\ - yes, \'n'\ - no \n";
        std::cin >> chooseSym;

        while ((chooseSym != 'y') && (chooseSym != 'n')) {

            std::cout << "Incorrect input, try again" << std::endl;
            std::cin >> chooseSym;
        }
    }


        }  // end of if-else


}
