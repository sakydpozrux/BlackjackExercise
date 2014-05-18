#ifndef CARDLIST_HPP
#define CARDLIST_HPP

#include <list>
#include <string>
#include <boost/lexical_cast.hpp>

struct invalid_card_value : std::exception
{
    const char* what() const noexcept {return "Exception: card value is out of [1,10] range";}
};

class CardList
{
private:
    std::list<int> cards;

public:
    CardList(const std::list<int>& list_of_ints);
    CardList(const std::string& input_str);
    unsigned int size() const;
    int front() const;
    void pop_front();

private:
    std::list<int> init_cards(const std::string& input_str) throw(boost::bad_lexical_cast, invalid_card_value);
    CardList() = delete;
};

#endif // CARDLIST_HPP
