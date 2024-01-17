#include "includes.hpp"

#include <QtDebug>

#define W 600
#define H 400
#define X 766
#define Y 0
#define OPACITY 0.7

int main(int argc, char **argv){
    QApplication app(argc, argv);
     
    QWidget *widget = new QWidget(NULL, Qt::Tool | Qt::FramelessWindowHint);
    widget->setAttribute(Qt::WA_QuitOnClose);
    widget->resize(W, H);
    widget->move(X, Y);
    widget->setWindowOpacity(OPACITY);
    widget->setWindowTitle("neofetch");
    
    setenv("TERM", "konsole-256color", 1);
    
    QFont font = QApplication::font();
    font.setFamily("Monospace");
    font.setPointSize(8);
    
	
    QTermWidget *console = new QTermWidget(1, widget);
    console->setGeometry(0, 0, W, H);
    console->setTerminalFont(font); 
    console->setColorScheme("GreenOnBlack");
    console->sendText("cd ~/ && clear\r");
    console->sendText("neofetch\r");
 
    QObject::connect(console, SIGNAL(finished()), widget, SLOT(close()));
    

    widget->show();
    return app.exec();
}
