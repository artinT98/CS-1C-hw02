#include "hw02.h"
#include <cstring> // For strcmp

void display_record(const STUD *student) {
    if (student == nullptr) {
        std::cout << "No student record to display." << std::endl;
        return;
    }

    std::cout << "ID: " << student->id << std::endl;
    std::cout << "Name: " << student->firstName << " " << student->lastName << std::endl;
    std::cout << "Email: " << student->email << std::endl;
    std::cout << "Phone: " << student->phone << std::endl;
    std::cout << "Address: " << student->street << ", " << student->city << ", " << student->state << " " << student->zip << std::endl;
    std::cout << "Major: " << student->major << std::endl;
    std::cout << "Rank: " << student->rank << std::endl;
    std::cout << "GPA: " << student->gpa << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void display_using_id(const SLIST &list) {
    int id;
    std::cout << "Enter student ID to display: ";
    std::cin >> id;

    SENTRY *current = list.first;

    //If no students
    if(current == NULL) { std::cout << "No students in list" << std::endl; }

    while (current != nullptr) {
        if (current->student->id == id) {
            std::cout << "\n-------------------------" << std::endl;
            display_record(current->student);
            return;
        }
        current = current->next;
    }

    std::cout << "Record with ID " << id << " not found." << std::endl;
}

void display_using_name(const SLIST &list) {
    char name[100];
    std::cout << "Enter student name to display (First Last): ";
    std::cin.ignore();
    std::cin.getline(name, 100);

    SENTRY *current = list.first;
    while (current != nullptr) {
        char fullname[100]; // Allocate enough space for the full name
        snprintf(fullname, sizeof(fullname), "%s %s", current->student->firstName, current->student->lastName);

        if (strcmp(fullname, name) == 0) {
            std::cout << "\n-------------------------" << std::endl;
            display_record(current->student);
            return;
        }
        current = current->next;
    }

    std::cout << "Record with name " << name << " not found." << std::endl;
}

void display_all_records(const SLIST &list) {
    SENTRY *current = list.first;

    //If no students
    if(current == NULL) { 
        std::cout << "No students in list" << std::endl;
        return;
    }

    //Formatting
    std::cout << "\nDisplaying all records:" << std::endl;
    std::cout << "-------------------------" << std::endl;

    //Output students
    while (current != NULL) {
        display_record(current->student);
        current = current->next;
    }
}
