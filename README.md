# 🖥️ Operating Systems Laboratory — B.Sc. (CA) V Semester

<div align="center">

![AMU](https://img.shields.io/badge/Aligarh_Muslim_University-006747?style=for-the-badge&logoColor=white)
![Course](https://img.shields.io/badge/Course_Code-CABSMJ5P05-8B0000?style=for-the-badge)
![Credits](https://img.shields.io/badge/Credits-04-0057A8?style=for-the-badge)
![Semester](https://img.shields.io/badge/Semester-V-gold?style=for-the-badge)
![Session](https://img.shields.io/badge/Session-2026--2027-333333?style=for-the-badge)

> *"When a nation becomes devoid of art and learning, it invites poverty and when poverty comes it brings in its wake thousands of crimes."*
> — **Sir Syed Ahmad Khan**

</div>

---

## 📋 Table of Contents

- [About the Course](#-about-the-course)
- [Course Details](#-course-details)
- [Assessment Scheme](#-assessment-scheme)
- [Weekly Lab Index](#-weekly-lab-index)
- [Tech Stack](#-tech-stack)
- [Lab File Format](#-lab-file-format)
- [Department Info](#-department-info)

---

## 📖 About the Course

This laboratory course is designed for **B.Sc. (Computer Applications) V Semester** students to build a comprehensive, hands-on foundation in **programming principles, data structures, and system-level operations**. The course begins with core constructs — arithmetic, conditionals, loops, and functions — and advances through **data structures** (arrays, matrices, stacks, queues), **object-oriented design** (inheritance, polymorphism, design patterns, UML), and **operating-systems internals** (process scheduling, deadlock avoidance, memory management, disk scheduling, and synchronization).

Students progress from simple logic-building exercises to full **scheduling algorithm implementations, Banker's Algorithm deadlock avoidance, paging simulations, disk-scheduling comparisons, and synchronization problems**, culminating in an integrated OS-simulation capstone.

---

## 📌 Course Details

| Field | Details |
|---|---|
| **Course Title** | Lab-V |
| **Course Code** | CABSMJ5P05 |
| **Programme** | B.Sc. (Computer Applications) |
| **Semester** | V |
| **Credits** | 04 |
| **Periods Per Week** | 06 |
| **Department** | Computer Science, AMU Aligarh |
| **Edition** | Revised — July 2026 |

### 🎯 Course Objectives

- Master fundamental programming techniques — arithmetic operations, conditionals, loops, and functions
- Develop skills in data structures and algorithms — arrays, matrices, stacks, queues, searching, sorting
- Understand and apply object-oriented principles — inheritance, polymorphism, design patterns, UML diagrams
- Acquire system-level programming proficiency — shell scripting, file management, process scheduling, deadlock handling
- Apply logical and mathematical reasoning — number systems, primes, sequences, and related computations

### ✅ Course Outcomes

After completing this course, students will be able to:

- Demonstrate proficiency in basic programming constructs and apply them to computational problems
- Implement and manipulate data structures, applying sorting, searching, and other operations
- Design and implement object-oriented systems, translating UML diagrams into working code (C++/Java)
- Demonstrate competence in system-level programming — file handling, process scheduling, deadlock avoidance
- Apply logical and mathematical concepts including number conversions, primes, Fibonacci sequences, palindromes

---

## 📊 Assessment Scheme

```
Total Marks: 100
├── Continuous Assessment   →  60 Marks
└── Final Lab Examination   →  40 Marks
```

> ⚠️ **Minimum Requirement:** At least **10** timely completed and duly signed weekly activities/assignments are compulsory to appear in the Final Lab Examination.
> 🚫 **Late submissions are not accepted** after the due date. Collaboration is encouraged — **copying is strictly prohibited**.

---

## 📅 Weekly Lab Index

### Week 1 — Process Fundamentals & OS Basics

**Objectives:** Introduce OS-related basic programming via process IDs and CPU time concepts; build logic for OS resource calculations.

| # | Problem |
|---|---|
| 1 | CPU Time Conversion — burst time (seconds) → `HH:MM:SS` |
| 2 | Process Type Identification — even PID → *System Process*, else *User Process* |
| 3 | Context Switch Overhead — given total processes and context switch time |
| 4 | Resource Distribution — printers allocated equally among users |

---

### Week 2 — OS Performance Metrics

**Objectives:** Understand CPU utilization and throughput; practice priority-based decision-making.

| # | Problem |
|---|---|
| 1 | CPU Utilization — given `busy_time` and `idle_time` |
| 2 | Priority Selection — 5 processes, High / Medium / Low |
| 3 | Throughput Calculation — processes / time |
| 4 | Ready Queue Order — manual ready-queue construction |

---

### Week 3 — Arrays for Process Data

**Objectives:** Store and manipulate process-related data using arrays; select processes by burst time.

| # | Problem |
|---|---|
| 1 | Burst Time Average — total and average across *n* processes |
| 2 | Shortest Process Finder |
| 3 | Sort by Arrival Time (ascending) |
| 4 | Ready Queue Simulation |

---

### Week 4 — Structures & Completion Times

**Objectives:** Represent process information using C structures; calculate process completion times.

| # | Problem |
|---|---|
| 1 | Define `Process` structure — `pid`, `arrival_time`, `burst_time` |
| 2 | Input & Display Processes |
| 3 | Completion Time = `arrival_time + burst_time` |
| 4 | Next Process Selection (SJN) — shortest burst time from ready queue |

---

### Week 5 — Waiting, Turnaround & Gantt Charts

**Objectives:** Calculate waiting and turnaround times for processes; understand Gantt chart representation.

| # | Problem |
|---|---|
| 1 | Turnaround & Waiting Time |
| 2 | Gantt Chart Representation — 3 processes |
| 3 | Response Ratio Calculation |
| 4 | Arrival-Based Ready Queue Simulation |

---

### Week 6 — Queues & Core Scheduling Algorithms

**Objectives:** Implement the queue data structure; implement FCFS and SJN scheduling algorithms.

| # | Problem |
|---|---|
| 1 | Queue Implementation — enqueue, dequeue, display |
| 2 | FCFS Scheduling (C) — average waiting & turnaround time |
| 3 | SJN Scheduling (C) — non-preemptive |
| 4 | Shell Script — convert CPU burst time: ms → ns, µs, s |

---

### Week 7 — Preemptive Scheduling & UML Introduction

**Objectives:** Learn and implement preemptive scheduling algorithms; calculate starvation in priority scheduling.

| # | Problem |
|---|---|
| 1 | Round Robin Scheduling — with time quantum |
| 2 | Priority Scheduling |
| 3 | Starvation Time Calculation |
| 4 | Shell Script — system uptime & running processes |
| 5 | OOAD — UML **class diagram** (Visual Paradigm) + analysis report |

---

### Week 8 — Deadlocks & Banker's Algorithm

**Objectives:** Understand deadlocks and avoidance techniques; implement Banker's Algorithm.

| # | Problem |
|---|---|
| 1 | Deadlock Detection — circular wait using arrays |
| 2 | Banker's Algorithm — deadlock avoidance |
| 3 | Resource Request Safety Check |
| 4 | Shell Script — list processes using more than 5% CPU |
| 5 | OOAD — UML **object diagram** |

---

### Week 9 — Paging & Memory Allocation

**Objectives:** Understand paging and basic memory allocation strategies.

| # | Problem |
|---|---|
| 1 | Paging Simulation — page number & offset for given logical addresses |
| 2 | First-Fit Allocation |
| 3 | Best-Fit & Worst-Fit Comparison — fragmentation analysis |
| 4 | Shell Script — top 5 memory-consuming processes |
| 5 | OOAD — UML **activity diagram** |

---

### Week 10 — File Handling in C

**Objectives:** Perform file handling operations using C; write and read process information from files.

| # | Problem |
|---|---|
| 1 | Create Process File — store PID & burst time |
| 2 | Read Process File — display stored process information |
| 3 | Count Processes in File |
| 4 | Shell Script — file size, permissions, and last modified date |
| 5 | OOAD — UML **sequence diagram** |

---

### Week 11 — Disk Scheduling

**Objectives:** Understand disk scheduling techniques and compare seek-time performance.

| # | Problem |
|---|---|
| 1 | FCFS Disk Scheduling — total head movement |
| 2 | SSTF Scheduling — compare seek time with FCFS |
| 3 | SCAN & C-SCAN — implement and compare results |
| 4 | Shell Script — display disk space usage |
| 5 | OOAD — UML **package diagram** |

---

### Week 12 — Process Synchronization

**Objectives:** Simulate process synchronization problems.

| # | Problem |
|---|---|
| 1 | Producer-Consumer Problem — arrays & semaphores |
| 2 | Dining Philosophers Problem — array-based logic |
| 3 | Readers-Writers Problem — simple simulation without threads |
| 4 | Shell Script — auto-refresh list of top 5 CPU-consuming processes |

---

### Week 13 — Page Replacement & File Allocation

**Objectives:** Simulate page replacement and file allocation techniques.

| # | Problem |
|---|---|
| 1 | Page Replacement (FIFO & LRU) — simulate and calculate page faults |
| 2 | Indexed File Allocation |
| 3 | Contiguous vs. Linked Allocation |
| 4 | Shell Script — search and list files > 100MB |

---

### Week 14 — Capstone: Integrated OS Simulation

**Objectives:** Integrate multiple OS concepts into a single simulation.

| # | Problem |
|---|---|
| 1 | Menu-Driven Process Scheduler — combines FCFS, SJN, RR, and Priority scheduling |
| 2 | Deadlock Detector with Banker's Algorithm — dynamic resource request handling |
| 3 | Memory Management Visualizer — First-Fit, Best-Fit, and fragmentation report |
| 4 | Shell Script — OS Health Monitor (combined CPU, memory, and disk report) |

---

## 🛠️ Tech Stack

| Tool | Purpose |
|---|---|
| ![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white) | Core programming, structures, file handling (Weeks 1–6, 8–11, 13–14) |
| ![Shell](https://img.shields.io/badge/Shell_Script-4EAA25?style=flat-square&logo=gnubash&logoColor=white) | System monitoring & automation (every week from Week 6 onward) |
| ![UML](https://img.shields.io/badge/UML-FF8300?style=flat-square) | Object-oriented analysis & design (Weeks 7–11, via Visual Paradigm) |
| **GCC** | C compilation |

---

## 📁 Lab File Format

```
Lab File Index Template
─────────────────────────────────────────────────────
Week No. │ Problems with Description │ Page No. │ Teacher Signature & Date
─────────────────────────────────────────────────────
   1     │ 1#, 2#, 3#                │          │
   2     │ 1#, 2#, 3#                │          │
   3     │ 1#, 2#, 3#                │          │
  ...    │ ...                       │          │
─────────────────────────────────────────────────────
Header: Page Number
Footer: Roll Number & Name
```

---

## 🏛️ Department Info

| Field | Details |
|---|---|
| **Department** | Department of Computer Science |
| **University** | Aligarh Muslim University, Aligarh (U.P.) India |
| **Lab Manual Edition** | Revised — July 2026 |
| **Convener** | Prof. Aasim Zafar |
| **Committee Members** | Prof. Arman Rasool Faridi (Chairperson) · Prof. Mohammad UbaidUllah Bokhari · Prof. Suhel Mustajab · Dr. Shafiqul Abidin · Dr. Asif Irshad Khan · Dr. Faisal Anwar · Dr. Mohammad Sajid · Dr. Mohammad Nadeem · Dr. Faraz Masood |
| **Design & Compilation** | Dr. Faraz Masood |

---

<div align="center">

**Department of Computer Science · Aligarh Muslim University**

*Lab Manual CABSMJ5P05 · Revised Edition July 2026*

</div>
