#include <iostream>
#include <map>


//! Holds the identification for a player.
struct PlayerID {

	//! The name for the player.
	std::string name;
	//! The numerical identification for the player.
	int         id;

	/**
	 * Tests if player id is the same as the provided one.
	 * @param rhs Other player id.
	 * @return true if the name and id are the same as the other player id.
	 */
	bool operator == (const PlayerID &rhs) const {
		return (name == rhs.name) &&
		       (id == rhs.id);
	}

	/**
	 * Tests if player id is not the same as the given one.
	 * @param rhs the other player id
	 * @return true if player id is not the same as rhs.
	 */
	bool operator != (const PlayerID &rhs) const {
		return !(rhs == *this);
	}

	/**
	 * Tests if player id is less than the given player id.
	 * @param rhs The other player id.
	 * @return True if id is less than rhs.
	 */
	bool operator < (const PlayerID &rhs) const {
		return id < rhs.id;
	}

	/**
	 * Tests if player id is greater than the given player id.
	 * @param rhs The other player id.
	 * @return true if rhs is less than this player id.
	 */
	bool operator > (const PlayerID &rhs) const {
		return rhs < *this;
	}

	/**
	 * Tests if player id is less than or equal to given player id.
	 * @param rhs The other player id.
	 * @return true if player id is less than or equal to rhs.
	 */
	bool operator <= (const PlayerID &rhs) const {
		return !(rhs < *this);
	}

	/**
	 * Tests if player id is greater than or equal to given player id.
	 * @param rhs the other player id.
	 * @return true if player id is greater than or equal to rhs.
	 */
	bool operator >= (const PlayerID &rhs) const {
		return !(*this < rhs);
	}
};

//! Add an easy name for player scores.
typedef std::map < PlayerID, int > PlayerScores;

/**
 * Prints an individual player's score.
 * @param player_id The player to be printed.
 * @param score The score of the player.
 */
void print (const PlayerID &player_id, const int &score);
/**
 * Tests if the given string is a number.
 * @param s The string to check on.
 * @return true if all characters in the string are digits.
 */
bool is_num (const std::string &s);
/**
 * Print all player scores.
 * @param scores a map holding the players' id as the key and their scores as their value.
 */
void print (const PlayerScores &scores);

/**
 * Checks if the given input is equivalent to a player id.
 * @param input The given input.
 * @param player_id The given player id to tested on.
 * @return true if the first character of the player's name is the input or the input is the player's name or id.
 */
bool is_player (const std::string &input, const PlayerID &player_id);

/**
 * Sets an inputted player's score to an inputted value.
 * @param scores The scores of the players in the game.
 */
void set_score (PlayerScores &scores);

/**
 * Add to a player's score with an inputted value.
 * @param scores The scores of the player in the game.
 * @param input The inputted player to be added to.
 */
void add_to_score (PlayerScores &scores, const std::string &input);

PlayerScores get_players ( );

int main ( ) {

	auto player_score = get_players();

	//! The input from the console.
	std::string input;

	// A help message
	std::cout << "Input <player id> <score addition> to change score at prompt." << std::endl;

	// Show the prompt
	std::cout << "> ";

	// While input is good (not EOF or corrupted)...
	while ( (std::cin >> input) ) {
		// Check if we want to print all the players scores.
		if ( input == "print" ) {
			// Do so if needed.
			print( player_score );
		} else if ( input[ 0 ] == 'p' ) { // Check if we want to print individual player's scores.
			// Get the requested player id.
			std::cin >> input;
			// For each player in the game...
			for ( auto &player : player_score ) {
				// If we are at the requested player...
				if ( is_player( input, player.first ) ) {
					// Print their score and id.
					print( player.first, player.second );
					// Early break.
					break;
				}
			}
		} else if ( input == "set" ) { // If we want to set a player's score...
			// Then do it.
			set_score( player_score );
		} else { // Otherwise...
			// Add to a player's score.
			add_to_score( player_score, input );
		}
		// Show the prompt.
		std::cout << "> ";
	}

	// Print final scores.
	print( player_score );

	// Exit code.
	return 0;
}

bool is_num (const std::string &s) {
	// For each character in the string...
	for ( auto c : s ) {
		// If the current character is not a digit...
		if ( !std::isdigit( c ) ) {
			// Return that the string is not a number.
			return false;
		}
	}
	// Return true if all the characters in the string are digits.
	return true;
}

void print (const PlayerScores &scores) {
	// For each player in the game...
	for ( const auto &score : scores ) {
		// Print their individual scores.
		print( score.first, score.second );
	}
}

void print (const PlayerID &player_id, const int &score) {
	// Print the given player's score.
	std::cout << "Player " << player_id.id << ": " << player_id.name << " has score " << score << "." << std::endl;
}

bool is_player (const std::string &input, const PlayerID &player_id) {

	// If input is only one character and is equal to the given player's first letter...
	if ( input.size() == 1 && input[ 0 ] == player_id.name[ 0 ] ) {
		// It is the given player.
		return true;
	}
	// If the input is a number and is equal to the player's id...
	if ( is_num( input ) && player_id.id == std::atoi( input.c_str() ) ) {
		// It is the given player.
		return true;
	}
	// Check if the input is the player's name.
	return input == player_id.name;
}

void set_score (PlayerScores &scores) {
	// Get the player we want to change the score of
	std::string player_input;
	std::cin >> player_input;
	// For each player in the game...
	for ( auto &player : scores ) {
		// If we found the right player...
		if ( is_player( player_input, player.first ) ) {
			// Get the new score.
			int num;
			std::cin >> num;
			// Set player's score to that number.
			player.second = num;
			// Print some stuff.
			std::cout << "Set Player " << player.first.name << "'s score to " << num << "." << std::endl;
			// Print the player's information.
			print( player.first, player.second );
			// Early quit from player for loop.
			break;
		}
	}
}

void add_to_score (PlayerScores &scores, const std::string &input) {
	// For each player in the game...
	for ( auto &player : scores ) {
		// If the input is the current player in the loop...
		if ( is_player( input, player.first ) ) {
			int addition;
			// Add the input to the player's score.
			std::cin >> addition;
			player.second += addition;
			// Confirm we increased their score.
			std::cout << player.first.name << " got " << addition << " points!" << std::endl;
			// Print the current score of the player.
			print( player.first, player.second );
			// Early break.
			break;
		}
	}
}

PlayerScores get_players ( ) {
	//! Total number of players.
	int num_of_players;
	std::cout << "How many players?" << std::endl;
	std::cin >> num_of_players;

	//! All of the player scores.
	PlayerScores player_score;

	// Add the players to the game.
	for ( int i = 0; i < num_of_players; i++ ) {
		std::cout << "What's player " << i + 1 << "'s name? " << std::endl;
		std::string name;
		std::cin >> name;
		// Set the player's initial score to 0
		player_score[ {name, i + 1} ] = 0;
	}
	return player_score;
}
