#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class For_key{
public:
    ~For_key();
    QLabel *la=nullptr;
    void show_information();
};

class MainWindow : public QMainWindow,public For_key
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void open_file(QString file_name);
private:
    void open_new_file();
    void set_key();
    void closeEvent(QCloseEvent *close );
    QString file_path;
    QString before_text;
    static int store_count;
    static int input_cmd;
public slots:
    void get_input_cmd();
    void return_richText();
    void MarkDown();
    void HTML();
    void plainText();
    void close_application();
    void about();
    void copy_text();
    void cut_text();
    void paste_text();
    void redo_text();
    void undo_text();
    void save_file();
    void check_save_as();
    void check_open();
    void new_file();
    void change_font();
    void call_increase_count();
    void call_other_class();
private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
