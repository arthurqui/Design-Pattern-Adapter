#include <iostream>

using namespace std;


//interface DisplayLocal

class DisplayLocal
{
    public:
    enum Numero
    {
        Um = 1,
        Dois,
        Tres,
        Quatro
    };
    
    virtual void Mensagem() {
        cout << Um << " - Nome da Musica" << endl;
        cout << Dois << " - Nome da Musica" << endl;
        cout << Tres << " - Nome da Musica" << endl;
        cout << Quatro << " - Nome da Musica" << endl;
    };
};

int main()
{   
    cout << "Foramto para Caixa de som com display local:"<< endl;
    DisplayLocal objeto;
    objeto.Mensagem();
    return 0;
   
   
}