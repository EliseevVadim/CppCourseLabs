#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Dealer.h"
#include "Player.h"
#include <Windows.h>
#include "IFormattable.h"
#include "AdaptedDeck.h"
#include <ctime>
int main()
{
    setlocale(LC_ALL, "Russian");
    Game* game = new Game();
    game->play();
    while (game->checkForContinue()) {
        game->play();
    }
    //delete game;
    system("pause");
    system("cls");
    std::wcout << L"Prepare to majesty!";
    Sleep(5000);
    system("cls");
    Deck* deck=new Deck();
    IFormattable* ifo = new AdaptedDeck(deck);
    ifo->prettyPrint(*ifo);
}