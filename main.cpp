#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//Function list/prototyping (not in order of appearance)
void startGame(); //Done
void update(string, int); //Done
void drawMainMenu(int); //Done
void drawGameMenu(int); //Done
void options(); //Done
void drawOptionsMenu(int); //Done
void drawPlayAgain(int); //Done
void introAnim(); //Done

//Some Global Variables
int sleep, scrollSpeed, compScore, playerScore, ties;
string cursor, cursorPick;


int main(int argc, char *argv[])
{
    
    //Setting defaults of global variables
    sleep = 150;
    scrollSpeed = 2;
    cursor = ">>";
    cursorPick = ">>";
    short option = 0;
    bool quit = false;
    
    //Play Introduction Animation
    introAnim();
    
    //Looping menu AFTER options are selected
    while(true){
        
        system("CLS");
        drawMainMenu(option);
        
        //Looping menu BEFORE options are selected
        while(true){
             
            //Is a Key Pressed? It should do something!
            if(GetAsyncKeyState(VK_UP) & 0x8000 && option > 0){
                option--;
                drawMainMenu(option);
                Sleep(sleep);
            }
            else if(GetAsyncKeyState(VK_DOWN) & 0x8000 && option < 2){
                option++;
                drawMainMenu(option);
                Sleep(sleep);
            }
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 0){
                Sleep(100);
                startGame();
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 1){
                Sleep(100);
                options();
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 2){
                Sleep(100);
                quit = true;
                break;
            }
        }
        //Should I quit?
        if(quit == true){
            Sleep(100);
            quit = false;
            break;
        }
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

//Game Controller Function
void startGame(){
    
    //Game Variables in order from most magical to least chaotic
    short compTurn, playerTurn, option;
    bool playerWin, quit;
    string winner;
    
    system("CLS");
    drawGameMenu(option);

    //Menu Looping AFTER selection
    while(true){
        
        option = 0;
        drawGameMenu(option);
        
        //Menu Looping BEFORE selection
        while(true){
            
            //Virtual Virtual Sim. Press the button!
            if(GetAsyncKeyState(VK_LEFT) & 0x8000 && option > 0){
                option--;
                drawGameMenu(option);
                Sleep(sleep);
            }
            else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && option < 2){
                option++;
                drawGameMenu(option);
                Sleep(sleep);
            }
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 0){
                Sleep(150);
                playerTurn = 0;
                system("CLS");
                cout << "You have chosen Rock. The computer is making it's decision...";
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 1){
                Sleep(150);
                playerTurn = 1;
                system("CLS");
                cout << "You have chosen Paper. The computer is making it's decision...";
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 2){
                Sleep(150);
                playerTurn = 2;
                system("CLS");
                cout << "You have chosen Scissors. The computer is making it's decision...";
                break;
            }
        }
        
        //Remove the Clutter
        system("CLS");
        
        //Randomly select something.
        srand(time(NULL));
        compTurn = rand() % 3;
        
        /*cout << compTurn << endl;
        system("PAUSE");*/
        
        //A Switch to handle who wins a round.
        switch(compTurn){
            case 0:
                //Switches inside of switches. WooOOoOOOoOoOoOOOo
                switch(playerTurn){
                    case 0:
                        update("tie", 1);
                        winner = "tie";
                        break;
                    case 1:
                        update("player", 1);
                        winner = "player";
                        break;
                    case 2:
                        update("comp", 1);
                        winner = "comp";
                        break;
                }
                break;
            case 1:
                switch(playerTurn){
                    case 0:
                        update("comp", 1);
                        winner = "comp";
                        break;
                    case 1:
                        update("tie", 1);
                        winner = "tie";
                        break;
                    case 2:
                        update("player", 1);
                        winner = "player";
                        break;
                }
                break;
            case 2:
                switch(playerTurn){
                    case 0:
                        update("player", 1);
                        winner = "player";
                        break;
                    case 1:
                        update("comp", 1);
                        winner = "comp";
                        break;
                    case 2:
                        update("tie", 1);
                        winner = "tie";
                        break;
                }
                break;
            }
        
        //If the computer wins, you suck uninstall.
        if(winner == "comp"){
            cout << "The computer wins!" << endl;
            switch(compTurn){
                case 0:
                    cout << "The Computer Chose Rock!" << endl;
                    break;
                case 1:
                    cout << "The Computer Chose Paper!" << endl;
                    break;
                case 2:
                    cout << "The Computer Chose Scissors!" << endl;
                    break;
            }
        }
        
        //If it's a draw you suck, get better scrub
        else if(winner == "tie"){
            cout << "The round ended in a draw!" << endl;
            switch(compTurn){
                case 0:
                    cout << "The Computer Chose Rock!" << endl;
                    break;
                case 1:
                    cout << "The Computer Chose Paper!" << endl;
                    break;
                case 2:
                    cout << "The Computer Chose Scissors!" << endl;
                    break;
            }
        }
        
        //If you win you hacked and are reported
        else{
            cout << "Congratulations! A WinRAR is you!" << endl;
            switch(compTurn){
                case 0:
                    cout << "The Computer Chose Rock!" << endl;
                    break;
                case 1:
                    cout << "The Computer Chose Paper!" << endl;
                    break;
                case 2:
                    cout << "The Computer Chose Scissors!" << endl;
                    break;
            }
        }
        
        //Let it all sink in for a second
        system("PAUSE");
        Sleep(150);
        
        //Reset Option for use in another menu
        option = 0;
        
        //Draw said menu
        drawPlayAgain(option);
        
        //Loop Menu, no need to worry about when or why. Just let it happen
        while(true){
            if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && option == 0){
                option = 1;
                drawPlayAgain(option);
                Sleep(sleep);
            }
            
            else if(GetAsyncKeyState(VK_LEFT) & 0x8000 && option == 1){
                option = 0;
                drawPlayAgain(option);
                Sleep(sleep);
            }
            
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 0){
                Sleep(150);
                system("CLS");
                break;
            }
            
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 1){
                Sleep(150);
                system("CLS");
                quit = true;
                break;
            }
        }
        
        //Rage Quit?
        if(quit == true){
            quit = false;
            break;
        }
    }
}

// Update Function to handle constantly changing states of variable within the game.
// This function almost simulates a class or structure. It takes in an Argument called
// arg which acts as a trigger word for what the function does. Think of each arg
// as a function.
void update(string arg, int number){
    
    //By that logic, this programmer is really bad. He should stop doing stupid stuff
    if(arg == "player"){
            switch(number){
                case 0:
                    playerScore = 0;
                    break;
                case 1:
                    playerScore++;
                    break;
            }
    }
    
    //Un-optimized bullshit this guy makes.
    else if(arg == "comp"){
            switch(number){
                case 0:
                    compScore = 0;
                    break;
                case 1:
                    compScore++;
                    break;
            }
    }
    
    //"But I was lazy" he says. Lazy enough to be a show off >.>
    if(arg == "tie"){
            switch(number){
                case 0:
                    ties = 0;
                    break;
                case 1:
                    ties++;
                    break;
            }
    }
     
}

//Options menu controller
void options(){
    
    //This stuff writes itself.
    int option = 0;
    bool quit = false;
    
    //Looping AFTER selection again.
    while(true){
        system("CLS");
        drawOptionsMenu(option);
        //Looping BEFORE selection agian. Basically this is just constantly drawing the menu.
        while(true){
        
            //Same old Same old. It's amazing how much you can do with one concept.
            if(GetAsyncKeyState(VK_UP) & 0x8000 && option > 0){
                option--;
                drawOptionsMenu(option);
                Sleep(sleep);
            }
    
            else if(GetAsyncKeyState(VK_DOWN) & 0x8000 && option < 3){
                option++;
                drawOptionsMenu(option);
                Sleep(sleep);
            }
    
            else if(GetAsyncKeyState(VK_LEFT) & 0x8000 && option == 0 && scrollSpeed > 0){
                sleep += 25;
                scrollSpeed--;
                drawOptionsMenu(option);
                Sleep(sleep);
            }
    
            else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && option == 0 && scrollSpeed < 4){
                sleep -= 25;
                scrollSpeed++;
                drawOptionsMenu(option);
                Sleep(sleep);
            }
    
            //Clear all game data. You know, incase you want to hide your losing streak.
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 1){
                Sleep(150);
                update("player", 0);
                update("comp", 0);
                update("tie", 0);
                system("CLS");
                cout << "All Game Data has been cleared!" << endl;
                system("PAUSE");
                Sleep(150);
                break;
            }
            
            //Customizing YOUR game! Too bad it resets after you close the program.
            else if(GetAsyncKeyState(VK_LEFT) & 0x8000 && option == 2){
                if(cursorPick == ">>"){
                    cursorPick = ":-";
                }
                else if(cursorPick == ":-"){
                    cursorPick = ")-";
                }
                else if(cursorPick == ")-"){
                    cursorPick = "o-";
                }
                else if(cursorPick == "o-"){
                    cursorPick = "--";
                }
                else if(cursorPick == "--"){
                    cursorPick = ":>";
                }
                else if(cursorPick == ":>"){
                    cursorPick = ")>";
                }
                else if(cursorPick == ")>"){
                    cursorPick = "O>";
                }
                else if(cursorPick == "O>"){
                    cursorPick = ">>";
                }
                drawOptionsMenu(option);
                Sleep(sleep);
            }
            
            else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && option == 2){
                if(cursorPick == ">>"){
                    cursorPick = "O>";
                }
                else if(cursorPick == "O>"){
                    cursorPick = ")>";
                }
                else if(cursorPick == ")>"){
                    cursorPick = ":>";
                }
                else if(cursorPick == ":>"){
                    cursorPick = "--";
                }
                else if(cursorPick == "--"){
                    cursorPick = "o-";
                }
                else if(cursorPick == "o-"){
                    cursorPick = ")-";
                }
                else if(cursorPick == ")-"){
                    cursorPick = ":-";
                }
                else if(cursorPick == ":-"){
                    cursorPick = ">>";
                }
                drawOptionsMenu(option);
                Sleep(sleep);
            }
            
            //Hit enter to set the cursor to the desired design. My favorit is :-
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 2){
                Sleep(150);
                cursor = cursorPick;
                drawOptionsMenu(option);
            }
            
            else if(GetAsyncKeyState(VK_RETURN) & 0x8000 && option == 3){
                Sleep(150);
                quit = true;
                break;
            }
        }
        //Your Loop is Forfeit.
        if(quit == true){
            Sleep(100);
            quit = false;
            break;
        }
    }
}

//This draws the game menu to the screen. It has no function beyond visuals.
void drawGameMenu(int choice){
    
    system("CLS");
    
    cout << "SCORE\nPlayer: " << playerScore << "\tTies: " << ties << "\tComputer: " << compScore << "\n\n\n";
    
    if(choice == 0){
        cout << cursor << "Rock\t  Paper\t  Scissors" << endl;
    }
    else if(choice == 1){
        cout << "  Rock\t" << cursor << "Paper\t  Scissors" << endl;
    }
    else if(choice == 2){
        cout << "  Rock\t  Paper\t" << cursor << "Scissors" << endl;
    }
}

//This draws the Main Menu to the Screen.
void drawMainMenu(int choice){
    
    system("CLS");
    
    if(choice == 0){
        cout << cursor << "\tPlay!\n\tOptions\n\tQuit" << endl;
    }
    
    else if(choice == 1){
        cout << "\tPlay!\n" << cursor << "\tOptions\n\tQuit" << endl;
    }
    
    else if(choice == 2){
        cout << "\tPlay!\n\tOptions\n" << cursor << "\tQuit" << endl;
    }
}

// This asks if you want to play again. It's like a cheap circus trick to get you to spend more money
// Except you aren't actually spending money because you're cheap and I don't get paid.
void drawPlayAgain(int choice){
    
    system("CLS");
    
    cout << "Would you like to play again?\n";
    
    if(choice == 0){
            cout << cursor << "Yes\t  No" << endl;
    }
    else if(choice == 1){
            cout << "  Yes\t" << cursor << "No" << endl;
    }
}

// This is a bunch of options. Or something. You know, I don't know what this is. Did I put this here?
void drawOptionsMenu(int choice){
    
    system("CLS");
    
    if(choice == 0){
        if(scrollSpeed == 0){
            cout << cursor << "\tScroll Speed (|----)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 1){
            cout << cursor << "\tScroll Speed (-|---)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 2){
            cout << cursor << "\tScroll Speed (--|--)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 3){
            cout << cursor << "\tScroll Speed (---|-)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 4){
            cout << cursor << "\tScroll Speed (----|)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
    }
    else if(choice == 1){
        if(scrollSpeed == 0){
            cout << "\tScroll Speed (|----)\n" << cursor << "\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 1){
            cout << "\tScroll Speed (-|---)\n" << cursor << "\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 2){
            cout << "\tScroll Speed (--|--)\n" << cursor << "\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 3){
            cout << "\tScroll Speed (---|-)\n" << cursor << "\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 4){
            cout << "\tScroll Speed (----|)\n" << cursor << "\tClear Game Stats\n\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
    }
    else if(choice == 2){
        if(scrollSpeed == 0){
            cout << "\tScroll Speed (|----)\n\tClear Game Stats\n" << cursor << "\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 1){
            cout << "\tScroll Speed (-|---)\n\tClear Game Stats\n" << cursor << "\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 2){
            cout << "\tScroll Speed (--|--)\n\tClear Game Stats\n" << cursor << "\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 3){
            cout << "\tScroll Speed (---|-)\n\tClear Game Stats\n" << cursor << "\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 4){
            cout << "\tScroll Speed (----|)\n\tClear Game Stats\n" << cursor << "\tCursor Type " << cursorPick << "\n\tBack to Main Menu" << endl;
        }
    }
    else if(choice == 3){
        if(scrollSpeed == 0){
            cout << "\tScroll Speed (|----)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n" << cursor << "\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 1){
            cout << "\tScroll Speed (-|---)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n" << cursor << "\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 2){
            cout << "\tScroll Speed (--|--)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n" << cursor << "\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 3){
            cout << "\tScroll Speed (---|-)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n" << cursor << "\tBack to Main Menu" << endl;
        }
        else if(scrollSpeed == 4){
            cout << "\tScroll Speed (----|)\n\tClear Game Stats\n\tCursor Type " << cursorPick << "\n" << cursor << "\tBack to Main Menu" << endl;
        }
    }
}

// This is a comment. It tells you stupid stuff I'm thinking. None of it is serious, please ignore me.
// Oh! You mean what's below this? Some 6 FPS consoul peseant stuff. Seriously, this animation plays at 6 FPS.
// I calculated it. It's also an introduction to the game.
void introAnim(){
    int speed = 150;
    
    cout << "J";
    Sleep(speed);
    system("CLS");
    
    cout << "Jo";
    Sleep(speed);
    system("CLS");
    
    cout << "Jos";
    Sleep(speed);
    system("CLS");
    
    cout << "Josi";
    Sleep(speed);
    system("CLS");
    
    cout << "Josia";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah ";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah S";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Sa";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Sal";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly ";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly P";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Pr";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Pre";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Pres";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Prese";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presen";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Present";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    Sleep(300);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "    RPapers";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "   RoPaperrs";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "  RocPaperors";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << " RockPapersors";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "Rock Paperssors";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "Rock Paperissors";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "Rock Papercissors";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "Rock PaperScissors";
    Sleep(speed);
    system("CLS");
    
    cout << "Josiah Saly Presents:" << endl;
    cout << "Rock Paper Scissors" << endl;
    Sleep(speed);
    system("PAUSE");
    Sleep(100);
}

//Wow 739 lines of code for a program that should have only fit on 20 - 30. gg wp no re.
