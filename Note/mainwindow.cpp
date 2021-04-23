#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QTextStream>
#include<QMessageBox>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QMenuBar>
#include <QFontDialog>
#include <QDirIterator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setbackground();
    file_path="";
    this->setWindowTitle("NOTE");
    this->setCentralWidget(ui->window_write);
    connect(ui->window_write,SIGNAL(textChanged()),this, SLOT(text_color_changed()));
    set_shortcut_key();
    setWindowIcon(QIcon(":/image/images (3).jpg"));

    QObject::connect(ui->window_write,SIGNAL(textChanged()),this,SLOT(call_increase_count()));
    int i=0;
    QFile file(QDir::homePath()+"/Note_data.txt");
    if(!file.open(QFile::WriteOnly |QFile::ReadOnly | QFile::Text)){
     QMessageBox::warning(this,"Error","Required file cannot be created");
    }
    QTextStream output(&file);
    QDirIterator an(QDir::homePath());
    while(an.hasNext()){
            if(an.next()==(QDir::homePath()+"/Note_data.txt")){i=1;break;}
    }
    if(i==0){
        output<<"";
        file.flush();
    }
    QString data_read=output.readAll();
    QFont font=QFont(data_read);
    font.setPointSize(9);
    ui->window_write->setFont(font);
    file.close();
 }

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::call_increase_count()
{
store_count=1;

}

void MainWindow::setbackground()
{
ui->window_write->setStyleSheet("background-image: url(:/image/back.jpg)");
ui->window_write->setTextColor(QColor("white"));
}

void MainWindow::read_font(){
    QFile font_read(":/image/Note_data.txt");
}
void MainWindow::set_shortcut_key()
{
    QShortcut *for_cut=new QShortcut(QKeySequence("ctrl+shift+x"),this);
    QObject::connect(for_cut, SIGNAL(activated()),this,SLOT(cut_text()));
    QShortcut *for_copy=new QShortcut(QKeySequence("ctrl+shift+c"), this);
    QObject::connect(for_copy, SIGNAL(activated()),this,SLOT(copy_text()));
    QShortcut *for_paste=new QShortcut(QKeySequence("ctrl+shift+v"),this);
    QObject::connect(for_paste, SIGNAL(activated()),this,SLOT(paste_text()));
    QShortcut *for_undo=new QShortcut(QKeySequence("ctrl+u"), this);
    QObject::connect(for_undo, SIGNAL(activated()),this,SLOT(undo_text()));
    QShortcut *for_redo=new QShortcut(QKeySequence("ctrl+r"), this);
    QObject::connect(for_redo, SIGNAL(activated()),this,SLOT(redo_text()));
   // QShortcut *for_find=new QShortcut(QKeySequence("ctrl+f"), this);
    //QObject::connect(for_find, SIGNAL(activated()),this,SLOT(find_text()));
    QShortcut *for_open=new QShortcut(QKeySequence("ctrl+o"),this);
    QObject::connect(for_open,SIGNAL(activated()),this,SLOT(check_open()));
    QShortcut *for_save=new QShortcut(QKeySequence("ctrl+s"),this);
    QObject::connect(for_save,SIGNAL(activated()),this,SLOT(save_file()));
    QShortcut *for_save_as=new QShortcut(QKeySequence("ctrl+shift+s"),this);
    QObject::connect(for_save_as,SIGNAL(activated()),this,SLOT(check_save_as()));
    QShortcut *for_new=new QShortcut(QKeySequence("ctrl+shift+n"),this);
    QObject::connect(for_new,SIGNAL(activated()),this,SLOT(new_file()));
    QShortcut *for_font_change= new QShortcut(QKeySequence("ctrl+f"),this);
    QObject::connect(for_font_change,SIGNAL(activated()),this,SLOT(change_font()));
}


void MainWindow::text_color_changed()
{
    ui->window_write->setTextColor(QColor("white"));
}

void MainWindow::find_text()
{
 statusBar()->showMessage("Search for a text.",2000);

}

void MainWindow::copy_text()
{
ui->window_write->copy();
statusBar()->showMessage("Text copied.",2000);
}

void MainWindow::cut_text()
{
statusBar()->showMessage("Cut.",2000);
    ui->window_write->cut();
}

void MainWindow::paste_text()
{
    statusBar()->showMessage("Paste.",2000);
if(ui->window_write->canPaste()){

    ui->window_write->paste();
}
}

void MainWindow::redo_text()
{
     statusBar()->showMessage("Redo.",1000);
    ui->window_write->redo();
}
void MainWindow::undo_text()
{
     statusBar()->showMessage("Undo.",1000);
    ui->window_write->undo();
    //QObject::connect(ui->window_write,SIGNAL(undoAvailable(bool)),ui->window_write,SLOT(undo_available(bool)));

}


void MainWindow::check_open()
{
     statusBar()->showMessage("Open file.",2000);
    QString file_name=QFileDialog::getOpenFileName(this,"Open the file.");
    file_path=file_name;
    if(!file_name.isEmpty()){
       open_file(file_name);
    }
//    QTextStream out(stdout);
//    out<<file_name;
}

void MainWindow::open_file(QString file_name)
{

    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Error opening the file.");
        return;
    }
    QTextStream input(&file);
    QString text_read= input.readAll();
    ui->window_write->setText(text_read);
    file.close();
    store_count=0;
}
void MainWindow::save_file()
{

    while(true){
    if(file_path==""){check_save_as();break;}
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Error saving the file.");
        return;
    }
    statusBar()->showMessage("file saved.",2000);
    store_count=0;
    QString text_write=ui->window_write->toPlainText();
    QTextStream output(&file);
    output<<text_write;
    file.flush();
    file.close();
    break;
}}

void MainWindow::check_save_as()
{
     statusBar()->showMessage("Save file as",2000);
     QString file_name=QFileDialog::getSaveFileName(this,"save file as");
     file_path=file_name;
     if(!file_name.isEmpty()){
         save_as_file(file_name);
     }
}

void MainWindow::save_as_file(QString file_name)
{
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Error saving the file.");
        return;
    }
    QTextStream output(&file);
    QString text_write=ui->window_write->toPlainText();
    output<<text_write;
    file.flush();
    file.close();
    store_count=0;
}

void MainWindow::closeEvent(QCloseEvent *close)
{   if(store_count==1){
    if (file_path!=""){
    QMessageBox::StandardButton button = QMessageBox::question(this,"Unsaved changes.", "Close anyway?",QMessageBox::Yes|QMessageBox::No | QMessageBox::Save);
    if (button==QMessageBox::Yes){close->accept();}
    else if(button==QMessageBox::Save){
        save_file();

    }
    else{ close->ignore();}
}}}
void MainWindow::new_file()
{
     statusBar()->showMessage("Opening new file.",1000);
    ui->window_write->setText("");
    file_path="";
}

void MainWindow::change_font()
{
    bool to_check;
    QFont set_font= QFontDialog::getFont(&to_check,this);
    if(to_check){
        ui->window_write->setFont(set_font);
        QString font_name=set_font.family();
        QString data_path="/Note_data.txt";
      // QTextStream out(stdout);
       //out<<font_name;

        QFile font_read(QDir::homePath()+data_path);
        if(!font_read.open(QFile::WriteOnly|QFile::Text)){
            QMessageBox::warning(this," Error! ","Error writing the font"); }
        QTextStream output(&font_read);
        output<<font_name;
        font_read.flush();
        font_read.close();
        }

    else
        return;
}

int MainWindow::store_count=0;

//void MainWindow::undo_available(bool available)
//{
//    if(available){
//        ui->window_write->undo();
//    }
//}

//void MainWindow::redo_available(bool available)
//{
//    if(available){
//        ui->window_write->redo();
//    }
//}

