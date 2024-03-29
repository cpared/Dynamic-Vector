#include "vector.h"

// Funciones del alumno.

void vector_destruir(vector_t* vector){
    free(vector->datos);
    free(vector);
}

bool vector_obtener(vector_t* vector, size_t pos, int* valor){
    if (pos >= vector->tam) return false;
    valor = vector->datos[pos];
    return true;
}
    
bool vector_guardar(vector_t* vector, size_t pos, int valor){
    if (pos >= vector->tam)return false;
    if ((float) vector->tam / (float) vector->cantidad > 0,7){
        vector_redimensionar(vector, vector->tam * 2);
    }
    vector->cantidad++;
    vector->datos[pos] = valor;
    return true;
}

size_t vector_largo(vector_t* vector){
    return vector->tam;
}

// Funciones implementadas por la catedra.

vector_t* vector_crear(size_t tam) {
    vector_t* vector = malloc(sizeof(vector_t));

    if (vector == NULL)return NULL;
    vector->datos = malloc(tam * sizeof(int));

    if (tam > 0 && vector->datos == NULL) {
        free(vector);
        return NULL;
    }
    vector->cantidad = 0;
    vector->tam = tam;
    return vector;
}

bool vector_redimensionar(vector_t* vector, size_t tam_nuevo) {
    int* datos_nuevo = realloc(vector->datos, tam_nuevo * sizeof(int));

    if (tam_nuevo > 0 && datos_nuevo == NULL) return false;

    vector->datos = datos_nuevo;
    vector->tam = tam_nuevo;
    return true;
}
