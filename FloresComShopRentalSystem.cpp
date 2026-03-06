#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <cstdlib>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void viewLayout(int& rows, int& cols, std::vector<std::vector<int>>& hours, std::vector<char>& letters)
{
    char leaveLayout = 'N';
    while (toupper(leaveLayout) == 'N')
    {
        system(CLEAR);
        std::cout << "\n";
        std::cout << "     ";
        for (int i = 0; i < cols; ++i)
            std::cout << std::setw(6) << i+1;
        std::cout << "\n";
        for (int i = 0; i < 7*cols; ++i)
            std::cout << "-";
        std::cout << "\n";
        for (int i = 0; i < rows; ++i)
        {
            std::cout << std::setw(5) << letters.at(i);
            for (int j = 0; j < cols; ++j)
                std::cout << std::setw(6) << hours.at(i).at(j) << "h";
            std::cout << "\n";
        }
        std::cout << "\nLeave the interface? [Y] [N]\n>> ";
        while (true)
        {
            std::cin >> leaveLayout;
            if (std::cin.fail())
            {
                std::cout << "Invalid Input. Try again.\n";
                clearInput();
            } else break;
        }
    }
}

void rentComputer(int& rows, int& cols, std::vector<std::vector<int>>& hours, std::vector<char>& letters)
{
    char rentAgain = 'Y';
    while (toupper(rentAgain) == 'Y')
    {
        system(CLEAR);
        int rowTempRent = 0;
        int colTempRent = 0;
        int hourTempRent = 0;

        std::cout << "Enter row (1 to 5)\n";
        while (true)
        {
            std::cout << ">> ";
            std::cin >> rowTempRent;
            if (std::cin.fail())
            {
                std::cout << "Invalid input. Try again.\n";
                clearInput();
            } else if (rowTempRent > 5 || rowTempRent < 1)
            {
                std::cout << "Computer unit does not exists. Try again.\n";
                clearInput();
            } else break;
        }
        std::cout << "Enter column (1 to 10)\n";
        while (true)
        {
            std::cout << ">> ";
            std::cin >> colTempRent;
            if (std::cin.fail())
            {
                std::cout << "Invalid input. Try again.\n";
                clearInput();
            } else if (colTempRent > 10 || colTempRent < 1)
            {
                std::cout << "Computer unit does not exists. Try again.\n";
                clearInput();
            } else if (hours.at(rowTempRent - 1).at(colTempRent - 1) > 0)
            {
                std::cout << "Computer unit already rented! Try again.\n";
                clearInput();
            } else break;
        }
        std::cout << "Enter hours to rent:\n";
        while (true)
        {
            std::cout << ">> ";
            std::cin >> hourTempRent;
            if (std::cin.fail() || hourTempRent <= 0)
            {
                std::cout << "Invalid input. Try again.\n";
                clearInput();
            } else break;
        }

        hours.at(rowTempRent - 1).at(colTempRent - 1) = hourTempRent;
        std::cout << "Computer unit " << letters.at(rowTempRent - 1) << colTempRent
                  << " successfully rented for " << hourTempRent << " hour(s)!\n";
        std::cout << "Rent another computer? [Y] [N]\n>> ";
        std::cin >> rentAgain;
    }
}

void returnComputer(int& rows, int& cols, std::vector<std::vector<int>>& hours, std::vector<char>& letters)
{
    char returnAgain = 'Y';
    while (toupper(returnAgain) == 'Y')
    {
        system(CLEAR);
        int rowTempReturn = 0;
        int colTempReturn = 0;
        int rentalPay = 0;
        std::cout << "Enter row (1 to 5)\n";
        while (true)
        {
            std::cout << ">> ";
            std::cin >> rowTempReturn;
            if (std::cin.fail())
            {
                std::cout << "Invalid input. Try again.\n";
                clearInput();
            } else if (rowTempReturn > 5 || rowTempReturn < 1)
            {
                std::cout << "Computer unit does not exists. Try again.\n";
                clearInput();
            } else break;
        }
        std::cout << "Enter column (1 to 10)\n";
        while (true)
        {
            std::cout << ">> ";
            std::cin >> colTempReturn;
            if (std::cin.fail())
            {
                std::cout << "Invalid input. Try again.\n";
                clearInput();
            } else if (colTempReturn > 10 || colTempReturn < 1)
            {
                std::cout << "Computer unit does not exists. Try again.\n";
                clearInput();
            } else if (hours.at(rowTempReturn - 1).at(colTempReturn - 1) == 0)
            {
                std::cout << "Computer unit already available! Try again.\n";
                clearInput();
            } else break;
        }

        rentalPay = hours.at(rowTempReturn - 1).at(colTempReturn - 1) * 20;
        hours.at(rowTempReturn - 1).at(colTempReturn - 1) = 0;

        std::cout << "Computer unit " << letters.at(rowTempReturn - 1) << colTempReturn
                  << " has been returned\nRental Sale: P" << rentalPay;
        std::cout << "\nReturn another computer? [Y] [N]\n";
        std::cin >> returnAgain;
    }
}

void resetSystem(int& rows, int& cols, std::vector<std::vector<int>>& hours)
{
    system(CLEAR);

    char deleteSystem = 'N';
    std::cout << "Are you sure you want to restart the renting system? [Y] [N]\n>> ";
    std::cin >> deleteSystem;

    if (std::cin.fail())
    {
        std::cout << "Invalid input. Ensure your answer.\n";
        clearInput();
        return;
    }

    if (toupper(deleteSystem) == 'Y')
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                hours.at(i).at(j) = 0;

        std::cout << "Successfully restarted the system!\n";
    }
    else
    {
        std::cout << "System reset canceled.\n";
    }
}

void menuSystem(int& choice, int& rows, int& cols, std::vector<std::vector<int>>& hours, std::vector<char>& letters, char& retry)
{
    system(CLEAR);
    std::cout << "===== COMPUTER SHOP RENTAL SYSTEM =====\n"
              << "[1] View Computer Layout\n"
              << "[2] Rent a Computer\n"
              << "[3] Return a Computer\n"
              << "[4] Reset Rental System\n"
              << "[5] Exit\n"
              << "=======================================\n"
              << "Enter Choice: ";
    while (true)
    {
        std::cin >> choice;
        if (std::cin.fail() || choice < 0 || choice > 5)
        {
            std::cout << "Invalid input. Try again.\n";
            clearInput();
        } else break;
    }

    switch (choice)
    {
        case 1: viewLayout(rows, cols, hours, letters); break;
        case 2: rentComputer(rows, cols, hours, letters); break;
        case 3: returnComputer(rows, cols, hours, letters); break;
        case 4: resetSystem(rows, cols, hours); break;
        case 5: retry = 'N'; break;
        default: std::cout << "Invalid input. Try again.\n"; break;
    }
}

int main()
{
    char retry = 'Y';
    int choice = 0;

    int rows = 5;
    int cols = 10;
    std::vector<std::vector<int>> hours(rows, std::vector<int>(cols, 0));

    std::vector<char> letters{
        'A', 'B', 'C', 'D', 'E'
    };

    while (toupper(retry) == 'Y')
    {
        menuSystem(choice, rows, cols, hours, letters, retry);
    }

    system(CLEAR);
    std::cout << "Thank you for using the computer shop rental system!.\n";
    return 0;
}
