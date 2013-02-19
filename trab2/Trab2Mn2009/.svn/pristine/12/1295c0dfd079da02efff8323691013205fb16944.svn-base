#include <QSplitter>
#include <QLabel>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QRegExp>
#include <QStringList>

#include <cmath>

#include "frmPrincipal.h"
#include "sistema.h"

frmPrincipal::frmPrincipal() {
  this -> setWindowTitle(tr("XTocator2"));
  //Expressao regular para numero nao negativo
  QRegExp regExp1("[0-9]{1,}");

  //Criacao dos objetos

  edtNumDias = new QLineEdit(this);
  edtNumDias -> setValidator(new QRegExpValidator(regExp1, this));

  matriz = new QTableWidget(this);
  resultados = new QTableWidget(this);
  btnCalcular = new QPushButton(tr("&Calcular"), this);
  btnCalcular -> setEnabled(false);

  //eventos
  connect(edtNumDias,SIGNAL(textChanged(QString)), this, SLOT(textoMudou(QString)));
  connect(btnCalcular, SIGNAL(clicked()), this, SLOT(cliqueCalcular()));

  //Tamanhos para os splitters
  QList<int> sizeList1;
  sizeList1 << 100 << 200;

  QList<int> sizeList2;
  sizeList2 << 10 << 10 << 500 << 10;

  //Splitters
  QSplitter *h1Splitter = new QSplitter(Qt::Horizontal);
  h1Splitter -> addWidget(new QLabel(tr("Qtd. de Produtos:"), this));
  h1Splitter -> addWidget(edtNumDias);
  h1Splitter -> setSizes(sizeList1);

  QSplitter *v1Splitter = new QSplitter(Qt::Vertical);
  v1Splitter -> addWidget(h1Splitter);
  v1Splitter -> addWidget(new QLabel(tr("Matriz do sistema de Produtos:"), this));
  v1Splitter -> addWidget(matriz);
  v1Splitter -> addWidget(btnCalcular);
  v1Splitter -> setSizes(sizeList2);

  QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);
  mainSplitter -> addWidget(v1Splitter);
  mainSplitter -> addWidget(resultados);

  setCentralWidget(mainSplitter);
}

void frmPrincipal::textoMudou(QString texto) {
  if (edtNumDias -> hasAcceptableInput()) {
    int valor = texto.toInt();

    if (valor != 0) {
      matriz -> setRowCount(valor);
      matriz -> setColumnCount(valor);

      for (int i = 0; i < valor; i++) {
        for (int j = 0; j <= valor; j++) {
          QTableWidgetItem *item = new QTableWidgetItem(tr("1"));
          matriz -> setItem(i, j, item);
        }
      }

      btnCalcular -> setEnabled(true);
    } else {
      matriz -> setRowCount(0);
      matriz -> setColumnCount(0);

      btnCalcular -> setEnabled(false);
    }
  } else {
    matriz -> setRowCount(0);
    matriz -> setColumnCount(0);

    btnCalcular -> setEnabled(false);
  }
}

void frmPrincipal::cliqueCalcular() {
  int numlinhas = matriz -> rowCount();
  int numcolunas = numlinhas ;

  float **valores = new float*[numlinhas];

  for (int i = 0; i < numlinhas; i++) {
    valores[i] = new float[numcolunas];

    for (int j = 0; j < numcolunas; j++) {
      QTableWidgetItem *atual = matriz -> item(i, j);

      float valor = atual -> text().toFloat();

      valores[i][j] = valor;
    }
  }

  Sistema s((float**)valores, numlinhas, numcolunas);

  resultados -> setRowCount(1);
  resultados -> setColumnCount(1);

  QStringList listStr;

  listStr << "Qe" ;

  resultados -> setHorizontalHeaderLabels(listStr);

    float Qe = s.getQe(0);

    QString strQe;

    strQe.setNum(Qe);

    QTableWidgetItem *novoQe = new QTableWidgetItem(strQe);

    resultados -> setItem(0, 0, novoQe);

}
