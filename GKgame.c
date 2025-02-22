#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RESET   "\033[0m"    
#define RED     "\033[31m"
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"   
#define BLUE    "\033[34m" 
#define CYAN    "\033[36m" 
#define WHITE   "\033[37m" 
#define MAGENTA "\033[35m"  
#define UNDERLINE "\033[4m"
#define TOTAL_QUESTIONS 15
struct Question
{
    char question[100];
    char options[4][150];
    int correctOption;
};
struct Question questions[TOTAL_QUESTIONS] = {
    {YELLOW"Who is the creator of the C programming language?"RESET,
     {MAGENTA"James Gosling"RESET, MAGENTA"Dennis Ritchie"RESET, MAGENTA"Guido van Rossum"RESET, MAGENTA"Bjarne Stroustrup"}, 2},

    {YELLOW"Which company developed Java?"RESET,
     {MAGENTA"Sun Microsystems"RESET, MAGENTA"Microsoft"RESET, MAGENTA"Apple"RESET, MAGENTA"Google"RESET}, 1},

    {YELLOW"What does HTML stand for?",
     {MAGENTA"Hyper Text Markup Language"RESET, MAGENTA"High Transfer Machine Learning"RESET, 
      MAGENTA"Hyperlink and Text Management Language"RESET, MAGENTA"Home Tool Management Language"RESET}, 1},

    {YELLOW"Which programming language is primarily used for Android development?"RESET,
     {MAGENTA"Swift"RESET, MAGENTA"Kotlin"RESET, MAGENTA"C++"RESET, MAGENTA"Python"RESET}, 2},

    {YELLOW"Who developed Python?"RESET,
     {MAGENTA"Dennis Ritchie"RESET, MAGENTA"Guido van Rossum"RESET, MAGENTA"Bjarne Stroustrup"RESET,MAGENTA "James Gosling"RESET}, 2},

    {YELLOW"What does RAM stand for?"RESET,
     {MAGENTA"Random Access Memory"RESET, MAGENTA"Read Access Memory"RESET,MAGENTA "Rapid Action Module"RESET, MAGENTA"Run Access Mode"RESET}, 1},

    {YELLOW"What does CPU stand for?"RESET,
     {MAGENTA"Central Process Unit"RESET, MAGENTA"Central Processing Unit"RESET,MAGENTA "Computer Processing Unit"RESET,MAGENTA "Central Performance Unit"RESET}, 2},

    {YELLOW"What is the extension of C source files?"RESET,
     {MAGENTA".exe"RESET,MAGENTA ".txt"RESET, MAGENTA".c"RESET, MAGENTA".cpp"RESET}, 3},

    {YELLOW"Which company created Windows OS?"RESET,
     {MAGENTA"Apple"RESET, MAGENTA"Google"RESET, MAGENTA"Microsoft"RESET, MAGENTA"IBM"RESET}, 3},

    {YELLOW"Which of the following is not an operating system?"RESET,
     {MAGENTA"Windows"RESET, MAGENTA"Linux"RESET,MAGENTA "C++"RESET, MAGENTA"MacOS"RESET}, 3},

    {YELLOW"Which sorting algorithm has the best average-case complexity?"RESET,
     {MAGENTA"Bubble Sort"RESET, MAGENTA"Quick Sort"RESET, MAGENTA"Merge Sort"RESET, MAGENTA"Selection Sort"RESET}, 3},

    {YELLOW"What is the default port number of HTTP?"RESET,
     {MAGENTA"21"RESET, MAGENTA"80"RESET,MAGENTA "443"RESET, MAGENTA"8080"RESET}, 2},

    {YELLOW"What does OOP stand for?"RESET,
     {MAGENTA"Object-Oriented Programming"RESET,MAGENTA "Open-Operational Process"RESET,MAGENTA "Online Object Processing"RESET,MAGENTA "Object-Oriented Processing"RESET}, 1},

    {YELLOW"Which of the following is a relational database?"RESET,
     {MAGENTA"MongoDB"RESET, MAGENTA"Redis"RESET,MAGENTA "MySQL"RESET, MAGENTA"Neo4j"RESET}, 3},

    {YELLOW"Which logic gate gives an output of 1 only when both inputs are different? "RESET,
     {MAGENTA"AND"RESET, MAGENTA"OR"RESET, MAGENTA"XOR"RESET, MAGENTA"NOR"RESET}, 2},

    {YELLOW"Which of the following languages is used in front-end web development? "RESET,
     {MAGENTA"PHP"RESET, MAGENTA"SQL"RESET, MAGENTA"PYTHON"RESET, MAGENTA"JAVASCRIPT"RESET}, 4}
    };

int main()
{
    char name[20];
    char choice;
    int points =0; 
    int answer;
    printf(CYAN"Enter your name: "RESET);
    scanf("%s", name);
    printf(YELLOW"\n^.^ > Hello %s, Welcome to the GK game! < ^.^ \n",name,RESET);
    do
    {
        printf("%s, please enter 'y' to check the rules of the game: ", name);
        scanf(" %c", &choice);
    } while (choice != 'y');

    printf(BLUE"\nRules of the game:\n"RESET);
    printf(BLUE"1) The game will start with %d questions.\n", TOTAL_QUESTIONS,RESET);
    printf(BLUE"2) Choose the correct option (1-4).\n"RESET);
    printf(BLUE"3) %s, you start with 0 points.\n", name,RESET);
    printf(BLUE"4) Correct answer: +5 points, Wrong answer: -1 point.\n"RESET);
    printf(BLUE"5) Try to score as high as possible!\n"RESET);
    printf(GREEN"\nLet's begin the game!\n"RESET);
    for (int i = 0; i < TOTAL_QUESTIONS; i++)
    {
        printf("\nQ%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++)
        {
            printf("%d) %s\n", j + 1, questions[i].options[j]);
        }
        printf(UNDERLINE"Enter your answer (1-4): "RESET);
        scanf("%d", &answer);
        if (answer < 1 || answer > 4)
        {
            printf(RED"Invalid choice! Please enter a number between 1 and 4.\n"RESET);
            i--;
            continue;
        }
        if (answer == questions[i].correctOption)
        {
            printf(GREEN" Correct answer! You earn +5 points.\n"RESET);
            points += 5;
        }
        else
        {
            printf(RED" Wrong answer! You lose -1 point.\n"GREEN);
            points -= 1;
        }
        printf(YELLOW"Current Points: %d\n", points,RESET);
    }

    printf(RED"\n Game Over! %s, your final points: %d\n", name, points,RESET);

    if (points >=70)
        printf(BLUE" You are a Computer Science Master!\n"RESET);
    else if (points >= 50)
        printf(BLUE"You are a Computer Science Enthusiast!\n"RESET);
    else if (points >=40)
        printf(BLUE"Keep learning and improving!\n"RESET);
    else
        printf(BLUE"Don't give up! Keep practicing and try again.\n"RESET);

    return 0;
}
