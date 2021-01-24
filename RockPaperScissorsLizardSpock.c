#include <stdio.h>
#include <time.h> //for generating seed
#include <stdlib.h> //for rand function

char* getName(int x) { //so 0-4 can be used for the input but replaced with their corresponding choice in its word in the output
    switch (x) {
        case 0:
            return "rock";
            break;
        case 1:
            return "paper";
            break;
        case 2:
            return "scissors";
            break;
        case 3:
            return "lizard";
            break;
        case 4:
            return "spock";
            break;
        default:
            return "invalid"; //for if anything other than 0-4 is entered
    }
}
int main() {
    srand(time(NULL)); //sets the seed for the random computer choice
    int matrix [5][5] = { //matrix corresponding to wins and loses for player, win=-1, lose=1 and draw=0
        {0, -1, 1, 1, -1},
        {1,  0, -1, -1, 1},
        {-1, 1, 0 , 1, -1},
        {-1, 1, -1, 0, 1},
        {1, -1, 1, -1, 0}};
        //sc -> l,p
        //sp -> sc, r
        //l -> sp, p
        //r -> sc, l
        //p -> sp, r
        
        //Losing
        //sc -> sp, r
        //sp -> l, p
        //l -> sc, r
        //r -> sp, p
        //p -> sc, l
    
    printf("Enter your choice of rock(0), paper(1), scissors(2), lizard(3) or spock(4):\n"); //text asking player for input
    
    int player, computer, isGameOver=0, rounds=0; //declaring integers
    
    while (!isGameOver) {
        rounds += 1; //adds 1 to round count
        computer = rand()%5; //generating computers random choice from 0-4
        scanf("%d", &player); //getting players input
        printf("computer = %s, player = %s\n", getName(computer), getName(player)); //gets what entry in the matrix to get result from
        if (matrix[computer][player] == 1) { //case for if player loses
            printf("Computer has won!\n");
            isGameOver = 1;
        } else if (matrix[computer][player] == -1) { //case for if player wins
            printf("Player has won!\n");
            isGameOver = 1;
        } else if (matrix[computer][player] == 0) { //case for a draw
            printf("Its a draw, play again.\n");
            isGameOver = 0;
                   }
    }
    printf("The game took %d round(s) to complete\n", rounds); //prints rounds
    return 0;
}
