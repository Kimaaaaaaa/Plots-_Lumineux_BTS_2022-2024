#include "controller.h"
#include "plot.h"

Controller::Controller()
{

    listePlots.append(new Plot());

    listePlots.append(new Plot());

    listePlots.append(new Plot());

    listePlots.append(new Plot());

    listePlots.append(new Plot());

    emit listePlotsChanged();

}

QQmlListProperty<Plot> Controller::getListePlots()
{
    return QQmlListProperty<Plot>(this, listePlots);;
}

//méthode détecter plot
