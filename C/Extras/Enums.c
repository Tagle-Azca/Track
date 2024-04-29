#include <stdio.h>

// we cna think of 'enum' like a menu of with different options. Here we have a menu for beach flags ans i will comment what those flags means.
enum BeachFlags
{
    GreenFlag,  // Option 0: All goof.
    YellowFlag, // Option 1: be careful.
    RedFlag,    // Option 2: it's dangerous.
    BlackFlag   // Option 3: don't even think about it.
};

int main()
{
    int choice; // now 'Choice' is like a menu of with different options and you need to choose one
    printf("Which flag is raised today? (0: Green, 1: Yellow, 2: Red, 3: Black): ");
    scanf("%d", &choice); // this section the print will ask you for a number that you need to put, thhen the scanf will read the number

    // with this the code get sure that you pick something from the menu
    if (choice < 0 || choice > 3)
    {
        printf("That's not a valid option. Try a number from 0 to 3.\n");
        return 1; // If you give a weird number, it will tell you something's wrong.
    }

    // the code will convert your choice into the corresponding flag.
    enum BeachFlags currentFlag = (enum BeachFlags)choice;

    // Depending on the flag you chose,it will tell you what it means.
    switch (currentFlag)
    {
    case GreenFlag:

        // do not steal my code-_-
        printf("Perfect day for a swim! The green flag means all is safe.\n");
        break;
    case YellowFlag:
        printf("You can go into the water, but be cautious. The yellow flag says to be alert.\n");
        break;
    case RedFlag:
        printf("Better stick to building sandcastles today. The red flag means the sea is dangerous.\n");
        break;
    case BlackFlag:
        printf("Today is not a day to be near the water. The black flag signals extremely dangerous conditions.\n");
        break;
    }

    return 0;
}
