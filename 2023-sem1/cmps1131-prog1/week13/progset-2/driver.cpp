/* Jennessa Sierra
* November 6, 2023
* Assignment: Program Set 2
* CMPS1131-4: Principles of Programming */

#include <iostream>
#include <cstdlib>
#include "Miscellaneous.h"

using std::cout;
using std::cin;
using std::endl;

void showMenu();
int getResponse();

int main() {
    int response;

    while ( ( response = getResponse() ) != 5 ) {
        switch( response ) {
            case 1: Miscellaneous::multiplication(); cout<<"\n\n"; break;
            case 2: Miscellaneous::numberGuess(); cout<<"\n\n"; break;
            case 3: Miscellaneous::printSquare(); cout<<"\n\n"; break;
            case 4: Miscellaneous::calculatePayroll(); cout<<"\n\n"; break;
        }
        system("pause");
    }

    cout<<"\n\nThank you and have a nice day!\n\n";

    return 0;
}

void showMenu() {
    system("cls");
    cout<<"***********************************\n";
    cout<<"* Press 1 to do multiplication    *\n";
    cout<<"* Press 2 to play number guessing *\n";
    cout<<"* Press 3 to print a square       *\n";
    cout<<"* Press 4 to calculate payroll    *\n";
    cout<<"* Press 5 to Quit                 *\n";
    cout<<"***********************************\n";
    cout<<"=====> ";
}

int getResponse() {
    int response;
    showMenu();
    cin>> response;

    while( response < 1 || response > 5) {
        showMenu();
        cin >> response;
    }
    return response;
}
