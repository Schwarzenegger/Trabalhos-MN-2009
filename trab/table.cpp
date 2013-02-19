#include <QtGui>
#include <QMessageBox>
#include "table.hpp"

//Construtor da Classe Tabela
Table::Table(int tipo, int max, QWidget *parent)
    : QTableWidget(0,max,parent)
{
    //Labels das tabelas, dependendo do tipo delas    
    if(tipo == 1) setHorizontalHeaderLabels(
            QStringList() << tr("Dia.") << tr("Qe") << tr("Qc"));
    if(tipo == 2) setHorizontalHeaderLabels(
            QStringList() << tr("Dia") << tr("Qr") << tr("Qs"));
    if(tipo == 3) setHorizontalHeaderLabels(
            QStringList() << tr("Metodo") << tr("Num. It.") << tr("Isol.") << tr("Raiz Ini.")
                          << tr("Raiz Fin.") << tr("Crit. Parada"));

    //contador de linhas das tabelas, usado para mudar a cor das linhas
    this->count = 0;
    
}

//Adiciona uma Linha numa Tabela de 3 colunas, dado um inicio da Lista recebida
void Table::addRow1(QList<float> lista,int inicio)
{
    int row = rowCount();
    insertRow(row);
    bool linhaPar = false;  
    QBrush pintaLinha(QColor(235,246,253,155)); //criando um brush para a cor da linha  

    //verifica se a linha a ser inserida é par
    if((this->count % 2) == 0) linhaPar = true;   
    
    //incrementa o contador de linhas
    this->count++;
 
    //item da primeira coluna
    QTableWidgetItem *item0 = 
        new QTableWidgetItem(tr("%1").arg(QString::number(lista[inicio])));
    item0->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item0->setBackground ( pintaLinha );
    setItem(row, 0, item0);
    
    //item da segunda coluna
    QTableWidgetItem *item1 = 
       new QTableWidgetItem(tr("%1").arg(QString::number(lista[inicio + 1])));
    item1->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item1->setBackground ( pintaLinha );
    setItem(row, 1, item1);
    
   //item da terceira coluna
    QTableWidgetItem *item2 = 
       new QTableWidgetItem(tr("%1").arg(QString::number(lista[inicio + 2])));
    item2->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item2->setBackground ( pintaLinha );
    setItem(row, 2, item2);

}

//Adiciona uma Linha numa Tabela de 3 colunas dada uma lista de entrada
void Table::addRow2(QList<float> lista)
{
    int row = rowCount();
    insertRow(row);
    
    QBrush pintaLinha(QColor(235,246,253,155)); //criando um brush para a cor da linha

    bool linhaPar = false;  

    if((this->count % 2) == 0) linhaPar = true;   

    this->count++;

    //item da primeira coluna
    QTableWidgetItem *item0 = 
        new QTableWidgetItem(tr("%1").arg(QString::number(lista[0])));
    item0->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item0->setBackground ( pintaLinha );
    setItem(row, 0, item0);
    
    //item da segunda coluna
    QTableWidgetItem *item1 = 
       new QTableWidgetItem(tr("%1").arg(QString::number(lista[1])));
    item1->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item1->setBackground ( pintaLinha );
    setItem(row, 1, item1);
    
    //item da terceira coluna
    QTableWidgetItem *item2 =
       new QTableWidgetItem(tr("%1").arg(QString::number(lista[2])));
    item2->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item2->setBackground ( pintaLinha );
    setItem(row, 2, item2);

}

//Adiciona uma Linha numa Tabela de 6 colunas, dado o método usado, o numero de iterações,
//o intervalo x do isolamento, o intervalo y do isolamento, a raiz inicial, a raiz final
//e o critério de parada
void Table::addRow3(QString metodo,float it,float isoX,float isoY,float raizIni,
                    float raizFim,int critPar)
{
    int row = rowCount(); //obtendo o número de linhas atuais da tabela
    QString critP;  //string que armazena o critério de parada  

    QBrush pintaLinha(QColor(235,246,253,155)); //criando um brush para a cor da linha
    
    bool linhaPar = false;  

    if((this->count % 2) == 0) linhaPar = true;   

    this->count++;

    //configurando os critérios de parada para o método de Bissecao
    switch(critPar)
    {
         case 1: critP = "|funcao(x) < E2 | < E1"; break;
         case 2: critP = "|b - a| < E1"; break;
         case 3: critP = "|b - a| > E1"; break;
    }
    
    //inserindo nova linha na última posição 
    insertRow(row);
    
    //item da primeira coluna
    QTableWidgetItem *item0 = 
        new QTableWidgetItem(tr("%1").arg(metodo));
    item0->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item0->setBackground ( pintaLinha );
    setItem(row, 0, item0);
    
    //item da segunda coluna
    QTableWidgetItem *item1 = 
       new QTableWidgetItem(tr("%1").arg(QString::number(it)));
    item1->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item1->setBackground ( pintaLinha );
    setItem(row, 1, item1);
    
    //item da terceira coluna
    QTableWidgetItem *item2 = 
       new QTableWidgetItem(tr("[%1,%2]").arg(isoX).arg(isoY));
    item2->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item2->setBackground ( pintaLinha );
    setItem(row, 2, item2);

    //item da quarta coluna
    QTableWidgetItem *item3 = 
       new QTableWidgetItem(tr("%1").arg(QString::number(raizIni)));
    item3->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item3->setBackground ( pintaLinha );
    setItem(row, 3, item3);

    //item da quinta coluna
    QTableWidgetItem *item4 = 
       new QTableWidgetItem(tr("%1").arg(QString::number(raizFim)));
    item4->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item4->setBackground ( pintaLinha );
    setItem(row, 4, item4);

    //item da sexta coluna
    QTableWidgetItem *item5 = 
       new QTableWidgetItem(tr("%1").arg(critP));
    item5->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    if(linhaPar) item5->setBackground ( pintaLinha );
    setItem(row, 5, item5);

   
}

//Limpa linhas da tabela dado o número de linhas que se deseja mudar
void Table::clear(int rows)
{
     int i; //contador
     
     //para cada linha que se deseja remover, remove elas de baixo para cima     
     for(i = rows; i >= 0; i--)
     { 
         removeRow(i);  //função que remove uma linha da tabela
     }

     this->count = 0; //reinicializando o contador de linhas
}




