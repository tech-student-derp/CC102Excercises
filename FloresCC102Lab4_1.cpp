#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    char retry = 'Y';
    while (toupper(retry) == 'Y') // force input to uppercase Y
    {
        int numStudents = 0; // always sets to zero when retrying the process
        int subsPerStudents = 0;
        for (;;) // input validation
        {
            std::cout << "Enter number of students:\n>> ";
            std::cin >> numStudents;
            if (std::cin.fail() || numStudents < 0 || numStudents > 50)
            {
                std::cout << "Invalid Input. Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else
                break;
        }
        for (;;) // another input validation, dont ask why for (;;)
        {
            std::cout << "Enter number of quizzes:\n>> ";
            std::cin >> subsPerStudents;
            if (std::cin.fail() || subsPerStudents < 0 || subsPerStudents > 15)
            {
                std::cout << "Invalid Input. Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else
                break;
        }

        double grades[numStudents][subsPerStudents]; // i know what im doing
        double averages[numStudents];

        for (int i = 0; i < numStudents; i++) // for loops for students
        {
            double sum = 0;
            std::cout << "Student " << i+1 << ": \n";
            for (int j = 0; j < subsPerStudents; j++) // for loops for subjects
            {
                for(;;) // and another input validation
                {
                    std::cout << "Student grade " << j+1 << ": ";
                    std::cin >> grades[i][j];
                    if (std::cin.fail() || grades[i][j] > 100 || grades[i][j] < 50)
                    {
                        std::cout << "Invalid grade. Must be below 100 and higher than 50.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else
                        break;
                }
                sum += grades[i][j];
            }
            averages[i] = sum / subsPerStudents;
        }

        std::cout << "\n";
        std::cout << std::setw(8) << "Student";
        for (int i = 0; i < subsPerStudents; i++)
        {
            std::cout << std::setw(8) << ("Q" + std::to_string(i+1));
        }
        std::cout << std::setw(8) << "Average" << "\n";
        for (int i = 0; i < 8 + 8*subsPerStudents + 8; i++)
            std::cout << "-";
        std::cout << "\n";

        for (int i = 0; i < numStudents; i++)
        {
            std::cout << std::setw(8) << i+1; // student number
            for (int j = 0; j < subsPerStudents; j++)
            {
                std::cout << std::setw(8) << std::fixed << std::setprecision(2) << grades[i][j];
            }
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << averages[i] << "\n";
        }
        std::cout << "\nTry again? (y/n)\n>> "; // retry it, ofc no input validation for this
        std::cin >> retry;
    }
    return 0;
}