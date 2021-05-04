#include "Board.hpp"
#include <fstream>
using namespace pandemic;
using namespace std;

const string DEFAULT_FILE_NAME="cities_map.txt";
//void Board::read(){
    // string city_name;
    // string color;
    // ifstream Cities_in_game(DEFAULT_FILE_NAME);
    // if(!Cities_in_game){cout<<"file error";}
    // while(true){
    //     char c;
    //     if(Cities_in_game.eof()){break;}
    //     Cities_in_game>>city_name>>color>>c;
    //     string s; 
    //     this->City_color[city_name]=color;
    //     this->Connections[city_name].insert(s);
    //     //char c;
    //     if(c=='\n'){
            
    //     }

        
        //char c; 

        
    //}

    
//}
uint& Board::operator[](City name){
    return this->Disease_dice[name];
}

ostream& pandemic::operator<<(ostream& op,const Board& board){
    return (op<<" ");
}
bool Board::is_clean(){
    return false;
}
void Board::remove_cures(){
    
}
void Board::remove_stations(){
    
}

Board::Board(){
    
}

