#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include "doctest.h"
#include <random>
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"


using namespace pandemic;
using namespace std;

void create_board(Board& b,uint seed,uint sum_of_cities){
    unordered_set<uint> city_visited;
   
    uint i = 0;
    while(i<sum_of_cities){
        
    //Color color = static_cast<Color>(rand()%TOTAL_COLORS); 
    City city = static_cast<City>(rand()%TOTAL_CITIES);
    uint cards = (uint)rand()%seed;
    if(city_visited.find(city)==city_visited.end()){
        b[city]=cards;
        i++;
    }
    
    
    }
    
     
    //b[City::]
    

}

City int_to_city(int val){
        
        switch (val)
        {
        case City::Algiers:
            return City::Algiers;
        case City::Atlanta:
            return City::Atlanta;
        case City::Baghdad:
            return City::Baghdad;
        case City::Bangkok:
            return City::Bangkok;
        case City::Beijing:
            return City::Beijing;
        case City::Bogota:
            return City::Bogota;
        case City::BuenosAires:
            return City::BuenosAires;
        case City::Cairo:
            return City::Cairo;
        case City::Chennai:
            return City::Chennai;
        case City::Chicago:
            return City::Chicago;
        case City::Delhi:
            return City::Delhi;
        case City::Essen:
            return City::Essen;
        case City::HoChiMinhCity:
            return City::HoChiMinhCity;
        case City::HongKong:
            return City::HongKong;
        case City::Istanbul:
            return City::Istanbul;
        case City::Jakarta:
            return City::Jakarta;
        case City::Johannesburg:
            return City::Johannesburg;
        case City::Karachi:
            return City::Karachi;
        case City::Khartoum:
            return City::Khartoum;
        case City::Kinshasa:
            return City::Kinshasa;
        case City::Kolkata:
            return City::Kolkata;
        case City::Lagos:
            return City::Lagos;
        case City::Lima:
            return City::Lima;
        case City::London:
            return City::London;
        case City::LosAngeles:
            return City::LosAngeles;
        case City::Madrid:
            return City::Madrid;
        case City::Manila:
            return City::Manila;
        case City::MexicoCity:
            return City::MexicoCity;
        case City::Miami:
            return City::Miami;
        case City::Milan:
            return City::Milan;
        case City::Montreal:
            return City::Montreal;
        case City::Moscow:
            return City::Moscow;
        case City::Mumbai:
            return City::Mumbai;
        case City::NewYork:
            return City::NewYork;
        case City::Oska:
            return City::Oska;
        case City::Paris:
            return City::Paris;
        case City::Riyadh:
            return City::Riyadh;
        case City::SanFrancisco:
            return City::SanFrancisco;
        case City::Santiago:
            return City::Santiago;
        case City::SaoPaulo:
            return City::SaoPaulo;
        case City::Seoul:
            return City::Seoul;
        case City::Shanghai:
            return City::Shanghai;
        case City::StPetersburg:
            return City::StPetersburg;
        case City::Sydney:
            return City::Sydney;
        case City::Taipei:
            return City::Taipei;
        case City::Tehran:
            return City::Tehran;
        case City::Tokyo:
            return City::Tokyo;
        case City::Washington:
            return City::Washington;
        default:
            break;
        }
        return City::Algiers;
        
    }
// test Board 
TEST_CASE("test -is_clean and operator[]"){
    Board b;
    CHECK(b.is_clean()==true);
    create_board(b,6,48);
    CHECK(b.is_clean()==false);
    Board c;
    c[City::Algiers]=1;
    CHECK(c[City::Algiers]==1);
    c[City::Baghdad]=4;
    CHECK(c[City::Baghdad]==4);
    c[City::Baghdad]=0;
    CHECK(c[City::Baghdad]==0);
    CHECK_NOTHROW(create_board(c,5,20));

}
TEST_CASE("player-OperationsExpert"){
    Board b;
    size_t cities_amount = 10;
    string role = "OperationsExpert";
    create_board(b,1,cities_amount);//init b to 10 cities with 0 disease dices
    OperationsExpert oe(b,City::Algiers);
    CHECK(oe.role()==role);
    CHECK_NOTHROW(oe.build());//build research station in Algiers
    
    //oe has no cards yet but he can build without cards
    for(size_t i=1;i<cities_amount;i++){
        oe.take_card(int_to_city(i));
        CHECK_NOTHROW(oe.fly_direct(int_to_city(i)));//throw the card
        CHECK_NOTHROW(oe.build());
        CHECK_NOTHROW(oe.build());//shouldnt do antything
        

    }
    cities_amount=47;
    for(size_t i=0;i<cities_amount;i++){ // take all the cards twice 
        CHECK_NOTHROW(oe.take_card(int_to_city(i)).take_card(int_to_city(i+1)));
    }
    CHECK_NOTHROW(oe.fly_direct(City::Baghdad));
    CHECK_THROWS(oe.fly_direct(City::Baghdad));// oe already in baghdad
    oe.take_card(City::Baghdad);
    
    //verify that oe can fly shuttle between the cities above 
    cities_amount = 10;
    for(size_t i = 1;i<cities_amount;i++){
        CHECK_NOTHROW(oe.fly_shuttle(int_to_city(i)));
    }
    oe.take_card(City::Algiers);
    oe.fly_direct(City::Algiers);
    b[City::Algiers]=4;
    CHECK(b.is_clean()==false);
    oe.treat(City::Algiers).treat(City::Algiers).treat(City::Algiers).treat(City::Algiers);// - 4 dices
    CHECK(b.is_clean()==true);
    CHECK_THROWS(oe.treat(City::Algiers)); 

}

TEST_CASE("Player-Dispatcher"){
    Board b;
    size_t cities_amount = 10;
    string role = "Dispatcher";
    create_board(b,1,cities_amount);//init b to 10 cities with 0 disease dices
    Dispatcher ds(b,City::Algiers);
    CHECK(ds.role()==role);
    CHECK_THROWS(ds.build());//build research station in Algiers but has no cards
    
    ds.take_card(City::Algiers);
    for(size_t i=1;i<cities_amount;i++){
        ds.take_card(int_to_city(i));
        CHECK_NOTHROW(ds.fly_charter(int_to_city(i)));//throw the card
        ds.take_card(int_to_city(i));//take the card again
        CHECK_NOTHROW(ds.build());
        CHECK_NOTHROW(ds.build());//shouldnt do antything
    }
    //ds has no cards at this point 
    for(size_t i=0;i<cities_amount;i++){ // take all the cards twice 
        CHECK_NOTHROW(ds.fly_direct(int_to_city(i)));
        CHECK_THROWS(ds.fly_direct(int_to_city(i)));//already in that city
    }
    
    
    //verify that oe can fly shuttle between the cities above 
    
    ds.take_card(City::NewYork);
    ds.fly_direct(City::NewYork);
    b[City::NewYork]=1;
    CHECK(b.is_clean()==false);
    ds.treat(City::Algiers);// - 1 dices
    CHECK(b.is_clean()==true);
    CHECK_THROWS(ds.treat(City::NewYork));
    //drive from NewYork to Washington 
    CHECK_NOTHROW(ds.drive(City::Washington));
}

TEST_CASE("Player-Scientist"){
    Board b;
    uint n = 1;
    Scientist sc(b,City::Algiers,n);
    sc.take_card(City::Algiers);
    CHECK_NOTHROW(sc.discover_cure(Color::Black));//discover cure with 1 black card only
    CHECK_THROWS(sc.discover_cure(Color::Blue));//no blue cards - should throw exception
    sc.take_card(City::Algiers);
    CHECK_NOTHROW(sc.discover_cure(Color::Black));//already discover that cure - dont do anything
    CHECK_NOTHROW(sc.drive(City::Madrid));//Drive to Madrid
    CHECK_NOTHROW(sc.fly_direct(City::Algiers));//verify that Algires card didnt throwed
    n = 3 ; 
    b[City::Madrid]=4;//4 disease dices in Madrid (Blue city)
    Scientist sc2(b,City::Madrid,n);
    sc2.take_card(City::Madrid);
    sc2.build();
    sc2.take_card(City::Montreal);//blue card 
    sc2.take_card(City::NewYork);//blue card
    CHECK_THROWS(sc2.discover_cure(Color::Blue));//only 2 blue cards - cost 3 
    sc2.take_card(City::Washington);
    CHECK_NOTHROW(sc2.discover_cure(Color::Blue));//3 blue cards 
    CHECK(b.is_clean()==false);
    sc2.treat(City::Madrid);
    CHECK(b[City::Madrid]==0);
    CHECK_THROWS(sc2.treat(City::Madrid));//should throw exceptions - Madris is clean 
    CHECK(b.is_clean()==true);

}

TEST_CASE("Player-Researcher"){
    Board b;
    b[City::Tokyo]=5;
    Scientist res(b,City::Algiers);
    string role = "Researcher";
    CHECK(res.role()==role);
    CHECK_THROWS(res.discover_cure(Color::Red));//no red cards
    res.take_card(City::Bangkok).take_card(City::Beijing).
    take_card(City::HongKong).take_card(City::Jakarta);//4 red cards 
    CHECK_THROWS(res.discover_cure(Color::Red));//need 5 red cards
    res.take_card(City::Algiers);//1 blue card
    CHECK_THROWS(res.discover_cure(Color::Red));//need 5 red cards - has only 4 red and 1 blue 
    res.take_card(City::Oska);
    CHECK_NOTHROW(res.discover_cure(Color::Red));//can discover cure without Research-station
    CHECK_THROWS(res.fly_direct(City::Bangkok));//Bangkok card already discarded 
    CHECK_NOTHROW(res.fly_charter(City::Tokyo)); // fly from Algiers to Tokyo
    CHECK_NOTHROW(res.treat(City::Tokyo));
    CHECK(b[City::Tokyo]==0);//discovered Red cure 

}

TEST_CASE("Player-Medic"){
    Board b;
    b[City::Algiers]=3;
    b[City::Cairo]=5;
    b[City::Mumbai]=4;
    b[City::Seoul]=2;
    Medic med(b,City::Bogota);
    string role = "Medic";
    CHECK(med.role()==role);
    b[City::Bogota]=1;
    med.treat(City::Bogota);
    CHECK(b[City::Bogota]==0);
    b[City::Bogota]=4;
    med.treat(City::Bogota);// should discarded all disease dices in the city
    CHECK(b[City::Bogota]==0);
    CHECK_THROWS(med.treat(City::Cairo));//med is in Bogota
    uint n = 1; 
    Scientist sc(b,City::Chicago,n);
    sc.take_card(City::Chicago);
    CHECK_NOTHROW(sc.build());// build research station in Chicago
    CHECK_NOTHROW(sc.discover_cure(Color::Black));
    med.take_card(City::Algiers);
    CHECK(b[City::Algiers]==3);
    CHECK_NOTHROW(med.fly_direct(City::Algiers));
    CHECK(b[City::Algiers]==0);//med is in Algiers and cure has discovered
    CHECK(b[City::Cairo]==5);
    CHECK_NOTHROW(med.drive(City::Cairo));
    CHECK(b[City::Cairo]==0);
    CHECK_THROWS(med.fly_charter(City::Mumbai));//med dont have Cairo card
    med.take_card(City::Cairo);
    CHECK(b[City::Mumbai]==4);
    CHECK_NOTHROW(med.fly_charter(City::Mumbai));
    CHECK(b[City::Mumbai]==0);
    med.take_card(City::Seoul);
    CHECK_NOTHROW(med.fly_direct(City::Seoul));
    CHECK(b[City::Seoul]==2);//seoul is a red city 

}

TEST_CASE("Player-Virologist"){
    Board b;
    Virologist vi(b,City::Taipei);
    string role = "Virologist";
    CHECK(vi.role()==role);
    b[City::Taipei]=1;
    CHECK_THROWS(vi.treat(City::Tehran));//no Tehran card
    CHECK_NOTHROW(vi.treat(City::Taipei)); // vi is in Taipei
    CHECK(b[City::Taipei]==0);
    vi.take_card(City::Tehran);
    b[City::Tehran]=3;
    CHECK_NOTHROW(vi.treat(City::Tehran));
    CHECK(b[City::Tehran]==2);
    CHECK_THROWS(vi.fly_direct(City::Tehran));//no Tehran card
    CHECK_THROWS(vi.treat(City::Sydney));//no sydney card
    vi.take_card(City::Sydney);
    CHECK_THROWS(vi.treat(City::Sydney));//sydney has no disease dices 
    b[City::Sydney]=2;
    CHECK_NOTHROW(vi.fly_charter(City::Sydney));
    vi.treat(City::Sydney).treat(City::Sydney).treat(City::Sydney);
    CHECK(b[City::Sydney]==0);
}

TEST_CASE("Player-GeneSplicer"){
    Board b;
    b[City::Bogota]=3;
    GeneSplicer gen(b,City::NewYork);
    string role = "GeneSplicer";
    CHECK(gen.role()==role);
    CHECK_THROWS(gen.discover_cure(Color::Yellow));//dont have a research station and enough cards 
    CHECK_THROWS(gen.build());//gen doesnt have NewYork card
    gen.take_card(City::NewYork);
    CHECK_NOTHROW(gen.build());
    CHECK_THROWS(gen.discover_cure(Color::Yellow));//no enough cards
    gen.take_card(City::Sydney).take_card(City::Taipei).take_card(City::Oska).take_card(City::Tokyo);
    CHECK_THROWS(gen.discover_cure(Color::Yellow));//need more 1 card 
    gen.take_card(City::HongKong);
    CHECK_NOTHROW(gen.discover_cure(Color::Yellow));//5 red cards 
    CHECK_THROWS(gen.fly_direct(City::HongKong));//dont have HongKong card 
    gen.take_card(City::Bogota);
    CHECK_NOTHROW(gen.fly_direct(City::Bogota));
    CHECK(b[City::Bogota]==3);
    gen.treat(City::Bogota);
    CHECK(b[City::Bogota]==0);
    gen.take_card(City::Atlanta).take_card(City::Essen).take_card(City::London).take_card(City::Madrid).take_card(City::Istanbul);//4 blue cards 1 red
    CHECK_NOTHROW(gen.discover_cure(Color::Black));

    
}

TEST_CASE("Player-Field-Doctor"){
    Board b;
    FieldDoctor fd(b,City::Paris);
    string role = "Field-Doctor";
    CHECK(fd.role()==role);
    b[City::London]=3;
    CHECK(b[City::London]==3);
    fd.treat(City::London);
    CHECK(b[City::London]==2);
    uint n = 1; 
    Scientist sc(b,City::Chicago,n);
    sc.take_card(City::Chicago);
    CHECK_NOTHROW(sc.build());// build research station in Chicago
    CHECK_NOTHROW(sc.discover_cure(Color::Blue));
    fd.treat(City::London);
    CHECK(b[City::London]==0);
    b[City::Milan]=3;
    CHECK(b[City::Milan]==3);
    fd.treat(City::Milan);
    CHECK(b[City::Milan]==0);

}

