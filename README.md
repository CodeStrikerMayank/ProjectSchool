# School Management System

A console-based application written in C for managing student records, including personal details and academic marks. The system provides a user-friendly, animated interface for all operations and persists data in a CSV file.

## 📸 Screenshot

Here's a glimpse of the main menu:

```
                ========================================
                |                                      |
                |      SCHOOL MANAGEMENT SYSTEM        |
                |                                      |
                ========================================

                        1. Display Student Report Card
                        2. New Student Enrollment
                        3. Update Student Details
                        4. Display Basic Student Info
                        5. Advanced Search & Filtering
                        6. Exit

                Enter your choice -->
```

## ✨ Features

-   **Data Persistence**: All student records are saved in `data.csv`, ensuring data is not lost between sessions.
-   **New Student Enrollment**: Add new students with their name, class, and marks for five subjects. The system automatically assigns a unique ID and calculates the final grade.
-   **View Student Data**:
    -   Display a formatted, detailed report card for any student.
    -   View basic student information quickly.
-   **Update Records**: Modify the details and marks of existing students.
-   **Advanced Search & Filtering**:
    -   Filter and list students based on their performance (Failed, Average, High Scorers).
    -   Perform a "deep search" to find students by ID, name, or class and view detailed analytics.
-   **Animated Interface**: Smooth, animated transitions for loading, searching, and other operations to enhance user experience.
-   **Color-Coded Output**: Uses colors to highlight important information, warnings, and success messages.

## 🛠️ Tech Stack

-   **Language**: C
-   **Compiler**: GCC (MinGW on Windows)
-   **Platform**: Windows (due to the use of `windows.h` and `conio.h`)

## 📋 Prerequisites

-   A Windows operating system.
-   A C compiler installed and configured in your system's PATH, such as MinGW-w64.

## 🚀 Installation & Compilation

1.  **Clone the repository** (or download the source files into a single directory).

2.  **Compile the source files** using a C compiler. Open a terminal or command prompt in the project directory and run the following command:
    ```sh
    gcc student.c extraction.c backprocess.c animation.c -o school_management.exe
    ```
    This command compiles all the necessary `.c` files and links them together to create an executable file named `school_management.exe`.

## 🏃 How to Use

1.  Run the compiled executable from your terminal:
    ```sh
    .\school_management.exe
    ```
2.  The main menu will appear. Enter the number corresponding to the action you wish to perform.
3.  Follow the on-screen prompts to interact with the system.

## 📂 File Structure

The project is organized into several files, each with a specific responsibility:

| File              | Description                                                                 |
| ----------------- | --------------------------------------------------------------------------- |
| `student.c`       | The main entry point of the application. Handles the main menu and program flow. |
| `extraction.c`    | Contains functions for data I/O: adding, updating, and extracting from CSV. |
| `backprocess.c`   | Handles data processing and display logic, including search and report cards. |
| `animation.c`     | Contains all functions responsible for the console animations and UI flair.   |
| `operation.h`     | Header file containing all function prototypes and struct definitions.      |
| `colour.h`        | Defines ANSI escape codes for adding color to the console output.           |
| `data.csv`        | The database file where all student records are stored.                     |

## ✍️ Author

-   **CoreShadow**