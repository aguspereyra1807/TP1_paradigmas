#include "EntidadOrganizativa.h"

class Empresa: public EntidadOrganizativa {
    public:
        using EntidadOrganizativa::nombre; // de protegido a público
        string direccion;
        Departamento getDeepByName

};