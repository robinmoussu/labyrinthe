#include <Array>
#include <Pair>

Class Case {
    protected:
    int visibilitee;
    protected:
    static const int BASE_POINT         = 90;
    static const int POINT_VOISINS      = 8;
    static const int POINT_DIAGONALE    = 7;
    static const int POINT_VOISINS_LOIN = 6;
}

class Map {
    void deplacer_fourmi();
    protected:
    int nb_total_point();
    protected:
    std::vector<bool> map;
    std::vector<Fourmi> fourmis;
}

void Map::deplacer_fourmi() {
    // TODO: remettre ça au propre
    map[rand() % nb_total_point()] = nouvelle position;
}

int nb_total_point() {
    int nb_total_point = BASE_POINT;
    for (fourmi: fourmis) {
        for (voisin: fourmi.voisins()) {
            if (map.case_occupee(voisin.position())) {
                nb_total_point -= POINT_VOISINS;
            }
        }
        for (diagonale: fourmi.diagonales()) {
            if (map.case_occupee(diagonale.position())) {
                nb_total_point -= POINT_DIAGONALES;
            }
        }
        for (voisin_loin: fourmi.voisins_loin()) {
            if (map.case_occupee(voisin_loin.position())) {
                nb_total_point -= POINT_VOISINS_LOINS;
            }
        }
    }
    return nb_total_point;
}

class Position {
    Position(int x, int y);
    std::Array<Pos, 4> voisins;
    std::Array<Pos, 4> diagonales;
    std::Array<Pos, 4> voisins_loin;
    Position operator+(Position position);
    int x() {return position.first;}
    int y() {return position.second;}
    protected:
    std::pair<int> position;
}

std::Array<Position, 4> voisins() {
    std::Array<Position, 4> voisins;
    voisins[0] = position + Position(0,1);
    voisins[1] = position + Position(1,0);
    voisins[2] = position + Position(0,-1);
    voisins[3] = position + Position(-1,0);
    return voisins;
}

std::Array<Position, 4> diagonales() {
    std::Array<Position, 4> voisins;
    voisins[0] = position + Position(1,1);
    voisins[1] = position + Position(1,-1);
    voisins[2] = position + Position(-1,-1);
    voisins[3] = position + Position(-1,1);
    return voisins;
}

std::Array<Position, 4> voisins_loin() {
    std::Array<Position, 4> voisins;
    voisins[0] = position + Position(0,2);
    voisins[2] = position + Position(2,0);
    voisins[2] = position + Position(0,-2);
    voisins[3] = position + Position(-2,0);
    return voisins;
}

Position operator+(Position position) {
    return Position(this->x() + position.x(), this->y() + position.y());
}

class Fourmi {
    std::pair< std::Array<Position, 4>, std::Array<int, 4> > Fourmi::case_visible(Fourmi fourmi) {
    Position position() {return position;}
    protected:
    Position position;
}

