#pragma once
#include <string>
#include <vector>
#include <memory>

using namespace std;

class EntidadOrganizativa {
    public:
        virtual void agregarSubentidad(EntidadOrganizativa& subentidad) = 0;
        virtual int contarSubentidades() = 0;
        string nombre;
    
    private: // NO DEBERIAN SER PROTEGIDOS? LAS DERIVADAS NO PUEDEN ACCEDER A SU NOMBRE O SUBENTIDADES
        vector<shared_ptr<EntidadOrganizativa>> subentidades;
};