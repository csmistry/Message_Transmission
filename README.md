# Message Transmission
This program allows you to transmit fragments of a message and print them in their corresponding positions, regardless of whether the full message has been transmitted or not. 

"..." represents missing fragments in the message
"???" indicates that the message length has not been defined

Console Interaction Syntax:

- To transmit a fragment, enter the index of the fragment followed by the fragment string.
- To print the current status of the received fragments, enter -1
- To transmit the length of the message or the "End of Transmission", enter index of last fragment in the message plus 1 and the string "EOT"
- To exit the program, enter -2

Example Tranmission:

- Transmit the message "Hello, this is Bob!"

Input:            
2 is
-1
0 Hello,
4 EOT
-1
3 Bob!
-1
1 this 
-1
-2

Output:
... ... is ???
Hello, ... is ???
Hello, ... is ...
Hello, ... is Bob!
Hello, this is Bob!


