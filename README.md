# ConsoleMonkey
## Instructions to Run ConsoleMonkey:
- Clone this repository and place it in a folder you can access
- Run the following commands in your bash terminal:
- cd (YourFolderNameHere)
- g++ -std=c++11 ConsoleMonkey.cpp -o ConsoleMonkey
- ./ConsoleMonkey
## ConsoleMonkey will start running and ask you some questions:
- "Enter available inputs (separated by spaces): "
- This question is asking about the inputs for the controller or test you would like to run, here's and example: A B X Y Up Left Down Right L2 R2 L1 R1
- "Enter the number of sequences: "
- This question is asking about the number of test sequences you would like generated, any positive integer like 2 is accepted
## Console Monkey will now generate your results:
- Each sequence will be shown in the following format Input1, Input2, Input3... | Pace = xms
- Each input is randomly chosen from the list of provided inputs, and combinations like A+B are possible
- Pace refers to the speed between the inputs in the sequence. A sleep of x milliseconds is preformed between each input
- After each sequence a random sleep is executed, don't be surpised if all sequences aren't generated instantly
## Here is an example output:
- L2, L2+Right, Y | Pace: 18ms
- Up, Left, L2, Y+A | Pace: 25ms
# Enjoy your random testing!
