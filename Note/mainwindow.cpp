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
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setbackground();
    this->setWindowTitle("NOTE");
    this->setCentralWidget(ui->window_write);
    set_shortcut_key();
    setWindowIcon(QIcon(":/image/icon1.jpg"));
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
        output<<"Bell MT";
        file.flush();
    }

    QString data_read=output.readAll();
    QFont font=QFont(data_read);
    font.setPointSize(12);
    ui->window_write->setFont(font);
    file.close();
    this->setGeometry(500,150,900,800);

 }

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::call_increase_count(){
    store_count=1;
    if (file_path==""){
        setWindowTitle("Untitled file");
    }
    else{   setWindowTitle("*"+QFileInfo(file_path).fileName());}
            }


void MainWindow::setbackground()
{
ui->window_write->setStyleSheet("background-image: url(:/image/test1.jpg)");
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
    QShortcut *for_README = new QShortcut(QKeySequence("ctrl+d"),this);
    QObject::connect(for_README,SIGNAL(activated()),this,SLOT(show_information()));
    QShortcut *for_about=new QShortcut(QKeySequence("ctrl+i"),this);
    QObject::connect(for_about,SIGNAL(activated()),this,SLOT(about()));
    QShortcut *for_close =new QShortcut(QKeySequence("ctrl+w"),this);
    QObject::connect(for_close,SIGNAL(activated()),this,SLOT(close_application()));
    QShortcut *for_markdown = new QShortcut(QKeySequence("ctrl+m"),this);
    QObject::connect(for_markdown,SIGNAL(activated()),this,SLOT(MarkDown()));
    QShortcut *for_html = new QShortcut(QKeySequence("ctrl+h"),this);
    QObject::connect(for_html,SIGNAL(activated()),this,SLOT(HTML()));
    QShortcut *for_plainText=new QShortcut(QKeySequence("ctrl+t"),this);
    QObject::connect(for_plainText,SIGNAL(activated()),this,SLOT(plainText()));
    QShortcut *for_rich_text= new QShortcut(QKeySequence("ctrl+b"),this);
    QObject::connect(for_rich_text,SIGNAL(activated()),this,SLOT(return_richText()));
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

}





void MainWindow::check_open()
{
    statusBar()->showMessage("Open file.",2000);
    QString file_name=QFileDialog::getOpenFileName(this,"Open the file.");
    file_path=file_name;
    if(!file_name.isEmpty()){
       open_file(file_name);
    }
}

void MainWindow::open_file(QString file_name)
{

    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Error opening the file.");
        return;
    }

    file_path = file_name;
    QTextStream input(&file);
    QString text_read= input.readAll();
    ui->window_write->setText(text_read);
    this->setWindowTitle(QFileInfo(file_name).fileName());
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

    QString text_write=ui->window_write->toPlainText();
    QTextStream output(&file);
    output<<text_write;
    file.flush();
    file.close();
    statusBar()->showMessage("file saved.",2000);
    this->setWindowTitle(QFileInfo(file_path).fileName());
    store_count=0;
    break;
}}

void MainWindow::check_save_as()
{
     statusBar()->showMessage("Save file as",2000);
     QString file_name=QFileDialog::getSaveFileName(this,"save file as");
     file_path=file_name;
     if(!file_name.isEmpty()){
         save_file();
     }
}


void MainWindow::new_file()
{
    QMessageBox::StandardButton ask;
    if(store_count==1){
         ask= QMessageBox::question(this,"Open New file?","Some changes are to be saved.\n Open anyway?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Save);
         if(ask==QMessageBox::Yes){open_new_file();}
         if(ask==QMessageBox::No){return;}
         if(ask==QMessageBox::Save){
             save_file();
             if(file_path==""){return;}
             open_new_file();
         }

    }
    else if(store_count==0){open_new_file();}


}
void MainWindow::open_new_file(){
    statusBar()->showMessage("Opening new file.",1000);
    ui->window_write->setText("");
    file_path="";
    this->setWindowTitle("New file");
    store_count=0;
        }

void MainWindow::change_font()
{
    bool to_check;
    QFont set_font= QFontDialog::getFont(&to_check,this);
    if(to_check){
        ui->window_write->setFont(set_font);
        QString font_name=set_font.family();
        QString data_path="/Note_data.txt";

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



void MainWindow::about(){QMessageBox::information(this,"About","This editor was designed to reduce the use of\nmouse as much as possible. All the key combination can be seen in Note_data file by pressing Ctrl+d.  ");}
void MainWindow::close_application(){QApplication::closeAllWindows();}




void MainWindow::MarkDown(){
    before_text = ui->window_write->toPlainText();
    QString text = ui->window_write->toPlainText();
    ui->window_write->setStyleSheet("background-image: url(:/image/test1.jpg);");
    ui->window_write->setMarkdown(text);
}

void MainWindow::HTML(){
    before_text = ui->window_write->toPlainText();
    QString text = ui->window_write->toPlainText();
    ui->window_write->setStyleSheet("background-image: url(:/image/test1.jpg);");
    ui->window_write->setHtml(text);
}

void MainWindow::plainText(){
    before_text = ui->window_write->toPlainText();
    QString text=ui->window_write->toPlainText();
    ui->window_write->setStyleSheet("background-image: url(:/image/test1.jpg);");
    ui->window_write->setPlainText(text);
}

void MainWindow::return_richText(){
    if(before_text!=""){ ui->window_write->setText(before_text);}
    before_text="";
}

void MainWindow::closeEvent(QCloseEvent *close)
{   if(store_count==1){
    QMessageBox::StandardButton button = QMessageBox::question(this,"Unsaved changes.", "Close anyway?",QMessageBox::Yes|QMessageBox::No | QMessageBox::Save);
    if (button==QMessageBox::Yes){close->accept();}
    else if(button==QMessageBox::Save){
        save_file();
        if(file_path==""){close->ignore();}

    }
    else{ close->ignore();}
}}


int MainWindow::store_count=0;



void MainWindow::show_information(){

    QMessageBox::about(this,"Key details","ShortCut keys used in Note:"
                 "\nCtrl+Shift +x = Cut \nCtrl+Shift+c  = Copy"
                 "\nCtrl+Shift+v = Paste \nCtrl+Shift+s = Save_as\nCtrl+Shift+n = New file"
                 "\nCtrl+u = Undo\nCtrl+r = Redo\nCtrl+o = Open file\nCtrl+s = Save file"
                 "\nCtrl+f = Open Font dialog box\nCtrl+d = Display key information"
                 "\nCtrl+i = Display information about Note\nCtrl+w = Quit the application"
                 "\nCtrl+h = Display text in HTML format \nCtrl+m = Display text in markdown format"
                 "\nCtrl+t = Display the text in Plain text format \nCtrl+b = Return from current format to pervious one"
         );
}




/*

    QLabel *txt = new QLabel();
    txt->setText("ShortCut keys used in Note:"
                           "\nCtrl+Shift +x = Cut \nCtrl+Shift+c  = Copy"
                           "\nCtrl+Shift+v = Paste \nCtrl+Shift+s = Save_as\nCtrl+Shift+n = New file"
                           "\nCtrl+u = Undo\nCtrl+r = Redo\nCtrl+o = Open file\nCtrl+s = Save file"
                           "\nCtrl+f = Open Font dialog box\nCtrl+d = Display key information"
                           "\nCtrl+i = Display information about Note\nCtrl+w = Quit the application"
                           "\nCtrl+h = Display text in HTML format \nCtrl+m = Display text in markdown format"
                           "\nCtrl+t = Display the text in Plain text format \nCtrl+b = Return from current format to pervious one"
                   );
    txt->show();



void MainWindow::README(){
    file_path=QDir::homePath()+"/README_Note.txt";
    open_file(file_path);

}


void MainWindow::for_ReadMe_File(){
    int i=0;
    QDirIterator ite(QDir::homePath());
    while(ite.hasNext()){
        if(ite.next()==(QDir::homePath()+"/README_Note.txt")){i=1;break;}
    }
    if(i==0){
        QFile file(QDir::homePath()+"/README_Note.txt");
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this,"Error","Error creating README file.");
                    }
        QTextStream display(&file);
        display<<"ShortCut key used in Note: \n\nCtrl+Shift +x = Cut \nCtrl+Shift+c  = Copy\nCtrl+Shift+v = Paste \nCtrl+Shift+s = Save_as\nCtrl+Shift+n = New file\nCtrl+u = Undo \nCtrl+r = Redo\nCtrl+o = Open file\nCtrl+s = Save file\nCtrl+f = Open Font dialog box\nCtrl+d = Display README.txt file\n";
        file.flush();
        file.close();
    }}*/
