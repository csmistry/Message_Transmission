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
2 is <br>
-1 <br>
0 Hello, <br>
4 EOT <br>
-1 <br>
3 Bob! <br>
-1 <br>
1 this <br>
-1 <br>
-2 <br>
 
Output: <br>
... ... is ??? <br>
Hello, ... is ??? <br>
Hello, ... is ... <br>
Hello, ... is Bob! <br>
Hello, this is Bob!<br>


