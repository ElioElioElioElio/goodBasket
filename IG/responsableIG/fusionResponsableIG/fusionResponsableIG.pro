QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ../gestionOuverturePCIG/gestionouverturepcpanel.cpp \
    ../ResponsablePanel/erreursousig.cpp \
    ../ResponsablePanel/consommateursousig.cpp \
    ../ResponsablePanel/livraisonsousig.cpp \
    ../ResponsablePanel/producteursousig.cpp \
    ../ResponsablePanel/produitsousig.cpp \
    ../ResponsablePanel/producteuritemsousig.cpp \
    ../../../pc.cpp \
    ../../../utilisateur.cpp \
    ../../../producteur.cpp \
    ../../../produit.cpp \
    ../../../responsable.cpp \
    ../formulaireCycle/formulairecycle.cpp \
    ../../../Outils/sqltool.cpp \
    ../../../Outils/idgenerator.cpp \
    ../ResponsablePanel/widgetresponsable.cpp \
    ../../GestionnaireIG/Gestionnaire/erreursousgestionnaire.cpp \
    ../../GestionnaireIG/Gestionnaire/gestionnaireig.cpp \
    ../../GestionnaireIG/Gestionnaire/pcsousig.cpp \
    fusionresponsableig.cpp

HEADERS += \
    ../../../pc.h \
    ../gestionOuverturePCIG/gestionouverturepcpanel.h \
    ../ResponsablePanel/erreursousig.h \
    ../ResponsablePanel/consommateursousig.h \
        ../ResponsablePanel/livraisonsousig.h \
    ../ResponsablePanel/producteursousig.h \
    ../ResponsablePanel/produitsousig.h \
    ../ResponsablePanel/producteuritemsousig.h \
    ../../../utilisateur.h \
    ../../../producteur.h \
    ../../../produit.h \
    ../../../responsable.h \
    ../../../Outils/sqltool.h \
    ../../../Outils/idgenerator.h \
    ../formulaireCycle/formulairecycle.h \
    ../ResponsablePanel/widgetresponsable.h \
    ../../GestionnaireIG/Gestionnaire/erreursousgestionnaire.h \
    ../../GestionnaireIG/Gestionnaire/gestionnaireig.h \
    ../../GestionnaireIG/Gestionnaire/pcsousig.h \
    fusionresponsableig.h

FORMS += \
    ../formulaireCycle/formulairecycle.ui \
    ../ResponsablePanel/consommateursousig.ui \
    ../ResponsablePanel/livraisonsousig.ui \
    ../gestionOuverturePCIG/gestionouverturepcpanel.ui \
    ../ResponsablePanel/widgetresponsable.ui \
    ../ResponsablePanel/producteursousig.ui \
    ../ResponsablePanel/producteuritemsousig.ui \
    ../ResponsablePanel/erreursousig.ui \
    ../ResponsablePanel/produitsousig.ui \
    ../../GestionnaireIG/Gestionnaire/erreursousgestionnaire.ui \
    ../../GestionnaireIG/Gestionnaire/gestionnaireig.ui \
    ../../GestionnaireIG/Gestionnaire/pcsousig.ui \
    fusionresponsableig.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
