#include <iostream>
#include <windows.h> //for sleep function
using namespace std;

void showMenu()
{
    cout << "********MENU********" << endl;
    cout << "Choose Option :" << endl;
    cout << "1 : Check Balance" << endl;
    cout << "2 : Deposit Money" << endl;
    cout << "3 : Withdraw Money" << endl;
    cout << "4 : Exit" << endl;
    cout << "********************" << endl;
}

int main()
{

    cout << "****** MY ATM ******" << endl
         << endl;

    //  PIN creation---------->
    int createPin;
    cout << "Create new PIN : ";
    cin >> createPin;

    cout << "Creating your PIN";

    for (int i = 0; i < 3; i++)
    {
        cout << ".";

        Sleep(1000);
    }
    cout << endl;
    cout << "***** PIN Created Successfully ***** " << endl;

    Sleep(500);

    cout << endl;

    // checking created pin is correct or not
    int userPin, errorCounter = 1;
    int maxAttempts = 3;
    bool cardBlocked = false;
    do
    {
        cout << "Enter Your PIN : ";
        cin >> userPin;
        if (createPin != userPin)
        {
            cout << "Invalid PIN ! You have " << maxAttempts - errorCounter << " attempt(s) left." << endl;
            errorCounter++;
            if (errorCounter > maxAttempts)
            {
                cardBlocked = true;
                break; // Exit loop if the card is blocked
            }
        }
        // system("cls");
    } while (errorCounter <= maxAttempts && createPin != userPin);

    cout<<endl;
    
    if (!cardBlocked)
    {
        cout << "Loading, please wait";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            Sleep(1000);
        }

        cout << endl;
        cout << endl;
        system("cls");

        // show menu options starts from1 here
        int options;
        double balance = 500;

        do
        {

            showMenu();
            cout << "Choose Options: ";
            cin >> options;

            switch (options)
            {
            case 1:
                cout << "Balance Available :" << balance << " Rs" << endl;
                break;

            case 2:
                cout << "Deposit Money: ";
                double depositAmount;
                cin >> depositAmount;
                balance += depositAmount;
                cout << "Your Available balance is :" << balance << " Rs" << endl;
                break;

            case 3:
                double withdrawAmount;
                cout << "Withdraw Amount: ";
                cin >> withdrawAmount;
                if (withdrawAmount <= balance)
                {
                    balance -= withdrawAmount;
                    cout << "Please Wait";
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";

                        Sleep(600);
                    }
                    cout << endl;

                    cout << ">>>Collect your " << withdrawAmount << " Rs"
                         << " Cash" << endl;
                }
                else
                {
                    cout << "Not enough balance available ";
                }
                cout << endl;
                break;

            case 4:
                system("cls");
                break;

            default:
                cout << "Invalid Option! Please Choose a Valid Option..." << endl;
                break;
            }
        } while (options != 4);
    }
    else
    {
        cout << "**** YOUR CARD HAS BEEN BLOCKED ****" << endl;
        cout << "**** VISIT NEAREST BRANCH ****" << endl;
    }

    return 0;
}