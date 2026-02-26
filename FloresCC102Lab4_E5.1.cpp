// Joshua Flores, ACT AD 1B
// Started at 11:35AM, finished at 8:32PM 

#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>

int main()
{
    char retry = 'Y';
    while (toupper(retry) == 'Y')
    {
        // clear screen
        system("cls");
        
        int students = 0;
        int schoolDays = 0;
        
        // input validation for students
        for (;;)
        {
            std::cout << "Enter number of students: ";
            std::cin >> students;
            if (std::cin.fail() || students <= 0)
            {
                std::cout << "Error: Invalid input.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else
                break;
        }
        
        // input validation for school days
        for (;;)
        {
            std::cout << "Enter number of school days: ";
            std::cin >> schoolDays;
            if (std::cin.fail() || schoolDays <= 0)
            {
                std::cout << "Error: Invalid input.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else
                break;
        }
        
        // vector initialization [2D]
        std::vector<std::vector<int>> matrix(students, std::vector<int>(schoolDays));
        
        // vector initialization [1D]
        std::vector<int> totalAttendance(students);
        std::vector<double> percentages(students);
        std::vector<std::string> remarks(students);

        // start loop for input and calculations
        for (int i = 0; i < students; ++i)
        {
            int totalPresent = 0;
            double percentage = 0;
            std::cout << "Student " << i+1 << " attendance:\n";
            for (int j = 0; j < schoolDays; ++j)
            {
                // checks if input isnt 1 or 0
                for (;;)
                {
                    std::cout << "Day " << j+1 << "\n(Please enter 1 for present, 0 for absent)\n>> ";
                    std::cin >> matrix[i][j];
                    if (std::cin.fail() || matrix[i][j] < 0 || matrix[i][j] > 1)
                    {
                        std::cout << "Error: Invalid Input.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else
                        break;
                }
                // counts total presents
                if (matrix[i][j] == 1) totalPresent++;
            }
            
            // calculating total, percentage and remark result
            percentage = ((double)totalPresent / schoolDays) * 100;
            totalAttendance[i] = totalPresent;
            percentages[i] = percentage;
            if (percentage < 50) remarks[i] = "DRP";
            else remarks[i] = "OK";
        }
        
        // headers using iomanip
        std::cout << std::right << std::setw(8) << "Student";
        for (int i = 0; i < schoolDays; ++i)
            std::cout << std::setw(5) << ("D" + std::to_string(i+1));

        std::cout << std::setw(6) << "Total" << std::setw(10) << "Percent" << std::setw(6) << "Remarks\n";

        // row separator
        int totalWidth = 8 + (5 * schoolDays) + 6 + 10 + 6;
        for (int i = 0; i < totalWidth; ++i)
            std::cout << "-";
        std::cout << "\n";

        // main table output
        for (int i = 0; i < students; ++i)
        {
            std::cout << std::left << std::setw(8) << i+1;
            for (int j = 0; j < schoolDays; ++j)
                std::cout << std::setw(5) << matrix[i][j];

            std::cout << std::setw(6) << totalAttendance[i];
            std::cout << std::setw(9) << std::fixed << std::setprecision(2) << percentages[i] << "%";
            std::cout << std::setw(6) << remarks[i] << "\n";
        }

        // retry operation
        std::cout << "\nTry again? (y/n)\n>> ";
        std::cin >> retry;
    }
    return 0;
}