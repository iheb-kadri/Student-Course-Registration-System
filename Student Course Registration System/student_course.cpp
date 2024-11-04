#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    int id;
    std::string name;

public:
    // Constructor
    Student(int id, const std::string& name) : id(id), name(name) {}

    // Methods
    std::string getStudentName() const {
        return name;
    }

    int getStudentId() const {
        return id;
    }

    void displayStudent() const {
        std::cout << "Student Name: " << name << ", Student ID: " << id << std::endl;
    }
};

class Course {
private:
    std::string courseName;
    std::vector<Student> listOfStudents;

public:
    // Constructor
    Course(const std::string& courseName) : courseName(courseName) {}

    // Method to display course name
    std::string getCourseName() const {
        return courseName;
    }

    // Method to register a student in the course
    void registerStudent(const Student& student) {
        listOfStudents.push_back(student);
    }

    // Method to display all students in the course
    void displayStudentsInCourse() const {
        std::cout << "Course: " << courseName << std::endl;
        for (const auto& student : listOfStudents) {
            student.displayStudent();
        }
    }
};

int main() {
    int studentnumb;
    int coursenumb;
    int opt;

    // Containers for user input
    std::string name;
    std::string coursename;
    int id;

    // Vector to store courses and students
    std::vector<Student> students;
    std::vector<Course> courses;

    while (true) {
        std::cout << "*************************************\n";
        std::cout << "Welcome to Student Course Management Program!\n";
        std::cout << "Please choose your option:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Course\n";
        std::cout << "3. Display All Students\n";
        std::cout << "4. Display All Courses\n";
        std::cout << "5. Register Student for Course\n";
        std::cout << "6. Display Students Registered for a Course\n";
        std::cout << "7. Exit\n";
        std::cout << "*************************************\n";
        std::cin >> opt;

        switch (opt) {
            case 1:
                std::cout << "Please enter the number of students: ";
                std::cin >> studentnumb;
                for (int i = 0; i < studentnumb; ++i) {
                    std::cout << "Please enter student #" << i + 1 << " name: ";
                    std::cin >> name;
                    std::cout << "Please enter student #" << i + 1 << " id: ";
                    std::cin >> id;
                    students.push_back(Student(id, name));
                }
                break;

            case 2:
                std::cout << "Please enter the number of courses: ";
                std::cin >> coursenumb;
                for (int i = 0; i < coursenumb; ++i) {
                    std::cout << "Please enter course #" << i + 1 << " name: ";
                    std::cin >> coursename;
                    courses.push_back(Course(coursename));
                }
                break;

            case 3:
                std::cout << "Displaying all students:\n";
                for (const auto& student : students) {
                    student.displayStudent();
                }
                break;

            case 4:
                std::cout << "Displaying all courses:\n";
                for (const auto& course : courses) {
                    std::cout << course.getCourseName() << std::endl;
                }
                break;

            case 5:
                std::cout << "Please enter the course name: ";
                std::cin >> coursename;
                std::cout << "Please enter the student id: ";
                std::cin >> id;

                // Find the course and student
                for (auto& course : courses) {
                    if (course.getCourseName() == coursename) {
                        for (const auto& student : students) {
                            if (student.getStudentId() == id) {
                                course.registerStudent(student);
                                std::cout << "Student registered to course successfully.\n";
                                break;
                            }
                        }
                        break;
                    }
                }
                break;

            case 6:
                std::cout << "Please enter the course name to display registered students: ";
                std::cin >> coursename;
                for (const auto& course : courses) {
                    if (course.getCourseName() == coursename) {
                        course.displayStudentsInCourse();
                        break;
                    }
                }
                break;

            case 7:
                std::cout << "Exiting program.\n";
                return 0;

            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}
