/* 
    These functions are compulsory for search algorithms but they are specific
    to problems. More clearly, you must must update their blocks but do not change
    their input and output parameters.
    
    Also, you can add new functions at the end of file by declaring them in GRAPH_SEARCH.h
*/

#include "GRAPH_SEARCH.h"
#include "data_types.h"
#include <stdio.h>
#include <stdlib.h>


void WarningMemoryAllocation(const char *message) {
    fprintf(stderr, "Memory allocation failed: %s\n", message);
    exit(EXIT_FAILURE);
}

//______________________________________________________________________________
State* Create_State()
{
 State *state = (State*)malloc(sizeof(State));
    if (state== NULL)
        WarningMemoryAllocation("Memory allocation failed!");
    
	state->PUZZLE_SIZE = 3;
    int i,j; 
    printf("Enter the status of the puzzle (row by row, separated by spaces and with a line break at the end of each row):\n");
	for (i = 0; i < state->PUZZLE_SIZE; i++) {
        for (j = 0; j < state->PUZZLE_SIZE; j++) { 
		    scanf("%d", &state->board[i][j]);
            if (state->board[i][j] == 0) {
            	state->empty_row= i; 
				state->empty_col = j;
			}
		}
	}
	printf("\n");
	
	return state;
}
//______________________________________________________________________________
void Print_State(const State* const state)
{
    // Assuming the state represents the puzzle configuration
    for (int i = 0; i < state->board_size; i++) {
        for (int j = 0; j < state->board_size; j++) {
            printf("%d ", state->board[i][j]);
        }
        printf("\n");
    }
}

//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
    switch (action) {
    case Move_Up: printf("Move Up"); break;
    case Move_Down: printf("Move Down"); break;
    case Move_Left: printf("Move Left"); break;
    case Move_Right: printf("Move Right"); break;
    }
}

//______________________________________________________________________________
int Result(const State* const parent_state, const enum ACTIONS action, Transition_Model* const trans_model)
{
    State new_state;
    // Assuming PATH_COSTS is a 2D array representing the cost of each action
    const int PATH_COSTS[PUZZLE_SIZE][PUZZLE_SIZE] = {
        // Define your costs for each action based on your puzzle requirements
    };

    // Check if the action is valid based on the empty cell position
    switch (action) {
    case Move_Up:
        if (parent_state->empty_row > 0) {
            new_state = *parent_state;
            new_state.board[parent_state->empty_row][parent_state->empty_col] = parent_state->board[parent_state->empty_row - 1][parent_state->empty_col];
            new_state.board[parent_state->empty_row - 1][parent_state->empty_col] = 0;
            new_state.empty_row = parent_state->empty_row - 1;
            new_state.empty_col = parent_state->empty_col;
            trans_model->new_state = new_state;
            trans_model->step_cost = PATH_COSTS[parent_state->empty_row][parent_state->empty_col]; // Update with appropriate cost
            return TRUE;
        }
        break;
    // Implement similar checks for other actions (Move_Down, Move_Left, Move_Right)
    }

    return FALSE;
}

//______________________________________________________________________________
float Compute_Heuristic_Function(const State *const state,const State *const goal)
{
	float h=0;
	int i,j,k,l,num;
	
	//Calculate the distance from Manhattan for each number from 1 to 8.
	for(num=1;num<=8;num++){
		//Finding the current position of the number in the current status
		int curr_row, curr_col;
		for(i=0;i<3;i++){
			if(state->board[i][j]==num){
				curr_row=i;
				cur_col=j;
				break;
			}
		}
	}
	
		//Find the target position of the number in target state.
		int goal_row,goal_col;
		for(k=0;k<3;k++){
			for(l=0;l<3;l++){
				if(goal->board[k][l]==num){
					goal_row=k;
					goal_col=l;
					break;
			}
		}
	}
		//Calculate the distance from Manhattan for this number
		int distance = abs(curr_row - goal_row) + abs(curr_col - goal_col);
		h += distance;
	}
	return h;
}

//_______________ Update if your goal state is not determined initially ___________________________________
int Goal_Test(const State *const state, const State *const goal_state)
{
	if(PREDETERMINED_GOAL_STATE)	
		return Compare_States(state, goal_state); 
	else
		return 1;
}

// ==================== WRITE YOUR OPTIONAL FUNCTIONS (IF REQUIRED) ==========================

