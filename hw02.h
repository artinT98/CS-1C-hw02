/* Pre-Processor directives*/
#ifndef HW02_H
#define HW02_H

#include <iostream>

/* Structures */
struct STUD {
    int id;
    char lastName[50];
    char firstName[50];
    char email[50];
    char phone[50];
    char street[50];
    char city[50];
    char state[50];
    int zip;
    char major[50];
    char rank[50];
    float gpa;
};

struct SENTRY; /* Forward declaration */

struct SLIST {
    int length; // Length of list
    SENTRY *first; // Points to first entry
    SENTRY *last;
};

struct SENTRY {
    SLIST *list;
    SENTRY *next;
    SENTRY *prev;
    STUD *student;
};

/* Function Prototypes */
    /* menu.cpp */
void initialize_slist(SLIST &list);
void initialize_slist_from_file(SLIST &list);
int display_and_handle_menu(SLIST &list);

    /* display_record.cpp */
void display_record(const STUD *student);
void display_using_id(const SLIST &list);
void display_using_name(const SLIST &list);
void display_all_records(const SLIST &list);

    /* add_record.cpp */
void add_record(SLIST &list);
STUD* input_record();


    /* delete_record.cpp */
void delete_entry(SLIST &list, SENTRY *entry);
void delete_using_id(SLIST &list);
void delete_using_name(SLIST &list);

    /* save_and_exit.cpp */
void write_to_database(const SLIST &list);
void delete_list(SLIST &list);

    /* sort_by_name.cpp */
void sort_list_by_names(SLIST &list);

#endif // HW02_H