#include <stdio.h>
#include <string.h>                                            //Dilono vivliothikes
#include <math.h>
#include <stdlib.h>


void admin_login();
void admin_screen();
void user_screen();                                          //Dilono tis sinartisis pou tha xrisimopoihsw
void change_reward();
void user_login();
void user_signup();
int generate_pin(char card_number[]);
int check_age(int age);
float calculate_reward();
int execute_transaction();
void print_receipt();

float reward_per0 = 0.1;
float reward_per1 = 0.09;
float reward_per2 = 0.08;
float reward_per3 = 0.07;
float reward_per4 = 0.06;                                       // Dilono Global kai ton pinaka me ta pososta pou exei o pinakas
float reward_per5 = 0.06;                                       // tis ekfonisis exontas kanei tin metatropi
float reward_per6 = 0.07;                                       //              π.χ. 10% = 10/100 = 0.1
float reward_per7 = 0.08;
float reward_per8 = 0.09;
float reward_per9 = 0.1;

//Genika h logikh poy exw akolouthisei einai oti h kathe synarthsh kalei mia allh dimiourgontas eikonika layers sto programma
//                 ADMIN             EXIT                     USER

//          Log in       Exit                  Sign up           Log in         Exit

//Change reward   Exit                             Cal Rew    Trans    Receipt    Exit


char name[20];
char surname[20];
int age, pin;
char card_number[17];
char username[8];
char password[8];                                     // dilono global metavlites katigoriopoiwntas tes me vash to shmeio tou programmatos
float amount, reward;                                 // pou tis xrhsimopoiw h me vash ton koino skopo tous
int tc;
char tt[11];

int dig1;
int dig2;
int dig3;
int dig4;

int loginaccess = 1;
int transaccess = 1;
int recaccess = 1;

// kai twra sthn main() dhmiourgw ena menu epikogwn kai analoga me thn epilogh tou xrhsth tha prowthitei sthn
// katallhlh synarthsh, h opoia me thn seira ths tha kalesei alles synartiseis klp. Etsi tha dimiourgithoun navigation layers
// poy tha shmatodotoun how deep tha eimaste sto programma.px main >> User_screen >> User_login >> Print_receipt

int main() {
    char choice[10];
    int exit=1;
    do{
    system("cls");
    printf("\nWELCOME TO DS E-BANKING, PLEASE SELECT PROFILE\n\n");   
    printf("Type ADMIN or USER or 0 to EXIT e-Banking!\n\n");
    printf("Enter your choice: ");
    scanf("%s", &choice);
    if(strcmp(choice, "ADMIN") == 0) {
        admin_screen();
    }
    else if(strcmp(choice, "USER") == 0) {                      // Xwrizw thn main()  se plohgisi 2 sinartisewn kai 
        user_screen();                                           // eksodo, panta me elegxo egkyrothtas
    }
    else if(strcmp(choice, "0") == 0) {
        system("cls");
        exit = 0;
        printf("\n       Goodbye!\n\n");
    }
    else {
        printf("That was not an option, try again!\n");
        system("pause");
    }
    }while(exit != 0);
    return 0;
}

void admin_screen() {
  int choice;  
    
    do{ 
        system("cls");
        printf("\n  ADMIN\n\n");
        printf("1. Login\n2. Exit\n");
        printf("Enter your choice: ");                      //Afou exoyme ploigithei stin admin selida-synartisi
        scanf("%d", &choice);                               // dialegoume apo to menu an tha kanoyme log in --> sthn katallhlh sinartisi
        if(choice == 1) {                                   // i eksodo me elegxo egkyrothtas se ola
            admin_login();                                   
        }
        else if(choice == 2) {

        }
        else {
            printf("That was not an option, try again!\n");
            system("pause");
        }
    }while(choice != 2);
   }

//afoy o xristis epilekesei na kanei log in tou zhtame na valei onoma kai kwdiko kai me EE(=ELegxo egkyrothtas poy kanw pantoy opote tha to paraleipw)
//ton prowthoyme se ena menu poy to dinei thn epilogh eksodos kai change reward kai ton ksanaprowthoyme sthn analogh synarthsh
void admin_login() {
    char input_username[6];
    char input_password[6];
    system("cls");
    printf("\n  SIGN IN\n\n");
    printf("Enter username: ");
    scanf("%s", input_username);
    printf("Enter password: ");
    scanf("%s", input_password);
    if(strcmp(input_username, "admin") == 0 && strcmp(input_password, "admin") == 0) {
        printf("Login successful!\n");
        char choice;
        do{
           system("cls"); 
           printf("\n  SELECT ACTION\n");
           printf("a. Change Reward\nb. Exit\n");
           printf("Enter your choice: ");
           scanf(" %c", &choice);
           if(choice == 'a')
           {
             change_reward();
           } 
           else if(choice == 'b') 
           {
                                  // to keno poy afhnw sthn epilogh poy dhlwnei exit einai giati thelw na leitourgisei
                                  // swsta i sinthiki if se sxesh me tin do while, opote einai skopimo keno kai yparxei kai parakatw
           }
           else
           {
               printf("That was not an option, try again!\n");
               system("pause");
           } 
        }while(choice != 'b');
        
    } else {
        printf("Invalid username or password!\n");
        system("pause");
        admin_screen();
    }
}

// me xrisi tis entolis switch exw epileksei kai epanalabei ta idia kommatia kwdika gia kathe periptwsh(0-9)
// Kanw ton elegxw gia to -+5% tis allagis kai tote allazw to pososto. Meta rwtaei ton xristi an thelei
// na sinexisei tis allages kai an apanthsei YES epanalambanetai h diadikasia, an kati allo, teleiwnei
void change_reward() {
    float temp=1;
    int exit=1;
  do{
    system("cls");
    printf("\n  REWARD EDITOR\n\n");
    printf("What industry from 0-9 you would like to change the reward percentage?\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
        
    case 0:
    printf("The current percentage for industry 0 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per0);
    
    scanf("%f", &temp);
    if(temp>reward_per0+(reward_per0*0.05) || temp<reward_per0-(reward_per0*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per0=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        break;
    case 1:
        printf("The current percentage for industry 1 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per1);
    
    scanf("%f", &temp);
    if(temp>reward_per1+(reward_per1*0.05) || temp<reward_per1-(reward_per1*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per1=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 2:
        printf("The current percentage for industry 2 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per2);
    
    scanf("%f", &temp);
    if(temp>reward_per2+(reward_per2*0.05) || temp<reward_per2-(reward_per2*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per2=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
         char c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 3:
        printf("The current percentage for industry 3 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per3);
    
    scanf("%f", &temp);
    if(temp>reward_per3+(reward_per3*0.05) || temp<reward_per3-(reward_per3*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per3=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 4:
        printf("The current percentage for industry 4 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per4);
    
    scanf("%f", &temp);
    if(temp>reward_per4+(reward_per4*0.05) || temp<reward_per4-(reward_per4*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per4=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 5:
        printf("The current percentage for industry 5 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per5);
    
    scanf("%f", &temp);
    if(temp>reward_per5+(reward_per5*0.05) || temp<reward_per5-(reward_per5*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per5=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 6:
        printf("The current percentage for industry 6 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per6);
    
    scanf("%f", &temp);
    if(temp>reward_per6+(reward_per6*0.05) || temp<reward_per6-(reward_per6*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per6=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 7:
        printf("The current percentage for industry 7 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per7);
    
    scanf("%f", &temp);
    if(temp>reward_per7+(reward_per7*0.05) || temp<reward_per7-(reward_per7*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per7=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 8:
        printf("The current percentage for industry 8 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per8);
    
        scanf("%f", &temp);
    if(temp>reward_per8+(reward_per8*0.05) || temp<reward_per8-(reward_per8*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }
           
    else {
        reward_per8=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    case 9:
        printf("The current percentage for industry 9 is %.2f\nWhat percentage would you like to be from now on?\n",reward_per9);
    
    scanf("%f", &temp);
    if(temp>reward_per9+(reward_per9*0.05) || temp<reward_per9-(reward_per9*0.05)) {
        printf("New percentage must not exceed an increase or decrease of more than 5%c of the previous one\n",'%');
        system("pause");
    }        
    else {
        reward_per9=temp;
        exit=0;
        printf("Reward updated successfully!\n");
        printf("Would you like to make more changes? If so, type YES . Else press any key.\n");
        int c[4];
        scanf("%s", &c);
        if(strcmp(c, "YES") == 0) {
            exit=1;
        }
    }
        
        break;
    

    default:
    exit=0;
    printf("That was not an option, try again\n");
    system("pause");
        break;
    }
  }while(exit == 1);
}

void user_screen(){     // afou exoyme ploigithei sto user screen, emfanizoyme to parakatw menu epilogwn
int choice;  
    
    do{ 
        system("cls");
        printf("\n  USER\n\n");
        printf("1. Sign Up\n2. Log In\n3. Exit\n");
        printf("Enter your choice: ");                      
        scanf("%d", &choice);                               //idia diadikasia me to menou epilogwn
        if(choice == 1) {                                   
            user_signup();                                   
        }
        else if(choice == 2) {
            user_login();
        }
        else if(choice == 3) {

        }
        else {
          printf("That was not an option, try again!\n");
          system("pause");   
        }
    }while(choice != 3);

    main();

}

void user_signup() {               // opws perigrafete sto pdf
    system("cls");
    printf("  CREATE AN ACCOUNT\n\n");

    printf("Name : ");
    scanf("%s", &name);

    printf("\nSurname : ");
    scanf("%s", &surname);

    printf("\nAge : ");                                      // pernoume ta stoixeia gia thn eggrafh tou xrhsth me tous katllhlous elegxous
    do{
       scanf("%d", &age);
    }while(check_age(age) == 1);

    printf("\nCard Number : ");
    do{
    scanf("%s", &card_number);
    if(strlen(card_number) != 16) {
        printf("\nCard Number must be exactly 16 digits. Try again!\nCard Number : ");
       }
    }while(strlen(card_number) != 16);

    printf("\nUsername : ");
    do{
    scanf("%s", &username);
    if(strlen(username) > 8) {
        printf("\nUsername must not exceed 7 characters. Try again!\nUsername : ");
       }
    }while(strlen(username) > 8);

    printf("\nPassword : ");
    do{
       scanf("%s", &password);
       if(strlen(password) > 8) {
        printf("\nPassword must not exceed 7 characters. Try again!\nPassword : ");
       } 
    }while(strlen(password) > 8);

    pin = generate_pin(card_number);

    printf("\n\nCredentials are successfully in the system. You now have an account!\n "); 
    printf("Your card PIN is : %d . Do not show it to anyone!\n\n", pin);
    system("pause");

    loginaccess = 0;                        // se ayto to shmeio pleon epitrepoyme ston xrhsth na kanei log in giati prin den mporouse

    user_screen();
}

int check_age(int age) {
    if(age<18){
        printf("\nAge must be 18 years or more. Try again!\nAge : ");    //elegxoume thn hlikia epistrefontas 0 gia to swsto 1 kai analogo minima lathous
        return 1;
    }
    else {
        return 0;
    }
}

int generate_pin(char card_number[]) {
    int pin;                               // orizw PIN se ayto to scope kai ara diaforetiko apo to global var PIN
    char str_dig[2] = "\0\0";  

    str_dig[0] = card_number[0];
    int dig1 = atoi(str_dig);

    str_dig[0] = card_number[4];
    int dig2 = atoi(str_dig);                // den xrhsimopoiousa swsta tin atoi enw eixa katalavei ti prepei na kanw opote voithithika apo to Internet
                                             // gia to sygkekrimeno shmeio!

    str_dig[0] = card_number[8];
    int dig3 = atoi(str_dig);

    str_dig[0] = card_number[12];
    int dig4 = atoi(str_dig);

    pin = 1000*dig1 + 100*dig2 + 10*dig3 + dig4; //epeidh o ypologisths diavazei px 3.592 kai oxi 3 5 9 2 synthetw etsi to pin

    return pin;
}


void user_login() {
    system("cls");
    if(loginaccess == 1)                                // elegxoume an exei dhmiourghthei toulaxiston 1 account wstw na exei nohma to log in
    {
      printf("\nYou can Login In only when you have an account! Sign up and try again!\n");
      system("pause");
    }
    while(loginaccess == 0)
    { 
      char input_username[8];
      char input_password[8];
      system("cls");
      printf("\n  SIGN IN\n\n");
      printf("Enter username: ");
      scanf("%s", input_username);
      printf("Enter password: ");
      scanf("%s", input_password);
      if(strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0) {
          printf("Login successful!\n");
          char choice;
          do{
             system("cls"); 
             printf("\n  SELECT ACTION\n");
             printf("a. Calculate Reward\nb. Transaction\nc. Receipt\nd. Exit\n");
             printf("Enter your choice: ");
             scanf(" %c", &choice);
             if(choice == 'a')
             {
               reward = calculate_reward();
               transaccess = 0 ;              // se ayto to shmeio pleon epitrepoyme ston xrhsth na kanei transaction giati prin den mporouse
             } 
             else if(choice == 'b')  
             {
               if(transaccess == 0){         //elexgoume an exei perasei prwta apo to calculate reward
                execute_transaction(); 
               }
               else {
                printf("You can Execute a Transaction only when you have calculated your rewards! Calculate them and try again!\n");
                system("pause");
               }   
             }
             else if(choice == 'c')  
             {
               if(recaccess == 0){               //elegxoume an exei perasei prwta apo to execute transaction
                print_receipt(); 
               }
               else {
                printf("You can view your Receipt only when you have Executed a Transaction! Execute one and try again!\n");
                system("pause");
                }
             }
             else if(choice == 'd')
               {
                user_screen();
               }
             else
             {
                printf("That was not an option, try again!\n");
                system("pause");
                user_screen();
             } 
            }while(choice != 'd');
          
          }
          else {
          printf("Invalid username or password!\n");
          system("pause");
          user_screen();
         }
    }
    main();
}     


float calculate_reward(){          

    char AM[7];
    int transaction_code;
    system("cls");
    printf("  REWARD CALCULATOR");
    printf("\n\nWhat is the amount you want to calculate your reward?\n");
    scanf("%f", &amount);
    printf("\nWhat is your AM?\n");                                                           // edw mou eipan oti eprepe apla na valw to diko mou AM alla 
    do{                                                                                      // to eixa hdh kanei kai fantastika oti ena addition den tha 
      scanf("%s", &AM);                                                                      // ephreasei thn vathmologia
      transaction_code = atoi(&AM[6]);
      if(atoi(&AM[6]) >= 0 && atoi(&AM[6] <= 9)){
        printf("\nThe AM you placed was not correct, be sure that the type is like 'E23230'\n");
        printf("AM : ");
      }
    }while(atoi(&AM[6]) >= 0 && atoi(&AM[6] <= 9));

    tc = transaction_code; 
    switch (tc)               // edw vazw analoga me to AM thn kathgoria synallaghs poy tha bgalei h apodeiksh kai to reward me ton analogo syntelesth
    {
    case 0:
        strcpy(tt, "AIRLINES");
        reward = reward_per0/log10(age)*amount;
        break;
    case 1:
         strcpy(tt, "HEALTH");
         reward = reward_per1/log10(age)*amount;
        break;
    case 2:
        strcpy(tt, "FASHION");
        reward = reward_per2/log10(age)*amount;
        break;
    case 3:
        strcpy(tt, "TECH");
        reward = reward_per3/log10(age)*amount;
        break;
    case 4:
        strcpy(tt, "NAVIGATION");
        reward = reward_per4/log10(age)*amount;
        break;
    case 5:
        strcpy(tt, "CONSULTING");
        reward = reward_per5/log10(age)*amount;
        break;
    case 6:
        strcpy(tt, "SPORT");
        reward = reward_per6/log10(age)*amount;
        break;
    case 7:
        strcpy(tt, "EDUCATION");
        reward = reward_per7/log10(age)*amount;
        break;
    case 8:
        strcpy(tt, "INSURANCE");
        reward = reward_per8/log10(age)*amount;
        break;
    case 9:
        strcpy(tt, "RESTOBAR");
        reward = reward_per9/log10(age)*amount;
        break;
    
    default:
        break;
    }
    printf("\n\nCalculation Completed! If the amount is %.2f EUR, then the reward based on your status will be %.2f EUR\n",amount, reward);
    system("pause");
    return reward;
}

int execute_transaction(){   // Opws akrivws perigrafetai sto pdf
    system("cls");
    printf("  COMPLETE TRANSACTION\n\n");
    char tempCard[20];  
    printf("Please insert your card number in order to complete the transaction\nCard Number : ");
    do{
      scanf("%s", tempCard);
      if(strcmp(tempCard, card_number) != 0)  {
        printf("The Card Number is not matched with that one you have given earlier, please try again!\nCard Number : ");
      } 
    }while(strcmp(tempCard, card_number) != 0);
    if(amount <= 50){
        printf("\n\nTransaction has been Completed!\n\nIf you want a receipt you can select option 'Receipt' by typing 'c' in the previous menu.\n");
        system("pause");
        recaccess = 0;
    }
    else {
        int rdig1 = rand() % 4 + 1;
        int rdig2;
        do {                                                 // kanw randomly generate 2 arithnous alla tous apotrepw na einai idioi
            rdig2 = rand() % 4 + 1;                 
        } while(rdig1 == rdig2);
        
        printf("Because of the amount being over 50 EUR, we have to verify you.\n");
        printf("For that you will only have to type the digit %d and the digit %d of your PIN\n",rdig1,rdig2);
        
        int success=1;
        
        for(int i=1;i<=3;i++){
            printf("Digit %d : ",rdig1);
            char t1,t2;
            scanf(" %c", &t1);
            printf("Digit %d : ",rdig2);           //edw me poly xazo tropo elegxw se oles tis periptwseis gia to na exei valei swsta digts o user
            scanf(" %c", &t2);
            int p1=1,p2=1; 
            if(rdig1 == 1) {
                if(card_number[0] == t1) {
                    p1=0;
                }
                   
            }
            else if(rdig1 == 2) {
                if(card_number[4] == t1) {
                    p1=0;
                }

            }
            else if(rdig1 == 3) {
                if(card_number[8] == t1) {
                    p1=0;
                }
            }
            else if(rdig1 == 4) {
                if(card_number[12] == t1) {
                    p1=0;
                }
            }


            if(rdig2 == 1) {
                if(card_number[0] == t2) {
                    p2=0;
                }
                   
            }
            else if(rdig2 == 2) {
                if(card_number[4] == t2) {
                    p2=0;
                }

            }
            else if(rdig2 == 3) {
                if(card_number[8] == t2) {
                    p2=0;
                }
            }
            else if(rdig2 == 4) {
                if(card_number[12] == t2) {
                    p2=0;
                }
            }

            if(p1 == 0 && p2 == 0) {                 //kai telika an kai ta dyo einai swsta tote einai okk
                printf("\nVerified!\nTransaction has been Completed!\n\nIf you want a receipt you can select option 'Receipt' by typing 'c' in the previous menu.\n");
                i=3;
                recaccess = 0;                 // se ayto to shmeio pleon epitrepoyme ston xrhsth na parei receipt giati prin den mporouse
                success = 0;              // to success katalavainei an teleiwse to loop logw 3 mistaken answers h logw success
                system("pause");
            }
            else
            {
                printf("\nThat is not correct. You have %d attempts left!\n\n",3-i);
            } 
        }  

        if(success == 1){
            printf("\nTransaction Declined! You now will be returned to the previous menu, and you have to repeat the process.\n");
            system("pause");
        }

    }
}


void print_receipt(){
  system("cls"); // to carddisplay einai gia na dimiourghsh gaps kathe 4 pshfia gia logous aisthitikhs
char carddisplay[20] = {card_number[0],card_number[1],card_number[2],card_number[3],' ',card_number[4],card_number[5],card_number[6],card_number[7],' ',card_number[8],card_number[9],card_number[10],card_number[11],' ',card_number[12],card_number[13],card_number[14],card_number[15]};

// εκτυπωνουμε την αποδειξη για τον χρηστη.

printf(" **************************************************\n");
printf(" *                    DS BANK                     *\n");
printf(" *                                                *\n");
printf(" *                                                *\n");
printf(" *                PAYMENT DETAILS                 *\n");
printf(" *                                                *\n");
printf("         CARD NUMBER:     %s                       \n", carddisplay);   // kai tekos ta kena ta evala giati prin analogws to poso
printf("         AMOUNT:                     %.2f EUR      \n", amount);       // kouniotan to perivlhma!           
printf(" *                                                *\n");
printf(" *                                                *\n");
printf(" *                REWARD DETAILS                  *\n");
printf(" *                                                *\n");
printf("         TRANSACTION TYPE:          %s             \n", tt);
printf("         REWARD:                     %.2f EUR      \n", reward);
printf(" *                                                *\n");
printf(" *                                                *\n");
printf(" *                                                *\n");
printf(" **************************************************\n\n\n");
system("pause");

}