#include "hw02.h"
#include <fstream>

void write_to_database(const SLIST &list) {
    std::ofstream file("studentdb.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    SENTRY *current = list.first;
    while (current != nullptr) {
        STUD *student = current->student;

        file << (student->id ? std::to_string(student->id) : "NA") << std::endl;
        file << (student->lastName[0] ? student->lastName : "NA") << std::endl;
        file << (student->firstName[0] ? student->firstName : "NA") << std::endl;
        file << (student->email[0] ? student->email : "NA") << std::endl;
        file << (student->phone[0] ? student->phone : "NA") << std::endl;
        file << (student->street[0] ? student->street : "NA") << std::endl;
        file << (student->city[0] ? student->city : "NA") << std::endl;
        file << (student->state[0] ? student->state : "NA") << std::endl;
        file << (student->zip ? std::to_string(student->zip) : "NA") << std::endl;
        file << (student->major[0] ? student->major : "NA") << std::endl;
        file << (student->rank[0] ? student->rank : "NA") << std::endl;
        file << (student->gpa ? std::to_string(student->gpa) : "NA") << std::endl;

        current = current->next;

        if (current != nullptr) {
            file << std::endl; // Add a blank line between records
        }
    }

    file.close();
}

void delete_list(SLIST &list) {
    SENTRY* current = list.first;
    while (current != nullptr) {
        SENTRY* next = current->next;
        delete current->student; // Deallocate the student object
        delete current; // Deallocate the SENTRY object
        current = next;
    }
    list.first = nullptr;
    list.last = nullptr;
    list.length = 0;
}

