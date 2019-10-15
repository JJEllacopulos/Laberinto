#include<iostream>
#include<cstdlib>
#include<string.h>
#include <cstdio>
#include <cstring>
#include<clocale>
#include<ctime>
using namespace std;

#include"Mapas.h"

///procedimental

int main(){

    char map_p[4][4][9][9];

    marco_mapa(map_p);

    asignar_mapa(map_p);

    control_mapa(map_p);

    leer_mapa(map_p);

    return 0;
}
