import java.util.Arrays;

public class TicTacToeGame
{
	/**
	 * The status of the 3x3 board. Each slot can be "-" for empty, "0" for player 1, or "1" for player 2.
	 */
	String Board[][];

	/**
	 * The player with the current turn. Should be 0 or 1.
	 */
	private int CurrentPlayerIndex;
	
	/**
	 *  @see GameStatus
	 */
	private GameStatus GameState;
        
        /**
         * MoveCount tracker.
         */
        
        private int moveCount;
	
	/*
	 * Constructor. Instantiate the Board array and fill it with the String "-". Reset the CurrentPlayerIndex and the GameState.
	 */
	public TicTacToeGame()
	{
        /* YOUR CODE HERE */
        // Instantiate Board
            Board = new String[3][3];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Board[i][j] = "-";
                }
            }
        }
	/**
	 * Start a new game. Reset the CurrentPlayerIndex and the GameState.
	 */
	public void StartNewGame()
	{
		// YOUR CODE HERE
                CurrentPlayerIndex = 0;
                GameState = GameStatus.ON;
                
	}
	
	/**
	 * Toggle the CurrentPlayerIndex between 0 and 1.
	 */
	public void NextTurn()
	{
		CurrentPlayerIndex = (CurrentPlayerIndex == 0) ? 1 : 0;
	}
	/**
	 * Which player's turn is it? player 1 or player 2?
	 * 
	 * @return either 1 or 2
	 */
	public int GetCurrentPlayer()
	{
		return CurrentPlayerIndex + 1;
	}
	
	/**
	 * Give the GameState to the calling program.
	 * 
	 * @return GameState
	 */
	public GameStatus GetGameState()
	{
		return GameState;
	}

	/**
	 * Fill a space with the CurrentPlayerIndex, which should be 0 or 1.
	 * 
	 * @param x the first, horizontal coordinate for the next move 
	 * @param y the second, vertical coordinate for the next move
	 */
	public void MakeMove(int x, int y)
	{
		// YOUR CODE HERE
                Board[y][x] = (CurrentPlayerIndex == 0) ? "0" : "1"; // REMEMBER TO PUT QUOTES OVER 0 and 1 BECAUSE THEY REPLACE STRINGS!
                moveCount++;
	}

	/**
	 * Checks the Board[][] array for win or draw conditions and updates the GameState property appropriately.
	 * 
	 * @return true if the game is over. false if the game should continue.
	 */
	public boolean CheckForWin()
	{
	// YOUR CODE HERE
            for(int i = 0; i < 3; i++) // THIS CHECKS HORIZONTAL
            {
                 if(Board[0][i].equals(Board[1][i]) && Board[0][i].equals(Board[2][i]))
                 {
                     if(Board[0][i].equals("0")) // P1 WIN HORIZ
                     {
                         GameState = GameStatus.WIN_PLAYER_1;
                         return true;
                     }
                     
                     if(Board[0][i].equals("1")) // P2 WIN HORIZ
                     {
                         GameState = GameStatus.WIN_PLAYER_2;
                         return true;
                     }
                 }
            }
            
            for(int i = 0; i < 3; i++) // THIS CHECKS VERTICAL
            {
                if(Board[i][0].equals(Board[i][1]) && Board[i][0].equals(Board[i][2]))
                {
                    if(Board[i][0].equals("0")) // P1 WIN VERT
                    {
                        GameState = GameStatus.WIN_PLAYER_1;
                        return true;
                    }
                    
                    if(Board[i][0].equals("1")) // P2 WIN VERT
                    {
                        GameState = GameStatus.WIN_PLAYER_2;
                        return true;
                    }
                }
            }
         
            if(Board[0][0].equals(Board[1][1]) && Board[0][0].equals(Board[2][2])) // THIS CHECKS DIAG L->R
                {
                    if(Board[0][0].equals("0")) // P1 WIN DIAG L->R
                    {
                        GameState = GameStatus.WIN_PLAYER_1;
                        return true;
                    }
                    
                    if(Board[0][0].equals("1")) // P2 WIN DIAG L->R
                    {
                        GameState = GameStatus.WIN_PLAYER_2;
                        return true;
                    }
                }
            
            if(Board[2][0].equals(Board[1][1]) && Board[2][0].equals(Board[0][2])) // THIS CHECKS DIAG R->L
                {
                    if(Board[2][0].equals("0")) // P1 WIN DIAG R->L
                    {
                        GameState = GameStatus.WIN_PLAYER_1;
                        return true;
                    }
                    
                    if(Board[2][0].equals("1")) // P2 WIN DIAG R->L
                    {
                        GameState = GameStatus.WIN_PLAYER_2;
                        return true;
                    }
                }
            
            if(moveCount == 9) // IF MOVECOUNT REACHES 9, THE GAME IS A DRAW. ALL 9 SPOTS OCCUPIED.
            {
                GameState = GameStatus.DRAW;
                return true;
            }
            
            return false;
	}
	
	/**
	 * Checks a string for win conditions. If three in a row occur, then it returns the proper GameState.
	 * This is a helper function that I used, but is not required for you to implement.
	 * 
	 * @param Input a representation of a row, column, or diagonal in the game. 
	 * 
	 * @return the proper GameStatus for a row, column, or diagonal represented by the Input String
	 *         "---" would indicate an entirely free row, column or diagonal, in which case it should return GameStatus.ON.
	 *         "000" indicates a row, column, or diagonal that has been won by player 1.
	 *         "111" indicates a row, column, or diagonal that has been won by player 2.
	 */
	private GameStatus CheckStringForThree(String Input)
	{
		// YOUR CODE HERE
		
		return GameStatus.ON;
	}
	
	/**
	 * <p>
	 * Print the game board to stdout.
	 * 0 should be used to represent moves by player 1.
	 * 1 should be used to represent moves by player 2.
	 * - should be used to represent a free space.
	 * One blank space should occur between each space.
	 * </p>
	 * <p>
	 * So an empty game board would be<br/>
	 * -&nbsp;-&nbsp;-<br/>
	 * -&nbsp;-&nbsp;-<br/>
	 * -&nbsp;-&nbsp;-<br/>
	 * </p>
	 * <p>
	 * And a game might look like<br/>
	 * 0&nbsp;-&nbsp;1<br/>
	 * 0&nbsp;-&nbsp;-<br/>
	 * 1&nbsp;-&nbsp;0<br/>
	 * </p>
	 * <p>
	 * WARNING: If you are storing the game board as Board[x][y], then the traditional nested loops won't 
	 * print the board properly. x should be the horizontal coordinate. y should be the vertical coordinate.
	 * </p>
	 */
	public void Print()
	{
		// YOUR CODE HERE
             System.out.println(Board[0][0] + " " + Board[0][1] + " " + Board[0][2]);
             System.out.println(Board[1][0] + " " + Board[1][1] + " " + Board[1][2]);
             System.out.println(Board[2][0] + " " + Board[2][1] + " " + Board[2][2]);
        }
}
