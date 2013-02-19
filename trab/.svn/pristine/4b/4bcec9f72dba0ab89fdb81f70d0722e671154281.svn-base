#ifndef TABLE_HPP
#define TABLE_HPP

#include <QTableWidget>
#include <QWidget>
#include <iostream>
using namespace std;

//classe Table, responsável pelo controle e manutenção do widget de tabela
class Table : public QTableWidget
{
   Q_OBJECT
   public:
	   //construtor
           Table(int tipo,int max, QWidget *parent = 0);
           
           //métodos que adicionam linhas na tabela
           void addRow1(QList<float> lista,int inicio);
           void addRow2(QList<float> lista);
           void addRow3(QString metodo,float it,float isoX,float isoY,float raizIni,
                        float raizFim,int critPar); 
           
           //Método que limpa a tabela
           void clear(int rows);
    private:
           int count;  //contador de linhas para uma tabela

};

#endif
