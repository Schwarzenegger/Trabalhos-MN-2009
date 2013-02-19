#ifndef JANELAP_HPP
#define JANELAP_HPP

#include <QMainWindow>
#include <QWidget>
class QAction;
class Canvas;
class Table;
class QLabel;
class QPushButton;
class QLineEdit;

//Classe da janela principal, onde todos os outros widgets ficarão
class JanelaP : public QMainWindow
{
    Q_OBJECT
public:
    JanelaP();
    void delay(int iterations);

private slots:
    void textoMudou();
    void calcular();
    void atualizarDias();
    
private:
    void createActions();
    void createMenus();
   
    Canvas *canvas;
    Table *tableBis;
    Table *tablePF;
    Table *tableComp;
    Table *tableDias;
    
    QLabel *qtdDiasLabel;
    QLabel *prec1Label;
    QLabel *prec2Label; 
    
    QLineEdit *qtdDiasLine;
    QLineEdit *prec1Line;
    QLineEdit *prec2Line;    
    
    QPushButton *calcButton;    

    QMenu *fileMenu;
    QMenu *helpMenu;
    
    QAction *exitAction;
    QAction *aboutQtAction;
     
    //numero de dias
    int numDia;

};

#endif



