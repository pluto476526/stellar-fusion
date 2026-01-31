#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constellation.h"
#include "display.h"

void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_menu(void) {
    printf("================================================================\n");
    printf("                  STELLAR FUSION - CONSTELLATIONS               \n");
    printf("================================================================\n");
    printf("\n");
    
    int count = get_constellation_count();
    int items_per_col = (count + 2) / 3;  // 3 columns
    
    for (int i = 0; i < items_per_col; i++) {
        for (int col = 0; col < 3; col++) {
            int idx = i + col * items_per_col;
            if (idx < count) {
                const Constellation* c = get_constellation(idx);
                printf(" %2d. %-18s", idx + 1, c->name);
            } else {
                printf("                      ");
            }
        }
        printf("\n");
    }
    
    printf("===============================================================\n");
    printf("   0. Exit                         R. Random Constellation     \n");
    printf("===============================================================\n");
}

int main(void) {
    char input[10];
    int choice;
    
    srand(time(NULL));  // Seed for random constellation
    
    do {
        clear_screen();
        print_menu();
        
        printf("\nSelect constellation (1-%d, R for random, 0 to exit): ", 
               get_constellation_count());
        scanf("%9s", input);
        
        if (strcmp(input, "0") == 0) {
            printf("\nGoodbye! Keep watching the stars! ✨\n");
            break;
        }
        
        if (strcasecmp(input, "R") == 0 || strcasecmp(input, "random") == 0) {
            choice = rand() % get_constellation_count() + 1;
            printf("Random selection: %d\n", choice);
        } else {
            choice = atoi(input);
        }
        
        if (choice < 1 || choice > get_constellation_count()) {
            printf("Invalid selection. Press Enter to continue...");
            getchar(); getchar();
            continue;
        }
        
        clear_screen();
        
        // Initialize and render
        init_grid();
        const Constellation* selected = get_constellation(choice - 1);
        render_constellation(selected);
        
        printf("\n==============================================================\n");
        printf("   CONSTELLATION: %-45s\n", selected->name);
        printf("   Stars: %2d\n", selected->star_count);
        printf("==============================================================\n");
        
        printf("\nPress Enter to continue...");
        getchar(); // Clear newline from scanf
        getchar(); // Wait for Enter
        
    } while (1);
    
    return 0;
}
