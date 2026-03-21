#include <iostream>
#include <vector>
#include <limits>
#include <cctype>

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Book
{
    public:
        int barcode = 0;
        std::string title = "";
        int year = 0;
        int rating = 0;
        std::string category = "";

        void inputCode(const std::vector<Book>& book, int i)
        {
            std::cout << "Enter barcode for book " << i+1 << ":";
            for (;;)
            {
                int inputBarcode = 0;
                bool isSameCode = false;

                std::cout << "\n>> ";
                std::cin >> inputBarcode;

                for (int j = 0; j < i; ++j)
                {
                    if (book.at(j).barcode == inputBarcode)
                    {
                        isSameCode = true;
                    } else continue;
                }

                if (std::cin.fail())
                {
                    std::cout << "Invalid input. Must be an integer.";
                    clearInput();
                    continue;
                }
                else if (isSameCode)
                {
                    std::cout << "Barcode already exists! Barcodes must be unique.";
                    clearInput();
                }
                else
                {
                    isSameCode = false;
                    barcode = inputBarcode;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }
        }

        void inputTitle(int i)
        {
            std::cout << "Enter title of the book " << i+1 << ":";
            std::cout << "\n>> ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, title);
        }

        void inputYear(int i)
        {
            std::cout << "Enter year published for book " << i+1 << ":";
            for (;;)
            {
                std::cout << "\n>> ";
                std::cin >> year;
                if (std::cin.fail())
                {
                    std::cout << "Invalid input. Must be an integer.";
                    clearInput();
                }
                else if (year > 9999 || year < 1)
                {
                    std::cout << "Invalid year. Must be at 1-9999.";
                    clearInput();
                }
                else break;
            }
        }

        void inputRating(int i)
        {
            std::cout << "Enter your rating for book " << i+1 << " [" << title << "]:";
            for (;;)
            {
                std::cout << "\n>> ";
                std::cin >> rating;

                if (std::cin.fail())
                {
                    std::cout << "Invalid input. Must be an integer.";
                    clearInput();
                }
                else if (rating > 5 || rating < 0)
                {
                    std::cout << "Invalid year. Must be 0-5.";
                    clearInput();
                }
                else break;
            }
        }

        void categoryCall()
        {
            switch (rating)
            {
                case 0: category = "No rating"; break;
                case 1: category = "Poor"; break;
                case 2: category = "Fair"; break;
                case 3: category = "Good"; break;
                case 4: category = "Very Good"; break;
                case 5: category = "Excellent"; break;
                default: category = "NULL";
            }
        }
};

int main()
{
    Book book;
    char r = 'Y';
    while (toupper(r) == 'Y')
    {
        system("cls");
        int bookCount = 0;
        std::cout << "Enter how many book count:";
        for (;;)
        {
            std::cout << "\n>> ";
            std::cin >> bookCount;
            if (std::cin.fail() || bookCount <= 0)
            {
                std::cout << "Invalid input. Must be integer and not below 1.\n";
                clearInput();
            } else break;
        }

        std::vector<Book> book(bookCount);

        for (int i = 0; i < bookCount; ++i)
        {
            book.at(i).inputCode(book, i);
            book.at(i).inputTitle(i);
            book.at(i).inputYear(i);
            book.at(i).inputRating(i);
            book.at(i).categoryCall();
        }

        system("cls");

        std::cout << "Number\tBarcode\tTitle\tYear\tRating\tCategory\n";
        for (int j = 1; j < 65; ++j)
        {
            std::cout << "-";
        }
        for (int i = 0; i < bookCount; ++i)
        {
            std::cout << "\n" << i+1
                      << "\t" << book.at(i).barcode
                      << "\t" << book.at(i).title
                      << "\t" << book.at(i).year
                      << "\t" << book.at(i).rating
                      << "\t" << book.at(i).category;
        }

        std::cout << "\n\nRety program? [y] [n]:\n>> ";
        std::cin >> r;
    }
    return 0;
}
