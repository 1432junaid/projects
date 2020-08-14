#include<iostream>
using namespace std;
namespace game{

    void play();
    void how_to_play();
    void who_smart_menu();

    void who_smart_menu(){
        cout << "\n\n\n\n\n\n\n\n";
        cout << "*******Welcome to the game [who is smart]*********\n"<<endl;
        cout << " 1. play\n";
        cout << " 2. how to play\n";
        cout << " 3. exit\n\n\n\n";
        int choice;
        while(1){
            cin >> choice;
            if(choice == 1){
                play();
            }else if(choice == 2 ){
                how_to_play();
            }else if(choice ==3 ){
                cout << "\n\n\n\n\n!!bye-bye\n\n\n";
                exit(0);
            }
        }
    }
    void how_to_play(){
        cout << "In this game we have two playes " << endl;
        cout << "there is a targate number " << endl;
        cout << "for example :  targate = 5" << endl;
        cout << "both player can take less than or equal to 3 consecutive number\n";
        cout << "for example :" << endl;
        cout << "targate = 5\n";
        cout << "player1 = 1\n";
        cout << "player2 = 2 ,3 ,4\n";
        cout << "player1 = 5\n";
        cout << "so the player 1 reached the target \n";
        cout << "player one winner\n\n\n\n"; 
        char choice;
        cout<< "go back to menu..........y/n:";
        cin >> choice;
        if(choice == 'N' || choice == 'n')exit(0);
        else who_smart_menu();
        
    }

    void play(){
//        int targate = get_random(5,20);
        int targate = rand()%10 + 5;
        int player1 = 0;
        int player2 = 0;
        int count = 0;
        cout << "Targate : " << targate <<endl << endl << endl;
        for(int i =0;i<targate;i++){
            
            cout << "player1 :how many number wolud you like to take :";
            try{
                cin >> player1;
                if(player1 > 3)throw()
            }
            count += player1;
            if(count >= targate){
                cout << "Player 1 winner\n\n\n\n";
                char choice;
                cout<< "go back to menu..........y/n:";
                cin >> choice;
                if(choice == 'N' || choice == 'n')exit(0);
                else who_smart_menu();
            }
            
            cout << "player2 :how many number would you like to take :";
            cin >> player2;
            
            count += player2;
            if(count >= targate){
                cout << "Player 2 winner \n\n\n\n";
                char choice;
                cout<< "go back to menu..........y/n:";
                cin >> choice;
                if(choice == 'N' || choice == 'n')exit(0);
                else who_smart_menu();
            }
        }

    }

//    int get_random(int lower,int upper){
  //      return  (int)( (rand() % (upper - lower+1 ) )+ lower);
  //  }

/*    
    class player{
        private:
        int x,y,z;
        public:
        player(){
            cout << "Please Enter min 1 or max 3 numbers:\n";
        }
        player(int x){
            this->x = x;
        }
        player(int x , int y){
            this->x = x;
            this->y = y;
        }
        player(int x,int y,int z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
    };

*/   
}