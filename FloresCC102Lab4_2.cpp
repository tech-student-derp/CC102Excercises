#include <iostream>
#include <iomanip>

int main() {
    char retry = 'Y';
    const int numSalespeople = 4;
    const int numProducts = 5;

    while (toupper(retry) == 'Y') {
        double sales[numProducts][numSalespeople] = {0};
        int sp, prod;
        double amount;

        std::cout << "Enter sales data (Salesperson, Product, Amount). Enter 0 0 0 to stop.\n";

        while (true) {
            std::cout << "Salesperson number (1-4): ";
            std::cin >> sp;
            std::cout << "Product number (1-5): ";
            std::cin >> prod;
            std::cout << "Amount sold: ";
            std::cin >> amount;

            if (sp == 0 && prod == 0 && amount == 0)
                break;

            if (sp < 1 || sp > numSalespeople || prod < 1 || prod > numProducts || amount < 0) {
                std::cout << "Invalid input. Try again.\n";
                continue;
            }

            sales[prod-1][sp-1] += amount;
        }

        std::cout << std::setw(10) << "Product";
        for (int i = 0; i < numSalespeople; i++)
            std::cout << std::setw(12) << ("SP" + std::to_string(i+1));
        std::cout << std::setw(12) << "Total" << "\n";

        for (int i = 0; i < 10 + 12*numSalespeople + 12; i++)
            std::cout << "-";
        std::cout << "\n";

        double colTotals[numSalespeople] = {0};
        double grandTotal = 0;

        for (int i = 0; i < numProducts; i++) {
            std::cout << std::setw(10) << (i+1);
            double rowTotal = 0;
            for (int j = 0; j < numSalespeople; j++) {
                std::cout << std::setw(12) << std::fixed << std::setprecision(2) << sales[i][j];
                rowTotal += sales[i][j];
                colTotals[j] += sales[i][j];
            }
            std::cout << std::setw(12) << std::fixed << std::setprecision(2) << rowTotal << "\n";
            grandTotal += rowTotal;
        }

        std::cout << std::setw(10) << "Total";
        for (int j = 0; j < numSalespeople; j++)
            std::cout << std::setw(12) << std::fixed << std::setprecision(2) << colTotals[j];
        std::cout << std::setw(12) << std::fixed << std::setprecision(2) << grandTotal << "\n";

        std::cout << "\nRun again? (Y/N): ";
        std::cin >> retry;
    }

    return 0;
}