#include<bits/stdc++.h>
using namespace std;

// Stores player name and balance. Base class for all game classes.
class Player{

private:
    string name;
protected:
    int amount;
    
protected: 

    // Reads an integer safely and prevents input failure loops.
    int read_int()
    {
        int value;
        while (!(cin >> value))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return value;
    }

public:

    // Gets the player's name and starting balance with a maximum limit of 10,000.
    int user_input()
    {
        cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                              Welcome to the Casino Game\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\nEnter Player name: ";
        getline(cin,name);
        cout<<"Enter Total gambling amount (MAX 10K): ";
        while(true)
        {
            amount = read_int();
            if(amount > 0 && amount <= 10000) break;
            cout << "Amount must be between 1 and 10,000.\nEnter again: ";
        }
        return 0;
    }

    // Returns the player's current balance.
    int get_amount(){
        return amount;
    }

};

class Casino : public Player 
{
    public:

    // Gets a valid guess between 1 and 10, allowing up to three invalid attempts.
    int betting_num()
    {
        int count = 3;
        int num;
        cout<<"Enter Betting number : ";
        while(count>0)
        {
            num = read_int();
            if(num >0 && num <=10) return num;
            count--;
            cout <<"Invalid input. Enter a number between 1 to 10.\nNumber of tries left : "<<count<<"\nEnter Again : ";
        }
        cout<<"\nOut of tries. Sorry\n";
        return 0;
    }

    // Gets a valid bet amount within the player's current balance.
    int betting_amt()
    {
        int bet;
        int count = 3;
        cout<<"\nEnter betting Amount : ";
        while(count>0)
        {
            bet = read_int();
            if(bet<=amount && bet >0) return bet;
            count--;    
            if (bet>amount)
            {
                cout<<"\nInsufficient Balance "<<endl;
                cout<<"Money Left : "<<amount<<"$"<<endl;
                cout<<"Number of tries left : "<<count<<endl;
                cout<<"Enter Again : "; 
            }
            else if(bet <= 0)
            {
                cout<<"Invalid Input.";
                cout<<"Number of tries left : "<<count<<endl;
                cout<<"Enter Again : ";
            }
        }
        cout<<"\nOut of tries. Sorry\n";
        return 0;
    }


    int lucky7_choice()
    {
        int choice;
        int count = 3;

        cout << "\nChoose your Lucky 7 prediction:\n";
        cout << "1. Less than 7\n";
        cout << "2. Exactly 7\n";
        cout << "3. Greater than 7\n";
        cout << "Enter choice: ";

        while(count > 0)
        {
            choice = read_int();
            if(choice == 1) return 6;  // less than 7
            if(choice == 2) return 7;  // exactly 7
            if(choice == 3) return 8;  // greater than 7
            count--;
            cout << "Invalid choice. Number of tries left : " << count << endl;
            if(count > 0) cout << "Enter Again : ";
        }
        cout << "\nOut of tries. Sorry\n";
        return 0;   
    }


    int even_odd_choice()
    {
        int choice;
        int count = 3;

        cout << "\nChoose your prediction:\n";
        cout << "1. ODD \n";
        cout << "2. EVEN \n";
        cout << "Enter choice: ";

        while(count > 0)
        {
            choice = read_int();
            if(choice == 1) return 1;  // for odd prediction
            if(choice == 2) return 2;  // for even prediction
            count--;
            cout << "Invalid choice. Number of tries left : " << count << endl;
            if(count > 0) cout << "Enter Again : ";
        }
        cout << "\nOut of tries. Sorry\n";
        return 0;   
    }

    int big_gamble_choice()
    {
        int choose;
        int count = 3;
        cout<<"Enter Betting number : ";
        while(count>0)
        {
            choose = read_int();
            if(choose >0 && choose <=100) return choose;
            count--;
            cout <<"Invalid input. Enter  a number between 1 to 100.\nNumber of tries left : "<<count<<"\nEnter Again : ";
        }
        cout<<"\nOut of tries. Sorry\n";
        return 0;
    }

    int gamechoice;
    void main_menu()
    {
        cout <<"GAMES \n";
        cout <<"1. GUESS THE NUMBER 3X RETURN\n";
        cout <<"2. LUCKY 7 2X RETURN\n";
        cout <<"3. EVEN ODD 2X RETURN\n";
        cout <<"4. BIG GAMBLE 10X RETURN\n";
        cout <<"5. EXIT\n";
        cout <<"Enter Game : ";
        gamechoice = read_int();
    }
    
    // Displays the player's final balance.
    void exit_func()
    {
        cout<<"\nFinal Amount : "<<amount<<"$"<<endl;
        cout<<"Thank you for playing\n"<<endl;
    }
};

// Uses virtual inheritance to avoid the diamond problem because all game classes share Casino as a base class.
class game1 : public virtual Casino{

    protected:
    // Runs the Guess the Number round and returns 1 for win, -1 for loss.
    int game_1_logic(int chosen_num, int betamount)
    {
        int random_number = (rand()%10)+1;
        cout<<"Generated Number : "<<random_number<<endl;
        int dup = betamount*3;
        if(random_number==chosen_num)
        {
            cout<<"\nCorrect guess!! You won "<<dup<<"$"<<endl;
            amount = amount+(2*betamount);
            return +1;
        }
        else{
            cout<<"Incorrect guess You lost "<<betamount<<"$"<<endl;
            amount -= betamount;
            return -1;
        }
    }   

    public:
    //Display Game 1 Rules.
    void Game_1_rules()
    {
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"                                             GUESS THE NUMBER\n";
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\tGAME RULES\n";
        cout<<"The system will generate a random number between 1 and 10.\n";
        cout<<"Your goal is to guess the exact number.\n";
        cout<<"If your guess is correct, you win 3 times your bet amount.\n";
        cout<<"If your guess is wrong, you lose your bet amount.\n";
        cout<<"Good luck!\n";
    }
};

class game2 : public virtual Casino{
    public:
    void game_2_rules()
    {
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"                                                   LUCKY 7\n";
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\tGAME RULES\n";
        cout<<"The system will generate a random number between 1 and 10.\n";
        cout<<"You must predict whether the number will be less than 7, exactly 7, or greater than 7.\n";
        cout<<"If your prediction is correct, you win 2 times your bet amount.\n";
        cout<<"If your prediction is wrong, you lose your bet amount.\n";
        cout<<"Good luck!\n";
    }

    protected:
    int game_2_logic(int higher_lesser,int betamount)
    {
        int random_number = (rand()%10)+1;
        cout<<"Generated Number : "<<random_number<<endl;
        int dup = betamount*2;
        if(random_number < 7)
        {
            if(higher_lesser<7)
            {
                cout<<"\nCorrect guess!! You won "<<dup<<"$"<<endl;
                amount += betamount;
                return +1;
            }
            else 
            {
                cout<<"Incorrect guess You lost "<<betamount<<"$"<<endl;
                amount -= betamount;
                return -1;
            }
        }

        else if(random_number > 7)
        {
            if(higher_lesser > 7)
            {
                cout<<"\nCorrect guess!! You won "<<dup<<"$"<<endl;
                amount += betamount;
                return +1;
            }
            else 
            {
                cout<<"Incorrect guess You lost "<<betamount<<"$"<<endl;
                amount -= betamount;
                return -1;
            }
        }

        else if(random_number == 7)
        {
            if(higher_lesser == 7)
            {
                cout<<"\nCorrect guess!! You won "<<dup<<"$"<<endl;
                amount += betamount;
                return +1;
            }
            else 
            {
                cout<<"Incorrect guess You lost "<<betamount<<"$"<<endl;
                amount -= betamount;
                return -1;
            }    
        }
        return -1;

    }
};

class game3 : public virtual Casino
{
    public:
    void game_3_rules()
    {
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"                                                   EVEN OR ODD\n";
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\tGAME RULES\n";
        cout<<"The system will generate a random number between 1 and 10.\n";
        cout<<"You must predict whether the number will be even or odd.\n";
        cout<<"If your prediction is correct, you win 2 times your bet amount.\n";
        cout<<"If your prediction is wrong, you lose your bet amount.\n";
        cout<<"Good luck!\n";
    }

    protected:
    int game_3_logic(int choose, int betamount)
    {
        int ch = choose;
        int random_number = (rand()%10)+1;
        cout<<"Generated Number : "<<random_number<<endl;
        int dup = 2*betamount;
        if(random_number%2 != 0 && ch == 1)
        {
            cout<<"\nCorrect guess!! You won "<<dup<<"$"<<endl;
            amount += betamount;
            return +1;
        }
        else if (random_number%2 == 0 && ch == 2)
        {
            cout<<"\nCorrect guess!! You won "<<dup<<"$"<<endl;
            amount += betamount;
            return +1;
        }
        else
        {
            cout<<"\nIncorrect guess!! You Lost "<<betamount<<"$"<<endl;
            amount -= betamount;
            return -1;
        }
        
    }
};

class game4 : public virtual Casino
{
    public:
    int game_4_rules()
    {
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"                                                   BIG GAMBLE\n";
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\tGAME RULES\n";
        cout<<"The system will generate a random number between 1 and 100.\n";
        cout<<"You must guess the exact number.\n";
        cout<<"This game automatically uses your entire current balance as the bet amount.\n";
        cout<<"If your guess is correct, you win 10 times your bet amount.\n";
        cout<<"If your guess is wrong, you lose your entire balance.\n";
        cout<<"Good luck!\n";
        cout << "\nEnter 0 to return to the main menu or 1 to continue: ";
        int count = 3;
        while(count > 0)
        {
            int choice;
            choice = read_int();
            if(choice == 0 || choice == 1) return choice;
            count--;
            cout << "\nInvalid input. Tries left: " << count << "\nEnter again: ";
        }
        cout<<"\nOut of tries. Returning to main menu\n";
        return 0;
        
    }

    protected:
    int game_4_logic(int choose, int betamount)
    {
        int random_number = (rand()%100)+1;
        cout<<"Generated Number : "<<random_number<<endl;
        int dup = betamount*10;
        if(random_number==choose)
        {
            cout<<"\nCorrect guess!! You won "<<dup<<"$"<<endl;
            amount = amount+(9*betamount);
            return +1;
        }
        else{
            cout<<"Incorrect guess You lost "<<betamount<<"$"<<endl;
            amount -= betamount;
            return -1;
        }
    }
};

class GameRunning : public game1, public game2, public game3, public game4 
{
    private:
    int wins = 0;
    int losses = 0;
    int continue_play = 1;

    public:
    // Runs the selected game logic, updates win/loss stats, and returns the current balance.
    int win_loss_signal(int m, int n, int game)
    {
        if(game == 1)
        { 
            int score = game_1_logic(m,n); 
            if(score == 1) wins++;
            else losses++;
            return get_amount();
        }
        else if (game == 2)
        {
            int score = game_2_logic(m,n); 
            if(score == 1) wins++;
            else losses++;
            return get_amount();
        }
        else if (game == 3)
        {
            int score = game_3_logic(m,n);
            if(score == 1) wins++;
            else losses++;
            return get_amount();
        }
        else if(game == 4)
        {
            int score = game_4_logic(m,n);
            if(score == 1) wins++;
            else losses++;
            return get_amount();
        }
        return -1;
    }

    void exitcall()
    {
        show_states();
        exit_func();
    }

    // Handles one round of the currently selected game.
    int continue_playing()
    {
        int Chosen_number;

        if(gamechoice == 1){Chosen_number = betting_num();}
        else if(gamechoice == 2){Chosen_number = lucky7_choice();}
        else if(gamechoice == 3){ Chosen_number = even_odd_choice();}
        else if(gamechoice == 4){ Chosen_number = big_gamble_choice();}
        else return 0;

        if(Chosen_number == 0) {exitcall(); return 0;}
        int bet_amount;
        if(gamechoice != 4 )
        {   bet_amount = betting_amt();
            if(bet_amount == 0){exitcall(); return 0;}
        }
        else bet_amount = amount;
        
        if(bet_amount <= 0)
        {
            cout << "\nYou have no money to gamble!\n";
            exitcall();
            return 0;
        }

        int current_amt = win_loss_signal(Chosen_number,bet_amount,gamechoice);
        cout << "\nCurrent Balance : " << current_amt << "$" << endl;
        if(current_amt <= 0)
            {
                cout<<"\nYOU LOST ALL YOUR MONEY BETTER LUCK NEXT TIME \n";
                exitcall();
                return 0;
            }
        cout << "Enter 1 to continue playing, Enter 2 to go back to Main Menu : ";
        continue_play = read_int();
        return continue_play;
    }

    // Displays the main menu, shows rules, and controls the game loop.
    int run()
    {
        main_menu();

        if(gamechoice == 1) Game_1_rules();
        else if(gamechoice == 2) game_2_rules();
        else if(gamechoice == 3) game_3_rules();
        else if(gamechoice == 4)
        {
            int special_case = game_4_rules();
            if( special_case == 0) return 1;
        }
        else if(gamechoice == 5) {exitcall(); return 0;}
        else
        {
            cout << "Invalid choice. Returning to menu.\n";
            return 1;
        }
        while(1)
        {
            int result = continue_playing();
            if(result == 0) return 0;
            switch(continue_play)
            {
                case 1:
                    break;
                case 2:
                    return 1;
                default:
                    cout << "\nInvalid input. Returning to Main Menu.";
                    return 1;
            }
        }
    }

    // Displays the player's win/loss stats.
    void show_states()
    {
        cout<<"\nYour Stats "<<endl;
        cout<<"Wins   : "<<wins<<endl;
        cout<<"Losses : "<<losses<<endl;
    }
};

int main()
{
    srand(time(0));
    GameRunning Casinogame;
    int running = 1;
    Casinogame.user_input();
    while(running)
    {
        running = Casinogame.run();
    }
    return 0;
}