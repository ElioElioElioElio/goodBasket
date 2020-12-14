#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void setLivraison(const QString & idConsommateur);
    void setLivraisonPrevue(const QString &idConsommateur);

private slots:
    void on_ajouter_panier_clicked();
    void on_supprimer_panier_clicked();
    void on_consulter_catalogue_clicked();
private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
