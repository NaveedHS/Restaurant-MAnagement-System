#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem(const string& itemName, double itemPrice) : name(itemName), price(itemPrice) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void display() const {
        cout << name << " - $" << price << endl;
    }
};

class Restaurant {
private:
    vector<MenuItem*> menu; //vector is a templated class that represents dynamic arrays

public:
    ~Restaurant() {
        for (MenuItem* item : menu) {
            delete item;
        }
    }

    void addMenuItem(MenuItem* item) {
        menu.push_back(item);
    }

    const vector<MenuItem*>& getMenu() const {
        return menu;
    }

    void displayMenu() const {
        cout << "Menu:" << endl;
        for (const MenuItem* item : menu) {
            item->display();
        }
    }

    void deleteMenuItem(const string& itemName) {
        for (size_t i = 0; i < menu.size(); ++i) {
            if (menu[i]->getName() == itemName) {
                delete menu[i];
                menu.erase(menu.begin() + i);
                cout << "Item deleted." << endl;
                return;
            }
        }
        cout << "Item not found." << endl;
    }

    void saveMenuToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            try {
                for (const MenuItem* item : menu) {
                    file << item->getName() << "," << item->getPrice() << endl;
                }
                file.close();
                cout << "Menu saved to file." << endl;
            } catch (const exception& e) {
                cerr << "Error writing to file: " << e.what() << endl;
            }
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void loadMenuFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            try {
                for (const MenuItem* item : menu) {
                    delete item;
                }
                menu.clear();

                string line;
                while (getline(file, line)) {
                    size_t pos = line.find(",");
                    if (pos != string::npos) {
                        string itemName = line.substr(0, pos);
                        double itemPrice = stod(line.substr(pos + 1));
                        MenuItem* item = new MenuItem(itemName, itemPrice);
                        menu.push_back(item);
                    }
                }
                file.close();
                cout << "Menu loaded from file." << endl;
            } catch (const exception& e) {
                cerr << "Error reading from file: " << e.what() << endl;
            }
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

bool validateStringInput(const string& input) {
    for (char c : input) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool validateNumericInput(const string& input) {
    for (char c : input) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

int main() {
    Restaurant restaurant;

    // Load menu from file (optional)
    restaurant.loadMenuFromFile("menu.txt");

    int choice;
    string name;
    string priceInput;
    double price;

    while (true) {
        cout << "\nRestaurant Management System" << endl;
        cout << "1. Add Menu Item" << endl;
        cout << "2. Display Menu" << endl;
        cout << "3. Delete Menu Item" << endl;
        cout << "4. Save Menu to File" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the name of the item: ";
                cin.ignore();
                getline(cin, name);

                // Validate name input
                if (!validateStringInput(name)) {
                    cout << "Error: Invalid name input. Please enter alphabetic characters only." << endl;
                    break;
                }

                cout << "Enter the price of the item: ";
                cin >> priceInput;

                // Validate price input
                if (!validateNumericInput(priceInput)) {
                    cout << "Error: Invalid price input. Please enter numeric characters only." << endl;
                    break;
                }

                price = stod(priceInput);
                restaurant.addMenuItem(new MenuItem(name, price));
                break;

            case 2:
                restaurant.displayMenu();
                break;

            case 3:
                cout << "\nEnter the name of the item to delete: ";
                cin.ignore();
                getline(cin, name);

                // Validate name input
                if (!validateStringInput(name)) {
                    cout << "Error: Invalid name input. Please enter alphabetic characters only." << endl;
                    break;
                }

                restaurant.deleteMenuItem(name);
                break;

            case 4:
                restaurant.saveMenuToFile("menu.txt");
                break;

            case 5:
                cout << "\nThank you for using the Restaurant Management System. Goodbye!\n";
                return 0;

            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
