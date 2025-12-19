# 🎓 EduTrack System - Student Performance Tracker
## 📊 Overview
EduTrack System is a C++ based student management and analytics tool that processes academic records to generate insightful reports. The system efficiently organizes student data using linked lists and implements multiple sorting algorithms to categorize students based on various academic metrics.

# ✨ Key Features
#### 📈 Task 1: University Ranking
#### Algorithm: Selection Sort

## Sorting Criteria:

Primary: CGPA (Descending)

Secondary: Credits Completed (Descending)

Output: ranked_by_cgpa.txt

Format: Ranked list with detailed student information.
# 🎓 Task 2: Enrollment Year Analysis
#### Algorithm: Bubble Sort

### Sorting Criteria:

**Primary:** Enrollment Year (Ascending)

**Secondary:** Student ID (Ascending)

**Output:** sorted_by_enrollment.txt

**Format:** Year-wise grouping with average CGPA per batch.

---

# 🏫 Task 3: Department Performance
#### Algorithm: Selection Sort

## Sorting Criteria:

**Primary:** Department (Alphabetical)

**Secondary:** Semester (Ascending)

**Tertiary:** CGPA (Descending)

**Output:** department_analysis.txt

**Format:** Department-wise analysis with statistics (Avg, High, Low CGPA)

# 🏆 Task 4: Performance Tiers
**Algorithm:** Bubble Sort

**Sorting Criteria:** Name (Alphabetical)

**Output:** performance_tiers.txt

### Categories:

**🥇 Elite Tier: CGPA ≥ 3.70**

**🥈 High Achievers: 3.30 ≤ CGPA < 3.70**

**🥉 Good Standing: 3.00 ≤ CGPA < 3.30**

**📘 Satisfactory: 2.50 ≤ CGPA < 3.00**

**📝 Needs Improvement: CGPA < 2.50**

# 🛠️ Technical Implementation
## Data Structure
```
struct Student {
    int id;           // Student ID
    string name;      // Full name
    string dept;      // Department
    int semester;     // Current semester
    double cgpa;      // Cumulative GPA
    int credits;      // Credits completed
    int year;         // Enrollment year
    Student* next;    // Pointer to next node
};
```
# Input File Example (students_data.txt)
```
101 John Doe CS 5 3.8 90 2020
102 Jane Smith EE 4 3.5 75 2021
103 Bob Wilson ME 6 3.2 110 2019
104 Alice Brown CS 5 3.9 95 2020
105 Charlie Davis CE 3 2.8 50 2022
```
# 📁 Output Files
**ranked_by_cgpa.txt - University-wide ranking**

**sorted_by_enrollment.txt - Year-wise student lists with averages**

**department_analysis.txt - Department performance reports
**
performance_tiers.txt - Categorized student performance levels**

# Memory Efficient Design
**Uses linked list for dynamic memory allocation**

**Proper destructor for memory cleanup**
**In-place sorting (no extra arrays)**

# 🎯 Learning Outcomes
### This project demonstrates:

**Data Structures:** Linked list implementation and manipulation

**Algorithms:** Selection Sort and Bubble Sort with custom comparison

**File Handling:** Reading input and writing formatted reports

**Object-Oriented Design:** Class-based system architecture

**Memory Management:** Proper allocation and deallocation

# 🤝 Contributing
**Feel free to fork this project and submit pull requests with:**

**Additional sorting algorithms (Merge Sort, Quick Sort)**

**GUI interface**
**Database integration**

**More analytics features**
