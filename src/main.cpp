#include<iostream>
#include<assert.h>

using namespace std;

#include "event.h"

int main() {

  // The nearest events to be shown. Avoid magic numbers
  const int NEAREST_EVENTS = 5;

  int coordX, coordY;

  bool swap_done = true;

  Ticket ticket1(50.95);
  Ticket ticket2(40.42);
  Ticket ticket3(100.50);
  Ticket ticket4(20.50);
  Ticket ticket5(210.50);

  int length = 5;
  Ticket tickets[5] = {ticket1,ticket2, ticket3, ticket4, ticket5};

  //SHOULD BE RANDOMLY CREATED
  Event event1("Tottenham-RM", 5, 9, tickets, length);
  Event event2("Peter Cay", 0, 6, tickets, length);
  Event event3("Strictly Come Dancing", 2, 1, tickets, length);
  Event event4("RBS Six Nations", 8, 0, tickets, length);
  Event event5("X Factor Live", 1, 9, tickets, length);
  Event event6("Tears for fears", 5, 5, tickets, length);

  Event event[] = {event1, event2, event3, event4, event5, event6};

  cout << "Please Input Coordinates: " << endl;
  cout << ">";
  cin >> coordX >> coordY;
  assert(coordX >=0 && coordX < 10);
  assert(coordX >=0 && coordX < 10);

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
          << " Distance " << event[i].calculate_distance_from_location(coordX, coordY)
          << "  ";
   }

  return 0;
}
