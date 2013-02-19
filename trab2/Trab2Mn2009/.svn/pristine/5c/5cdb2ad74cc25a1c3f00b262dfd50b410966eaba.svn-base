#ifndef __FRMPRINCIPAL_H__

#define __FRMPRINCIPAL_H__

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGridLayout>
#include <QPushButton>

class frmPrincipal: public QMainWindow {
  Q_OBJECT

  private:
    QTableWidget *matriz;
    QTableWidget *resultados;
    QLineEdit *edtNumDias;
    QPushButton *btnCalcular;
  public:
    frmPrincipal();
  public slots:
    void textoMudou(QString texto);
    void cliqueCalcular();
};

#endif /* __FRMPRINCIPAL_H__ */
