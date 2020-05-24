#ifndef PROBLEMEDESHUITDAMES_H
#define PROBLEMEDESHUITDAMES_H

#include <iostream> 
#include "./../OP/individu.h"


class ProblemeDesHuitDames {

    public:
        ProblemeDesHuitDames(individu* individu_x);
        void printSolution();

        individu *individu_x;
        void detection_position(int a);
        void generation_echiquier();
        void verification_solution();
        int ** getech();


    private:
        int gene[8][2];
        int **echiquier;
};

#endif
