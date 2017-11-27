#include<assert.h>
#include<cmath>
#include "event.h"

using namespace std;

int Event::num_of_events = 0;

Event::Event(string name, int coordX, int coordY, Ticket event_tickets[], int ticket_num) {
  this->id = ++num_of_events;
  this->name = name;
  this->coordX = coordX;
  this->coordY = coordY;
  this->available_tickets = ticket_num;

  assert(ticket_num <= MAX_TICKETS);

  for(int i = 0; i < ticket_num; i++) {
    tickets[i] = event_tickets[i];
  }
}

double Event::calculate_distance_from_location(int X, int Y) {
  return sqrt(pow(X-coordX, 2) + pow(Y-coordY, 2));
}

int Event::cheapest_ticket_price() {
  int i = 1;
  int ticket_with_minimum_price = 0;

  while(i < available_tickets) {
    if((tickets[i].already_sold() == false) && (tickets[i].get_price() < tickets[ticket_with_minimum_price].get_price())) {
      ticket_with_minimum_price = i;
    }
    i++;
  }
  return tickets[ticket_with_minimum_price].get_price();
}

int Event::get_ID() {
  return this->id;
}

int Event::get_events_count() {
  //Because it starts from 0
  return num_of_events;
}
