#include <stdio.h>
#include <string.h>

// Define states
enum State { Q0, Q1, Q2, Q3, Q4, Q5 };

// Function to simulate the unique finite automaton
int simulateFA(char *input) {
    enum State currentState = Q0; // Start state

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        switch (currentState) {
            case Q0:
                if (c == 'a') currentState = Q1;
                else if (c == 'b') currentState = Q3;
                break;
            case Q1:
                if (c == 'a') currentState = Q2;
                else if (c == 'b') currentState = Q4;
                break;
            case Q2:
                if (c == 'a') currentState = Q0;
                else if (c == 'b') currentState = Q5;
                break;
            case Q3:
                if (c == 'a') currentState = Q4;
                else if (c == 'b') currentState = Q0;
                break;
            case Q4:
                if (c == 'a') currentState = Q5;
                else if (c == 'b') currentState = Q1;
                break;
            case Q5:
                if (c == 'a') currentState = Q3;
                else if (c == 'b') currentState = Q2;
                break;
        }
    }

    // Accept if in state Q3 (a count % 3 == 0 and odd b count)
    return (currentState == Q3);
}

int main() {
    char input[100];

    printf("Enter a string over {a, b}: ");
    scanf("%s", input);

    if (simulateFA(input)) {
        printf("String '%s' is ACCEPTED.\n", input);
    } else {
        printf("String '%s' is REJECTED.\n", input);
    }

    return 0;
}
