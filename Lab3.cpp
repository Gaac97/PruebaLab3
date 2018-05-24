#include <iostream>
#include <cmath>
#include <stdio.h>

#include <cstdlib>
using std:: string;
using std::cout;
using std::cin;
using std::endl;

int menu();
int  ejercicio1();
void ejercicio2();
int ejercicio3();
void ejercicio3(int arr[], int l, int r);
void merge(int arr[], int l,int m, int r);
void imprimir(int A[], int size);
void impresion(float,float);

float raiz_real(float,float ,float);

int main(){
switch(menu()){

	case 1:
		cout << "ejercicio 1"<<endl;
		cout << ejercicio1()<<endl;
		break;

	case 2:
		{

		//ejercicio2();
		float x1,x2,a,b,c;
 string ecua="";
 cout<< "Ingrese la ecuacion:";
 cin>> ecua;
 a = ecua[0]-48;
 b = ecua[5]-48;
 c= ecua[8]-48;

  if(((b*b)- (4.0*a*c)) >= 0.0)
{


cout << " las raices de la f(x) son reales: " << endl;

//x1 = (-b + sqrt(b*b - 4.0*a*c))/(2.0*a);

x1 = raiz_real(a,b,c);

x2 = (-b - sqrt(b*b - 4.0*a*c))/(2.0*a);

//cout << "x1: " << x1 << endl;
//cout << "x2: " << x2 << endl;

impresion(x1,x2);

}
else{

float im_x1, im_x2;
float re_x1, re_x2;


re_x1 = -b/(2.0*a);
re_x2 = -b/(2.0*a);

im_x1 = sqrt(-b*b + 4.0*a*c);
im_x2 = sqrt(-b*b + 4.0*a*c);

cout << "x1: " << re_x1 << " + " << im_x1 << " i " << endl;
cout << "x2: " << re_x2 << " - " << im_x2 << " i " << endl;

	
}break;
}

case 3:
{
int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    imprimir(arr, arr_size);

 
    ejercicio3(arr, 0, arr_size - 1);

 
   imprimir(arr, arr_size);


}break;


}
return 0;
}


int menu(){
int opcion=0;
do{


	cout<<"Ejercicio 1:"<<endl
	 <<"Ejercicio 2:"<<endl
	 << "Ejercicio 3:"<< endl
	 <<"SALIR 4:"<<endl;
	cin >>opcion;
	
	return opcion;


}while(opcion!=4);



}

int  ejercicio1(){
string cadena;
string cadena2;

int result=0;
string cadena3;
int numeros;
srand(time(NULL));
char letra1;
char letra2;
int cont=0;
numeros =0+rand()%99999;
cadena = std::to_string(numeros);
int limite = cadena.length();
	
	cout<< "El numero random:" << cadena<<endl;

	for(int x=0; x <cadena.length(); x++){
	cout<< "Ingrese cadena:"<<endl;
	cin>> cadena2;
	     for(int j=0; j< cadena2.length();j++){
		if(limite>=4){
			if(cadena2.compare(cadena)!=0){
			cout <<"GANO!!"<<endl;
	}
		letra1 = cadena2[x];
		letra2 = cadena[j];

			if(letra1==letra2){
				result++;
				cadena3 =cadena3+letra1;

			}
		cadena="";

		
		
		}else{
			cout<<"La cadena tiene que tener 5 digitos";
	}
	

	}
	}
	cout << "Numeros en la cadena:"<< result<<endl;

return result;
}



void ejercicio2(){

float x1,x2,a,b,c;
string ecua;
cout<< "Ingrese la ecuacion:";
cin>> ecua;



a = ecua[0]-48;
b = ecua[5]-48;
c= ecua[8]-48;

/*int interiorRaiz = pow(b,2)-4*(a*c);

cout << "a:"<<a<<endl;
cout << "b" << b <<endl;
cout << "c"<< c<<endl;

x1 = (-b+sqrt(interiorRaiz))/(2*a);
x2 = (-b-sqrt(interiorRaiz))/(2*a);

cout << "El resultado de x1:" <<x1-48<<endl;
cout << "El resultado de x2:" <<x2-48<<endl;*/

 x1 = (-b + (sqrt(pow(b, 2) - (4 * a * c)))) / (2 * a);
 x2 = (-b - (sqrt(pow(b, 2) - (4 * a * c)))) / (2 * a);
 cout << "x1 es igual a: " << x1 << endl;
 cout << "x2 es igual a: " << x2 << endl;



}







float raiz_real (float a, float b, float c)
{
float x;

x = (-b + sqrt(b*b - 4.0*a*c))/(2.0*a);
return x;
}


void impresion (float x, float y)
{

cout << x << endl;
cout << y << endl;


}

void imprimir(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

 
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

   
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void ejercicio3(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        ejercicio3(arr, l, m);
        ejercicio3(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
