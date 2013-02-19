#include <QtGui>
#include <QLabel>
#include <iostream>
#include "janelaP.hpp"
#include "canvas.hpp"
#include "table.hpp"
using namespace std;

JanelaP::JanelaP()
{
    canvas    = new Canvas;     //objeto que representa o Canvas
    tableBis  = new Table(1,3); //tabela para os dados do método de Bicessao
    tablePF  = new Table(1,3); //tabela para os dados do método da posicaofalsa
    tableDias = new Table(2,3); //tabela que irá receber os dados sobre os Dias
    tableComp = new Table(3,6); //tabela que mostrará a comparação entre os dois Métodos Numéricos

    this->numDia = 0; //inicializando o número de Dias
 
    //Expressão regular para ponto flutuante
    QRegExp regExp("(((^[-])?)[0-9]([.][0-9])?){1,}");

    //Expressão regular para número não-negativo
    QRegExp regExp2("[0-9]{1,}");
    
    qtdDiasLabel = new QLabel(tr("&Qtd de Dias:"));
    qtdDiasLine = new QLineEdit;
    qtdDiasLine->setValidator(new QRegExpValidator(regExp2, this)); //Validação
    qtdDiasLabel->setBuddy(qtdDiasLine);
 
    prec1Label = new QLabel(tr("P&recisao 1:"));     
    prec1Line = new QLineEdit;
    prec1Line->setValidator(new QRegExpValidator(regExp, this)); //Validação
    prec1Label->setBuddy(prec1Line); 
    
    prec2Label = new QLabel(tr("Pr&ecisao &2:"));     
    prec2Line = new QLineEdit;
    prec2Line->setValidator(new QRegExpValidator(regExp, this)); //Validação
    prec2Label->setBuddy(prec2Line); 

    calcButton = new QPushButton("&Calcular", this);   
    calcButton->setEnabled(false);
    calcButton->setDefault(true);
    calcButton->setAutoDefault(true);

    //Label's informativos
    QLabel *canvasLabel = new QLabel(tr("Grafico - <font color='green'>Bissecao</font> | "
                                        "<font color='red'>Possicao-Falsa</font>"));
    QLabel *bissecaoLabel = new QLabel(tr("Metodo de Bissecao"));
    QLabel *PFLabel = new QLabel(tr("Metodo da Posicao Falsa"));
    QLabel *comptbLabel = new QLabel(tr("Tabela Comparativa"));
    QLabel *diastbLabel = new QLabel(tr("Entrada de Dados"));
  
    //Conexões
    connect(qtdDiasLine, SIGNAL(textChanged(const QString &)),
            this, SLOT(atualizarDias()));
   
    connect(qtdDiasLine, SIGNAL(textChanged(const QString &)),
            this, SLOT(textoMudou()));

    connect(prec1Line, SIGNAL(textChanged(const QString &)),
            this, SLOT(textoMudou()));
  
    connect(prec2Line, SIGNAL(textChanged(const QString &)),
            this, SLOT(textoMudou()));
 
    connect(calcButton, SIGNAL(clicked()),
            this, SLOT(calcular()));

    //Listas de Tamanho dos Splitter's
    QList<int> sizeList1;
    sizeList1 << 10 << 140 << 10 << 140 << 10 << 140 << 10 << 140;

    QList<int> sizeList2;
    sizeList2 << 10 << 550 << 10 << 10 << 10 << 10;

    QList<int> sizeList3;
    sizeList3 << 100 << 200;
  
    //Splitter's
    QSplitter *v1Splitter = new QSplitter(Qt::Vertical);
      v1Splitter->addWidget(bissecaoLabel);
      v1Splitter->addWidget(tableBis);
      v1Splitter->addWidget(PFLabel);
      v1Splitter->addWidget(tablePF);
      v1Splitter->addWidget(comptbLabel);
      v1Splitter->addWidget(tableComp);
      v1Splitter->addWidget(diastbLabel);
      v1Splitter->addWidget(tableDias);
      v1Splitter->setSizes(sizeList1);
    
    QSplitter *h2Splitter = new QSplitter(Qt::Horizontal);
      h2Splitter->addWidget(qtdDiasLabel);
      h2Splitter->addWidget(qtdDiasLine);
      h2Splitter->setSizes(sizeList3);

    QSplitter *h3Splitter = new QSplitter(Qt::Horizontal);
      h3Splitter->addWidget(prec1Label);
      h3Splitter->addWidget(prec1Line);
      h3Splitter->setSizes(sizeList3);  

    QSplitter *h4Splitter = new QSplitter(Qt::Horizontal);
      h4Splitter->addWidget(prec2Label);
      h4Splitter->addWidget(prec2Line);
      h4Splitter->setSizes(sizeList3);

    QSplitter *v2Splitter = new QSplitter(Qt::Vertical);
      v2Splitter->addWidget(canvasLabel);
      v2Splitter->addWidget(canvas);
      v2Splitter->addWidget(h2Splitter);
      v2Splitter->addWidget(h3Splitter);
      v2Splitter->addWidget(h4Splitter);
      v2Splitter->addWidget(calcButton);
      v2Splitter->setSizes(sizeList2);

    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);
      mainSplitter->addWidget(v2Splitter);
      mainSplitter->addWidget(v1Splitter);
   
    //colocando o widget central como o mainSplitter    
    setCentralWidget(mainSplitter);
    
    createActions();
    createMenus();
    
    //atributo que configura como as janelas irão fechar
    //neste caso, quando uma janela é fechada ela é deletada da memória
    setAttribute(Qt::WA_DeleteOnClose); 
    
    //ícone da janela principal
    setWindowIcon(QIcon(":/imagens/icon.png"));
    
}

//criando as ações do Menu
void JanelaP::createActions()
{

    exitAction = new QAction(tr("&Sair"), this);
    exitAction->setIcon(QIcon(":/imagens/close.png"));
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Sair do Programa"));
    connect(exitAction, SIGNAL(triggered()),
            qApp, SLOT(closeAllWindows()));

    aboutQtAction = new QAction(tr("Sobre &Qt"), this);
    aboutQtAction->setStatusTip(tr("Mostra a Caixa de Dialogo Sobre a QT"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
  
}

/*Cria menu principal*/
void JanelaP::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Arquivo"));
    fileMenu->addAction(exitAction);

    helpMenu = menuBar()->addMenu(tr("A&juda"));
    helpMenu->addAction(aboutQtAction);
    
}


//Ativar o Botão de Calcular
void JanelaP::textoMudou()
{
   calcButton->setEnabled( qtdDiasLine->hasAcceptableInput() && qtdDiasLine->text() != "0"
                           && prec1Line->hasAcceptableInput() && prec1Line->text() != "0"
                           && prec2Line->hasAcceptableInput() && prec2Line->text() != "0");
}

//Método que chama o Método Numérico Escolhido
void JanelaP::calcular()
{
    QString rowAtualS,prec1i,prec2i;
    float rowAtual,prec1,prec2;  
    QList<float> dias;
    QList<float> resultadoBissecao;
    QList<float> resultadoPF;
    QList<float> resultadoComp;
    int critN,critS; //criterio de parada inteiro
      
    //colocando as células vazias e inválidas para 0
    for (int row = 0; row < tableDias->rowCount(); row++)
    {
       for(int i = 0; i < 3; i++)
       {
                     
           //célula vazia
           if(tableDias->item(row, i)->text() == "")
              tableDias->item(row, i)->setText("0");


 
           rowAtualS = tableDias->item(row, i)->text();
           rowAtual = rowAtualS.toFloat();
           dias << rowAtual;   //armazenando as informções dos dias
       }
    }

    //recebendo os valores da interface
    prec1i = prec1Line->text(); 
    prec2i = prec2Line->text(); 

    //convertendo os valores recebidos para float
    prec1 = prec1i.toFloat();
    prec2 = prec2i.toFloat();
    
    tableBis->clear(tableBis->rowCount()); //limpando a tabela do Bissecao
    tablePF->clear(tablePF->rowCount()); //limpando a tabela da PF
    tableComp->clear(tableComp->rowCount()); //limpando a tabela de Comparação 

    //Chamando o método que calcula o Qe para cada Dia pelo
    // método de Bissecao, parte mais importante do programa!
    resultadoBissecao = canvas->Qebissecao(dias, prec1, prec2);
    
    //Chamando o método que calcula o Qe para cada Dia pelo
    // método da posicaofalsa, parte mais importante do programa!
    resultadoPF = canvas->QePF(dias, prec1, prec2);

    //recebendo os valores da tabela de comparação entre os métodos
    resultadoComp = canvas->retornaComp();
 
    critN = (int)resultadoComp[5];
    critS = (int)resultadoComp[11];

    //Gerando a Tabela de Resultados para o Método de Bissecao
    for(int row = 0; row < resultadoBissecao.size(); row += 3)
    {
       tableBis->addRow1(resultadoBissecao,row);
    }

    //Gerando a Tabela de Resultados para o Método do  PF
    for(int row = 0; row < resultadoPF.size(); row += 3)
    {
       tablePF->addRow1(resultadoPF,row);
    }
     
    //Adicionando dados �  tabela de comparação entre os métodos
    tableComp->addRow3("Bissecao",resultadoComp[0],resultadoComp[1],resultadoComp[2],
                       resultadoComp[3],resultadoComp[4],critN);
    tableComp->addRow3("Posicao-Falsa",resultadoComp[6],resultadoComp[7],resultadoComp[8],
                       resultadoComp[9],resultadoComp[10],critS);
    
    

    //zndo o canvas
    canvas->updateGL();

}

//usado para atualizar o número de Dias que serão usados
void JanelaP::atualizarDias()
{
   QString numDias;  //armazena o número de Dias
   int i; //contador
   QList<float> list; //lista de inicialização da tabela de Dias
  
   //no começo todos os valores dos Dias são zero
   list << 0.0 << 0.0 << 0.0 << 0.0;
   
   tableDias->clear(this->numDia);         //limpando a tabela dos Dias
   tableBis->clear(tableBis->rowCount());   //limpando a tabela de Bissecao
   tablePF->clear(tablePF->rowCount());   //limpando a tabela da PF
   tableComp->clear(tableComp->rowCount()); //limpando a tabela de Comparação
 
   numDias = qtdDiasLine->text(); //recebendo o número de Dias do campo de entrada
   this->numDia = numDias.toInt(); //convertendo o número de Dias para inteiro
   
   //para cada Dia, adicione ele na tabela de entrada dos Dias
   for(i = 0; i < (this->numDia); i++)
   {
      list[0]++; //auto-incrementa o número de Dia
      tableDias->addRow2(list);
   }   

}
 
//adiciona delay   
void JanelaP::delay(int iterations)
{
    for(int i = 0; i <= iterations; i++)
    {
          //delay
    }

}

