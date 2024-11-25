#include <stdio.h>
#include <stdbool.h>
#include "project.h"

int main(void)
{
    int chosen_action_item = 0;
    bool is_input_valid;
    const char action_menu[] = {
        "Please select an item from below for your next action:\n "
        "1. Check in\n "
        "2. Check out\n "
        "3. Book a dinner table\n "
        "4. Exit program\n"
        "Enter a corresponding number:"};

    printf("Welcome to Hotel Kashyyyk!\n");

    enum action_menu
    {
        ACTN_CHECK_IN = 1,
        ACTN_CHECK_OUT,
        ACTN_BOOK_TABLE,
        ACTN_EXIT_PROGRAM
    };

    do { // until item ACTN_EXIT_PROGRAM is not selected
        printf(action_menu);

        do { // until valid input is given
            is_input_valid = true;

            fflush(stdin);
            scanf("%d", &chosen_action_item);

            if (chosen_action_item < ACTN_CHECK_IN || chosen_action_item > ACTN_EXIT_PROGRAM)
            {   is_input_valid = false;
                printf("It seems that your input is invalid! Please try selecting again:\n");}

        } while (is_input_valid == false); // check if user input is an integer in a given range

        switch (chosen_action_item)
        {   case ACTN_CHECK_IN:
                checkIn();
                break;
            case ACTN_CHECK_OUT:
                checkOut();
                break;
            case ACTN_BOOK_TABLE:
                bookTable();
                break;
            case ACTN_EXIT_PROGRAM:
                printf("Thank you for staying with us!");
                return 0;
            default:
                printf("An error occured when selecting an item from the menu.");
                return 1;}
    } while (chosen_action_item != ACTN_EXIT_PROGRAM); // check if user wants to exit the program

    return 0;
}
