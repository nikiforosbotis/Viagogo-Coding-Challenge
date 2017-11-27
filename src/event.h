#include<string>

using namespace std;

#include "ticket.h"

// We make the assumption that each event can have up to 1.000 tickets.
const int MAX_TICKETS = 1000;

class Event {
private:
  int id;
  string name;
  // Each event has its own unique coordinates according to specification
  int coordX;
  int coordY;
  int available_tickets;
  static int num_of_events;
  /* array of Ticket objects since they have a composition relationship with Event
   * class in terms of UML depiction */
  Ticket tickets[MAX_TICKETS];
public:
  /* Constructor of the Event class taking as parameters the name of the event, its
   * coordinates, the table of Ticket objects which correspond to this and the total
   * number of tickets that are initially issued */
  Event(string name, int coordX, int coordY, Ticket event_tickets[], int ticket_num);
  // Returns the Manhattan distance from the given coordinates (arguments)
  double calculate_distance_from_location(int X, int Y);
  // Returns the cheapest price from the tickets that have not been sold yet
  int cheapest_ticket_price();
  // Returns event's ID
  int get_ID();
  // Returns the total number of event objects that have been created
  static int get_events_count();

};
