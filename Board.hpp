#pragma once
#include "Direction.hpp"
#include <string>

// for the map
#include <bits/stdc++.h>

using namespace std;

namespace ariel{
     
    class Board{
        private:
            map<string,char> board_mp;

        //constactor
        public:
            Board();
            
        void update_limits(u_int row,u_int col,Direction d,u_int n);
        void post(u_int row ,u_int col, ariel::Direction d, const string & s);
        string read(u_int row ,u_int col, ariel::Direction d,u_int n);
        void show() const ;
        
        

    };
}
