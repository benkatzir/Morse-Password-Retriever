## Inspiration

We all know that many people use the same passwords for everything, including highly sensitive accounts such as their bank, work email, or medical records. After looking further into this topic, we discovered the shocking statistic that two-thirds of Americans use the same password for everything ([Google, Harris Poll](https://storage.googleapis.com/gweb-uniblog-publish-prod/documents/PasswordCheckup-HarrisPoll-InfographicFINAL.pdf) - 2019). This led us to conclude that repetitive password usage is also a main contributor to the fact that one in five persons experience identity theft throughout their lifetime ([Bureau of Justice](https://bjs.ojp.gov/press-release/victims-identity-theft-2021#:~:text=As%20of%202021%2C%20about%201,email%20or%20social%20media%20account.) - 2021).

Morse Code has been a popular tool in the arsenal of agencies such as the CIA and FBI for decades due to its complexity and discreteness. This inspired us to develop a password retrieval system utilizing Morse code to allow a user to retrieve their password.

## What it does

Morse Password Retriever allows users to retrieve or rediscover their password via messages in Morse Code. It does this via an Arduino Uno unit connected to a local machine with a USB cable. The Morse Password Retriever sketch (program written in Arduino Language - similar to C++) resides on the local machine and interacts with the Arduino unit to relay these messages by blinking them out on the built-in LED light on the Arduino board. Short blinks are dots, and dash blinks are three times as long as dot blinks.

A combination of two methods are available to the user to retrieve the password, each designed to help the user recall the password in their distant memory without giving out the full password.

The user is first prompted to pick a method with a number “1” or “2” to signify their choice. The methods are:
1. Type the password
2. Listen to half the password in Morse Code

### For method 1:
The user is prompted to type their predicted password. After entering their input, they are either responded to with “Correct password.” in Morse, or they are given one of three hints also in Morse:
- “Incorrect number of characters.”
- “Correct but characters in wrong case.”
- Number of incorrect characters in Morse (1, 2, 3, 4, etc.)

After the Morse response, the user is again prompted to choose the method, allowing a user to use a combination of method 1 and 2 to retrieve the password.

### For method 2:
The user is responded to with half their password in Morse. After the Morse response, the user is again prompted to choose the method, allowing a user to use a combination of method 1 and 2 to retrieve the password.

## How we built it

We took a systematic approach in building Morse Password Retriever:
- We discovered how to download the Arduino IDE onto one of our local machines.
- We discovered how to write Arduino sketches in Arduino Language and how to download sketches onto the board via a USB connection.
- We did research into Morse code and defined DOT_DURATION, DASH_DURATION, GAP_DURATION, LETTER_GAP, and WORD_GAP in milliseconds.
- We used ChatGPT to write us blink sequences for each character in Morse Code using our blinkLED function.
- We worked on a user-friendly UI which is accessed through the Serial Monitor of the Arduino IDE to let the user input and receive Morse responses from the Arduino Uno unit.

## Challenges we ran into

By far the hardest challenge was to create the UI which allows the user to select between two different methods because we had to get used to collecting and processing input differently than we normally do in regular C++ code (Arduino Language is almost like C++). Writing and debugging the UI menu available to the user on the serial port took the bulk of the time.

## Accomplishments that we're proud of

We are proud of being able to come up with a creative idea that we could follow through on short notice while facing many obstacles in executing other ideas we had before, such as an SQLite3 server on an Arduino. We were very limited with our resources, being that we did not know what to prepare and that this was all of our first hardware hackathon and major hardware project.

## What we learned

We learned how Morse Code works and we got to explore the capabilities of small but powerful devices such as Raspberry Pis and Arduinos. We learned a whole new way of writing code in a C++ oriented manner (Arduino Language) to communicate with hardware which we’re sure will be useful in the future.

## What's next for Morse Password Retriever

The next big advancement in our project will be adding input sensors to the Arduino unit for a user to be able to input a new password into Morse Password Retriever by using Morse Code. This can be a more secure way to create a password when around others, assuming that the majority of people around you will not understand that you are inputting a new password when using an Arduino and Morse Code.
