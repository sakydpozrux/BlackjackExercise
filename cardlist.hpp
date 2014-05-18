#ifndef CARDLIST_HPP
#define CARDLIST_HPP

#include <list>
#include <string>

class CardList
{
private:
    std::list<int> cards;

public:
    CardList(const std::list<int>& list_of_ints);
    CardList(const std::string& input_str);
    unsigned int size() const;

private:
    std::list<int> init_cards(const std::string& input_str);
    CardList() = delete;
};

#endif // CARDLIST_HPP
