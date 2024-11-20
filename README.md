
# University Management System 🎓

The **University Management System** is a desktop application built in C++ that helps streamline and manage various administrative tasks for universities. It integrates with a MySQL database to manage student and faculty information, including contact details, addresses, and course enrollments.

---

## Features

- **Student Management**:
  - Add, update, and delete student records.
  - Manage personal details including ID, name, section, roll number, and contact information.
  
- **Faculty Management**:
  - Manage faculty records and assign them to courses or departments.
  
- **Course Management**:
  - Manage and assign courses to students and faculty.

- **Administrative Tools**:
  - Insert and update data in the database.
  - Secure role-based access control for different users (admin, faculty).

- **Database Management**:
  - Supports MySQL database for storing and retrieving data.
  - SQL queries are executed to insert or update records in various tables (student, faculty, courses, etc.).

---

## Technologies Used

- **Programming Language**: C++
- **Database**: MySQL
- **Libraries**: MySQL C++ Connector, Windows API (for Sleep function)

---

## Getting Started

### Prerequisites

Make sure you have the following installed:

- C++ compiler (like MinGW or Microsoft Visual C++)
- MySQL server running locally
- MySQL C++ connector library

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Aniket-a14/Uni_Management_System.git
   cd Uni_Management_System
   ```

2. **Set up MySQL Database**:
   - Create a database and import the necessary schema.
   - Ensure that your MySQL server is running on localhost.

3. **Configure Database Connection**:
   - Edit the `main.cpp` file and update the MySQL credentials (host, user, password, database name).

4. **Build the Project**:
   - Compile the C++ project using your preferred compiler.
   
5. **Run the Application**:
   - Execute the compiled program to launch the system.

---

## Project Structure

```
Uni_Management_System/
│
├── src/                  # C++ source files for database operations and menu logic
├── database/             # Database schema and initialization scripts
│
├── main.cpp              # Entry point for the application
└── README.md             # Project documentation
```

---

## Example Usage

1. **Insert New Data**: Insert student details including contact and address into the database.
2. **Update Data**: Modify existing student or faculty records using the update functionality.

---

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
