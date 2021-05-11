#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Scientist& Scientist::discover_cure(Color color){
    Player::discover_cure_by_amount(color,this->DEFAULT_CARDS_AMOUNT);
    return *this;
}
