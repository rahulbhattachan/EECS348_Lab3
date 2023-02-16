/*

#include <stdio.h>



int main()
{
    int score;
    printf("Enter a score (value less than or equal to 1 to stop): ");
    scanf("%d", &score);
    if (score > 1)
        {
            
        }
    else;
    printf("Program terminated.\n");
    return 0;
}
*/

#include <stdio.h>


void print_combination(int td_plustwo, int td_plusFG  ,int touchdowns, int field_goals, int safety)
{
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d  Safety\n", td_plustwo, td_plusFG, touchdowns, field_goals, safety);
}

void find_combinations(int score)
{
    int td_plustwo, td_plusFG, touchdowns, field_goals, safety, points;
    for(td_plustwo = 0; touchdowns <= score / 8; td_plustwo++)
    {   
        for(td_plusFG = 0; td_plusFG <= score / 7; td_plusFG++)
        {
            for (touchdowns = 0; touchdowns <= score / 6; touchdowns++)
            {
                for (field_goals = 0; field_goals <= score / 3; field_goals++)
                {
                    for(safety = 0; safety <= score / 2; safety++)
                    {
                        points = score - td_plustwo*8 - td_plusFG*7 - touchdowns*6 - field_goals*3 - safety*2;
            if (points == 0)
            {
                print_combination(td_plustwo, td_plusFG, touchdowns, field_goals, safety);
            }
                    }
            
                }
            }
        }
        
    }
     
}

int main()
{
    int score;
    printf("Enter 0 or 1 to stop\n");
    printf("Enter an American football score: ");
    scanf("%d", &score);
    if (score == 0 )
        printf("Program terminated.\n");
    else if (score == 1)
        printf("Program terminated.\n");
    else
    printf("All possible combinations of scoring plays that result in %d points:\n", score);
    find_combinations(score);
     return 0;
    }
    
    
   

