#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_QUESTION_LENGTH 100

typedef struct 
{
    char question[MAX_QUESTION_LENGTH];
    int answer; 
} Question;

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s Questions.txt\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int num_questions;
    fscanf(file, "%d", &num_questions);
    fgetc(file);
    Question questions[MAX_QUESTIONS];

    for (int i = 0; i < num_questions; i++)  
    {
        fgets(questions[i].question, sizeof(questions[i].question), file);
        strtok(questions[i].question, "\n"); 
        
        char answer[10];
        fgets(answer, sizeof(answer), file);
        strtok(answer, "\n");

        if (strcmp(answer, "True") == 0 || strcmp(answer, "true") == 0) 
        {
            questions[i].answer = 1;
        } else 
        {
            questions[i].answer = 0;
        }
    }
    fclose(file);

    int score = 0;
    printf("\nLet's start the quiz!\n");

    for (int i = 0; i < num_questions; i++) 
    {
        printf("\nQuestion %d:\n%s\n", i + 1, questions[i].question);
        printf("Enter 'True' or 'False': ");

        char user_answer[10];
        fgets(user_answer, sizeof(user_answer), stdin);
        strtok(user_answer, "\n");

        int user_response;
        if (strcmp(user_answer, "True") == 0 || strcmp(user_answer, "true") == 0) 
        {
            user_response = 1;
        } else
        {
            user_response = 0;
        }

        if (user_response == questions[i].answer) 
        {
        
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is: %s\n", (questions[i].answer == 1) ? "True" : "False");
        }
    }

    printf("\nQuiz finished! You scored %d out of %d\n", score, num_questions);

    return 0;
}

