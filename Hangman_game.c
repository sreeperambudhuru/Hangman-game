#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD_LENGTH 50

void print_hangman(int tries);
void print_word_state(const char* word, const int* guessed);

int main() {
    char word[WORD_LENGTH] = "programming";  // The word to guess
    int word_length = strlen(word);
    int guessed[WORD_LENGTH] = {0};  // Tracks guessed letters
    int tries = 0;
    char guess;
    int correct_guess;

    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES) {
        print_word_state(word, guessed);
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        correct_guess = 0;
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                guessed[i] = 1;
                correct_guess = 1;
            }
        }

        if (!correct_guess) {
            tries++;
            printf("Incorrect guess!\n");
            print_hangman(tries);
        }

        // Check if the player has won
        int won = 1;
        for (int i = 0; i < word_length; i++) {
            if (!guessed[i]) {
                won = 0;
                break;
            }
        }

        if (won) {
            printf("Congratulations! You've guessed the word: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("Sorry, you've run out of tries. The word was: %s\n", word);
    }

    return 0;
}

void print_hangman(int tries) {
    printf("\nHangman Status:\n");
    switch (tries) {
        case 0:
            printf("  _____\n");
            printf("  |   |\n");
            printf("      \n");
            printf("      \n");
            printf("      \n");
            printf("      \n");
            break;
        case 1:
            printf("  _____\n");
            printf("  |   |\n");
            printf("  O   \n");
            printf("      \n");
            printf("      \n");
            printf("      \n");
            break;
        case 2:
            printf("  _____\n");
            printf("  |   |\n");
            printf("  O   \n");
            printf("  |   \n");
            printf("      \n");
            printf("      \n");
            break;
        case 3:
            printf("  _____\n");
            printf("  |   |\n");
            printf("  O   \n");
            printf(" /|   \n");
            printf("      \n");
            printf("      \n");
            break;
        case 4:
            printf("  _____\n");
            printf("  |   |\n");
            printf("  O   \n");
            printf(" /|\\  \n");
            printf("      \n");
            printf("      \n");
            break;
        case 5:
            printf("  _____\n");
            printf("  |   |\n");
            printf("  O   \n");
            printf(" /|\\  \n");
            printf(" /    \n");
            printf("      \n");
            break;
        case 6:
            printf("  _____\n");
            printf("  |   |\n");
            printf("  O   \n");
            printf(" /|\\  \n");
            printf(" / \\  \n");
            printf("      \n");
            break;
        default:
            break;
    }
}

void print_word_state(const char* word, const int* guessed) {
    printf("\nWord: ");
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
