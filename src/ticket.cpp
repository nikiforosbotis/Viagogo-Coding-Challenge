#include<cstring>
#include "ticket.h"

int Ticket::num_of_tickets = 0;

Ticket::Ticket() {};

Ticket::Ticket(double price) {
  this->id = ++num_of_tickets;
  this->price = price;
  is_purchased = false;
}

double Ticket::get_price() {
  return this->price;
}

void Ticket::buy_ticket() {
  this->is_purchased = true;
}

bool Ticket::already_sold() {
  return this->is_purchased;
}
