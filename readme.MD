# Student Hall Mess Management & Food Registration System

## A Demonstration of Modular Programming in C
---
🌐 [Live Demo](https://hall-dining-management.vercel.app/) · 🗄️ [Server Repo](https://github.com/With-ALIF/hall-dining-management) · 💻 [C Project](https://github.com/With-ALIF/mess_system_C)
---

## Overview

The **Student Hall Mess Management System** is a modular C-based application designed to digitalize and streamline university mess administration.


<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Paradigm-Modular_Programming-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Build-gcc%20%2B%20Makefile-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Usage-Academic_Project-purple?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Platform-Linux%2FUnix-lightgrey?style=for-the-badge" />
</p>

The system manages:

-  Student registration  
-  Meal booking and cancellation  
-  Monthly bill generation  
-  Data persistence  

This project demonstrates **Modular Programming** and **Separate Compilation** in C.

---

## Key Features

### Student Features
  
- 🍽️ Book meals (Breakfast / Lunch / Dinner)  
- ❌ Cancel meals  
- 📊 Check meal status  
- 💳 View monthly bill  

### Admin Features

- 🛠️ Register students  
- 📋 View all student records  
- 🍛 Generate Billin  

---

## Modular Architecture

```text
src/
├── main.c
├── auth.c/.h
├── student.c/.h
├── meal.c/.h
├── billing.c/.h
└── file_handler.c/.h
```

## ⚙️ Compilation Instructions

This project uses gcc and a simple Makefile.

## Quick Compilation (Without Makefile)

If you do not want to use a Makefile, you can compile the project using a single gcc command.

Compile all source files:
```bash
gcc *.c -o mess
```

If you want to create object files from all `.c` files, use the following command:
```bash
make

```
Run the program
```bash
./mess
```
 
<h2>💾 Data Persistence</h2>
The system stores data in three files:

auth.txt - admin details (username and passsword)

students.txt – Student details (roll, name, balance)

meal_log.txt – (Logs of meal booking/cancellation)

ℹ️ For simplicity, meal logs are saved textually; per-day meal arrays can be extended later.

<h2>🧮 Billing Logic</h2>
💰 Meal charges:

Breakfast: 20
Lunch: 30
Dinner: 30

<h2>🧪 Demonstrated Programming Concepts</h2>
✔️ Modular Programming

✔️ Separate Compilation

✔️ Header Guards

✔️ Struct-Based Data Modeling

✔️ File Handling (Text-based Persistence)

✔️ Menu-driven CLI Application

<h2>📌 How the System Works</h2>
👨‍🎓 Student Login using roll number

🧑‍💼 Admin Login (username: admin, password: 1234)

Students can:

👤 View Profile

🍽️ Book Meal

🔄 Cancel Meal

👀 Check Meal Status

🧾 Generate Monthly Bill

🏠 Update Room Number

Admin can:

➕ Register Students

🍛 Display Mess Menu

📋 View Student List

<h2>🚀 Future Enhancements</h2>
🔐 Password-based student login

📆 Persistent storage of meals_consumed[30]

🗓️ Support for multiple months

📂 CSV/Binary storage

🖥️ GUI/Python interface

<h2>🧑‍🎓 Ideal For</h2>
🎓 University course projects

💻 Modular C programming demonstrations

📚 Learning file I/O and struct design

 
<h2>📜 License</h2>
This project is free for academic use and may be modified as needed.
Feel free to ⭐ the repo, fork it, and extend the features for your own university or course work!
