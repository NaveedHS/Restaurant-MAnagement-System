The Restaurant Management System program is an object-oriented C++ application that allows users to 
manage a restaurant's menu. It provides functionalities such as adding menu items, displaying the menu, 
deleting menu items, saving the menu to a file, and exiting the program. The program utilizes dynamic 
memory management, exception handling, and file handling to efficiently handle menu data and provide 
a user-friendly interface.
The program consists of two main classes: `MenuItem` and `Restaurant`. The `MenuItem` class 
represents an item on the restaurant menu and has private member variables for name and price, as 
well as getter functions and a display function to retrieve and display the item's details.
The `Restaurant` class manages the menu items and contains a private member variable `menu`, which is 
a vector of `MenuItem` pointers. The class provides functions to add a new menu item, retrieve the 
menu, display the menu, and delete a menu item. It also implements file handling functions to save the 
menu to a file and load the menu from a file.
The program uses exception handling to catch and handle potential errors, such as invalid inputs or file 
I/O errors. It includes input validation functions `validateStringInput()` and `validateNumericInput()` to 
ensure the correctness of user inputs.

The program consists of two main classes: `MenuItem` and `Restaurant`.
1. `MenuItem` class:
 - Represents an item on the restaurant menu.
 - It has private member variables `name` (string) and `price` (double).
 - Provides a constructor to initialize the `name` and `price` of the menu item.
 - Contains getter functions to retrieve the `name` and `price` of the menu item.
 - Provides a `display()` function to display the name and price of the menu item.
2. `Restaurant` class:
 - Represents a restaurant and manages the menu items.
 - It has a private member variable `menu` (vector of MenuItem pointers) to store the menu items.
 - Provides a destructor to clean up dynamically allocated MenuItem objects.
 - Contains functions to add a new menu item, retrieve the menu, display the menu, and delete a menu 
item.
 - Implements file handling functions to save the menu to a file and load the menu from a file.
 - The `loadMenuFromFile()` function reads the menu items from a text file and dynamically creates 
MenuItem objects.
 - The `saveMenuToFile()` function writes the menu items to a text file.
3. Input Validation:
 - The program includes input validation functions `validateStringInput()` and `validateNumericInput()` 
to validate user inputs.
 - `validateStringInput()` checks if a string contains only alphabetic characters.
 - `validateNumericInput()` checks if a string contains only numeric characters (digits and decimal point).
The main function:
- Creates an instance of the `Restaurant` class.
- Loads the menu from a file using `loadMenuFromFile()` (optional).
- Displays a menu of options to the user.
- Accepts user input for the chosen option and performs the corresponding action using a switch-case 
statement.
- The user can choose to add a menu item, display the menu, delete a menu item, save the menu to a 
file, or exit the program.
- Input validation is performed for name and price inputs to ensure they are in the correct format.
- The program continues to display the menu of options until the user chooses to exit.
This program provides a simple and interactive way to manage a restaurant's menu by utilizing objectoriented programming principles, dynamic memory management, exception handling, and file handling
