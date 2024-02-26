In computer science and telecommunication, Hamming codes are a family of linear error-correcting codes. Hamming codes can detect one-bit errors and correct errors. Richard Hamming mathematician is the inventor of Hamming code.

Steps for Hamming Code Generation-
First I take input from text documents and it is character type. Then I convert character to binary bit.
2. I determine input size and how many parity bit I need. Then, I take an extra copy array to copy input value also I store -1 in parity position.
3. Then I determine parity bit value using their condition. I use another array to store this parity bits and input values.
4. Finally I print these array, because when I get parity bits value that means I get final hamming code.

Steps for Error Detection-
1. First I take input from text documents that store previous hamming code output and it is binary type.
2. Then I determine how many 1 store in parity bit. If it is even then I store 0 in parity position and if it is odd value then I store 1 in parity position.
3. If my parity position value is 0 I print the input has no error.
4. If my parity position value isn’t 0 I reverse their position and convert binary to decimal and print this input error position.
5. If position value is 0 I store 1 in that position and if it is 1 I store 0 in that position.
6. I use another array to copy correct bits but this time I avoid parity bits. Then I convert binary to character part by part.
7. Finally I print the characters and that output has no error. Because I remove the error in previous conditions.
