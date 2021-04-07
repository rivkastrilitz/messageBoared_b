#include "Board.hpp"
#include "Direction.hpp"
#include <string>


using std::string;
using std::cout;
using std::map;


using ariel::Direction;

    u_int left_limit;
    u_int right_limit;
    u_int up_limit;
    u_int down_limit;
    
    u_int ziro=0;
    u_int one=1;
    u_int maximum=ziro-one;
    

    // initialize bound of board
    ariel::Board::Board(){
        left_limit=maximum;
        right_limit=0;
        up_limit=maximum;
        down_limit=0;
        
    }

    void ariel::Board::update_limits(u_int row,u_int col,Direction d,u_int n){

        if(d==Direction::Horizontal){

            if(col<left_limit){
            left_limit=col;
            }
            if(col+n-1>right_limit){
            right_limit= col+n-1;
            }

            if(row > down_limit){
            down_limit=row;
            }
            if(row<up_limit){
            up_limit=row;
            }  
        }else{

            if(col<left_limit){
            left_limit=col;
            }
            if(col>right_limit){
            right_limit= col;
            }

            if(row +n-1> down_limit){
            down_limit=row+n-1;
            }
            if(row<up_limit){
            up_limit=row;
            }

        }  
    }


    void ariel::Board::post(u_int row ,u_int col, Direction d, const string & s){
        u_int n=s.length();
        
        for(u_int i=0;i<n;i++){
            if(d==Direction::Horizontal){
               string pos=to_string(row).append(",").append(to_string(col+i));;
                board_mp[pos]=s.at(i);
                ariel::Board::update_limits(row,col,d,n);
               
            }else{
                string pos=to_string(row+i).append(",").append(to_string(col));
                board_mp[pos]=s.at(i);
                ariel::Board::update_limits(row,col,d,n);

            }
            
        }

    }

    string ariel::Board::read(u_int row ,u_int col, Direction d,u_int n){
        
        string s;
        string pos;
        
        for(u_int i=0;i<n;i++){
            
            if(d==Direction::Horizontal){
                pos=to_string(row).append(",").append(to_string(col+i));
                
            }else{
                pos=to_string(row+i).append(",").append(to_string(col));  
            }
            
            // apend a char to the end of the string 
            if(board_mp.find(pos)==board_mp.end()){
                s+='_';
            }else{
              s+=board_mp.at(pos);
            } 
             
            
        }
        
        return s;
    }

    void ariel::Board::show () const {
        for(u_int i=up_limit;i<=down_limit;i++){
            for(u_int j=left_limit;j<=right_limit;j++){
                string pos=to_string(i).append(",").append(to_string(j));
                string end=to_string(down_limit).append(",").append(to_string(right_limit));
                if(board_mp.find(pos)==board_mp.end()){
                    cout<<"_";

                }else{
                    cout<<board_mp.at(pos);
                }
            }
            cout<<endl;
        }
        if(board_mp.empty()){
                cout<<"___\n___"<<endl;
        } 
       
    }
