#include <Array>
#include <Pair>

class Coordonnee {
    Coordonnee(int x, int y);
    std::Array<Coordonnee, 4> voisins;
    std::Array<Coordonnee, 4> diagonales;
    std::Array<Coordonnee, 4> voisins_loin;
    Coordonnee operator+(Coordonnee position);
    int x() const {return position.first;}
    int y() const {return position.second;}
    protected:
    std::pair<int> position;
}

std::Array<Coordonnee, 4> Coordonnee::voisins() {
    std::Array<Coordonnee, 4> voisins;
    voisins[0] = position + Coordonnee(0,1);
    voisins[1] = position + Coordonnee(1,0);
    voisins[2] = position + Coordonnee(0,-1);
    voisins[3] = position + Coordonnee(-1,0);
    return voisins;
}

std::Array<Coordonnee, 4> Coordonnee::diagonales() {
    std::Array<Coordonnee, 4> voisins;
    voisins[0] = position + Coordonnee(1,1);
    voisins[1] = position + Coordonnee(1,-1);
    voisins[2] = position + Coordonnee(-1,-1);
    voisins[3] = position + Coordonnee(-1,1);
    return voisins;
}

std::Array<Coordonnee, 4> Coordonnee::voisins_loin() {
    std::Array<Coordonnee, 4> voisins;
    voisins[0] = position + Coordonnee(0,2);
    voisins[2] = position + Coordonnee(2,0);
    voisins[2] = position + Coordonnee(0,-2);
    voisins[3] = position + Coordonnee(-2,0);
    return voisins;
}

Coordonnee operator+(Coordonnee position) {
    return Coordonnee(this->x() + position.x(), this->y() + position.y());
}

class Fourmi {
    Coordonnee position() {return position;}
    protected:
    Coordonnee position;
}

class Map {
    void deplacer_fourmi();
    Box *const operator[] (Coordonnee const coordonnee) const;
    void update_visibilitee(Coordonnee const coordonnee);
    protected:
    int nb_total_point() const {return nb_total_point;}

    Class Box {
        bool occupee() const {return occupee;}
        bool visibilitee() const {return visibilitee;}
        protected:
        bool occupee = false;
        int visibilitee = 0;
        protected:
        static const int BASE_POINT         = 90;
        static const int POINT_VOISINS      = 8;
        static const int POINT_DIAGONALE    = 7;
        static const int POINT_VOISINS_LOIN = 6;
    }

    protected:
    int width;
    int hight;
    int nb_total_point = 0;
    std::vector<Box> map;
    std::vector<Fourmi> fourmis;
}

void Map::deplacer_fourmi() {
    // TODO: remettre ça au propre
    map[rand() % nb_total_point()] = nouvelle position;

    // mise à jour des cases
    // la zone contenant les cases à mettre à jour est un rectangle de 3×4 cases
    // On compte le nombre de point 
}

Box *const Map::operator[] (Coordonnee const coordonnee) const {
    return map[coordonnee.x*width + coordonnee.y]
}

void Map::update_visibilitee(Coordonnee const coordonnee) {
    const Box box = self->[coordonnee].occupee;
    if (box) {
        visibilitee = 0;
    } else {
        visibilitee = BASE_POINT;
        for (voisin: coordonnee.voisins()) {
            if (map.case_occupee(voisin.position())) {
                nb_total_point -= POINT_VOISINS;
            }
        }
        for (diagonale: coordonnee.diagonales()) {
            if (map.case_occupee(diagonale.position())) {
                nb_total_point -= POINT_DIAGONALES;
            }
        }
        for (voisin_loin: coordonnee.voisins_loin()) {
            if (map.case_occupee(voisin_loin.position())) {
                nb_total_point -= POINT_VOISINS_LOINS;
            }
        }
    }
}
