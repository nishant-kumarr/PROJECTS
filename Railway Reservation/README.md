# IRCTC Reservation System

## Overview
This code is a project focusing on an IRCTC reservation system. The primary goal is to assist passengers or organizations with reservation data stored in "myfile.txt" acting as a database. The code utilizes a user-defined data type, structure, to manage various details of a passenger. The database `myfile.txt` is currently holding information for 50 passengers across 13 coaches. And it can be further expanded with no issue.

## Functionalities
The code offers five main functionalities:

1. **PNR Search:** Search for a passenger by their PNR number.
2. **List of Passengers within a Coach with Different Berths:** Display passengers in a specific coach with details of different berths (lower, middle, and upper).
3. **List of Senior Passengers:** Display a list of passengers aged 60 and above.
4. **List of All Passengers in a Coach:** Display all passengers in a specific coach.
5. **Passengers under Waiting List:** Display passengers in the waiting list, indicating the highest probable coach they may get.

## Code Explanation
The code utilizes a file named "myfile.txt" as a database, storing passenger information. The main functions include searching for passengers, listing passengers based on different criteria, and identifying senior citizens. The program operates through a simple menu system, allowing users to choose their desired functionality.

## Working
1. The code reads passenger data from "myfile.txt" into an array of structures.
2. Users interact with the program through a menu, selecting various functionalities.
3. The program performs the requested operation, displaying relevant passenger information.
4. The menu loop continues until the user chooses to exit.

## How to Use
1. Ensure "myfile.txt" is properly maintained with data in the specified order - mentioned in 'Note' section.
2. Compile and run the code.
3. Choose the desired functionality by entering the corresponding number.
4. Follow on-screen prompts to input additional details if required.
5. Review the displayed information.

## Note
Ensure that the "myfile.txt" file is correctly formatted with data in the order `<Pnr> <Name> <Age> <Coach> <Berth> <BoardingPoint> <Destination>`. For passengers under the waiting list, the berth is set to zero.

## Further Expansion
The code can be expanded by incorporating additional features such as ticket booking, cancellation, or dynamic data handling. Additionally, improvements to user interface and error handling can enhance the overall user experience.

<div>
  <br> 
  <br>
  <h2 align = 'right'> Thank You !! </h2>
</div>
