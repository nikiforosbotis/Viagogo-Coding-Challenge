#include<iostream>
#include<ctime>
#include<cstdlib>
#include<assert.h>

using namespace std;

#include "event.h"

int main() {

  /* The maximum number of events in this world, based on the program's specification (21*21)
   * Number 21 comes from the fact that 0 can also be a valid coordinate ([-10,10]) */
  const int MAXIMUM_EVENTS = 441;

  // The nearest events to be shown
  const int NEAREST_EVENTS = 5;

  int coordX, coordY;

  bool swap_done = true;

  // use current time as seed for random generator
  std::srand(std::time(0));
  /* Generate the number of events for this case as a number ranging from 6 (Minimum)
   * to 441 (Maximum). We assume that there are at least 6 events */
  int number_of_events = (std::rand() % (MAXIMUM_EVENTS - 5)) + 6;

  int ticket_num_for_event[number_of_events];

  // Generates tickets number for event i
  for(int i = 0; i < number_of_events; i++) {
    /* We assume that each event will have between 0 (specification) and 199 tickets. This of course does
     * not apply in the real world but neither does the fact that the data is randomly generated */
    ticket_num_for_event[i] = (std::rand() % 200);
  }

  Event event[number_of_events];
  double price;
  int coordX1 = 0, coordY1 = 0;

  for(int i = 0; i < number_of_events; i++) {
    /* We assume that each ticket is priced individually (rather than a bunch of tickets having
     * the same price). This of course does not apply in the real world but it is considered as
     * a good opportunity to illustrate the usage of the cheapest ticket utility */
    Ticket tickets_for_event[ticket_num_for_event[i]];

    for(int y = 0; y < ticket_num_for_event[i]; y++) {
      /* We assume that each ticket can be priced from 5 (Minimum) to 1005 (Maximum) USD and that prices
       * are integer numbers */
      price = std::rand() % 1000 + 6.0;
      //tickets1[i][y] = Ticket(price);
      tickets_for_event[y] = Ticket(price);
    }

    // According to the specification, the world operates in the interval [-10,10]
    coordX1 = std::rand() % 21 - 10;
    coordY1 = std::rand() % 21 - 10;

    int k = 0;

    // Apply the limitation that each pair of coordinates can hold only one event
    while(k < i) {
      if((coordX1 == event[k].get_coordX()) && (coordY1 == event[k].get_coordY())) {
        // If an event exists with the same coordinates, re-generate them
        coordX1 = std::rand() % 21 - 10;
        coordY1 = std::rand() % 21 - 10;
        k = 0;
      }
      k++;
    }

    event[i] = Event(coordX1, coordY1, tickets_for_event, ticket_num_for_event[i]);
  }

  cout << "Please Input Coordinates: " << endl;
  cout << ">";
  cin >> coordX >> coordY;
  assert(coordX >=-10 && coordX < 10);
  assert(coordY >=-10 && coordY < 10);

   /* Find the 5 nearest events by sorting the Events array.
   Bubble sort has been chosen. Quite inefficient (complexity: O(n^2))
   but it was preferred due to the (small) length of the array */
   while(swap_done) {
     swap_done = false;
     for(int i = 0; i < Event::get_events_count()-1; i++) {
       if(event[i].calculate_distance_from_location(coordX, coordY) > event[i+1].calculate_distance_from_location(coordX, coordY)) {
         Event temp = event[i];
         event[i] = event[i+1];
         event[i+1] = temp;
         swap_done = true;
       }
     }
   }

   cout << "Closest Events to (" << coordX << "," << coordY << "): " << endl;

   for(int i = 0; i < NEAREST_EVENTS; i++) {
     cout << "Event " << event[i].get_ID() << " - $" << event[i].cheapest_ticket_price()
          << ", Distance " << event[i].calculate_distance_from_location(coordX, coordY)
          << endl;
   }

  return 0;
}
