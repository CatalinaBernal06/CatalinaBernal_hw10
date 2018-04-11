#include <iostream>
#include <cstdlib>

double matrix_product(double **M , double **N);
double get_Matrix(int M, int N);

int main(){

  std::cout << "Ingrese el numero de filas de la primera matriz " << std::endl;
  int filas1;
  std::cin << filas1;

  std::cout << "Ingrese el numero de columnas de la primera matriz " << std::endl;
  int ncol1;
  std::cin << ncol1;

   std::cout << "Ingrese el numero de filas de la segunda matriz " << std::endl;
  int filas2;
  std::cin << filas2;

  std::cout << "Ingrese el numero de columnas de la segunda matriz " << std::endl;
  int ncol2;
  std::cin << ncol2;

  if(ncol1 != filas2){
    std::cout << "El numero de filas de la primera matriz debe ser igual al numero de columnas de la segunda matriz. " << std::endl;
  }

  else{
    std::cout << "Creará la primera matriz " << std::endl;
    double M1 =  get_Matrix(filas1, ncol1);

    std::cout << "Creará la segunda matriz " << std::endl;
    double M2 =  get_Matrix(filas2, ncol2);

    double resultado = matrix_product(M1, M2, filas1, ncol1, filas2, ncol2);
    std::cout << "El resultado de la multiplicacion de las matrices es: " << resultado << std::endl;
  }  
  
}

// metodo de multiplicacion de matrices

double matrix_product(double **M , double **N, int nfilasM, int ncolM, int nfilasN, int ncolN){
  // inicializo la matriz resultado
  double *c = new double[ncolN];
  double **R = new double[nfilasM];

  //inicializo filas de matriz
  for(int i=0; i<nfilasM; i++){
      R[i]= new double[0];
  }

  //metodo para efectuar la multiplicacion de matrices
  //recorre filas (numero de filas de matriz M)
  for(int i=0; i<nfilasM; i++){
    // recorre columnas (numero de columnas de matriz N)
    for(int j=0; i<ncolN; j++){
      //recorre elemento por vector de cada matriz para multiplicacion
      for(int k = 0; k<nfilasN; k++){
	//construye matriz resultado
	R[i][j] = M[i][k]*N[k][j];
      }
      // std::cout << R[i][j] << " ";
    }
    // std::cout << std::endl;
 }
  return R;
}


double get_Matrix(int M, int N){
  double *col = new double[N];
  //luego filas
  double **Mat = new double*[M];

  std::cout << "La dimension de la matriz es: " << M << " x " << N << std::endl;
  //inicializar matriz
  for(int i=0; i<M; i++){
      Mat[i]= new double[0];
  }
  //construyendo matriz con  parametros ingresados por el usuario
   for(int i=0; i<M; i++){
     for (int j=0; j<N; j++){
       std::cout << "Ingrese el valor de la posicion " << i << ", " << j << std::endl;
       float valor;
       std::cin >> valor;
       Mat[i][j] = valor;

     }
   }
   //imprime la matriz creada por usuario
   std::cout << "La matriz creada es " << std::endl;
   
   for(int i=0; i<M; i++){
     for (int j=0; j<N; j++){
       std::cout << Mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
 
  
