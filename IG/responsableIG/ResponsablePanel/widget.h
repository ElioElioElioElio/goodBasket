#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


/**
 * @brief InterfaceGraphique Responsable
 * @version 1
 * @author CAI Yunfan
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Class  Responsbale
     * @param Qwidget widget de QT
     */
    Widget(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe Responsable
     */
    ~Widget();

private slots:


    /**
     * @brief button de payerProducteur
     */
    void on_PayerProducteur_clicked();

    /**
     * @brief button de rebourser
     */
    void on_Rembourser_clicked();

    /**
     * @brief button de recruterProducteur
     */
    void on_RecruterProducteur_clicked();

    /**
     * @brief button de reporterErreur
     */
    void on_ReporterReports_clicked();

private:
    /**
     * @brief ui de interface responsable
     */
    Ui::Widget *ui;
};
#endif // WIDGET_H
