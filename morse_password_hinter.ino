#define DOT_DURATION 500    // Duration of a dot in milliseconds
#define DASH_DURATION 1500  // Duration of a dash in milliseconds
#define GAP_DURATION 500    // Duration between dots and dashes
#define LETTER_GAP 1500     // Duration between letters
#define WORD_GAP 3000       // Duration between words

const int ledPin = 13; // Built-in LED pin

String accounts[] = {"CitiBank", "Gmail", "Canvas", "Kaiser Permanente", "Amazon", "Spotify", "AppleID"};
String passwords[] = {"hunnidbandz", "goGlGogl", "DeliaG", "koolaidPunch", "Bezos", "meus1c", "penpineapplepen"};

int mode = 0; // 1 for typing password, 2 for listening in Morse Code
int selectedAccount = -1;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 baud
  displayInitialMenu();
}

// Function to display the initial menu
void displayInitialMenu() {
  Serial.println("");
  Serial.println("PASSWORD RETRIEVER:");
  Serial.println("Use one of these methods to retrieve a password.");
  Serial.println("Enter \"1\" or \"2\":");
  Serial.println("1. Type the password");
  Serial.println("2. Listen to half the password in Morse Code");
}

// Function to display the account selection menu
void displayAccountMenu() {
  Serial.println("PASSWORD RETRIEVER:");
  Serial.println("Enter the number of the account you need a password for:");
  int arraySize = sizeof(accounts) / sizeof(accounts[0]);
  for (int i = 0; i < arraySize; i++) {
    Serial.print(i + 1);
    Serial.print(". ");
    Serial.println(accounts[i]);
  }
}

// Function to blink LED for a specified duration
void blinkLED(int duration) {
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(GAP_DURATION);
}

// Function to encode and blink a single character
void blinkCharacter(char c) {
  switch (c) {
    case 'A': blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); break;
    case 'B': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case 'C': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); break;
    case 'D': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case 'E': blinkLED(DOT_DURATION); break;
    case 'F': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); break;
    case 'G': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); break;
    case 'H': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case 'I': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case 'J': blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case 'K': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); break;
    case 'L': blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case 'M': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case 'N': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); break;
    case 'O': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case 'P': blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); break;
    case 'Q': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); break;
    case 'R': blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); break;
    case 'S': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case 'T': blinkLED(DASH_DURATION); break;
    case 'U': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); break;
    case 'V': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); break;
    case 'W': blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case 'X': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); break;
    case 'Y': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case 'Z': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case '1': blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case '2': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case '3': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    case '4': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DASH_DURATION); break;
    case '5': blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case '6': blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case '7': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case '8': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); blinkLED(DOT_DURATION); break;
    case '9': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DOT_DURATION); break;
    case '0': blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); blinkLED(DASH_DURATION); break;
    default: break;
  }
  delay(LETTER_GAP); // Gap between characters
}

// Function to encode and blink a message
void blinkMessage(String message) {
  for (int i = 0; i < message.length(); i++) {
    if (message[i] == ' ') {
      delay(WORD_GAP); // Gap between words
    } else {
      blinkCharacter(message[i]);
    }
  }
}

// Function to check the password
void checkPassword(int accountIndex, String inputPassword) {
  String correctPassword = passwords[accountIndex];
  
  if (inputPassword.length() != correctPassword.length()) {
    blinkMessage("Incorrect number of characters.");
  } else {
    int wrongCaseCount = 0;
    int wrongCharCount = 0;
    for (int i = 0; i < inputPassword.length(); i++) {
      if (inputPassword[i] != correctPassword[i]) {
        if (tolower(inputPassword[i]) == tolower(correctPassword[i])) {
          wrongCaseCount++;
        } else {
          wrongCharCount++;
        }
      }
    }
    if (wrongCaseCount > 0 && wrongCharCount == 0) {
      blinkMessage("Correct but characters in wrong case.");
    } else if (wrongCaseCount == 0 && wrongCharCount == 0) {
      blinkMessage("Correct password.");
    } else {
      String wrongCountMessage = String(wrongCharCount);
      blinkMessage(wrongCountMessage);
    }
  }
  Serial.println("Re-type the password or listen to it again.");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any leading/trailing whitespace

    if (mode == 0) {
      int selectedMode = input.toInt();
      if (selectedMode == 1 || selectedMode == 2) {
        mode = selectedMode;
        Serial.print("YOU: ");
        Serial.println(accounts[input.toInt()-1]);
        displayAccountMenu();
      } else {
        Serial.print("YOU: ");
        Serial.println(accounts[input.toInt()-1]);
        Serial.println("Invalid selection. Please try again.");
        displayInitialMenu();
      }
    } else if (selectedAccount == -1) {
      int accountNumber = input.toInt();
      if (accountNumber >= 1 && accountNumber <= 10) {
        selectedAccount = accountNumber - 1;
        Serial.println("YOU:");
        Serial.println(accounts[selectedAccount]);
        if (mode == 1) {
          Serial.println("PASSWORD RETRIEVER: ");
          Serial.print("Enter the password for ");
          Serial.println(accounts[selectedAccount]);
        } else if (mode == 2) {
          Serial.println("PASSWORD RETRIEVER: ");
          Serial.print("Blinking half of the password for ");
          Serial.println(accounts[selectedAccount]);
          // blink half the password
          String halfPassword = passwords[selectedAccount].substring(0, passwords[selectedAccount].length() / 2);
          blinkMessage(halfPassword);
          Serial.println("PASSWORD RETRIEVER: ");
          Serial.println("Re-type the password or listen to it again.");
          selectedAccount = -1; // Reset to allow selecting an account again
          displayInitialMenu(); // Display the initial menu again
          mode = 0; // Reset mode for next cycle
        }
      } else {
        Serial.println("PASSWORD RETRIEVER: ");
        Serial.println("Invalid selection. Please try again.");
        displayAccountMenu();
      }
    } else if (mode == 1 && selectedAccount != -1) {
      Serial.println("YOU:");
      Serial.println(input);
      Serial.println("PASSWORD RETRIEVER: ");
      Serial.print("Blinking hint for the password for ");
      Serial.println(accounts[selectedAccount]);
      checkPassword(selectedAccount, input);
      selectedAccount = -1; // Reset to allow selecting an account again
      displayInitialMenu(); // Display the initial menu again
      mode = 0; // Reset mode for next cycle
    }
  }
}
