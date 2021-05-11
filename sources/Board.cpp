#include "Board.hpp"
#include <fstream>
#include <sstream>
//#include <string>
using namespace pandemic;
using namespace std;





const string DEFAULT_CONNECTIONS_FILE="connections.txt";
const string DEFAULT_CITIES_FILE="cities.txt";
const uint DEFAULT_PRINT_SIZE = 15;

/**
 * return refernce of the dices amount in the given City name . 
 */
int& Board::operator[](City name){
    return get<DICES>(this->cities.at(name));
}

/**
 * create the string represents the city data
 */
  string Board::build_city_cube(City city)const{
    string s;
    
    s+='|'+city_to_str(city)+'\n';
    if(get<Board::RS>(this->cities.at(city))){
        s+="|RS:V\n";
    }
    else{
        s+="|RS:X\n";
    }
    s+="|Disease level:"+to_string(get<DICES>(this->cities.at(city)))+'\n';

    return s;


}
/**
 * return the board status- for each city : 
 * 1 - city name
 * 2- station X/V
 * 3- disease dices
 * and the cures that discovered  
 */

ostream& pandemic::operator<<(ostream& op,const Board& board){
    for(const auto& city:board.Cards){
    string s;
    for(int i=0;i<DEFAULT_PRINT_SIZE;i++){
        op<<'_';
        if(i==DEFAULT_PRINT_SIZE-1){op<<"_\n";}
    }
        op<<board.build_city_cube(city);

    
}
    for(int i=0 ; i<DEFAULT_PRINT_SIZE;i++){
        op<<'_';
    }
    op<<"|\n Cures discovered: ";
    for(const auto& cure:board.cures){
        op<<Board::color_to_str(cure)<<'|';
    }
return (op);
}

/**
 * return true iff there is no disease dices in any city on the board. 
 */
bool Board::is_clean(){
    for(const auto& pair:this->cities){
        if(get<DICES>(this->cities.at(pair.first))!=0){return false;}
    }
    return true;
}
/**
 * remove all the cures that discovered 
 */
void Board::remove_cures(){
    this->cures.clear();
}
/**
 * remove all the stations that was build
 */
void Board::remove_stations(){
    for(const auto& pair:this->cities){
        get<RS>(this->cities.at(pair.first)) = false;
    }
}
/**
 * private method that return the City that represented by the given string 
 */
City Board::str_to_city(const string& city){
         if(city=="Algiers"){ return City::Algiers;}
        if(city=="Atlanta"){return City::Atlanta;}
        if(city=="Baghdad"){return  City::Baghdad;}
        if(city=="Bangkok"){return  City::Bangkok;}
        if(city=="Beijing"){return  City::Beijing;}
        if(city=="Bogota"){return City::Bogota;}
        if(city=="BuenosAires"){return  City::BuenosAires;}
        if(city=="Cairo"){return  City::Cairo;}
        if(city=="Chennai"){return  City::Chennai;}
        if(city=="Chicago"){return  City::Chicago;}
        if(city=="Delhi"){return  City::Delhi;}
        if(city=="Essen"){return  City::Essen;}
        if(city=="HoChiMinhCity"){return  City::HoChiMinhCity;}
        if(city=="HongKong"){return  City::HongKong;}
        if(city=="Istanbul"){return City::Istanbul;}
        if(city=="Jakarta"){return  City::Jakarta;}
        if(city=="Johannesburg"){return City::Johannesburg;}
        if(city=="Karachi"){return  City::Karachi;}
        if(city=="Khartoum"){return City::Khartoum;}
        if(city=="Kinshasa"){return  City::Kinshasa;}
        if(city=="Kolkata"){return City::Kolkata;}
        if(city=="Lagos"){return City::Lagos;}
        if(city=="Lima"){return City::Lima;}
        if(city=="London"){return  City::London;}
        if(city=="LosAngeles"){return City::LosAngeles;}
        if(city=="Madrid"){return City::Madrid;}
        if(city=="Manila"){return City::Manila;}
        if(city=="MexicoCity"){return City::MexicoCity;}
        if(city=="Miami"){return City::Miami;}
        if(city=="Milan"){return City::Milan;}
        if(city=="Montreal"){return  City::Montreal;}
        if(city=="Moscow"){return City::Moscow;}
        if(city=="Mumbai"){return  City::Mumbai;}
        if(city=="NewYork"){return  City::NewYork;}
        if(city=="Osaka"){return  City::Osaka;}
        if(city=="Paris"){return  City::Paris;}
        if(city=="Riyadh"){return  City::Riyadh;}
        if(city=="SanFrancisco"){return  City::SanFrancisco;}
        if(city=="Santiago"){return  City::Santiago;}
        if(city=="SaoPaulo"){return City::SaoPaulo;}
        if(city=="Seoul"){return City::Seoul;}
        if(city=="Shanghai"){return  City::Shanghai;}
        if(city=="StPetersburg"){return City::StPetersburg;}
        if(city=="Sydney"){return City::Sydney;}
        if(city=="Taipei"){return City::Taipei;}
        if(city=="Tehran"){return  City::Tehran;}
        if(city=="Tokyo"){return City::Tokyo;}
        if(city=="Washington"){return  City::Washington;}
        return City::TOTAL_CITIES;
    }
    
    string Board::city_to_str(const City& city){
         if(city==City::Algiers){return "Algiers";}
        if(city==City::Atlanta){return "Atlanta";}
        if(city==City::Baghdad){return "Baghdad" ;}
        if(city==City::Bangkok){return  "Bangkok";}
        if(city==City::Beijing){return  "Beijing";}
        if(city==City::Bogota){return "Bogota" ;}
        if(city==City::BuenosAires){return "BuenosAires";}
        if(city==City::Cairo){return "Cairo";}
        if(city==City::Chennai){return "Chennai";}
        if(city==City::Chicago){return "Chicago";}
        if(city==City::Delhi){return  "Delhi";}
        if(city==City::Essen){return  "Essen";}
        if(city==City::HoChiMinhCity){return "HoChiMinhCity";}
        if(city==City::HongKong){return  "HongKong";}
        if(city==City::Istanbul){return "Istanbul";}
        if(city==City::Jakarta){return "Jakarta";}
        if(city==City::Johannesburg){return "Johannesburg";}
        if(city==City::Karachi){return "Karachi";}
        if(city==City::Khartoum){return "Khartoum";}
        if(city==City::Kinshasa){return "Kinshasa";}
        if(city==City::Kolkata){return "Kolkata";}
        if(city==City::Lagos){return "Lagos";}
        if(city==City::Lima){return "Lima";}
        if(city==City::London){return "London";}
        if(city==City::LosAngeles){return "LosAngeles";}
        if(city==City::Madrid){return "Madrid";}
        if(city==City::Manila){return "Manila" ;}
        if(city==City::MexicoCity){return "MexicoCity";}
        if(city==City::Miami){return "Miami";}
        if(city==City::Milan){return "Milan";}
        if(city==City::Montreal){return  "Montreal";}
        if(city==City::Moscow){return "Moscow";}
        if(city==City::Mumbai){return  "Mumbai";}
        if(city==City::NewYork){return "NewYork";}
        if(city==City::Osaka){return "Osaka";}
        if(city==City::Paris){return "Paris";}
        if(city==City::Riyadh){return "Riyadh";}
        if(city==City::SanFrancisco){return "SanFrancisco";}
        if(city==City::Santiago){return "Santiago";}
        if(city==City::SaoPaulo){return "SaoPaulo";}
        if(city==City::Seoul){return "Seoul";}
        if(city==City::Shanghai){return "Shanghai";}
        if(city==City::StPetersburg){return "StPetersburg";}
        if(city==City::Sydney){return "Sydney";}
        if(city==City::Taipei){return "Taipei";}
        if(city==City::Tehran){return  "Tehran";}
        if(city==City::Tehran){return "Tokyo";}
        if(city==City::Washington){return "Washington";}
        return "Washington";
    }
    



/**
 * private method - return the Color represented by the given string 
 */
    Color Board::str_to_color(const string& color){

    if(color=="Black"){return Color::Black;}
    if(color=="Blue"){return  Color::Blue;}
    if(color=="Yellow"){return Color::Yellow;}
    if(color=="Red"){return Color::Red;}
    return Color::TOTAL_COLORS;

    }
     string Board::color_to_str(const Color color){

    if(color==Color::Black){return "Black";}
    if(color==Color::Blue){return  "Blue";}
    if(color==Color::Yellow){return "Yellow";}
    if(color==Color::Red){return "Red";}
    return "Black";

    }

  


Board::Board(){
    
    ifstream cities_file{DEFAULT_CITIES_FILE};
    ifstream connections_file{DEFAULT_CONNECTIONS_FILE};
    string city;
    string color;
    string line;
    string connection;
    
    // int i =  0; 
    while(cities_file >>city>>color){ // init each city to to her color
        City temp =str_to_city(city);
        this->cities[temp]=make_tuple(str_to_color(color),false,0); // by default - false mean no Research station 
        // 0 - no disease dices 
        this->Cards.insert(temp); // add that city to the cards . 
    }
    for(const auto& city:this->Cards){ // accesses to all the cities in the board
        getline(connections_file,line);// get line by line from the connections_file 
        istringstream iss(line);
        do{
            iss>>connection; // get city by city 
           this->connections[city].insert(str_to_city(connection));//add to the connections map 
        }while(iss);
    }
}

