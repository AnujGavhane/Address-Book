<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language">
  <img src="https://img.shields.io/badge/Platform-Linux%20(WSL)-green?style=for-the-badge" alt="Platform">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" alt="Status">
  <img src="https://img.shields.io/github/license/anujgavhane/AddressBook?style=for-the-badge" alt="License">
</p>

<h1 align="center">📖 AddressBook</h1>

<p align="center">
  <b>A simple console-based Address Book application built in C.</b><br>
  <i>Manage your contacts — create, edit, delete, search, and save them efficiently.</i>
</p>

<p align="center">
  <a href="https://github.com/anujgavhane/AddressBook/stargazers">
    <img src="https://img.shields.io/github/stars/anujgavhane/AddressBook?color=yellow&style=flat-square" alt="Stars">
  </a>
  <a href="https://github.com/anujgavhane/AddressBook/network/members">
    <img src="https://img.shields.io/github/forks/anujgavhane/AddressBook?color=lightblue&style=flat-square" alt="Forks">
  </a>
  <a href="https://github.com/anujgavhane/AddressBook/issues">
    <img src="https://img.shields.io/github/issues/anujgavhane/AddressBook?color=red&style=flat-square" alt="Issues">
  </a>
  <a href="https://github.com/anujgavhane/AddressBook">
    <img src="https://img.shields.io/github/repo-size/anujgavhane/AddressBook?color=orange&style=flat-square" alt="Repo Size">
  </a>
</p>

---

### 🧠 About the Project

**AddressBook** is a menu-driven program that helps users manage their contacts easily.  
It supports creating, editing, deleting, searching, listing, and saving contacts to a CSV file.  
The project demonstrates **C programming fundamentals** like structs, file handling, and validation logic.

---

### ⚙️ Tech Stack

- **Language:** C  
- **Environment:** Linux (WSL)  
- **Storage:** CSV File Handling  
- **Concepts:** Structs, Arrays, String Handling, File I/O, Validation

---

### 🚀 Run Locally

```bash
# Clone this repository
git clone https://github.com/anujgavhane/AddressBook.git

# Go to the project directory
cd AddressBook

# Compile the program
gcc main.c contact.c dummy_contact.c -o addressbook

# Run the executable
./addressbook

# Anuj_G_AddressBook
# 📖 Address Book in C

A **console-based Address Book application** written in **C**, designed to help users manage contact information efficiently.  
The project demonstrates **file handling, modular programming, and input validation** — making it ideal for beginners learning C programming.

---

## 🧩 Features

- ➕ **Create**, ✏️ **Edit**, ❌ **Delete**, 🔍 **Search**, and 📋 **List** contacts  
- 💾 **Save and load** contacts from a CSV file (`contacts.csv`)  
- 🔁 **Prevents duplicate entries** automatically  
- ✅ **Validates** phone numbers and email addresses before saving  
- 👥 **Loads 10 predefined dummy contacts** at startup  

---

## 📁 Project Structure

| File | Description |
|------|--------------|
| **main.c** | Provides the user menu and program loop |
| **contact.c** | Core logic for creating, editing, deleting, searching, listing, saving, and loading contacts |
| **contact.h** | Header file containing structures and function declarations |
| **dummy_contact.c** | Contains dummy contact data and email validation function |

---

## ⚙️ How to Compile and Run

```bash
# Compile
gcc main.c contact.c dummy_contact.c -o addressbook

# Run
./addressbook
