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
#include <QLabel>
#include <QInputDialog>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("NOTE"));
    this->setCentralWidget(ui->window_write);
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
    file.close();
    QFont font=QFont(data_read);
    font.setPointSize(12);
    ui->window_write->setFont(font);
    this->setGeometry(500,150,900,800);
    set_key();
    this->setFocusPolicy(Qt::NoFocus);
    ui->window_write->setStyleSheet("QTextEdit{outline:none}");

    ui->window_write->setStyleSheet("QTextEdit"
                                  "{border-width: 1px;"
                                  "border-color: #1e1e1e;"
                                  "border-style: solid;border-radius: 6;"
                                  "background-image: url(:/image/#FBF0D9.jpg)"
                                    "}");

    ui->window_write->setAcceptRichText(false);
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::call_increase_count(){
    QTextCursor cursor = ui->window_write->textCursor();
    int row = cursor.blockNumber();
    int col = cursor.columnNumber() + 1;
    statusBar()->showMessage("R : "+QString::number(row+1)+" | C: "+QString::number(col));
    QString ui_words = ui->window_write->toPlainText();
    QStringList words = ui_words.split(" ");
    if(input_cmd==1)
        statusBar()->showMessage("R : "+QString::number(row+1)+" | C: "+QString::number(col)+"\t\t\t  total words: "+QString::number(words.length()-1));
    store_count=1;
    if (file_path==""){
        setWindowTitle("[UNNAMED]");
    }
    else{   setWindowTitle("*"+QFileInfo(file_path).fileName());}

}



void MainWindow::set_key()
{
    QShortcut *for_undo=new QShortcut(QKeySequence("ctrl+u"), this);
    QObject::connect(for_undo, SIGNAL(activated()),this,SLOT(undo_text()));
    QShortcut *for_redo=new QShortcut(QKeySequence("ctrl+r"), this);
    QObject::connect(for_redo, SIGNAL(activated()),this,SLOT(redo_text()));
    QShortcut *for_open=new QShortcut(QKeySequence("ctrl+o"),this);
    QObject::connect(for_open,SIGNAL(activated()),this,SLOT(check_open()));
    QShortcut *for_save=new QShortcut(QKeySequence("ctrl+s"),this);
    QObject::connect(for_save,SIGNAL(activated()),this,SLOT(save_file()));
    QShortcut *for_save_as=new QShortcut(QKeySequence("ctrl+shift+s"),this);
    QObject::connect(for_save_as,SIGNAL(activated()),this,SLOT(check_save_as()));
    QShortcut *for_new=new QShortcut(QKeySequence("ctrl+n"),this);
    QObject::connect(for_new,SIGNAL(activated()),this,SLOT(new_file()));
    QShortcut *for_font_change= new QShortcut(QKeySequence("ctrl+f"),this);
    QObject::connect(for_font_change,SIGNAL(activated()),this,SLOT(change_font()));
    QShortcut *for_README = new QShortcut(QKeySequence("ctrl+k"),this);
    QObject::connect(for_README,SIGNAL(activated()),this,SLOT(call_other_class()));
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
    QShortcut *for_input_cmd = new QShortcut(QKeySequence("ctrl+shift+i"),this);
    QObject::connect(for_input_cmd,SIGNAL(activated()),this,SLOT(get_input_cmd()));

}


void MainWindow::redo_text()
{
 ui->window_write->redo();
}

void MainWindow::undo_text()
{
 ui->window_write->undo();
}

void MainWindow::check_open()
{
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
    this->setWindowTitle(QFileInfo(file_path).fileName());
    store_count=0;
    break;
}}

void MainWindow::check_save_as()
{
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
    this->setWindowTitle("[UNNAMED]");
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



void MainWindow::about(){QMessageBox::about(this,"About","This editor was designed"
                                            " to reduce the use of\nmouse as much as possible. "
                                   "All the key combination can be seen by pressing Ctrl+k.  ");}
void MainWindow::close_application(){QApplication::closeAllWindows();}




void MainWindow::MarkDown(){
    before_text = ui->window_write->toPlainText();
    QString text = before_text;
    ui->window_write->setMarkdown(text);
}

void MainWindow::HTML(){
    before_text = ui->window_write->toPlainText();
    QString text = before_text;
    ui->window_write->setHtml(text);
}

void MainWindow::plainText(){
    before_text = ui->window_write->toPlainText();
    QString text=before_text;
    ui->window_write->setPlainText(text);
}

void MainWindow::return_richText(){
    if(before_text!=""){
         ui->window_write->setPlainText(before_text);}
    before_text="";

}


void MainWindow::get_input_cmd(){
    bool ok;
    QString input_text = QInputDialog::getText(this, tr("Command"),
                      tr("Input Command:"), QLineEdit::Normal,tr(""), &ok,Qt::WindowFlags(
                      Qt::WindowTitleHint));
    if(ok){
        if(input_text == "word count")
            input_cmd=1;
        else if(input_text == "word count -o")
            input_cmd=0;
        else
            statusBar()->showMessage("No such command found.",1000);
    }
    int row = ui->window_write->textCursor().blockNumber();
    int col = ui->window_write->textCursor().positionInBlock();
    if(input_cmd==0)
            statusBar()->showMessage("R : "+QString::number(row+1)+" | C: "+QString::number(col));

}


void MainWindow::keyPressEvent(QKeyEvent *event){
if(event->key()==61)
    ui->window_write->zoomIn(1);
if(event->key()==45)
    ui->window_write->zoomOut(1);

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
}

}

int MainWindow::store_count=0;
int MainWindow::input_cmd=0;



void MainWindow::call_other_class(){
For_key::show_information();
}
void For_key::show_information(){
   delete la;
   la = new QLabel;
   la->setText("Key Combinations :\n"
                           "\nCtrl+Shift+s = Save_as\nCtrl+n = New file"
                           "\nCtrl+u = Undo\nCtrl+r = Redo\nCtrl+o = Open file\nCtrl+s = Save file"
                           "\nCtrl+f = Open Font dialog box\nCtrl+k = Display key information"
                           "\nCtrl+i = Display information about Note\nCtrl+w = Quit the application"
                           "\nCtrl+h = Display text in HTML format \nCtrl+m = Display text in markdown format"
                           "\nCtrl+t = Display the text in Plain text format \nCtrl+b = Return from current format to pervious one"
               "\nCtrl+Plus(+) = ZoomIn"
               "\nCtrl+Minus(-) = ZoomOut"
               "\nCtrl+Shift+i = Open command box."
                           "\n cmd: word count : Display total number of words."
                           "\n         word count -o : Stop showing the word number."
               );

    QFont font ;
    font.setPointSize(11);
    la->setFont(font);
    la->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    la->show();
}
For_key::~For_key(){
    delete la;
}

