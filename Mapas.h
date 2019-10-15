#ifndef MAPAS_H_INCLUDED
#define MAPAS_H_INCLUDED



bool puerta(int w, int x, int y, int z){
    if(w == 0){
        if(y == 0){
            return false;
        }
    }
    if(w == 3){
        if(y == 8){
            return false;
        }
    }
    if(x == 0){
        if(z == 0){
            return false;
        }
    }
    if(x == 3){
        if(z == 8){
            return false;
        }
    }

    return true;
}

void marco_submapa(char map_p[4][4][9][9], int w, int x){

    int y, z;

    for(y=0; y<9; y++){
        for(z=0; z<9; z++){

            if(y == 0 || y == 8 || z == 0 || z == 8){
                if(y == 4 || z == 4){
                    if(puerta(w,x,y,z)){
                        map_p[w][x][y][z] = 'A';
                    }
                    else{
                        map_p[w][x][y][z] = 'x';
                    }
                }
                else{
                    map_p[w][x][y][z] = 'x';
                }
            }
            else{
                map_p[w][x][y][z] = '0';
            }
        }
    }

}

void marco_mapa(char map_p[4][4][9][9]){

    int w, x, y, z;

    for(w=0; w<4; w++){
        for(x=0; x<4; x++){
            marco_submapa(map_p, w, x);
        }
    }
}

void armar_camino(char map_p[4][4][9][9],int w,int x,int y,int z){

    int mov;
    int direccion;

    bool key2 = false;
    bool key = true;

    srand(time(0));

    for(mov=0; mov<20; mov++){

        int direccion;

        while(key){

            direccion = ((rand() +w+x) % 3);
            switch(direccion){
                case 0: ///Arriba
                    if((y - 1) > 0){
                        if(map_p[w][x][y-1][z] != 'x' && map_p[w][x][y-1][z] != 'A'){

                            map_p[w][x][y-1][z] = ' ';
                            y--;
                            key = false;
                        }
                    }
                break;
                case 1: ///Abajo
                    if((y + 1) < 8){
                        if(map_p[w][x][y+1][z] != 'x' && map_p[w][x][y+1][z] != 'A'){

                            map_p[w][x][y+1][z] = ' ';
                            y++;
                            key = false;
                        }
                    }
                break;
                case 2: ///Izquierda
                    if((z - 1) > 0){
                        if(map_p[w][x][y][z-1] != 'x' && map_p[w][x][y-1][z] != 'A'){
                            map_p[w][x][y][z-1] = ' ';
                            z--;
                            key = false;
                        }
                    }
                break;
                case 3: ///Derecha
                    if((z + 1) < 8){
                        if(map_p[w][x][y][z+1] != 'x' && map_p[w][x][y+1][z] != 'A'){
                            map_p[w][x][y][z+1] = ' ';
                            z++;
                            key = false;
                        }
                    }
                break;
            }

            if(key2){
                key = false;
            }
            key2 = true;

        }

        key2 = false;
        key = true;
    }

}

void asignar_mapa(char map_p[4][4][9][9]){


    int w, x, y, z;

    for(w=0; w<4; w++){
        for(x=0; x<4; x++){
            for(y=0; y<9; y++){
                for(z=0; z<9; z++){
                    if(map_p[w][x][y][z] == 'A'){
                        armar_camino(map_p, w, x, y, z);
                    }
                }
            }
        }
    }
}

void borrar_bloques_aislados(char map_p[4][4][9][9],int w,int x,int y,int z){

    if(map_p[w][x][y+1][z] == ' '){
        if(map_p[w][x][y-1][z] == ' '){
            if(map_p[w][x][y][z+1] == ' '){
                if(map_p[w][x][y][z-1] == ' '){
                    map_p[w][x][y][z] = ' ';
                }
            }
        }
    }

}

void control_mapa(char map_p[4][4][9][9]){

    int w, x, y, z;

    for(w=0; w<4; w++){
        for(x=0; x<4; x++){
            for(y=0; y<9; y++){
                for(z=0; z<9; z++){
                    if(map_p[w][x][y][z] == '0'){
                        borrar_bloques_aislados(map_p, w, x, y, z);
                    }
                }
            }
        }
    }
}

void leer_mapa(char map_p[4][4][9][9]){

    int w, x, y, z;

    for(w=0; w<4; w++){
        for(y=0; y<9; y++){
            for(x=0; x<4; x++){
                for(z=0; z<9; z++){
                    cout<< map_p[w][x][y][z];
                }
                cout<< " ";
                //cout<< endl;
            }

            cout<< endl;
        }

        cout<< endl;
    }

}

#endif // MAPAS_H_INCLUDED
