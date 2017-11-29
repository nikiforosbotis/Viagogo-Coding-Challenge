# Viagogo-Coding-Challenge
Grid Developer Test

## Run program:

In order to compile and run the program, you need to follow one of the two following options:

1. (Windows & Linux) Clone the repository and run the following command, after you have cd to the corresponding directory.

   `g++ -Wall -g event.h ticket.h event.cpp ticket.cpp main.cpp -o grid`


   which actually compiles (using the g++ compiler, needs to be installed in your machine) the listed files and creates an executable called grid(.exe in Windows) which can be used in order to run the application.

2. (Linux, using GNU Make) Clone the repository and run the `make` command, after you have cd to the corresponding directory.

   Then, type `./grid` on the command line and the program will run.

>When entering the input parameters (coordinate X and coordinate Y) they should be given when the program asks for them by separating them with a whitespace).

## Assumptions

Most of the assumptions that have been made are explicitly stated in the comments above the corresponding code snippet in **main.cpp.**. Please refer to this file for the assumptions that have been made.

Apart from that, it is highlighted that:

* Even though there is no implemented functionality for the actual purchase of ticket (out of scope of this challenge), there is an 'is_purchased' data member at the Ticket objects in order to indicate whether they are sold or not. If the cheapest ones are sold (cannot happen in this case), they are not shown to the user as the cheapest available ticket but instead, the next cheapest (but still more expensive that the initial cheapest) ticket is presented.

## Answers to the Questions

**Q: How might you change your program if you needed to support multiple events at the same location?**


**A**: In such a case, first of all I would use a "Location" class which would include a data structure in each combination of coordinates (each instance of this class) for holding events. This is to avoid corresponding each pair (X,Y) to only one event. This also implies removal of the logic that is implemented right now in main method, which checks if an event already exists in the given coordinates. I would use a flexible data structure (e.g. Linked List) in order to be able to easily add/delete/search for a certain event in a specific location (pair of X,Y). Thus, the only thing one would have to do it to associate the newly created event with the (maybe already existing) object of the specific location and add the event to its data structure.

**Q: How would you change your program if you were working with a much larger world size?**


**A**: Working with a much larger world size would mean that the current implementation is quite inefficient in terms of the time required to do the necessary calculations and the memory space that is needed in order to store the data. Assuming that the data in this case would be stored in a database system, I would improve the current implementation, setting my main goal the efficiency in terms of time complexity. I would not want my user to be waiting in front of a screen loading the results for a long amount of time. I would also try to do some grouping to my data based on some high-level locations, let's say areas or cities. So, for example, when a user from a location which corresponds to a specific city asks for the nearest events, I would automatically scan the events of this area (and then gradually "zoom out", if this is not enough) rather than starting with the whole world and querying this table as a whole.

## Expected Output

**(Note that this output cannot be emulated with exact numbers since all of the input is randomly produced each time the program runs.)**

`Please Input Coordinates:
> 3 6
Closest Events to (3,6):
Event 96 - $361, Distance 0
Event 60 - $12, Distance 1
Event 17 - $12, Distance 1.41421
Event 58 - $13, Distance 2.23607
Event 74 - $8, Distance 2.34541`
