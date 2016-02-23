import java.util.Scanner;

/**
 * This program tests the TicTacToeGame class.<br/>
 * For San Jose State University CS 46b.<br/>
 * 
 * @author Evan X. Merz
 */
public class Play_TicTacToe
{

	/**
	 * This method will run a quick game of TicTacToe, looking to stdin for moves
	 * 
	 * @param args not used
	 */
	public static void main(String[] args)
	{
		TicTacToeGame t = new TicTacToeGame();
		t.StartNewGame();

		Scanner user_input = new Scanner(System.in);		
		
		while(t.GetGameState() == GameStatus.ON)
		{
			System.out.println("Player " + t.GetCurrentPlayer() + ":");
			t.Print();
			
			System.out.println("  x coordinate for next move:");
			String UserInput = user_input.next();
			int x = Integer.parseInt(UserInput);

			System.out.println("  y coordinate for next move:");
			UserInput = user_input.next();
			int y = Integer.parseInt(UserInput);
			
			if( x >= 0 && x < 3 && y >= 0 && y < 3 )
			{
				t.MakeMove(x, y);
			}

			t.CheckForWin();
			t.NextTurn();
		}
		if( t.GetGameState() == GameStatus.DRAW ) System.out.println("Game resulted in a draw.");
		else if( t.GetGameState() == GameStatus.WIN_PLAYER_1) System.out.println("Player 1 won.");
		else if( t.GetGameState() == GameStatus.WIN_PLAYER_2) System.out.println("Player 2 won.");
		t.Print();
	}

}
