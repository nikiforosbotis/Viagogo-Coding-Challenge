class Ticket {
private:
  int id;
  double price;
  bool is_purchased;
  static int num_of_tickets;
public:
  // Default constructor
  Ticket();
  // Constructor initializing ticket's price
  Ticket(double price);
  // Returns ticket's price
  double get_price();
  /* Method that turns the state of the ticket (is purchased)
   * to true when the ticket is sold */
  void buy_ticket();
  // Returns the ticket state
  bool already_sold();
};
