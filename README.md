🎮 GameZone Management System

A complete C++ console-based management system for gaming cafés / game zones.

🚀 Overview

The Galaxy GameZone Management System is a C++ project designed to manage daily operations of a gaming café.
It features separate logins for Admin, Employee, and Member, and supports tasks like:

Device & game inventory management

User & membership management

Booking requests

Billing with discounts

Report submission

Balance recharge & more

The project uses a file-based database system (.txt files) and object-oriented C++ programming concepts.

📁 Project Structure
GameZone-Management/
│
├── Functions.h
├── Functions.cpp          # Main entry point (contains mainWindow)
├── admin.cpp
├── Employee.cpp
├── member.cpp
│
├── admin.txt              # Admin credentials
├── employee.txt           # Employee data
├── member.txt             # Member data
├── device.txt             # Device inventory
├── games.txt              # Games list
├── requests.txt           # Booking requests
├── bills.txt              # Generated bills
├── employee_reports.txt   # Reports submitted by employees
│
├── README.md
└── .gitignore

🧩 Features
👑 Admin Panel

Manage Admins (add, remove, view)

Manage Employees (add, remove, change status, view reports)

Manage Members (view, remove, update membership)

Manage Games (add, update, remove, view)

Manage Devices (add, update, remove, view faulty devices)

👨‍💼 Employee Panel

View employee profile

View available or faulty devices

View member booking requests

Generate bills for customers

Submit reports to admin

🧑‍🤝‍🧑 Member Panel

Login / Register

View profile

Recharge membership balance

View available devices

Send booking requests

Retrieve past bills

💰 Billing System

Calculates charges based on:

Device hourly rate

Number of hours

Membership type (Silver/Gold/Platinum discounts)

Updates member balance

Marks device as unavailable

Saves bill details to file

🛠️ Technologies Used
Technology	Purpose
C++	Core programming
OOP Concepts	Classes, inheritance, polymorphism
File Handling	Data storage using .txt files
Windows Console	UI and menus
g++/MinGW Compiler	Compilation
⚙️ How to Compile & Run
✔️ Windows (using g++)

Open terminal in project folder:

g++ Functions.cpp admin.cpp Employee.cpp member.cpp -o GameZone.exe


Run:

./GameZone.exe

✔️ CodeBlocks / Visual Studio

Create a new console project

Add all .cpp + .h files

Build & Run

📌 Sample Data Files
device.txt
D1|PC|80|Working|Available
D2|Console|120|Working|Available

admin.txt
adminName|username|password

games.txt
PCG2|Far Cry 6|PC|Action|4


(You may replace these with your own data.)

🧪 Testing Scenarios
Scenario	Expected Output
Login as Admin	Shows admin control menu
Add new game	Stored in games.txt
Add booking request	Appears in requests.txt
Generate bill	Deducts balance + writes to bills.txt
Device broken	Appears in showNotWorkingDevices()
🚧 Future Improvements

Replace txt-based storage with SQLite or JSON

Add GUI using QT or FLTK

Move to modern C++ (smart pointers, RAII)

Add encryption for passwords

Add logs & analytics

Cloud database integration

🤝 Contributing

Fork this repo

Create a feature branch

Commit and push

Create a pull request

📜 License

This project is released under the MIT License — feel free to use it for learning or personal projects.

💬 Contact

Chaitanya Chavda
📧 chavdachaitanyasinh@gmail.com

🔗 LinkedIn: Add your link here
📍 Surat, India
