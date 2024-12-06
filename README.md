# Salem Online Market

Welcome to **Salem Online Market**, a simple C++ console application demonstrating the application of Object-Oriented Programming (OOP) concepts and data structures to simulate an online shopping system.

## 🚀 Project Overview

This project provides a basic structure for an online market where **admins** and **users** can interact with the system:

- **Admins** can manage the inventory by adding, deleting, or modifying items.
- **Users** can register, log in, view available items, add items to a shopping cart, and generate a bill for their purchases.

The project emphasizes the use of OOP principles, file handling, and data structures to build a functional and modular application.

---

## 🛠 Features

### Admin Features
- Log in to the system.
- Add new items to the inventory or update existing item quantities.
- Delete items from the inventory.
- View a detailed list of all items (with prices and quantities).

### User Features
- Register or log in to the system.
- Browse the list of available items with their prices.
- Add items to a shopping cart with a specific quantity.
- View the shopping cart and total bill.
- Modify or remove items from the shopping cart if needed.

### Common Features
- **Data Persistence:** Data is stored in external files for items, users, and admin credentials.
- **Secure Access:** Admin and user actions are separated to ensure system integrity.

---

## 💻 Technologies Used

- **Programming Language:** C++  
- **File Handling:** Persistent storage of user and item data using text files.  
- **OOP Concepts:**
  - **Encapsulation:** Use of classes to encapsulate data and methods.
  - **Inheritance:** Hierarchical structure to distinguish between `User` and `Admin`.
  - **Polymorphism:** Virtual functions to allow flexible interaction between different user types.
  - **Abstraction:** Hiding complex implementation details from the user.
- **Data Structures:**
  - **Vector:** Used for managing the user's shopping cart.
  - **Pair:** For efficient storage and handling of item details (name, price, and quantity).

---

## 📂 Project Structure

```plaintext
.
├── src/
│   ├── Admin.h            # Admin class header
│   ├── Admin.cpp          # Admin class implementation
│   ├── User.h             # User class header
│   ├── User.cpp           # User class implementation
│   ├── Item.h             # Item class header
│   ├── Item.cpp           # Item class implementation
│   ├── main.cpp           # Main program entry point
├── data/
│   ├── admin.txt          # Admin credentials
│   ├── user.txt           # Registered user data
│   ├── item.txt           # Inventory data
├── CMakeLists.txt         # CMake configuration for CLion
└── README.md              # Project documentation
