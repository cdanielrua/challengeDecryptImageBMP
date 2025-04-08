#include <iostream>
using namespace std;

int get_lsb(int numero){
    cout<<"el bit menos significativo es el primero"<<endl
        <<"a la derecha puede ser 1 o 0"<<endl;
    int lsb;
    lsb = numero & 1;//mask=1
    return lsb;
}

int get_msb(int numero,int *pos){
    //1000 0100 0010 0001 
    //8    4    2    1
    //0001 0010 0100 1000
    //1    2    3    4
    cout<<"el bit mas significativo puede estar en cualquier"<<endl
        <<"posicion a la izquierda, lo importante es saber"<<endl
        <<"a que valor corresponde en decimal y/o en que "<<endl
        <<"posicion se encuentra"<<endl;

    if(numero == 0 || numero == 1){
        *pos = 0;
        return numero;
        
    }
    else if (numero==2)
    {
        *pos = 1;
        return 2;
    }
    
    int msb = 1;
    for(*pos=0; numero > 1; (*pos)++){
        numero >>= 1;
        msb <<= 1;
    }
    return msb;//retornamos el valor en decimal del msb
    
    }
    


int get_lsb_msb(){
    int numero;
    cout<<"ingrese un numero para obtener su bit mas significativo"<<endl
        <<"y menos signisicativo"<<endl;
    cin>>numero;
    
    int lsb=get_lsb(numero);
    //necesitamos definir una variable pos y un  apuntador
    //a pos para pasarlos como argumento msb
    int pos=0;
        
    int msb=get_msb(numero,&pos);
    
    cout<<"el bit menos significativo es: "<<lsb<<endl
        <<"el bit mas significativo es : "<<msb<<endl
        <<"ubicado en la posicion: "<<pos<<endl;
    return 0;

}
int get_nth_bit(){
    cout<<"ingrese un numero para obtener el n-esimo bit"<<endl;
    int numero;
    cin>>numero;
    cout<<"ingrese la posicion del bit que desea obtener"<<endl;
    int n;  
    cin>>n;
    if(numero < n || n < 0 ){
        cout<<"la posicion ingresada no es valida"<<endl;
        return 0;
    }
    int mask = 1 << n-1;
    int bit = numero & mask;
    cout<<"el bit en la posicion "<<n<<" es: "<<bit<<endl;
    return 0;
}

int set_one_nth_bit(){
    cout<<"ingrese un numero para establecer el n-esimo bit en 1"<<endl;
    int numero;
    cin>>numero;
    cout<<"ingrese la posicion del bit que desea establecer en 1"<<endl;
    int n;
    cin>>n;
    if(numero < n || n < 0 ){
        cout<<"la posicion ingresada no es valida"<<endl;
        return 0;
    }
    int mask = 1 << n-1;
    int bit = numero | mask;
    cout<<"el numero con el bit en la posicion "<<n<<" establecido en 1 es: "<<bit<<endl;
    return 0;
}
int count_zero_bits(){
    cout<<"ingrese un numero para contar los bits en 0"<<endl;
    int numero;
    cin>>numero;
    int count = 0;
    while( numero > 0 ){
        count += !(numero & 1);
        numero >>= 1;
    }
    cout<<"el numero de bits en 0 es: "<<count<<endl;
    return 0;
}
int flip_nth_bit(){
    cout<<"ingrese un numero para invertir el n-esimo bit"<<endl;
    int numero;
    cin>>numero;
    cout<<"ingrese la posicion del bit que desea invertir"<<endl;
    int n;
    cin>>n;
    if(numero < n || n < 0 ){
        cout<<"la posicion ingresada no es valida"<<endl;
        return 0;
    }
    int mask = 1 << n;
    int bit = numero ^ mask;
    cout<<"el numero con el bit en la posicion "<<n<<" invertido es: "<<bit<<endl;
    return 0;
}
int get_rigth_most_one_bit(){
    cout<<"ingrese un numero para obtener el bit mas a la derecha que sea 1"<<endl;
    int numero;
    cin>>numero;
    int mask = 1;
    int bit = 0;
    int rigth_most=1;
    while( numero > 0 ){
        bit = numero & mask;
        if(bit == 1){
            break;
        }
        rigth_most++;
        numero >>= 1;
    }
    cout<<"el bit mas a la derecha que sea 1 es: "<<rigth_most<<endl;
    return 0;
}
int flip_all_bit(){
    cout<<"ingrese un numero para invertir todos los bits"<<endl;
    int numero;
    cin>>numero;
    int mask = 0;
    int bit = 0;
    int numero_aux = numero;
    while( numero_aux > 0 ){
        mask <<= 1;
        mask |= 1;
        numero_aux >>= 1;
    }
    bit = numero ^ mask;
    cout<<"el numero con todos los bits invertidos es: "<<bit<<endl;
    return 0;
}
int check_even_odd(){
    cout<<"ingrese un numero para verificar si es par o impar"<<endl;
    int numero;
    cin>>numero;
    int bit = numero & 1;
    if(bit == 0){
        cout<<"el numero es par"<<endl;
    }else{
        cout<<"el numero es impar"<<endl;
    }
    return 0;
}

int main(){
    //menu de selección 
    int short opcion = 0;
    cout<<"ingrese una de las siguientes opciones:"<<endl
        <<"1.obtener el bit menos y mas significativo de un numero"<<endl
        <<"2.obtener el n-esimo bit de un numero"<<endl
        <<"3.establecer el n-esimo bit en uno de un numero"<<endl
        <<"4.contar los bits en 0 de un numero"<<endl
        <<"5.invertir el n-esimo bit de un numero"<<endl
        <<"6.obtener el bit mas a la derecha que sea 1"<<endl
        <<"7.invertir todos los bits de un numero"<<endl    
        <<"8.verificar si un numero es par o impar"<<endl;

    cin>>opcion;
    
    switch(opcion){
        case 1:
            get_lsb_msb();
       case 2:
            get_nth_bit();
        case 3:
            set_one_nth_bit();
        case 4:
            count_zero_bits();
        case 5:
            flip_nth_bit();
        case 6:
            get_rigth_most_one_bit();
        case 7:
            flip_all_bit();
        case 8:
            check_even_odd();
           
    }
    return 0;
}