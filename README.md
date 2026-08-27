# Event Management System

##  Project Overview

The **Event Management System** is a console-based C++ application developed using **Object-Oriented Programming (OOP)** and **File Handling**.

The system allows an administrator to manage events and users to register, login, book events, cancel bookings, and add reviews.

## Objectives

* Manage events efficiently.
* Allow users to register and login.
* Allow users to view and book events.
* Prevent duplicate event bookings.
* Allow users to cancel bookings.
* Allow users to add reviews for booked events.
* Generate event, user, and booking reports.
* Store data permanently using text files.

##Technologies Used

* **Language:** C++
* **Concepts:** OOP, Classes, Objects, Functions, File Handling
* **Compiler:** G++
* **IDE:** Visual Studio Code
* **Storage:** Text Files (`.txt`)

## Features

### Admin Module

* Admin Login
* Add Event
* View Events
* Search Event
* Delete Event
* Generate Report
* Clear All Data

### User Module

* User Registration
* User Login
* View Events
* Book Event
* Cancel Booking
* Add Event Review

## Admin Login

```text
Username: admin
Password: 1234
```

## Event Validation

The system accepts only **future event dates**.

Event information includes:

* Event ID
* Event Name
* Event Type
* Budget
* Location
* Date

## File Structure

```text
Event-Management-System/
│
├── main.cpp
├── Event.h
├── Event.cpp
├── User.h
├── User.cpp
├── Booking.h
├── Booking.cpp
├── Review.h
├── Review.cpp
├── Report.h
├── Report.cpp
├── Utils.h
├── Utils.cpp
│
├── events.txt
├── users.txt
├── bookings.txt
├── reviews.txt
├── PPT
└── README.md
```

## 💾 File Handling

The project stores data in separate text files:

| File           | Purpose                 |
| -------------- | ----------------------- |
| `events.txt`   | Stores event details    |
| `users.txt`    | Stores registered users |
| `bookings.txt` | Stores event bookings   |
| `reviews.txt`  | Stores user reviews     |

## ▶️ How to Run

### Step 1: Open Terminal

Open the project folder in Visual Studio Code.

### Step 2: Compile

```bash
g++ main.cpp Event.cpp User.cpp Booking.cpp Review.cpp Report.cpp Utils.cpp -o main
```

### Step 3: Run

For Windows:

```bash
main.exe
```

## OOP Concepts Used

* **Classes and Objects**
* **Encapsulation**
* **Member Functions**
* **Modular Programming**
* **File Handling**

The project is divided into multiple classes such as:

* `Event`
* `User`
* `Booking`
* `Review`
* `Report`

This makes the project easier to understand, maintain, and extend.

##  Future Enhancements

* GUI-based interface
* Database integration using MySQL
* Online event booking
* Payment integration
* Email/SMS notifications
* Event capacity management
* User profile management
* Admin dashboard

##  Project

**Event Management System**

Developed as a C++ OOP project demonstrating event management, user management, booking, review, and report generation using file handling.
