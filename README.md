# DA Hacks 2.5 Hackathon 2024 Project

## Inspiration

We all know that many people use the same passwords for everything, including highly sensitive accounts such as their bank, work email, or medical records. After looking further into this topic, I discovered the shocking statistic that two-thirds of Americans use the same password for everything ([Google, Harris Poll](https://storage.googleapis.com/gweb-uniblog-publish-prod/documents/PasswordCheckup-HarrisPoll-InfographicFINAL.pdf) - 2019). This LED to the conclusion that repetitive password usage is also a main contributor to the fact that one in five persons experience identity theft throughout their lifetime ([Bureau of Justice](https://bjs.ojp.gov/press-release/victims-identity-theft-2021#:~:text=As%20of%202021%2C%20about%201,email%20or%20social%20media%20account.) - 2021).

Morse Code has been a popular tool in the arsenal of agencies such as the CIA and FBI for decades due to its complexity and discreteness. This inspired me to develop a password retrieval system utilizing Morse code to allow a user to retrieve their password. Additional functionality also allows a user to create a password for a new account in Morse.

## What it does

Morse Password Retriever allows users to retrieve or rediscover their password via messages in Morse Code. It does this via an Arduino Uno unit connected to a local machine with a USB cable. The Morse Password Retriever sketch (program written in Arduino Language - similar to C++) resides on the local machine and interacts with the Arduino unit to relay messages by blinking them out on the built-in LED light on the Arduino board. Short blinks are dots, and dash blinks are three times as long as dot blinks. Morse Password Retriever also allows the user to create a password for a new account with Morse. The Arduino unit also has a button attached to it via a breadboard for the user to input Morse Code with. Every time the button is pressed, an external LED light blinks for the duration of the button hold.

A combination of two methods are available to the user to retrieve the password, each designed to help the user recall the password in their distant memory without giving out the full password.

The user is first prompted to pick a method with a number “1”, “2”, or "3" (this is for entering a new account's password as opposed to retrieving an already existing password) to signify their choice. The methods are:
1. Type the password.
2. Listen to half the password in Morse Code.
3. To create a password for a new account.

### For method 1:
The user is prompted to type their predicted password. After entering their input, they are either responded to with “Correct password.” in Morse, or they are given one of three hints also in Morse:
- “Incorrect number of characters.”
- “Correct but characters in wrong case.”
- Number of incorrect characters in Morse (1, 2, 3, 4, etc.)

After the Morse response, the user is again prompted to choose the method, allowing a user to use a combination of method 1 and 2 to retrieve the password.

### For method 2:
The user is responded to with half their password in Morse. After the Morse response, the user is again prompted to choose the method, allowing a user to use a combination of method 1 and 2 to retrieve the password.

### For method 3:
The user is prompted to enter in the name of the new account they will create a password for. Through a button connected to the Arduino Uno unit through a breadboard, the user can enter in a new password in Morse Code. Button clicks also enable a new (external) LED light to blink. The Morse Code is then converted and stored as text and the password is displayed in Morse Code and plain text in the Serial Monitor. After this, the user is again prompted to choose the method 1, 2, or 3.

## How I built it

I took a systematic approach in building Morse Password Retriever:
- Discovered how to download the Arduino IDE onto my local machine.
- Discovered how to write Arduino sketches in Arduino Language and how to download sketches onto the board via a USB connection.
- Did research into Morse code and defined DOT_DURATION, DASH_DURATION, GAP_DURATION, LETTER_GAP, and WORD_GAP in milliseconds in our Arduino Language code.
- Wrote LED light blink sequences for each character in Morse Code using my blinkLED function.
- Worked on a user-friendly UI which is accessed through the Serial Monitor of the Arduino IDE to let the user input and receive Morse responses from the Arduino Uno unit.

## Challenges I ran into

By far the hardest challenge was to create the UI which allows the user to select between two different methods because I had to get used to collecting and processing input differently than we normally do in regular C++ code (Arduino Language is almost like C++). Writing and debugging the UI menu available to the user on the Serial Monitor took the bulk of the time.

## Accomplishments that I'm proud of

I am proud of being able to come up with a creative idea that I could follow through on short notice while facing many obstacles in executing other ideas I had before, such as an SQLite3 server on an Arduino. Hackathon contestants were very limited with their resources, being that we did not know what to prepare and that this was my first hardware hackathon and major hardware project.

## What I learned

I learned how Morse Code works and I got to explore the capabilities of small but powerful devices such as Raspberry Pis and Arduinos. I learned a whole new way of writing code in a C++ oriented manner (Arduino Language) to communicate with hardware which I'm sure I will find many other applications for in the future.

## Potential future updates

The next big advancement in my project will be having the Arduino language script communicate with and store data to an SQL Server. Another enhancement will be to add a speaker to the Arduino Uno unit to beep for the duration of a button press or if the on board LED light flashes when responding to user in Morse Code.
