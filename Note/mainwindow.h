#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void setbackground();
    void set_shortcut_key();
    void open_file(QString file_name);
    void save_as_file(QString file_name);
    void closeEvent(QCloseEvent *close );
    QString file_path;
public slots:
    void text_color_changed();
    void find_text();
    void copy_text();
    void cut_text();
    void paste_text();
    void redo_text();
    void undo_text();
    void save_file();
    void check_save_as();
    void check_open();
    void new_file();
private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
