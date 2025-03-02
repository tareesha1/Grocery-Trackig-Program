#include <iostream>
#include <fstream>
#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequencyMap; // for the store item frequencies
    std::string inputFileName = "input.txt"; // Name of input file
    std::string outputFileName = "frequency.dat"; // name of output file

public:
    // Loading data from input file into the map
    void loadData() {
        std::ifstream inputFile(inputFileName);
        if (!inputFile) {
            std::cerr << "Error: Unable to open input file." << std::endl;
            return;
        }

        std::string item;
        while (inputFile >> item) {
            itemFrequencyMap[item]++; //incrementing the frequency for each item
        }
        inputFile.close();
    }

    // getting the frequency of a specific item
    int getItemFrequency(const std::string& item) {
        return itemFrequencyMap[item];
    }

    // to print all items and their frequencies
    void printAllFrequencies() {
        for (const auto& pair : itemFrequencyMap) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    // method to print a histogram of item frequencies
    void printHistogram() {
        for (const auto& pair : itemFrequencyMap) {
            std::cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

    // method to save the item frequencies to the output file
    void saveData() {
        std::ofstream outputFile(outputFileName);
        if (!outputFile) {
            std::cerr << "Error: Unable to create output file." << std::endl;
            return;
        }

        for (const auto& pair : itemFrequencyMap) {
            outputFile << pair.first << " " << pair.second << std::endl;
        }
        outputFile.close();
    }
};

int main() {
    GroceryTracker tracker;
    tracker.loadData(); // Loading data from input file

    int choice;
    do {
        // show menu 
        std::cout << "\nMenu Options:\n";
        std::cout << "1. Search for an item\n";
        std::cout << "2. Print all frequencies\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: { // Search for an item
                std::string item;
                std::cout << "Enter the item: ";
                std::cin >> item;
                int frequency = tracker.getItemFrequency(item);
                std::cout << "Frequency of " << item << ": " << frequency << std::endl;
                break;
            }
            case 2: // Print  frequencies
                std::cout << "\nAll Frequencies:\n";
                tracker.printAllFrequencies();
                break;
            case 3: // Print the histogram
                std::cout << "\nHistogram:\n";
                tracker.printHistogram();
                break;
            case 4: // Quit the program
                tracker.saveData(); // Save data to the output file
                std::cout << "Data saved to " << "frequency.dat" << ". Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}