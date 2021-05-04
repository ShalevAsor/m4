#pragma once

#include <iostream>
#include <unordered_set>

namespace pandemic{

    // class City{
    //     private:
    //         uint color;
    //         //std::unordered_set<std::string> connections; 
    //         uint Disease_dice;
    //         std::string name;
    //         std::unordered_set<std::string> Cards;
    //         bool Resarch_station;

        
    //     public:
    //         // uint color;
    //         // std::unordered_set<std::string> connections; 
    //         // uint Disease_dice;
        

    // };
    

    enum City{
        Algiers,Atlanta,Baghdad,Bangkok,Beijing,Bogota,BuenosAires,Cairo,Chennai,Chicago,Delhi,
        Essen,HoChiMinhCity,HongKong,Istanbul,Jakarta,Johannesburg,Karachi,Khartoum,Kinshasa,
        Kolkata,Lagos,Lima,London,LosAngeles,Madrid,Manila,MexicoCity,Miami,Milan,Montreal,
        Moscow,Mumbai,NewYork,Oska,Paris,Riyadh,SanFrancisco,Santiago,SaoPaulo,Seoul,Shanghai,
        StPetersburg,Sydney,Taipei,Tehran,Tokyo,Washington,TOTAL_CITIES
        
    };
    // City str_to_city(std::string name){
    //     switch(name){
    //         case "Algiers": 
    //             return City::Algiers;
    //             break;
    //     }
    // }
    // uint& operator[] ( const std::string city_name){
    //     return Diseace_dice;
    // }




}
