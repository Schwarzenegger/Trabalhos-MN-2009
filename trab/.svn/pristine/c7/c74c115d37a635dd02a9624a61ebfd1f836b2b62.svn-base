#include <QApplication>
#include <QSplashScreen>
#include <iostream>
#include "janelaP.hpp"
using namespace std;

#define ITERATIONS 100000000

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    

    
    app.processEvents();
    
    JanelaP *janelaP = new JanelaP;

    janelaP->delay(ITERATIONS); //delay 

    app.processEvents();
 
    janelaP->delay(ITERATIONS); //delay 

    app.processEvents();

    janelaP->delay(ITERATIONS); //delay  

    janelaP->setWindowTitle(QObject::tr("XTocator"));
    
    janelaP->resize(800, 600);



    app.processEvents();
    
    janelaP->delay(ITERATIONS); //delay 

    janelaP->show();
    

    return app.exec();
}




