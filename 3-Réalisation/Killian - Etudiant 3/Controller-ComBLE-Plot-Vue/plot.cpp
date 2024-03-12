#include "plot.h"


Plot::Plot()
{
    connect(this, &Plot::tempsRecu,
            this, &Plot::standBy);

    this->couleur = nullptr;
    lireBatterie(this);
    nvBatterie = 10;

    this->listePlot.append(this);
}

void Plot::lireBatterie(Plot *)
{
    this->nvBatterie = 70; //valeur fictive en attendant de recevoir la donnée batterie
}

bool Plot::activerPlot(Plot * plot, QString couleur)
{
    plot->couleur = couleur;

    //Composer le code permettant d'allumer le plot

    return true;

}

bool Plot::desactiverPlot(Plot *)
{
    //Composer le code permettat au plot de s'éteindre (Couleur éteindre ?)

    return true;
}

int Plot::getNvBatterie()
{
    return nvBatterie;
}

void Plot::standBy()
{

    for(int i = 0; i < this->listePlot.count(); i++)
    {
        desactiverPlot(listePlot.takeAt(i));
    }

    //Bloquer 1 seconde......

}


