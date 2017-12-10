#include "Execfiles.hpp"

int main(int argc, char* argv[]) {
        try {

            sa(argc, argv);
            sll(argc,argv);
            ull(argc, argv);


        }  catch (std::logic_error& e) {
                std::cout << e.what() << std::endl;
        }

}

