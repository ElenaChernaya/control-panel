#include <QApplication>
#include "./ui_desing.h"
#include "contolpanelmainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ControlPanelMainWindow window(nullptr);
    Ui::MainWindow design;
    design.setupUi(&window);
    window.label = design.label;
    window.resize(240, 600);
    window.show();

    return app.exec();
}
