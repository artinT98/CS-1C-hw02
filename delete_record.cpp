#include "hw02.h"
#include <cstring> // For strcmp

void delete_entry(SLIST &list, SENTRY *entry) {
    if (entry->prev != nullptr) {
        entry->prev->next = entry->next;
    } else {
        list.first = entry->next;
    }
    if (entry->next != nullptr) {
        entry->next->prev = entry->prev;
    } else {
        list.last = entry->prev;
    }
    delete entry->student;
    delete entry;
    list.length--;
}


void delete_using_id(SLIST &list, int id) {
    SENTRY *current = list.first;
    while (current != nullptr) {
        if (current->student->id == id) {
            delete_entry(list, current);
            std::cout << "Record with ID " << id << " deleted." << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Record with ID " << id << " not found." << std::endl;
}

void delete_using_id(SLIST &list) {
    int id;
    std::cout << "\n\nEnter student ID to delete: ";
    std::cin >> id;
    std::cin.ignore();

    SENTRY *current = list.first;
    while (current != nullptr) {
        if (current->student->id == id) {
            delete_entry(list, current);
            std::cout << "Record with ID " << id << " deleted." << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Record with ID " << id << " not found." << std::endl;
}

void delete_using_name(SLIST &list) {
    char fullname[100]; // Allocate enough space for the full name
    char name[100];
    std::cin.ignore();
    std::cout << "Enter student name to delete: ";
    std::cin.getline(name, 100);

    SENTRY *current = list.first;
    while (current != nullptr) {
        snprintf(fullname, sizeof(fullname), "%s %s", current->student->firstName, current->student->lastName);

        if (strcmp(fullname, name) == 0) {
            delete_entry(list, current);
            std::cout << "Record with name " << name << " deleted." << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Record with name " << name << " not found." << std::endl;
}