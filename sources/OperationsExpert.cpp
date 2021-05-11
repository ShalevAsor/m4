#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;


OperationsExpert& OperationsExpert::build(){
    get<Board::RS>(this->board.cities.at(this->position))=true;
    return *this;
}


