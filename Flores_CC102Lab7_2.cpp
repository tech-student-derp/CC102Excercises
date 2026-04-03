#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include <chrono>
#include <thread>

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Book
{
    public:
        std::string barcode = "";
        std::string title = "";
        int year = 0;
        int rating = 0;
        std::string category = "";

        void addBook(std::vector<Book>& b)
        {
            char r = 'Y';
            while (toupper(r) == 'Y')
            {
                std::string codeTemp = "";

                std::cout << "Enter barcode (Must be unique)";
                while (true)
                {
                    bool isCodeDupe = false;
                    std::cout << "\n>> ";
                    std::cin >> codeTemp;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    for (int i = 0; i < b.size(); i++)
                    {
                        if (codeTemp == b[i].barcode)
                        {
                            isCodeDupe = true;
                            break;
                        }
                    }

                    if (isCodeDupe)
                        std::cout << "[WARN] Barcode should be unique!";
                    else
                    {
                        barcode = codeTemp;
                        break;
                    }
                }

                std::cout << "Enter book title\n>> ";
                std::getline(std::cin, title);

                std::cout << "Enter year published (from 0-9999)";
                while (true)
                {
                    std::cout << "\n>> ";
                    std::cin >> year;
                    if (std::cin.fail())
                    {
                        std::cout << "[ERROR] Invalid input. Try again.";
                        clearInput();
                    }
                    else if (year < 0 || year > 9999)
                    {
                        std::cout << "[WARN] No numbers lower than 0 and higher than 9999";
                        clearInput();
                    } else break;
                }

                std::cout << "Enter your rating (from 0-5)";
                while (true)
                {
                    std::cout << "\n>> ";
                    std::cin >> rating;
                    if (std::cin.fail())
                    {
                        std::cout << "[ERROR] Invalid input. Try again.";
                        clearInput();
                    }
                    else if (rating < 0 || rating > 5)
                    {
                        std::cout << "[WARN] No numbers lower than 0 and higher than 5";
                        clearInput();
                    } else break;
                }

                switch (rating)
                {
                    case 0: category = "No rating"; break;
                    case 1: category = "Poor"; break;
                    case 2: category = "Fair"; break;
                    case 3: category = "Good"; break;
                    case 4: category = "Very Good"; break;
                    case 5: category = "Excellent"; break;
                }


                std::cout << "Book " << barcode << " has been successfully added.\n";

                b.push_back({barcode, title, year, rating, category});


                std::cout << "Try again? [Y] [N]";
                while (true)
                {
                    std::cout << "\n>> ";
                    std::cin >> r;
                    r = toupper(r);

                    if (r != 'Y' && r != 'N')
                    {
                        std::cout << "[ERROR] Invalid input. Try again.";
                        clearInput();
                    } else break;
                }
            }
        }

        void editBook(std::vector<Book>& b)
        {
            char r = 'Y';
            while (toupper(r) == 'Y')
            {
                if (b.size() < 1)
                {
                    std::cout << "[WARN] There are no books yet!\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    break;
                }

                std::string codeTemp = "";

                while (true)
                {
                    bool isCodeFound = false;
                    std::cout << "Enter barcode to edit";
                    std::cout << "\n>> ";

                    std::cin >> codeTemp;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    for (int i = 0; i < b.size(); ++i)
                    {
                        if (b[i].barcode == codeTemp)
                        {
                            isCodeFound = true;

                            std::string newTitle = "";
                            int newYear = 0;
                            int newRating = 0;
                            std::string newCategory = "";

                            std::cout << "Enter the new book title\n>> ";
                            std::getline(std::cin, newTitle);

                            std::cout << "Enter the new year published (from 0-9999)";
                            while (true)
                            {
                                std::cout << "\n>> ";
                                std::cin >> newYear;
                                if (std::cin.fail())
                                {
                                    std::cout << "[ERROR] Invalid input. Try again.";
                                    clearInput();
                                }
                                else if (newYear < 0 || newYear > 9999)
                                {
                                    std::cout << "[WARN] No numbers lower than 0 and higher than 9999";
                                    clearInput();
                                } else break;
                            }

                            std::cout << "Enter your new rating (from 0-5)";
                            while (true)
                            {
                                std::cout << "\n>> ";
                                std::cin >> newRating;
                                if (std::cin.fail())
                                {
                                    std::cout << "[ERROR] Invalid input. Try again.";
                                    clearInput();
                                }
                                else if (newRating < 0 || newRating > 5)
                                {
                                    std::cout << "[WARN] No numbers lower than 0 and higher than 5";
                                    clearInput();
                                } else break;
                            }

                            switch (newRating)
                            {
                                case 0: newCategory = "No rating"; break;
                                case 1: newCategory = "Poor"; break;
                                case 2: newCategory = "Fair"; break;
                                case 3: newCategory = "Good"; break;
                                case 4: newCategory = "Very Good"; break;
                                case 5: newCategory = "Excellent"; break;
                            }

                            b[i].title = newTitle;
                            b[i].year = newYear;
                            b[i].rating = newRating;
                            b[i].category = newCategory;

                            std::cout << "Book " << b[i].barcode << " has been successfully edited.\n";
                            break;
                        }
                    }

                    if (!isCodeFound)
                    {
                        std::cout << "[WARN] Barcode " << codeTemp << " does not exists.\nTry again? [Y] [N]\n>> ";
                        std::cin >> r;
                        r = toupper(r);

                        if (r != 'Y') break;
                    }
                }
            }
        }

        void deleteBook(std::vector<Book>& b)
        {
            char r = 'Y';
            while (toupper(r) == 'Y')
            {
                if (b.size() < 1)
                {
                    std::cout << "[WARN] There are no books yet!\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    break;
                }

                std::string codeTemp = "";
                while (true)
                {
                    bool isCodeFound = false;
                    std::cout << "Enter barcode to delete\n>> ";
                    std::cin >> codeTemp;

                    for (int i = 0; i < b.size(); ++i)
                    {
                        if (b[i].barcode == codeTemp)
                        {
                            isCodeFound = true;
                            char confirmDelete = 'N';

                            std::cout << "Are you sure you want to delete this book? [Y] [N]";
                            while (true)
                            {
                                std::cout << "\n>> ";
                                std::cin >> confirmDelete;

                                confirmDelete = toupper(confirmDelete);
                                if (confirmDelete != 'N')
                                {
                                    b.erase(b.begin() + i);
                                    std::cout << "Book successfully deleted.";
                                    break;
                                } else
                                    break;
                            }

                            if (confirmDelete == 'N')
                                break;
                        }
                    }

                    if (!isCodeFound)
                    {
                        std::cout << "[WARN] Barcode " << codeTemp << " does not exists.\n";
                        break;
                    }
                }
                std::cout << "Try again? [Y] [N]\n>> ";
                std::cin >> r;

                r = toupper(r);
                if (r != 'Y')
                    break;
            }
        }

        void displayBooks(std::vector<Book>& b)
        {
            char leave = 'N';
            while (toupper(leave) == 'N')
            {

                if (b.size() < 1)
                {
                    std::cout << "[WARN] There are no books yet!\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    break;
                }

                for (int i = 1; i < 75; ++i)
                    std::cout << "-";
                std::cout << "\nNumber\tBarcode\tTitle\tYear\tRating\tCategory\n";
                for (int i = 1; i < 75; ++i)
                    std::cout << "-";
                std::cout << "\n";

                for (int i = 0; i < b.size(); i++)
                {
                    std::cout << i+1 << "\t"
                              << b[i].barcode << "\t"
                              << b[i].title << "\t"
                              << b[i].year << "\t"
                              << b[i].rating << "\t"
                              << b[i].category << "\n";
                }

                std::cout << "\n\nLeave the interface? [Y] [N]\n>> ";
                std::cin >> leave;

                leave = toupper(leave);
                if (leave != 'N') break;
            }
        }

        void menu(std::vector<Book>& b)
        {
            int choice = 0;

            while (choice != 5)
            {
                system("cls");
                std::cout << "[1] Add book\n"
                          << "[2] Edit book\n"
                          << "[3] Delete book\n"
                          << "[4] Display book\n"
                          << "[5] Exit\n"
                          << "Enter choice ";
                while (true)
                {
                    std::cout << ">> ";
                    std::cin >> choice;
                    if (std::cin.fail())
                    {
                        std::cout << "[ERROR] Invalid input.\n";
                        clearInput();
                    } else break;
                }

                switch (choice)
                {
                    case 1:
                        system("cls");
                        addBook(b);
                        break;
                    case 2:
                        system("cls");
                        editBook(b);
                        break;
                    case 3:
                        system("cls");
                        deleteBook(b);
                        break;
                    case 4:
                        system("cls");
                        displayBooks(b);
                        break;
                    case 5:
                        system("cls");
                        std::cout << "Thank you for using this program.";
                        return;
                        break;
                    default: std::cout << "[ERROR] Invalid input.\n";
                }
            }
        }
};

int main()
{
    Book book;
    std::vector<Book> b;
    book.menu(b);
    return 0;
}
