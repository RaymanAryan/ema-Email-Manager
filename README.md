# Contact Manager(ema) CLI

A lightweight **Contact Management Command-Line Application** written in **C (C99)**.  
Designed to be fast, simple, and portable — works on **Linux** and **Termux (Android)**.

---
# ✨ Features

- Add and manage contacts from the terminal
- Store names and emails persistently
- Simple, menu-driven CLI
- Clean project structure

---
# 📁 Project structure

contact_manager/
|--dev/ #foe dev loved Makefile
├── bin/            # Compiled executable
│   └── ema
├── build/          # Object files (if used)
├── include/        # Header files (.h)
├── saves/          # Data storage (important)
│   ├── names.txt
│   └── emails.txt
├── src/            # Source files (.c)
├── Makefile
└── README.md

---
# 🛠️ Build Requirements

- GCC (or compatible C compiler)
- Make
- POSIX-compatible system (Linux / Termux)

---
# 🔧 Build Instructions

## Compile the project
```bash
make # create bin/ema
```

---
# 💾 Data Storage
Contacts are stored in plain text files:

```bash
saves/names.txt
saves/emails.txt
```

These files are automatically read on startup.
⚠️ Do not delete saves/ unless you want to reset all data.

---
# Install the app locally so it can be run from anywhere.

### Install to ~/.local/bin

```bash
make install
```
### Run it using:

```bash
~/.local/bin/ema #to run

(Optional) Add to PATH:
Bash
export PATH="$HOME/.local/bin:$PATH"
```
---
# 🧹 Clean Build Files

```bash
make clean
```
This removes:
object files
compiled binary
✔ User data in saves/ is preserved.

---
# 🧪 Development Notes
Language standard: C99

dev/Makefile is a special minimial makefile.

---
# 📜 License

This project is open-source and free to use for learning and personal projects.(GPL)
---
# 👤 Author

## Rayman Aryan
email:rayma666n@gmail.com 
---

