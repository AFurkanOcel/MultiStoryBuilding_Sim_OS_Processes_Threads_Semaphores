# 🏗️ Operating_Systems_Term_Project

## 📌 About the Project

**Platform**: Linux

This project simulates the **construction of a multi-story apartment building**, serving as a practical demonstration of key **Operating Systems** concepts: **processes**, **threads**, and **semaphores**.

- Each **floor** is represented by a **separate process**.
- Each **apartment unit on a floor** is handled as an individual **thread**.
- A **shared crane** resource is synchronized among threads using a **POSIX semaphore**, ensuring mutual exclusion during critical operations.

This simulation provides a creative and educational approach to understanding concurrency and synchronization in operating systems.

---

## 👨‍💻 Developers

- Ahmet Furkan Öcel
- Lütfü Bedel

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

![1](https://github.com/user-attachments/assets/69f0cd68-4075-4d96-bc8b-9755241fc13b)

![2](https://github.com/user-attachments/assets/ac77d95f-32e9-4a51-b198-224d920c9ff0)


---

## 🎥 Video

*Watch the project demo here:*  
[https://www.youtube.com/watch?v=dEPhvAmfPIM&t=2s](https://www.youtube.com/watch?v=dEPhvAmfPIM&t=2s)
