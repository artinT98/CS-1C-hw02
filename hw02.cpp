#include "hw02.h"

int main() {
    int exit = 0;
    SLIST slist; //Declare object
    initialize_slist(slist);

    while(!exit) {
        exit = display_and_handle_menu(slist);
    }

    // Write to database file before exiting
    write_to_database(slist);

    delete_list(slist);
    
    return 0;
    
}

