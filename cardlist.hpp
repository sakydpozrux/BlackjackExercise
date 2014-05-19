#ifndef CARDLIST_HPP
#define CARDLIST_HPP

#include <list>
#include <string>
#include <boost/lexical_cast.hpp>
#include "card.hpp"

class CardList
{
private:
    std::list<Card> cards;

public:
    CardList();
    CardList(const std::list<Card>& list_of_cards);
    CardList(const std::string& input_str);
    unsigned int size() const;
    Card front() const;
    void pop_front();


private:
    std::list<Card> init_cards(const std::string& input_str) throw(boost::bad_lexical_cast, invalid_card_value);
    friend std::ostream& operator<<(std::ostream &stream, const CardList& cards);
};

std::ostream& operator<<(std::ostream &stream, const CardList& cards);

#endif // CARDLIST_HPP
