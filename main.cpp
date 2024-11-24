#include <iostream>
class Room{
    private:
        int N;
        int M;
        int countB;
        int* B;
    
    public:
        ~Room(){
            delete [] B;
        }
        Room():N(5), M(5),countB(0),B(nullptr){}//default-che za kusmet, oh, poludqvam
        Room(int rows, int cols, int countB, const int* broken): N(rows), M(cols){
            if (broken != nullptr) {
                delete [] B;
                B = new int[countB+1];
                int i = 0;
                while (broken != nullptr) { 
                    *B = *broken;
                    B++;
                    broken++;
                    i++;
                }
                //*B=nullptr; zasho ne raboti, of, nevermind, spi mi se
            }

        }

        Room(const Room& other){
            if(this!=&other){
                this->N=other.N;
                this->M=other.M;
                this->countB=other.countB;
                int* broken=other.B;
                if (broken != nullptr) {
                    delete [] B;
                    B = new int[other.countB+1];
                    int i = 0;
                    while (broken != nullptr) { 
                        *B = *broken;
                        B++;
                        broken++;
                        i++;
                    }
                }
            }
        }

        Room& operator=(const Room& other) {
            Room copy(other);
            swap(copy);
            return *this;
            }

        void swap(Room& other) {
            std::swap(N, other.N);
            std::swap(M, other.M);
            std::swap(countB, other.countB);
            std::swap(B, other.B);
        }


        void printBrokenIndexes(){
            if(B!=nullptr){
                std::cout<<"The broken seats' positions are: ";
            }
            while(B!=nullptr){
                std::cout<<*B<<" ";
                B++;
            }
        }

        void printRoomSeats(){
            for (size_t i = 0; i < N; i++)
            {
                for (size_t j = 0; j < M; j++)
                {
                    std::cout<<(j+i*j-1)<<" ";
                }
                std::cout<<std::endl;
            }
            
        }
};


class Simulation{
    private:
        Room room;
        /*std::queue<Student> waiting;
        int currentTime=8;
        Seat* seats;
        Seat* usableSeats;*/

    public:
        Simulation(){
            enterData();
        }

        void enterData(){
            enterRoomData();
        }

        void enterRoomData(){
            std::cout<<"Please enter rows(N), columns(M), lector's lateness(L) and the minutes for grading each work(C): ";
            int N,M,L,C,count;
            std::cin>>N>>M>>L>>C;

            std::cout<<"Please enter the broken seats' count: ";
            std::cin>>count;
            int b[count];

            for (size_t i = 0; i < count; i++)
            {
                std::cin>>b[i];
            }

            this->room=Room(N,M,count,b);
        }



};

void startSimulation(){
    Simulation sim;
}

int main(){
    startSimulation();
    return 0;
}
