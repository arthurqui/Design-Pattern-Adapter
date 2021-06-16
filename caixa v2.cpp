#include <iostream>
#include <memory>

using namespace std;


//interface DisplayLocal

class DisplayLocal
{
    public:
    enum Numero
    {
        Um = 0,
        Dois,
        Tres,
        Quatro
    };
    
    virtual void Mensagem(Numero numero, string mensagem) = 0;
};


// RemoteDisplay lib
// RemoteDisplay.hpp
class DisplayRemoto

{
    public:
        void MsgUm(string mensagem) const;
        void MsgDois(string mensagem) const;
        void MsgTres(string mensagem) const;
        void MsgQuatro(string mensagem) const;
    
};

//RemoteDisplay.cpp
void DisplayRemoto::MsgUm(string mensagem) const {
    cout << "Display V2 - 1: " << mensagem << endl;
}

void DisplayRemoto::MsgDois(string mensagem) const {
    //..implementa..
    cout << "Display V2 - 2: " << mensagem << endl;
}

void DisplayRemoto::MsgTres(string mensagem) const {
    //..implementa..
    cout << "Display V2 - 3: " << mensagem << endl;
}

void DisplayRemoto::MsgQuatro(string mensagem) const {
    //..implementa..
    cout << "Display V2 - 4: " << mensagem << endl;
}



//DisplayAdapter

class DisplayAdapter : public DisplayLocal, public DisplayRemoto
{
    virtual void Mensagem(Numero numero, string mensagem)
    {
        switch (numero)
        {
            case Um:
                MsgUm(mensagem);
                break;
            case Dois:
                MsgDois(mensagem);
                break;
            case Tres:
                MsgTres(mensagem);
                break;
            case Quatro:
                MsgQuatro(mensagem);
                break;
            default:
                cout << "Erro" << endl;
                break;
        }
    }
};

int main()
{
   unique_ptr<DisplayLocal> displayPtr(new DisplayAdapter);
   displayPtr -> Mensagem(displayPtr -> Um, "Musica1");
   displayPtr -> Mensagem(displayPtr -> Dois, "Musica2");
   displayPtr -> Mensagem(displayPtr -> Tres, "Musica3");
   displayPtr -> Mensagem(displayPtr -> Quatro, "Musica4");
   
}




