#include <iostream>
#include <ctime>

/*
Commenting chonks of code:
Ctrl + / 

Compiling & Running:
Right click on the file/Open in integrated terminal
In the terminal for compiling: cl TripleX.cpp /EHsc
In the terminal for executing: TripleX
*/

// In this game you have to decipher the 3 number needed for Sum and Mult
void IntroGame(int iLevelDifficulty)
{
    std::cout << R"(
  ______     __  __     ______     ______     ______        ______     ______     __    __     ______    
/\  ___\   /\ \/\ \   /\  ___\   /\  ___\   /\  ___\      /\  ___\   /\  __ \   /\ "-./  \   /\  ___\   
\ \ \__ \  \ \ \_\ \  \ \  __\   \ \___  \  \ \___  \     \ \ \__ \  \ \  __ \  \ \ \-./\ \  \ \  __\   
 \ \_____\  \ \_____\  \ \_____\  \/\_____\  \/\_____\     \ \_____\  \ \_\ \_\  \ \_\ \ \_\  \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_____/   \/_____/      \/_____/   \/_/\/_/   \/_/  \/_/   \/_____/ 
                                                                                                        
)" << '\n';

    // For new line you can use: std::endl or \n
    std::cout << "\nIf you want to leave this dungeon, you will have to face the challenge number " << iLevelDifficulty;
    std::cout << "\nYou have to decipher three glyphs... \n\n";
    
    std::cout << "You deciphered these three glyphs are three numbers but which numbers? \n";
}

bool GuessGame(int iDifficult)
{
    // These numbers are used for comparing the user inputs
    const int iFirst = (rand() % iDifficult) + iDifficult;
    const int iSecond = (rand() % iDifficult) + iDifficult;
    const int iThird = (rand() % iDifficult) + iDifficult;

    const int iSumResult = iFirst + iSecond + iThird;
    const int iProductResult = iFirst * iSecond * iThird;

    // In this variables will be saved the users inputs
    int iOneInput;
    int iTwoInput;
    int iThreeInput;

    int iSumInput;
    int iProductInput;

    IntroGame(iDifficult);

    // You can stack std:: in the same line
    std::cout << "The three numbers added: " << iSumResult << std::endl;
    std::cout << "The three numbers multiplied: " << iProductResult << std::endl;
    std::cout << std::endl;

    std::cout << "First number:";
    std::cin >> iOneInput;
    std::cout << "Second second:";
    std::cin >> iTwoInput;
    std::cout << "Third number:";
    std::cin >> iThreeInput;

    iSumInput = iOneInput + iTwoInput + iThreeInput;
    iProductInput = iOneInput * iTwoInput * iThreeInput;

    std::cout << "Your three numbers added: " << iSumInput << std::endl;
    std::cout << "Your three numbers multiplied: " << iProductInput << std::endl;

    // Comparing the results 
    if((iSumInput == iSumResult) && (iProductInput == iProductResult))
    {
        std::cout << "Congratulations! You passed the challenge number " << iDifficult;
        return true;
    }
    else
    {
        std::cout << "You...  FAILED! Try Again...\n";
        return false;
    }
}

int main()
{
    bool bLevelCompleted;
    int iDifficulty = 1;
    const int iMaxLevel = 3;
    
    srand(time(NULL));

    while (iDifficulty <= iMaxLevel)
    {
        bLevelCompleted = GuessGame(iDifficulty);
        // Clears any errros
        std::cin.clear();
        // Discards the buffer
        std::cin.ignore();

        if (bLevelCompleted)
        {
            iDifficulty++;
        }
    }

    std::cout << "\n\nYou passed the dungeon! You can go home! ";

    std::cout << R"(
 __  __     ______     __  __        __     __     ______     __   __    
/\ \_\ \   /\  __ \   /\ \/\ \      /\ \  _ \ \   /\  __ \   /\ "-.\ \   
\ \____ \  \ \ \/\ \  \ \ \_\ \     \ \ \/ ".\ \  \ \ \/\ \  \ \ \-.  \  
 \/\_____\  \ \_____\  \ \_____\     \ \__/".~\_\  \ \_____\  \ \_\\"\_\ 
  \/_____/   \/_____/   \/_____/      \/_/   \/_/   \/_____/   \/_/ \/_/ 
                                                                         
)" << '\n';

    return 0;
}