#include<bits/stdc++.h>


using namespace std;

class Board{
    private:
        int board[12][12];
        set<int> mines;
        int n;
        set<int> validmoves;
        set<int> moves;
        set<int> seen;
    public:
        int plot=0;
        Board(int n,int mine){
            this->n=n;
            // for(int i=0;i<n;i++){
            //     vector<int> temp{n,0};
            //     board.push_back(temp);
                
            // }
            //cout<<"in here"<<endl;
            //cout<<mines.size()<<endl;
            while(mines.size()<mine){
                    srand(time(nullptr));
                    long ran=rand()%(n*n)+1;
                    //cout<<ran<<endl;
                    //cout<<mines.size()<< " size "<<endl;
                    if(mines.find(ran)==mines.end()){
                        //cout<<ran<<" vitore "<<endl;
                        if(mines.size()==0){
                            mines.insert(ran);
                        }
                        mines.insert((int)ran);
                    }else{
                        mines.insert(ran);
                    }
            }
            //cout<<"in here 2"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0; j<n;j++){
                    int count = 0 ;
                    int flag=0;
                    //validmoves.insert(i*n+j+1);
                    if(mines.find(i*n+j+1)!=mines.end()){
                        board[i][j]=9;
                        //cout<<i*n+j+1<<" "<< board[i][j]<<endl;
                        flag=1;
                        
                    }
                    if(flag==0){
                        if(mines.find((i-1)*n+j)!=mines.end()&& i-1>=0 && j-1>=0){
                            count++;
                        }
                        if(mines.find((i-1)*n+j+1)!=mines.end() && i-1>=0){
                            count++;
                        }
                        if(mines.find((i-1)*n+j+2)!=mines.end() && i-1>=0 && j+1<n){
                            count++;
                        }
                        if(mines.find((i)*n+j)!=mines.end() && j-1>=0){
                            count++;
                        }
                        if(mines.find((i)*n+j+2)!=mines.end() && j+1<n){
                            count++;
                        }
                        if(mines.find((i+1)*n+j)!=mines.end() && j-1>=0 && i+1<n){
                            count++;
                        }
                        if(mines.find((i+1)*n+j+1)!=mines.end() && i+1<n){
                            count++;
                        }
                        if(mines.find((i+1)*n+j+2)!=mines.end() && i+1<n && j+1<n){
                            count++;
                        }

                        //cout<<count<<endl;
                        board[i][j]=count;
                        //cout<<i*n+j+1<<" "<< board[i][j]<<endl;
                    }
                }
                
            }
        }

        void setValidMoves(set<int> m){
            validmoves=m;
        }

        set<int> getValidMoves(){
            return validmoves;
        }

        void deleteMove(int move){
            validmoves.erase(move);
        }

        void showBoard(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<board[i][j];
                    if(j!=n-1){ 
                        cout<<" | ";
                    }else{
                        cout<<endl;
                    }
                }
                if(i!=n-1){
                    cout<<"----------------------------------"<<endl;
                }
            }
        }

        void rec(int i,int j){
            if(seen.find(i*n+j+1)!=seen.end()){
                return;
            }
            if(board[i][j]!=9){
                if(moves.find(i*n+j+1)==moves.end() || moves.size()==0){
                    moves.insert(i*n+j+1);
                    deleteMove(i*n+j+1);
                    plot++;
                    
                }
            }
            if(board[i][j]==0 ){
                //cout<<"in here"<<i*n+j+1<<endl;
                
                if(seen.find(i*n+j+1)==seen.end()){
                    seen.insert(i*n+j+1);
                }
                

                if( i-1>=0 && j-1>=0){
                    rec(i-1,j-1);
                }
                if( i-1>=0){
                    rec(i-1,j);
                }
                if(i-1>=0 && j+1<n){
                    rec(i-1,j+1);
                }
                if( j-1>=0){
                    rec(i,j-1);
                }
                if(j+1<n){
                    rec(i,j+1);
                }
                if( j-1>=0 && i+1<n){
                    rec(i+1,j-1);
                }
                if( i+1<n){
                    rec(i+1,j);
                }
                if( i+1<n && j+1<n){
                    rec(i+1,j+1);
                }

            }else{
                return;
            }
        }

        int changeState(int move){
            if(board[(move-1)/n][(move-1)%n]==9){
                return 1;
            }
            moves.insert(move);
            deleteMove(move);
            plot++;
            seen={0};
            rec((move-1)/n,(move-1)%n);
            showRealBoard();
            
            if(plot==n*n-mines.size()){
                return 2;
            }
            return 0;
        }

        void showBomb(){
            cout<<endl<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]!=9){
                        cout<<"  "<<board[i][j]<<" ";
                    }else{
                        cout<<"  "<<"*"<<" ";
                    }
                    


                    if(j!=n-1){ 
                        cout<<" | ";
                    }else{
                        cout<<endl;
                    }
                }
                if(i!=n-1){
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
            }
            cout<<endl<<endl;
        }

        void showRealBoard(){
            cout<<endl<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(moves.find(i*n+j+1)!=moves.end()){
                        cout<<"  "<<board[i][j]<<" ";
                    }else{
                        if(i*n+j+1<10){
                            cout<<" *0"<<i*n+j+1;
                        }else if(i*n+j+1>9 && i*n+j+1<100){
                            cout<<" *"<<i*n+j+1;
                        }else{
                            cout<<"*"<<i*n+j+1;
                        }
                    }
                    


                    if(j!=n-1){ 
                        cout<<" | ";
                    }else{
                        cout<<endl;
                    }
                }
                if(i!=n-1){
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
            }
            cout<<endl<<endl;
        }
};

class Player{
    private:
        set<int> validmoves;
    public:
        Player(int n){
            for(int i=1;i<=n*n;i++){
                validmoves.insert(i);
            }
        }
        bool isValidMove(int move){
            return validmoves.find(move)!=validmoves.end();
        }

        void setValidMoves(set<int> m){
            validmoves=m;
        }

        set<int> getValidMoves(){
            return validmoves;
        }

        int getMove(){
            int move;
            cin>>move;
            while(!isValidMove(move)){
                cout<<"Requesting a valid move"<<endl;
                cin >> move;
            }
            return move;
        }
};



int main(){
    Board b(12,30);
    //b.showBoard();
    cout<<endl;
    b.showRealBoard();
    Player p(12);
    int result;
    while(true){
        b.setValidMoves(p.getValidMoves());
        int move=p.getMove();
        result=b.changeState(move);
        if(result==1){
            b.showBomb();
            cout<<endl<<endl<<"----------------You have lost-------------------"<<endl<<endl;
            break;
        }else if(result==2){
            cout<<endl<<endl<<"----------------You have won-------------------"<<endl<<endl;
            break;
        }
        //b.showRealBoard();
        p.setValidMoves(b.getValidMoves());
    }
}