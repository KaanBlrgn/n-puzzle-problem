#ifndef DATA_TYPES_H
#define DATA_TYPES_H



enum TILES 
{
    Tile1, Tile2, Tile3, 
    Tile4, Tile5, Tile6, 
    Tile7, Tile8, EmptyTile
};

enum ACTIONS // All possible moves
{
    MoveUp, MoveDown, MoveLeft, MoveRight
};

typedef struct State  
{
    int puzzle[3][3];  // 3x3'lük puzzle tahtasýný temsil eden 2 boyutlu bir dizi
    float h_n;          // Heuristic function
} State;

enum METHODS
{
	BreadthFirstSearch = 1,   UniformCostSearch = 2,        DepthFirstSearch = 3,    
	DepthLimitedSearch = 4,   IterativeDeepeningSearch = 5, GreedySearch = 6,
    AStarSearch = 7, GeneralizedAStarSearch = 8  
};

typedef struct Transition_Model
{
    State new_state;
    float step_cost;
} Transition_Model;

typedef struct Node
{
    State state;
    float path_cost;
    enum ACTIONS action; //The action applied to the parent to generate this node
    struct Node *parent;
    int Number_of_Child; // required for depth-first search algorithms
} Node;

typedef struct Queue  // Used for frontier
{
    State state;
    struct Queue *next;
} Queue;

#endif

