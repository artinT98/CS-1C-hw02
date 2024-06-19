#include "hw02.h"
#include <cstring> //strcmp()

void sort_list_by_names(SLIST &list) {
    // If the list is empty or has only one element, no need to sort
    if (!list.first || !list.first->next) return;

    //Show process
    std::cout << "\n Sortin List..." << std::endl;

    bool swapped; // A flag to track whether a swap occurred in the current pass
    do {
        swapped = false; // Reset the flag at the beginning of each pass
        SENTRY* current = list.first; // Start from the first element

        // Traverse the list until the second last element
        while (current->next != nullptr) {
            // Compare the last names of the current student and the next student
            if (std::strcmp(current->student->lastName, current->next->student->lastName) > 0) {
                // If they are in the wrong order, swap their student pointers
                STUD* temp = current->student;
                current->student = current->next->student;
                current->next->student = temp;
                swapped = true; // Set the flag to indicate a swap occurred
            }
            current = current->next; // Move to the next element
        }
    } while (swapped); // Continue the loop until no swaps occur in a pass
}