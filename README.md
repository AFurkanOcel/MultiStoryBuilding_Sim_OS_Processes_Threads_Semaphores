# 🏗️ Operating_Systems_Term_Project

## 📌 About the Project

This project simulates the **construction of a multi-story apartment building**, serving as a practical demonstration of key **Operating Systems** concepts: **processes**, **threads**, and **semaphores**.

- Each **floor** is represented by a **separate process**.
- Each **apartment unit on a floor** is handled as an individual **thread**.
- A **shared crane** resource is synchronized among threads using a **POSIX semaphore**, ensuring mutual exclusion during critical operations.

This simulation provides a creative and educational approach to understanding concurrency and synchronization in operating systems.

---

## 👨‍💻 Developers

- Ahmet Furkan Öcel — `23360859729`  
- Lütfü Bedel — `21360859030`

---

## 🧠 Core Concepts Implemented

- **Process (`fork`)**  
  Each floor is built by a separate process to simulate isolated tasks.

- **Thread (`pthread`)**  
  Each apartment on a floor is managed by a thread to enable concurrent operations.

- **Semaphore (`sem_open`, `sem_wait`, `sem_post`)**  
  A single shared crane is accessed in a mutually exclusive way across threads using a named semaphore.

---

## 🔧 Compilation and Execution

### Requirements:
- POSIX-compliant operating system (Linux/macOS)
- GCC or compatible C compiler

---

## 🎥 Video

*Watch the project demo here:*  
[https://www.google.com](https://www.google.com)

- POSIX-compliant operating system (Linux/macOS)
- GCC or compatible C compiler

### Compile:
```bash
gcc -o building_simulator building_simulator.c -lpthread -lrt
