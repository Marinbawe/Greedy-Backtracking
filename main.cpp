#include <iostream>

using namespace std;


//crearea clasei de tip Student
struct Student{

int ordine;
float timpi_probleme = 0;

};
/*
int main()
{
    int nr, n;
    cin>>n;
    float Probleme[n];
     cout<<"Introduceti timpii de rezolvare ai fiecarei probleme."
    for(int i = 0; i<n; i++)
       cout<<"Problema "<<i; cin>>Probleme[n]; cout<<"\n";

   //Folositi exemplul {0.5, 0.42, 1.25, 3.20, 0.75, 0.89, 2.23, 0.07, 3.73, 1.94} si n = 10;


    cin >> nr;
    Student Array[nr]; //initierea variabilei


    for(int i = 0; i < nr; i++)
    {
        Array[i].ordine = i;
        cout<<"Introduceti trei probleme pe care studentul trebuie sa le faca, de la 1 la 10."<<"\n";
        cin >> index; Array[i].timpi_probleme += Probleme[index-1];// se introduc problemele si dupa sunt adaugate,
        cin >> index; Array[i].timpi_probleme += Probleme[index-1];// una cate una, in variabila Array[i].timpi.probleme
        cin >> index; Array[i].timpi_probleme += Probleme[index-1];
    }
    Student aux;
for(int i = 0; i < nr; i++) //se face sortarea Bubble Sort, in mod crescator ai timpilor de rezolvare
    for(int j = i+1; j < nr; j++)
    if(Array[i].timpi_probleme > Array[j].timpi_probleme)
{
    aux = Array[i]; //se face interschimbarea cu ajutorul variabilei aux
    Array[i] = Array[j];
    Array[j] = aux;
}



    for(int i = 0; i < nr; i++) //afisarea studentilor si ale timpilor de rezolvare
        cout<<"Studentul "<< Array[i].ordine+1<<" "<<Array[i].timpi_probleme<<"\n";


}
*/



int scari, FibonacciVector[100], pozitie = 0, solutii = 0;
void BackTrackingFibonacci(int Pas, int SumaPasi)
{


    FibonacciVector[pozitie] = Pas; //se introduce pasul pe care Cetateanul Turmentat l-a facut pe scara

    if(SumaPasi < scari) //cazul intai pentru un singur pas pe scara
    {
        pozitie++; // incrementarea pozitiei pe "stiva"
        BackTrackingFibonacci(1, SumaPasi+1); //apelare recursiva la efectuarea unui pas
    }

    if(SumaPasi+1 < scari) //cazul al doilea pentru doi pasi pe scara
    {
        pozitie++;
        BackTrackingFibonacci(2, SumaPasi+2); //apelare recursiva la efectuarea a doi pasi
    }

    if (SumaPasi == scari) // atunci cand suma pasilor este egala cu cea a scarilor, se afiseaza solutia
    {
      solutii++;  cout<<"Solutia "<<solutii<<": ";
        cout<<"(";
        for(int i = 1; i <= pozitie; i++)
            if(i != pozitie){cout<<FibonacciVector[i]<<", "; } else {cout<<FibonacciVector[i]<<")"; cout<<endl;}
    }
 pozitie--; // legat de backtracking, problema nu va putea ajunge la aceasta linie decat daca va afisa o solutie.
            //  dupa fiecare rezultat efectuat corect, va cobori pe stiva (sau, in cazul nostru, tablou) cu 1
}

int Fibonacci(int scari) //aceasta functie recursiva va afisa numarul de metode al n scari pe care le poti urca, inainte sa le afiseze
{
    if(scari <= 3)
    return scari;
    else return Fibonacci(scari-1) + Fibonacci(scari-2);

}


int NrMetode(int scari) //aceasta functie va apela functia recursiva Fibonacci
{
    return Fibonacci(scari);
}

int main()
{
   cout<<"Introduceti numarul de scari pe care le poate urca Cetateanul Turmentat: "; cin>>scari;

    cout<<"Numarul de metode prin care Cetateanul Turmentat poate urca scarile este: "<<NrMetode(scari);
    cout<<endl;
    BackTrackingFibonacci(0,0); //apelarea va initia functia de la inceput
}


