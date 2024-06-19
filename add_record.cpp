#include "hw02.h"
#include <limits>

void add_record(SLIST &list) {
    std::cout << std::endl << "*** Adding record selected. Please input record ***" << std::endl;
    SENTRY *new_entry = new SENTRY;
    new_entry->student = input_record();
    new_entry->list = &list;
    new_entry->next = nullptr;
    new_entry->prev = list.last;

    if(list.last != nullptr) {
        list.last->next = new_entry;
    } else {
        list.first = new_entry;
    }

    list.last = new_entry;
    list.length++;
}

STUD* input_record() {
    STUD* student = new STUD;

    std::cout << "Enter ID: ";
    std::cin >> student->id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    std::cout << "Enter Last Name: ";
    std::cin.getline(student->lastName, 50);

    std::cout << "Enter First Name: ";
    std::cin.getline(student->firstName, 50);

    std::cout << "Enter Email: ";
    std::cin.getline(student->email, 50);

    std::cout << "Enter Phone: ";
    std::cin.getline(student->phone, 50);

    std::cout << "Enter Street: ";
    std::cin.getline(student->street, 50);

    std::cout << "Enter City: ";
    std::cin.getline(student->city, 50);

    std::cout << "Enter State: ";
    std::cin.getline(student->state, 50);

    std::cout << "Enter ZIP: ";
    std::cin >> student->zip;
    std::cin.ignore();

    std::cout << "Enter Major: ";
    std::cin.getline(student->major, 50);

    std::cout << "Enter Rank: ";
    std::cin.getline(student->rank, 50);

    std::cout << "Enter GPA: ";
    std::cin >> student->gpa;
    std::cin.ignore();

    return student;
}
