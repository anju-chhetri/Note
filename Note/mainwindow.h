#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void open_file(QString file_name);
private:
    void open_new_file();
    void setbackground();
    void set_key();
    void closeEvent(QCloseEvent *close );
    QString file_path;
    QString before_text;
    static int store_count;

public slots:
    void show_information();
    void return_richText();
    void MarkDown();
    void HTML();
    void plainText();
    void close_application();
    void about();
    void text_color_changed();
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
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
