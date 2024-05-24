  #include <iostream> // Include the input/output library
  using namespace std; // Use the standard namespace

  // Function to decide the points based on the prisoners' decisions
  int* makeDecision(int prisoner1, int prisoner2) {
      static int a[2]; // Declare a static array of two integers
      if (prisoner1 == 0 && prisoner2 == 0) { // Both prisoners are quiet
          a[0] = 2; // Assign 2 points to both prisoners
          a[1] = 2;
      } else if (prisoner1 == 0 && prisoner2 == 1) { // First prisoner is quiet, second prisoner speaks
          a[0] = 5; // Assign 5 points to the first prisoner and 1 point to the second
          a[1] = 1;
      } else if (prisoner1 == 1 && prisoner2 == 0) { // First prisoner speaks, second prisoner is quiet
          a[0] = 1; // Assign 1 point to the first prisoner and 5 points to the second
          a[1] = 5;
      } else if (prisoner1 == 1 && prisoner2 == 1) { // Both prisoners speak
          a[0] = 4; // Assign 4 points to both prisoners
          a[1] = 4;
      } else { // Invalid input
          a[0] = 0; // Assign 0 points to both prisoners
          a[1] = 0;
      }
      return a; // Return the pointer to the array
  }

  // Function to take validated input from the user
  int takeInput(string inputMessage, int value1, int value2) {
      int inputReceived; // Declare an integer variable to store the input
      bool shallContinue = true; // Declare a boolean variable to control the loop
      do {
          cout << inputMessage; // Print the input message to the console
          cin >> inputReceived; // Read the input from the user
          if (inputReceived == value1 || inputReceived == value2) { // Valid input
              shallContinue = false; // Set the loop condition to false
          } else { // Invalid input
              cout << "Invalid Input. Please try again." << endl; // Print an error message to the console
          }
      } while (shallContinue); // Repeat the loop while the condition is true
      return inputReceived; // Return the input value
  }

  int main() {
      bool shouldContinue = true; // Declare a boolean variable to control the loop
      int prisoner1Points = 0, prisoner2Points = 0; // Declare variables to store the points of the prisoners

      do {
          int prisoner1, prisoner2; // Declare variables to store the moves of the prisoners
          int repeatLoop; // Declare a variable to store the user's choice

          // Get the first prisoner's move
          prisoner1 = takeInput("Please enter first Prisoner's move. Enter 0 for Quiet and 1 for Speak.\n", 0, 1);
          // Get the second prisoner's move
          prisoner2 = takeInput("Please enter second Prisoner's move. Enter 0 for Quiet and 1 for Speak.\n", 0, 1);

          // Get the decision based on the prisoners' moves
          int* decision = makeDecision(prisoner1, prisoner2);

          // Update the points of the prisoners
          prisoner1Points += decision[0];
          prisoner2Points += decision[1];

          // Ask the user if they want to continue or exit
          repeatLoop = takeInput("Do you want to continue or leave? Enter 0 for exit and 1 for continuing\n", 0, 1);
          if (repeatLoop == 0) {
              shouldContinue = false; // Exit the loop if the user chooses to exit
          }

          // Print the current points of both prisoners
          cout << "-------------------------------------------------------" << endl;
          cout << "Prisoner 1 Points == " << prisoner1Points << endl;
          cout << "Prisoner 2 Points == " << prisoner2Points << endl;
          cout << "-------------------------------------------------------" << endl;

      } while (shouldContinue); // Repeat the loop while the condition is true

      // Print the final points of both prisoners
      cout << "-------------------------------------------------------" << endl;
      cout << "Final Scores:" << endl;
      cout << "Prisoner 1 Points == " << prisoner1Points << endl;
      cout << "Prisoner 2 Points == " << prisoner2Points << endl;
      cout << "-------------------------------------------------------" << endl;

      return 0; // Return 0 as the main function value
  }
