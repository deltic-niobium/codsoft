#include  <bits/stdc++.h>
using namespace std;
#define MAX_NAME_LEN 60

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

vector<vector<char>> seatMap(NUM_ROWS, vector<char>(NUM_COLS, 'O'));

void displaySeatMap() {
    cout << "  ";
    for (int i = 1; i <= NUM_COLS; ++i)
        cout << setw(3) << i;
    cout << endl;

    for (int row = 0; row < NUM_ROWS; ++row) {
        cout << char('A' + row) << " ";
        for (int col = 0; col < NUM_COLS; ++col) {
            cout << setw(3) << seatMap[row][col];
        }
        cout << endl;
    }
}

bool isSeatAvailable(int row, int col) {
    return seatMap[row][col] == 'O';
}

bool isValidSeat(int row, int col) {
    return row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS;
}

double calculateTotalCost(int numTickets) {
    return numTickets * TICKET_PRICE;
}

void makeBooking(int row, int col, int numTickets) {
    for (int i = 0; i < numTickets; ++i) {
        seatMap[row][col + i] = 'X'; // Mark seats as booked
    }
}

int main() {
    cout << "Welcome to Movie Ticket Booking System!" << endl;
    int ch;
    string moviee;
    char movie_name[MAX_NAME_LEN];
    int row, col, numTickets;
    double totalCost;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. View Movie seat Listings" << endl;
        cout << "2. Make Booking" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1/2/3): ";
        cin>>ch;

        switch (ch) {
            case 1:
                cout << " \n name the movie you want to see: ";
                cin.getline(movie_name,MAX_NAME_LEN,'$');
                 cout<< "\n your searched movie ticket is available at the movie hall:"<<endl;
                break;

            case 2:
                cout << "\nMovie Seat Map:" << endl;
                displaySeatMap();
                 cout << "Enter the number of tickets to book: ";
                cin >> numTickets;

                if (!isSeatAvailable(row, col) || !isSeatAvailable(row, col + numTickets - 1))
                {
                    cout << "Some of the selected seats are not available. Please try again." << endl;
                    continue;
                }

          for (int i=1;i<=numTickets;i++)
          {
                cout << "\nEnter the row (A to E) and column (1 to 10) for the seat  " << i ;
                char rowChar;
                cin >> rowChar >> col;
                

                row = toupper(rowChar) - 'A';
                col--;

                if (!isValidSeat(row, col)) {
                    cout << "Invalid seat selection. Please try again." << endl;
                    continue;
                }
          }

            

                totalCost = calculateTotalCost(numTickets);
                cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;

                cout << "Confirm booking? (Y/N): ";
                char confirm;
                cin >> confirm;

                if (confirm == 'Y' || confirm == 'y') {
                    makeBooking(row, col, numTickets);
                    cout << "Booking successful!" << endl;
                } else {
                    cout << "Booking canceled!" << endl;
                }
                break;

            case 3:
                cout << "Thank you for using the Movie Ticket Booking System!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (ch != 3);

    return 0;
}