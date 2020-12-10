#include "AdaptedDeck.h"
#include "IFormattable.h"
AdaptedDeck::AdaptedDeck(Deck* deck) {
	deck_ = deck;
}
std::wstring AdaptedDeck::format() {
	std::wstring formatted_line = L"";
	for (int i = 0; i < deck_->getCount(); i++) {
		Card card = deck_->getCardPerIndex(i);
		if (card.getSuit() == Suit::Club || card.getSuit() == Suit::Spades) {
			for (int j = 0; j < card.getValue(); j++) {
				formatted_line += L"\x1b[35m";
				formatted_line += card.getSuitInSymbol();
				formatted_line += L"\x1b[0m";
			}
			formatted_line += card.getPrintInterpretation();
			for (int j = 0; j < card.getValue(); j++) {
				formatted_line += L"\x1b[35m";
				formatted_line += card.getSuitInSymbol();
				formatted_line += L"\x1b[0m";
			}
			formatted_line += L"\n";
		}
		else {
			for (int j = 0; j < card.getValue(); j++) {
				formatted_line += L"\x1b[31m";
				formatted_line += card.getSuitInSymbol();
				formatted_line += L"\x1b[0m";
			}
			formatted_line += card.getPrintInterpretation();
			for (int j = 0; j < card.getValue(); j++) {
				formatted_line += L"\x1b[31m";
				formatted_line += card.getSuitInSymbol();
				formatted_line += L"\x1b[0m";
			}
			formatted_line += L"\n";
		}
	}
	return formatted_line;
}
void AdaptedDeck::prettyPrint(const IFormattable& object) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	std::wcout<<format();
}