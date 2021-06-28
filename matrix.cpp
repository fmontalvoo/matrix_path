#include<stdio.h>

int cantidad_de_pasos = 0;

int opt = -1, rows = 0, cols = 0, x = 10001;

int **matrix;
int *m, *arr, *pos;

void create_matrix(){
    matrix = new int*[rows];
    for(int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            matrix[row][col] = 0;
        }
    }
}

void enumerate_positions(){
    arr = new int[x];
    pos = new int[x];

    for(int i = 0; i < x; i++)
        arr[i] = (i+1);

    for(int j = 0; j < x; j++)
        pos[j] = j;

}

void display_matrix(){
    printf("\n");
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            printf("[%d]", matrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrix_to_array(){
    m = new int[rows*cols];
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            m[col+row*cols] = matrix[row][col];
        }
    }
}

void array_to_matrix(){
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            matrix[row][col] = m[col+row*cols];
        }
    }
}

void go_forward(){
    int sum = 0;
    int total = rows*cols;

    for(int i = 0; i < total; i++)
         m[i] = 0;

    for(int i = 0; i < x; i++){
        sum = pos[i] + cantidad_de_pasos;
        if(sum >= total)
            pos[i] = sum - total;
        else
            pos[i] = sum;
        m[pos[i]] = arr[i];
    }
    array_to_matrix();
}

void go_backward(){
    int res = 0;
    int total = rows*cols;

    for(int i = 0; i < total; i++)
         m[i] = 0;

    for(int i = 0; i < x; i++){
        res = pos[i] - cantidad_de_pasos;
        if(res < 0)
            pos[i] = res + total;
        else
            pos[i] = res;
        m[pos[i]] = arr[i];
    }
    array_to_matrix();
}

int main(){
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &rows);

    if(rows > 100){
        while(rows > 100){
            printf("No puede ingresar mas de 100 filas\n");
            printf("Ingrese la cantidad de filas: ");
            scanf("%d", &rows);
        }
    }

    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &cols);

    if(cols > 100){
        while(rows > 100){
            printf("No puede ingresar mas de 100 columnas\n");
            printf("Ingrese la cantidad de columnas: ");
            scanf("%d", &cols);
        }
    }

    create_matrix();
    matrix_to_array();

    printf("Cuantas posiciones numerar: ");
    scanf("%d", &x);

    int total = rows*cols;
    if(x > total){
       while(x > total){
            printf("No puede numerar mas de %d posiciones.\n", total);
            printf("Cuantas posiciones numerar: ");
            scanf("%d", &x);
        }
    }

    enumerate_positions();
    go_forward();
    display_matrix();

    while(opt != 0){
        printf("Escoga una direccion\n");
        printf("1. Ir hacia adelante\n");
        printf("2. Ir hacia atras\n");
        printf("0. Salir del programa\n");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                printf("Ingrese la cantidad de pasos a desplazar: ");
                scanf("%d", &cantidad_de_pasos);
                go_forward();
                display_matrix();
            break;

            case 2:
                printf("Ingrese la cantidad de pasos a desplazar: ");
                scanf("%d", &cantidad_de_pasos);
                go_backward();
                display_matrix();
            break;

            case 0:
                printf("Adios...");
            break;

            default:
                printf("No existe esa opcion.\n");
        }

    }

    return 0;
}
