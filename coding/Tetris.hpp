#include <iostream>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"

namespace GameBoy{
    class Tetris{ 

        public:
            int Run();
            bool check();


        private:
            const int M = 20;
            const int N = 10;

            int field[20][10] = {0};

            struct Point
            {int x,y;} a[4], b[4];

            int figures[7][4] =
            {
                1,3,5,7, // I
                2,4,5,7, // Z
                3,5,4,6, // S
                3,5,4,7, // T
                2,3,5,7, // L
                3,5,7,6, // J
                2,3,4,5, // O
            };

            bool escapeButtonStatus = false;
            bool pause = false;
            unsigned score = 0;
    };
}