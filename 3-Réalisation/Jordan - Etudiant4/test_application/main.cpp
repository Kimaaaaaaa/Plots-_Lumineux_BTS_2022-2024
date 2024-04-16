#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtSql>
#include <QDebug>
#include <QQmlContext>
#include <QDebug>
#include "entites/resultat.h"
#include "controller.h"
#include "DataApi/dataJoueurs.h"




int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif


    // partager au QML le Joueur
    qmlRegisterType<Joueur>("Joueur", 1, 0, "Joueur");

    DataJoueurs dataJoueurs;


    DataResultats dataResultats;


    Controller controller(&dataJoueurs,&dataResultats);



    //dataJoueurs.getJoueurs();

    //dataJoueurs.getStatistiques();

    //dataJoueurs.getDate();


    //dataJoueurs.getJoueur("2");

    //dataJoueurs.createJoueur("identifiant", "password", "email");


    //dataJoueurs.getTours();


   // dataJoueurs.getUnepartie("1");

    QVector<Resultat*> listeResultats;

    QJsonDocument jsonData = QJsonDocument::fromJson("{\n    \"partie\": {\n        \"statut\": 1,\n        \"message\": \"ok\",\n        \"statistiques\": [\n            {\n                \"idPartie\": \"1\",\n                \"date\": \"2024-03-20\",\n                \"tempsReactionJ1\": \"160\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"1\",\n                \"joueur2_id\": \"7\"\n            },\n            {\n                \"idPartie\": \"2\",\n                \"date\": \"2024-03-21\",\n                \"tempsReactionJ1\": \"150\",\n                \"tempsReactionJ2\": \"140\",\n                \"joueur1_id\": \"8\",\n                \"joueur2_id\": \"6\"\n            },\n            {\n                \"idPartie\": \"3\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"190\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"4\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"130\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"5\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"152\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"6\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"121\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"7\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"163\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"8\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"200\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"9\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"220\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"10\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"240\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"6\",\n                \"joueur2_id\": \"0\"\n            },\n            {\n                \"idPartie\": \"11\",\n                \"date\": \"2024-03-25\",\n                \"tempsReactionJ1\": \"230\",\n                \"tempsReactionJ2\": \"0\",\n                \"joueur1_id\": \"2\",\n                \"joueur2_id\": \"0\"\n            }\n        ]\n    }\n}");
    QJsonObject dataJson = jsonData["partie"].toObject();
    QJsonArray listePartiesJson = dataJson["statistiques"].toArray();
    qDebug()<<listePartiesJson;

    for(int i = 0; i< listePartiesJson.size(); i++ ){
        listeResultats.append(new Resultat(listePartiesJson[i].toObject()));
    }


    for(int i=0;i<listeResultats.size();i++){
        qDebug()<< listeResultats[i]->toString();
    }


    //Resultat result();

    Resultat resultat;

    //qDebug() << resultat.toString();



    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    //partager au QML le controller

    engine.rootContext()->setContextProperty("controller", &controller);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);




    return app.exec();
}
