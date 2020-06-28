#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Max customers and entries
#define MAX_ENTRIES 1000
#define MAX_CUSTOMERS 50

// Customers have name, and entries
typedef struct
{
    char name[64];
    int entries;
}
customer;

// Array of customers
customer customers[MAX_CUSTOMERS];


int pool[MAX_ENTRIES * MAX_CUSTOMERS];

// Numbers of Customers and Entries
int entry_count;
int customer_count;

// Function prototypes

int printRandoms(int lower, int upper, int draws);


int main(void)
{

    printf("Number of Customers: ");
    scanf("%i", &customer_count);
    int cc;
    while((cc = getchar()) != '\n' && cc != EOF);
    int count = 0;
    for (int i = 0; i < customer_count; i++)
    {
        printf("Customer %i's name: ", i + 1);
        if (fgets(customers[i].name, sizeof (customers[i].name), stdin))
        {
            // input has worked, do something with data
            printf("customer name is : %s", customers[i].name);
        }
        printf("Number of entries for %s: ", customers[i].name);
        scanf("%i", &entry_count);
	customers[i].entries = entry_count;
        printf("entry_count is %i\n", entry_count);
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        int whichCustomer = i;
        if (entry_count > MAX_ENTRIES)
        {
            printf("Maximum number of entries is %i\n", MAX_ENTRIES);
            return 3;
        }
        for (int x = 0; x < entry_count; x++)
        {
            pool[count] = whichCustomer;
            count = count + 1;
        }
    }
    int lower = 0, upper = count - 1, draws = 1;
    // Use current time as
    // seed for random generator
    srand(time(0));
    int random_slot = printRandoms(lower, upper, draws);
    int winner_num = pool[random_slot];
    printf("Winner num %i\n", winner_num);
    printf("The winner is : %s, %s had %d entries out of %d total entries!!\n", customers[winner_num].name, customers[winner_num].name, customers[winner_num].entries, count);
    return 0;
}

int printRandoms(int lower, int upper, int draws)
{
    int z;
    int num;
    for (z = 0; z < draws; z++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        printf("The Random is %d , the lower is %d , the upper is %d\n", num, lower, upper);
    }
    return num;
}

