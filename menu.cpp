#include "hw02.h"
#include <fstream>
#include <cstring>

void initialize_slist(SLIST &list) {
    list.length = 0;
    list.first = nullptr;
    list.last = nullptr;
    initialize_slist_from_file(list);
}

void initialize_slist_from_file(SLIST &list) {
    // Open the file "studentdb.txt" for reading
    std::ifstream file("studentdb.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    while (true) {
        // Allocate a new STUD structure on the heap
        STUD* student = new STUD;
        std::string line;
        
        if (!(file >> student->id)) break;  // Read the ID + Break if no entry
        file.ignore(); // Ignore the newline character after the ID

        std::getline(file, line);   // Read the last name
        strncpy(student->lastName, line.c_str(), sizeof(student->lastName)); //String->C-string
        student->lastName[sizeof(student->lastName) - 1] = '\0';

        std::getline(file, line);   // Read the first name
        strncpy(student->firstName, line.c_str(), sizeof(student->firstName)); //String->C-string
        student->firstName[sizeof(student->firstName) - 1] = '\0';

        std::getline(file, line); // Read the email
        strncpy(student->email, line.c_str(), sizeof(student->email)); //String->C-string
        student->email[sizeof(student->email) - 1] = '\0';

        std::getline(file, line); // Read the email
        strncpy(student->phone, line.c_str(), sizeof(student->email)); //String->C-string
        student->email[sizeof(student->phone) - 1] = '\0';
        
        std::getline(file, line); // Read the street
        strncpy(student->street, line.c_str(), sizeof(student->street)); //String->C-string
        student->street[sizeof(student->street) - 1] = '\0';

        std::getline(file, line); // Read the city
        strncpy(student->city, line.c_str(), sizeof(student->city)); //String->C-string
        student->city[sizeof(student->city) - 1] = '\0';

        std::getline(file, line); // Read the state
        strncpy(student->state, line.c_str(), sizeof(student->state)); //String->C-string
        student->state[sizeof(student->state) - 1] = '\0';

        std::getline(file, line); // Read the ZIP code 
        student->zip = std::atoi(line.c_str());

        std::getline(file, line); // Read the major
        strncpy(student->major, line.c_str(), sizeof(student->major));
        student->major[sizeof(student->major) - 1] = '\0';

        std::getline(file, line); // Read the rank
        strncpy(student->rank, line.c_str(), sizeof(student->rank));
        student->rank[sizeof(student->rank) - 1] = '\0';

        std::getline(file, line); // Read the GPA
        student->gpa = std::atof(line.c_str());

        // Create a new SENTRY structure to hold the student
        SENTRY *new_entry = new SENTRY;
        new_entry->student = student;
        new_entry->list = &list;
        new_entry->next = nullptr;
        new_entry->prev = list.last;

        // Link the new entry to the end of the list
        if (list.last != nullptr) {
            list.last->next = new_entry;
        } else {
            list.first = new_entry;
        }

        // Update the last pointer to the new entry
        list.last = new_entry;
        list.length++;
        
        if (!std::getline(file, line)) break; // Skip line + Break if no entry
    }

    // Close the file after reading all records
    file.close();
}


int display_and_handle_menu(SLIST &list) {
    int exit = 0; //exit code
    int choice; //input

    /* Print Menu */
    std::cout << std::endl;
    std::cout << "Menu – Select (1-5):" << std::endl;
    std::cout << "1. Add a record" << std::endl;
    std::cout << "2. Delete a record" << std::endl;
    std::cout << "   (a) Select record to delete using student ID" << std::endl;
    std::cout << "   (b) Select record to delete using student's name" << std::endl;
    std::cout << "3. Display database contents on the screen" << std::endl;
    std::cout << "   (a) Select record to display using student ID" << std::endl;
    std::cout << "   (b) Select record to display using student's name" << std::endl;
    std::cout << "   (c) Display all records" << std::endl;
    std::cout << "4. Sort DB by names" << std::endl;
    std::cout << "5. Save and Exit" << std::endl;
    std::cout << "Enter your choice: ";

    //Get Input 
    std::cin >> choice;

    /* Main Switch*/
    switch (choice) {
        /* Case 1 */
        case 1: add_record(list);
            break;
        /* Case 2 */
        case 2: std::cout << std::endl;
            std::cout << "Sub Selection (1-2):" << std::endl <<
            "   (1) Select record to delete using student ID\n   (2) Select record to delete using student's name\n";
            std::cout << "Enter your choice: ";  //Prompt + Input
            std::cin >> choice;
                /* Sub Switch 1*/
                switch(choice) {
                    case 1: delete_using_id(list);
                        break;
                    case 2: delete_using_name(list);
                        break;
                    default: std::cout << "Incorrect input" << std::endl;
                        break;
                }/* End of Sub Switch 1*/
            break;
        /* Case 3 */
        case 3: std::cout << std::endl;
            std::cout << "Sub Selection(1-3):" << std::endl <<
            "   (1) Select record to display using student ID\n   (2) Select record to display using studentś name\n   (3) Display all records\n";
            std::cout << "Enter your choice: ";  //Prompt + Input
            std::cin >> choice;
                /* Sub Switch 2*/
                switch(choice) {
                    case 1: display_using_id(list);
                        break;
                    case 2: display_using_name(list);
                        break;
                    case 3: display_all_records(list);
                        break;
                    default: std::cout << "Incorrect input" << std::endl;
                        break;
                }/* End of Sub Switch 2*/
            break;
        /* Case 4 */
        case 4: sort_list_by_names(list);
            break;
        /* Case 5 */
        case 5: //save_and_exit();
            exit = 1;
            break;
        /* Default: Invalid*/
        default: //Invalid option
            std::cout << "\nInvalid choice. Please try again." << std::endl;
            break;
    }

    return exit; //1 if TRU
}