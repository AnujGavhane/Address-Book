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
