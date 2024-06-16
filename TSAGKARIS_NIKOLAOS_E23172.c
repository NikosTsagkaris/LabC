     // Include the standard input/output and string libraries
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    // Declare a global variable to store the current user's name
    char currentUser[20];

    // Define a structure to store user information
    typedef struct {
        int id; // User ID
        char name[20]; // User first name
        char surname[20]; // User last name
        int age; // User age
        char card_number[17]; // User card number (increased size for null character)
        int university_student; // User status (1 if university student, 0 otherwise)
        char username[20]; // User username
        char password[8]; // User password (increased size for null character)
    } User;

    // Define a structure to store route information
    typedef struct {
        char port[20]; // Port name
        char portCode[4]; // Port code
        float deckPrice, airPrice, cabinPrice, carCost; // Prices for different options
    } Route;

    typedef struct {
        unsigned int dd;
        unsigned int mm;
        unsigned int yyyy;
    } Date;

    // Define a structure to store booked trip information
    typedef struct {
        char BTusername[20];
        char UniqueID[30];
        float BTfinalCost;
        int BTDateByUser;
        int BTDate2ByUser;
        int trip_type;
        char status[20];
    } Booked_Trip;

    // Declare an array of booked_trips with size 30
    Booked_Trip booked_trips[30];
    // Declare an array of users with size 30
    User users[30];
    // Declare an array of routes with size 13
    Route routes[13];
    // Declare an array of dates with size 50
    Date dates[50];

    // Declare the function prototypes
    void HomePage(int option, User users[], int *userCount);
    void SignUp(User users[], int *userCount);
    void Login(User users[], int userCount);
    void ViewAvailableRoutes();
    void Dashboard(char currentUser[20]);
    void Book_Trip(char currentUser[20]);
    int compareDates(Date date1, Date date2);
    void MakePayment(char currentUser[20]);
    void ConfirmedTrips(char currentUser[20]);

    // Define the main function
    int main() {
        int option; // Declare a variable to store the user's option

        
        // Initialize the routes for route struct
        // KOS
        strcpy(routes[0].port, "Kos"); // Set the port name
        strcpy(routes[0].portCode, "KOS"); // Set the port code
        routes[0].deckPrice = 60; // Set the deck price
        routes[0].airPrice = 80; // Set the air price
        routes[0].cabinPrice = 120; // Set the cabin price
        routes[0].carCost = 100; // Set the car cost

        // RODOS
        strcpy(routes[1].port, "Rodos"); // Set the port name
        strcpy(routes[1].portCode, "RHO"); // Set the port code
        routes[1].deckPrice = 80; // Set the deck price
        routes[1].airPrice = 100; // Set the air price
        routes[1].cabinPrice = 140; // Set the cabin price
        routes[1].carCost = 100; // Set the car cost

        // KALIMNOS
        strcpy(routes[2].port, "Kalimnos"); // Set the port name
        strcpy(routes[2].portCode, "KAL"); // Set the port code
        routes[2].deckPrice = 60; // Set the deck price
        routes[2].airPrice = 80; // Set the air price
        routes[2].cabinPrice = 120; // Set the cabin price
        routes[2].carCost = 100; // Set the car cost
        
        // PATMOS
        strcpy(routes[3].port, "Patmos"); // Set the port name
        strcpy(routes[3].portCode, "PAT"); // Set the port code
        routes[3].deckPrice = 55; // Set the deck price
        routes[3].airPrice = 75; // Set the air price
        routes[3].cabinPrice = 115; // Set the cabin price
        routes[3].carCost = 100; // Set the car cost

        // ASTYPALAIA
        strcpy(routes[4].port, "Astypalaia"); // Set the port name
        strcpy(routes[4].portCode, "AST"); // Set the port code
        routes[4].deckPrice = 50; // Set the deck price
        routes[4].airPrice = 70; // Set the air price
        routes[4].cabinPrice = 110; // Set the cabin price
        routes[4].carCost = 100; // Set the car cost

        // KASOS
        strcpy(routes[5].port, "Kasos"); // Set the port name
        strcpy(routes[5].portCode, "KAS"); // Set the port code
        routes[5].deckPrice = 65; // Set the deck price
        routes[5].airPrice = 85; // Set the air price
        routes[5].cabinPrice = 125; // Set the cabin price
        routes[5].carCost = 100; // Set the car cost

        // KASTELORIZO
        strcpy(routes[6].port, "Kastelorizo"); // Set the port name
        strcpy(routes[6].portCode, "KST"); // Set the port code
        routes[6].deckPrice = 100; // Set the deck price
        routes[6].airPrice = 120; // Set the air price
        routes[6].cabinPrice = 160; // Set the cabin price
        routes[6].carCost = 120; // Set the car cost

        // LEROS
        strcpy(routes[7].port, "Leros"); // Set the port name
        strcpy(routes[7].portCode, "LER"); // Set the port code
        routes[7].deckPrice = 60; // Set the deck price
        routes[7].airPrice = 80; // Set the air price
        routes[7].cabinPrice = 120; // Set the cabin price
        routes[7].carCost = 100; // Set the car cost

        // KARPATHOS
        strcpy(routes[8].port, "Karpathos"); // Set the port name
        strcpy(routes[8].portCode, "KAR"); // Set the port code
        routes[8].deckPrice = 70; // Set the deck price
        routes[8].airPrice = 90; // Set the air price
        routes[8].cabinPrice = 130; // Set the cabin price
        routes[8].carCost = 100; // Set the car cost

        // SYMI
        strcpy(routes[9].port, "Symi"); // Set the port name
        strcpy(routes[9].portCode, "SYM"); // Set the port code
        routes[9].deckPrice = 80; // Set the deck price
        routes[9].airPrice = 100; // Set the air price
        routes[9].cabinPrice = 140; // Set the cabin price
        routes[9].carCost = 120; // Set the car cost

        // XALKI
        strcpy(routes[10].port, "Xalki"); // Set the port name
        strcpy(routes[10].portCode, "XAL"); // Set the port code
        routes[10].deckPrice = 70; // Set the deck price
        routes[10].airPrice = 90; // Set the air price
        routes[10].cabinPrice = 130; // Set the cabin price
        routes[10].carCost = 100; // Set the car cost

        // TILOS
        strcpy(routes[11].port, "Tilos"); // Set the port name
        strcpy(routes[11].portCode, "TIL"); // Set the port code
        routes[11].deckPrice = 75; // Set the deck price
        routes[11].airPrice = 95; // Set the air price
        routes[11].cabinPrice = 135; // Set the cabin price
        routes[11].carCost = 100; // Set the car cost

        // PSERIMOS
        strcpy(routes[12].port, "Pserimos"); // Set the port name
        strcpy(routes[12].portCode, "PSE"); // Set the port code
        routes[12].deckPrice = 60; // Set the deck price
        routes[12].airPrice = 80; // Set the air price
        routes[12].cabinPrice = 120; // Set the cabin price
        routes[12].carCost = 100; // Set the car cost
        
    int userCount = 0; // Declare and initialize a variable to store the number of users
        do {
            system("cls");
            printf("Welcome to DS Ferries, please select an option\n0)Exit\n1)Sign Up\n2)Login\n"); // Display the menu options
            scanf("%d", &option); // Read the user's input
            HomePage(option, users, &userCount); // Call the HomePage function with the user's option and the user array
        } while (option != 0); // Repeat until the user chooses to exit

        return 0;
        
    }

    // Define the HomePage function that takes the user's option and the user array as parameters
    void HomePage(int option, User users[], int *userCount) {
        // Use a switch statement to handle different options
        switch (option) {
            case 0: // If the option is 0, print goodbye and exit
                printf("Goodbye!\n");
                break;
            case 1: // If the option is 1, call the SignUp function
                SignUp(users, userCount);
                break;
            case 2: // If the option is 2, call the Login function
                Login(users, *userCount);
                break;
            default: // If the option is invalid, print an error message
                printf("Please select a valid Option\n");
                system("pause");
                break;
        }
    }

    // Define the SignUp function that takes the user array and the user count as parameters
    void SignUp(User users[], int *userCount) {
        // Check if the user limit is reached
        if (*userCount >= 30) {
            printf("User limit reached\n");
            return; // Return from the function
        }

        system("cls");
        printf("  SIGN UP\n\n");

        // Declare a new user variable
        User newUser;
        // Prompt the user to enter their name
        printf("Name: ");
        scanf("%s", newUser.name);
        // Prompt the user to enter their surname
        printf("Surname: ");
        scanf("%s", newUser.surname);
        // Prompt the user to enter their age
        printf("Age: ");
        // Use a do-while loop to validate the input
        do{
        scanf("%d", &newUser.age); 
        // Check if the age is less than 18
        if(newUser.age <18){
                // Print an error message and ask for a different age
                printf("You must be 18 and over to continue. Try a different age!\nAge: ");
        }
        }while( newUser.age <18 ); // Repeat until the age is valid
        
        // Prompt the user to enter their card number
        printf("Card Number: ");
        // Use a do-while loop to validate the input
        do{
        scanf("%s", newUser.card_number);
        // Check if the card number is not 16 digits long
        if(strlen(newUser.card_number) != 16){
                // Print an error message and ask for a different card number
                printf("Card Number must be a sequence of 16 digits to continue. Try a different Card Number!\nCard Number: ");
        }
        }while( strlen(newUser.card_number) != 16 ); // Repeat until the card number is valid
        
        // Prompt the user to enter their university student status
        printf("University Student? Type 0 for NO or 1 for YES.\nAnswer: ");
        // Use a do-while loop to validate the input
        do{
        scanf("%d", &newUser.university_student);
        // Check if the answer is not 0 or 1
        if( newUser.university_student != 0 && newUser.university_student != 1 ){
                // Print an error message and ask for a different answer
                printf("The answer must be 0 or 1 to continue. Try a different answer!\nAnswer: ");
        }
        }while( newUser.university_student != 0 && newUser.university_student != 1 ); // Repeat until the answer is valid
        
        // Prompt the user to enter their username
        printf("Username: ");
        scanf("%s", newUser.username);

        // Prompt the user to enter their password
        printf("Password: ");
        // Use a do-while loop to validate the input
        do{
        scanf("%s", newUser.password);
        // Check if the password is longer than 7 characters
        if(strlen( newUser.password) > 7 ){
                // Print an error message and ask for a different password
                printf("Password must be a sequence of max 7 characters to continue. Try a different Username!\nPassword: ");
        }
        }while( strlen( newUser.password) > 7 ); // Repeat until the password is valid

        // Assign the user ID as the current user count plus one
        newUser.id = *userCount + 1;
        // Add the new user to the user array
        users[*userCount] = newUser;
        // Increment the user count
        (*userCount)++;

        // Print a success message and ask the user to login
        printf("Successfully Registered, please Login\n");
        system("pause"); // Pause the program until the user presses a key

    }

void Login(User users[], int userCount) {
    char username[20], password[8];
    int loginSuccessful = 0; // Flag to indicate successful login

    system("cls");
    printf("  SIGN IN\n\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("\nLogin Successful\n");
            strcpy(currentUser, users[i].username); // Now we know which user is signed in, that we'll use it for a booked trip
            loginSuccessful = 1; // Set flag to indicate successful login
            system("pause");
            Dashboard(currentUser);
            break; // Exit the loop once login is successful
        }
    }

    // Check if login was unsuccessful (no user found with matching credentials)
    if (!loginSuccessful) {
        printf("Invalid username or password.\n");
        system("pause");
    }
}

    void Dashboard(char currentUser[20]) {
        char option;
        system("cls");
        do {
            printf("  DASHBOARD\n\nWelcome %s \na)View Available Routes\nb)Book Trip\nc)Payment\nd)Confirmed Trips\ne)Logout\n", currentUser);
            scanf(" %c", &option);
            switch (option) {
                case 'a':
                    ViewAvailableRoutes();
                    system("pause");
                    break;
                case 'b':
                    Book_Trip(currentUser);
                    break;
                case 'c':
                    MakePayment(currentUser);
                    break;
                case 'd':
                    ConfirmedTrips(currentUser);
                    break;
                case 'e':
                    break;
                default:
                    printf("Please select a valid Option\n");
                    break;
            }
        } while (option != 'e');
    }

    void ViewAvailableRoutes() {
        printf("Available Routes:\n");

        for (int i = 0; i < 13; i++) {
            printf("Route: %s (%s)\n", routes[i].port, routes[i].portCode);
            printf("Deck Price: %.2f\n", routes[i].deckPrice);
            printf("Aviation Price: %.2f\n", routes[i].airPrice);
            printf("Cabin Price: %.2f\n", routes[i].cabinPrice);
            printf("Car Cost: %.2f\n\n", routes[i].carCost);
        }
    }

 void Book_Trip(char currentUser[20]) {
        char portCodeByUser[20];
        char typeOfSeatByUser[20];
        int hasCar;
        int isStudent;
        int forReturn;
        int seatCost;
        int carsCost;
        int finalCost;
        Date lastTripDate;
        Date returnDate;
        system("cls");
        printf("   BOOK A TRIP\n\n");


        // Initialize lastTripDate with a default date
        lastTripDate.dd = 1;
        lastTripDate.mm = 1;
        lastTripDate.yyyy = 2000;
        
        int tripsCount = 0;  // Initialize the trips count

        for (int i = 0; i < 30; i++) {
        if (strcmp(booked_trips[i].BTusername, currentUser) == 0) {
            tripsCount++;
            if (tripsCount >= 50) {
                printf("You have reached the maximum number of trips (50).\n");
                system("pause");
                return;  // Return without proceeding with the booking
            }
            
        }
        }
        // Prompt the user to enter a date for the trip
    printf("Please select a date for the trip (DD MM YYYY): ");
    // Use a do-while loop to validate the input
    do {
        scanf("%d %d %d", &dates[0].dd, &dates[0].mm, &dates[0].yyyy);
        // Check if the entered date is valid
        if (compareDates(dates[0], lastTripDate) == 0) {
            printf("Invalid date. Please enter a valid date (DD MM YYYY): ");
        }
    } while (compareDates(dates[0], lastTripDate) == 0); // Repeat until a valid date is entered
        // Prompt the user to enter the Port Code
        printf("Please select the Port Code (from Dashboard): ");
        // Use a do-while loop to validate the input
        do {
            scanf("%s", portCodeByUser);
            // Check if the answer is a code from Dashboard
            if (strcmp(portCodeByUser, "KOS") != 0 && strcmp(portCodeByUser, "RHO") != 0 && strcmp(portCodeByUser, "KAL") != 0 && strcmp(portCodeByUser, "PAT") != 0 && strcmp(portCodeByUser, "AST") != 0 && strcmp(portCodeByUser, "KAS") != 0 && strcmp(portCodeByUser, "KST") != 0 && strcmp(portCodeByUser, "LER") != 0 && strcmp(portCodeByUser, "KAR") != 0 && strcmp(portCodeByUser, "SYM") != 0 && strcmp(portCodeByUser, "XAL") != 0 && strcmp(portCodeByUser, "TIL") != 0 && strcmp(portCodeByUser, "PSE") != 0) {
                // Print an error message and ask for a different answer
                printf("The answer must be a Port Code from Dashboard to continue. Try a different answer!\nAnswer: ");
            }
        } while (strcmp(portCodeByUser, "KOS") != 0 && strcmp(portCodeByUser, "RHO") != 0 && strcmp(portCodeByUser, "KAL") != 0 && strcmp(portCodeByUser, "PAT") != 0 && strcmp(portCodeByUser, "AST") != 0 && strcmp(portCodeByUser, "KAS") != 0 && strcmp(portCodeByUser, "KST") != 0 && strcmp(portCodeByUser, "LER") != 0 && strcmp(portCodeByUser, "KAR") != 0 && strcmp(portCodeByUser, "SYM") != 0 && strcmp(portCodeByUser, "XAL") != 0 && strcmp(portCodeByUser, "TIL") != 0 && strcmp(portCodeByUser, "PSE") != 0); // Repeat until the answer is valid

        // Prompt the user to enter a type of seat
        printf("Please select the type of seat. TYPE:\n DECK - for a deck seat\n AVIATION - for an aviation type seat\n CABIN - for a cabin seat\n\n Answer: ");
        // Use a do-while loop to validate the input
        do {
            scanf("%s", typeOfSeatByUser);
            // Check if the answer is an option from Dashboard
            if (strcmp(typeOfSeatByUser, "DECK") != 0 && strcmp(typeOfSeatByUser, "AVIATION") != 0 && strcmp(typeOfSeatByUser, "CABIN") != 0) {
                // Print an error message and ask for a different answer
                printf("The answer must be an option from Dashboard to continue. Try a different answer!\nAnswer: ");
            }
        } while (strcmp(typeOfSeatByUser, "DECK") != 0 && strcmp(typeOfSeatByUser, "AVIATION") != 0 && strcmp(typeOfSeatByUser, "CABIN") != 0); // Repeat until the answer is valid

        // Prompt the user to enter if they want to bring a car
        printf("Please select if you want to bring a car. Type 0 for NO or 1 for YES.\nAnswer: ");
        // Use a do-while loop to validate the input
        do {
            scanf("%d", &hasCar);
            // Check if the answer is not 0 or 1
            if (hasCar != 0 && hasCar != 1) {
                // Print an error message and ask for a different answer
                printf("The answer must be 0 or 1 to continue. Try a different answer!\nAnswer: ");
            }
        } while (hasCar != 0 && hasCar != 1); // Repeat until the answer is valid

        // Prompt the user to enter if it is One-Way trip
        printf("Please select if it is One-Way trip. Type 0 for NO or 1 for YES.\nAnswer: ");
        // Use a do-while loop to validate the input
        do {
            scanf("%d", &forReturn);
            // Check if the answer is not 0 or 1
            if (forReturn != 0 && forReturn != 1) {
                // Print an error message and ask for a different answer
                printf("The answer must be 0 or 1 to continue. Try a different answer!\nAnswer: ");
            }
        } while (forReturn != 0 && forReturn != 1); // Repeat until the answer is valid

    if (forReturn == 0) {
        // Prompt the user to enter a date for the return trip
        printf("Please select a date for the return trip (DD MM YYYY): ");
        // Use a do-while loop to validate the input
        do {
            scanf("%d %d %d", &returnDate.dd, &returnDate.mm, &returnDate.yyyy);
            // Check if the return date is valid
            if (compareDates(dates[0], returnDate) >= 0) {
                printf("Invalid return date. Please enter a valid date after the departure date (DD MM YYYY): ");
            }
        } while (compareDates(dates[0], returnDate) >= 0); // Repeat until a valid return date is entered
    }
    



        for (int i = 0; i < 30; i++) {
        if (strcmp(users[i].username, currentUser) == 0) {
            isStudent = users[i].university_student;
            break;
        }
    }

    // Find the cost
        seatCost = 0; // Initialize seatCost
        carsCost = 0; // Initialize carsCost
        finalCost = 0; // Initialize finalCost

        for (int i = 0; i < 13; i++) { // Iterate through routes
            if (strcmp(routes[i].portCode, portCodeByUser) == 0) {
                // Check type of seat and calculate seatCost
                if (strcmp(typeOfSeatByUser, "DECK") == 0) {
                    seatCost = routes[i].deckPrice;
                } else if (strcmp(typeOfSeatByUser, "AVIATION") == 0) {
                    seatCost = routes[i].airPrice;
                } else if (strcmp(typeOfSeatByUser, "CABIN") == 0) {
                    seatCost = routes[i].cabinPrice;
                }
                carsCost = routes[i].carCost;
                break;
            }
        }

        if (hasCar == 1) {
            finalCost = seatCost + carsCost;
        } else {
            finalCost = seatCost;
        }

        if (forReturn == 1) {
            finalCost = finalCost + finalCost *0.75;
        }

        if (isStudent == 1) {
            finalCost = finalCost / 2;
        }

        booked_trips[tripsCount].BTfinalCost = finalCost;
        printf("\n You have now booked a trip! Your booking is on 'Pending' at the moment, proceed to the Payment to complete it!\n");
        system("pause");

        // Set the booked_trip information
        strcpy(booked_trips[tripsCount].BTusername, currentUser);
        booked_trips[tripsCount].BTDateByUser = dates[0].dd * 1000000 + dates[0].mm * 10000 + dates[0].yyyy;

        char dateStr[9];
        sprintf(dateStr, "%d", booked_trips[tripsCount].BTDateByUser);
        
        strcpy(booked_trips[tripsCount].status, "Pending");
        strcpy(booked_trips[tripsCount].UniqueID, dateStr);
        strcat(booked_trips[tripsCount].UniqueID, portCodeByUser);
        strcat(booked_trips[tripsCount].UniqueID, "-");
        strcat(booked_trips[tripsCount].UniqueID, currentUser);
        system("cls");
    }




    int compareDates(Date date1, Date date2) {
        // Assuming date1 > date2 returns 1, date1 == date2 returns 0, and date1 < date2 returns -1
        if (date1.yyyy > date2.yyyy) return 1;
        else if (date1.yyyy < date2.yyyy) return -1;

        if (date1.mm > date2.mm) return 1;
        else if (date1.mm < date2.mm) return -1;

        if (date1.dd > date2.dd) return 1;
        else if (date1.dd < date2.dd) return -1;

        return 0; // Dates are equal
    }

    // Define the MakePayment function
    void MakePayment(char currentUser[20]) {
        system("cls");
        printf("  PAYMENT\n\n");

        // Display bookings for the current user that are not paid
        printf("Unpaid Bookings for %s:\n", currentUser);

        for (int i = 0; i < 30; i++) {
            if (strcmp(booked_trips[i].BTusername, currentUser) == 0 && strcmp(booked_trips[i].status, "Pending") == 0) {
                printf("Booking ID: %s\n", booked_trips[i].UniqueID);
                printf("Status: %s\n", booked_trips[i].status);
                printf("Final Cost: %.2f\n\n", booked_trips[i].BTfinalCost);
            }
        }

        char bookingID[30];
        int paymentSuccessful = 0;

        // Prompt the user to enter the UniqueID of the booking to be paid
        printf("Enter the UniqueID of the booking you want to pay: ");
        scanf("%s", bookingID);

        // Check if the booking exists and is not paid
        for (int i = 0; i < 30; i++) {
            if (strcmp(booked_trips[i].UniqueID, bookingID) == 0 && strcmp(booked_trips[i].status, "Pending") == 0) {
                paymentSuccessful = 1;
                // Mark the booking as paid
                strcpy(booked_trips[i].status, "Paid");
                printf("Payment successful! Booking %s is now paid.\n", bookingID);
                break;
            }
        }

        // Display an error message if payment is not successful
        if (!paymentSuccessful) {
            printf("Payment failed. Please check the UniqueID and try again.\n");
        }

        system("pause");
    }

    // Define the ConfirmedTrips function (FYSALIDA 3H LYKEIOY)
    void ConfirmedTrips(char currentUser[20]) {
    system("cls");
    printf("  CONFIRMED TRIPS\n\n");

    int confirmedTripsCount = 0;

    // Count the number of confirmed trips for the current user
    for (int i = 0; i < 30; i++) {
        if (strcmp(booked_trips[i].BTusername, currentUser) == 0 && strcmp(booked_trips[i].status, "Paid") == 0) {
            confirmedTripsCount++;
        }
    }

    // Check if the user has at least one paid booking
    if (confirmedTripsCount == 0) {
        printf("You have no confirmed trips yet.\n");
        system("pause");
        return;
    }

    char sortOrder[5];

    // Prompt the user to enter the sorting order (LOW or HIGH)
    printf("Enter sorting order (LOW for ascending, HIGH for descending): ");
    scanf("%s", sortOrder);

    // Sort the confirmed trips based on the final cost
    Booked_Trip temp;
    for (int i = 0; i < 30 - 1; i++) {
        for (int j = 0; j < 30 - i - 1; j++) {
            if (strcmp(booked_trips[j].BTusername, currentUser) == 0 &&
                strcmp(booked_trips[j].status, "Paid") == 0 &&
                ((strcmp(sortOrder, "LOW") == 0 && booked_trips[j].BTfinalCost > booked_trips[j + 1].BTfinalCost) ||
                 (strcmp(sortOrder, "HIGH") == 0 && booked_trips[j].BTfinalCost < booked_trips[j + 1].BTfinalCost))) {
                // Swap the positions of the two bookings
                temp = booked_trips[j];
                booked_trips[j] = booked_trips[j + 1];
                booked_trips[j + 1] = temp;
            }
        }
    }

    // Display the sorted confirmed trips
    printf("Confirmed Trips for %s\n\n", currentUser);

    for (int i = 0; i < 30; i++) {
        if (strcmp(booked_trips[i].BTusername, currentUser) == 0 && strcmp(booked_trips[i].status, "Paid") == 0) {
            printf("Booking ID: %s\n", booked_trips[i].UniqueID);
            printf("Status: %s\n", booked_trips[i].status);
            printf("Final Cost: %.2f\n", booked_trips[i].BTfinalCost);
            printf("Date: %d\n\n", booked_trips[i].BTDateByUser);
        }
    }

    system("pause");
}