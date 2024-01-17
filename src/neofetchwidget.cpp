#include "includes.hpp"

#include <QtDebug>

int main(int argc, char **argv){
    QApplication app(argc, argv);
     
    QWidget *widget = new QWidget(NULL, Qt::Tool | Qt::FramelessWindowHint);
    widget->setAttribute(Qt::WA_QuitOnClose);
    widget->resize(600, 400);
    widget->move(766, 0);
    widget->setWindowOpacity(0.7);
    widget->setWindowTitle("neofetch");
    
    setenv("TERM", "konsole-256color", 1);
    
    QFont font = QApplication::font();
    font.setFamily("Monospace");
    font.setPointSize(8);
    
	
    QTermWidget *console = new QTermWidget(1, widget);
    console->setGeometry(0, 0, 600, 400);
    console->setTerminalFont(font); 
    console->setColorScheme("GreenOnBlack");
    console->sendText("cd ~/Desktop && clear\r");
    console->sendText("neofetch\r");
 
    QObject::connect(console, SIGNAL(finished()), widget, SLOT(close()));
    

    widget->show();
    return app.exec();
}
