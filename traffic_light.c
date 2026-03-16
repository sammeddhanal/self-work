#include <stdio.h>
#include <unistd.h>

typedef enum
{
    RED,
    GREEN,
    YELLOW
} State;

State next_state(State current)
{
    switch(current)
    {
        case RED:
            return GREEN;

        case GREEN:
            return YELLOW;

        case YELLOW:
            return RED;
    }
}

void display_state(State s)
{
    switch(s)
    {
        case RED:
            printf("RED Light\n");
            sleep(5);
            break;

        case GREEN:
            printf("GREEN Light\n");
            sleep(5);
            break;

        case YELLOW:
            printf("YELLOW Light\n");
            sleep(2);
            break;
    }
}

int main()
{
    State current = RED;

    while(1)
    {
        display_state(current);
        current = next_state(current);
    }

    return 0;
}
