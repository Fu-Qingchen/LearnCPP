#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>
#include <algorithm>
#include <QComboBox>
#include <QKeyEvent>
#include <QDir>
#include <QStandardPaths>
#include <QMessageBox>
#include <typeinfo>
#include <QTableWidget>
#include <QDesktopServices>
#include <QMessageBox>
#include <QAxObject>

#pragma execution_character_set("utf-8")    //解决显示乱码问题


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    init_Statu();
    init_Table();
    init_FilePath();
}

MainWindow::~MainWindow(){
    delete ui;
    delete alipay_statu;
    delete wechat_statu;
}

void MainWindow::on_pushButton_wechat_clicked(){
    QString curPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = "选择微信账单";
    QString filter = "微信账单(*.csv)";
    QString fileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    ui->wechatPath->setText(fileName);
    if(fileName.indexOf("微信支付账单") != -1){ getDataFromWechat(fileName); }
    else{ wechat_statu->setText("微信账单不匹配"); ui->wechatPath->setText("微信账单不匹配"); }
}

void MainWindow::on_pushButton_alipay_clicked(){
    QString curPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = "选择支付宝账单";
    QString filter = "支付宝账单(*.csv)";
    QString fileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    if(fileName.indexOf("alipay_record") != -1){ getDataFromAlipay(fileName); }
    else{ alipay_statu->setText("支付宝账单不匹配"); ui->alipayPath->setText("支付宝账单不匹配"); }
}	

void MainWindow::init_Statu(){
    alipay_statu = new QLabel("支付宝账单未导入");
    alipay_statu->setMinimumWidth(300);
    ui->statusBar->addWidget(alipay_statu);
    wechat_statu = new QLabel("微信账单未导入");
    wechat_statu->setMinimumWidth(300);
    ui->statusBar->addWidget(wechat_statu);
}

void MainWindow::init_Table(){
    ui->tableWidget->clear();
    QStringList headerText;
    ui->tableWidget->setColumnCount(6);
    headerText << "时间" << "交易对方" << "商品名称" << "分类" << "金额" << "状态";
    ui->tableWidget->setHorizontalHeaderLabels(headerText);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void MainWindow::init_FilePath(){
    // 支付宝部分
    QString filePath_alipay = getFilePath(alipayKeyword);
    if (filePath_alipay != QString("")) { getDataFromAlipay(filePath_alipay); }

    // 微信部分
    QString filePath_wechat = getFilePath(wechatKeyword);
    if (filePath_wechat != QString("")) { getDataFromWechat(filePath_wechat); }
}

void MainWindow::insertColumnByIOflow(IOflow &data){
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    // 时间
    QTableWidgetItem *time_item = new QTableWidgetItem(data.tradeTime);
    setTableItemStyle(time_item, data);
    ui->tableWidget->setItem(rowCount, 0, time_item);
    // 交易对方
    QTableWidgetItem *name_item = new QTableWidgetItem(data.name);
    setTableItemStyle(name_item, data);
    ui->tableWidget->setItem(rowCount, 1, name_item);
    // 商品名称
    QTableWidgetItem *item_item = new QTableWidgetItem(data.item);
    setTableItemStyle(item_item, data);
    ui->tableWidget->setItem(rowCount, 2, item_item);
    // 分类
    QComboBox *type_item = new QComboBox();
    if (data.type == In){
        type_item->addItems(statuString);
        type_item->setCurrentIndex(0);
        type_item->setEnabled(false);
    }
    else{
        type_item->addItems(typeString);
        type_item->setCurrentIndex(data.type);
    }
    ui->tableWidget->setCellWidget(rowCount, 3, type_item);
    // 金额
    QTableWidgetItem *value_item = new QTableWidgetItem(QString::number(data.value));
    setTableItemStyle(value_item, data);
    ui->tableWidget->setItem(rowCount, 4, value_item);
    // 状态
    QComboBox *statu_item = new QComboBox();
    statu_item->addItems(statuString);
    statu_item->setCurrentIndex(data.statu);
    ui->tableWidget->setCellWidget(rowCount, 5, statu_item);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    QList<QTableWidgetSelectionRange> ranges = ui->tableWidget->selectedRanges();
    if (event->key() == Qt::Key_Delete){
        if(ranges.count() > 1){
            QMessageBox messageBox;
            messageBox.information(NULL, "提示", "无法删除多块");
            messageBox.show();
            return;
        }
        for(int i = 0; i < ranges.count(); i++){
            int topRow = ranges.at(i).topRow();
            int bottomRow = ranges.at(i).bottomRow();
            for(int j = bottomRow; j >= topRow; j--){ ui->tableWidget->removeRow(j); }
        }
    }
    if (event->matches(QKeySequence::Copy)){
        if(ranges.count() > 0){
            QComboBox *comboBox = static_cast<QComboBox *>(ui->tableWidget->cellWidget(ranges.at(0).topRow(), 3));
            typeInCopy = static_cast<Type>(comboBox->currentIndex());
        }
    }
    if (event->matches(QKeySequence::Paste)){
        if(ranges.count() > 1){
            QMessageBox messageBox;
            messageBox.information(NULL, "提示", "无法粘贴多块");
            messageBox.show();
            return;
        }
        for(int i = 0; i < ranges.count(); i++){
            int topRow = ranges.at(i).topRow();
            int bottomRow = ranges.at(i).bottomRow();
            for(int j = bottomRow; j >= topRow; j--){
                QComboBox *comboBox = static_cast<QComboBox *>(ui->tableWidget->cellWidget(j, 3));
                comboBox->setCurrentIndex(typeInCopy);
            }
        }
    }
}

QString MainWindow::getFilePath(QString keyword){
    // 首先在桌面查找
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir dir(desktop_path);
    QStringList filter{ keyword + "*.csv" };
    QStringList files = dir.entryList(filter, QDir::Files|QDir::Readable, QDir::Name);
    if(files.size() == 1){
        QString file_path = desktop_path + "/" + files.at(0);
        return file_path; }
    else{ return ""; }
}

void MainWindow::getDataFromAlipay(QString fileName){
    ui->alipayPath->setText(fileName);
    alipay_statu->setText("支付宝账单已导入");
    QFile alipayFile(fileName);
    QTextStream alipayStream(&alipayFile);
    alipayStream.setCodec("GBK");
    alipayFile.open(QIODevice::ReadOnly | QIODevice::Text);

    int i = 5;  // 支付宝文件多余的行数
    while (!alipayFile.atEnd()) {
        QStringList sublist = alipayStream.readLine().split(",");
        double temp_value = sublist.at(9).toDouble();
        QString temp_statu_string(sublist.at(15));
        if((!--i) || sublist.at(1) == "" || temp_value == 0 || temp_statu_string == "资金转移     "){ continue; }
        Statu temp_statu;
        temp_statu_string == "已支出      " ? temp_statu = Outcome : temp_statu = Income;
        IOflow temp_ioflow(sublist.at(4), temp_value, sublist.at(7).trimmed(),
                           sublist.at(8).trimmed(), temp_statu);
        insertColumnByIOflow(temp_ioflow); }
    alipayFile.close();

    ui->pushButton_alipay->setEnabled(false);
}

void MainWindow::getDataFromWechat(QString fileName){
    ui->wechatPath->setText(fileName);
    wechat_statu->setText("微信账单已导入");
    QFile wechatFile(fileName);
    QTextStream wechatStream(&wechatFile);
    wechatFile.open(QIODevice::ReadOnly | QIODevice::Text);

    int i = 17;  // 微信文件多余的行数
    while (!wechatStream.atEnd()) {
        QStringList sublist = wechatStream.readLine().split(",");
        QString temp_value = sublist.at(5);
        temp_value.remove(0, 1);
        QString item_string = sublist.at(3);
        item_string.remove('"');
        double temp_value_double = temp_value.toDouble();
        QString temp_statu_string(sublist.at(4));
        if((!--i) || temp_value == 0){ continue; }
        Statu temp_statu;
        temp_statu_string == "支出" ? temp_statu = Outcome : temp_statu = Income;
        IOflow temp_ioflow(sublist.at(0), temp_value_double,
                           sublist.at(2), item_string, temp_statu);
        insertColumnByIOflow(temp_ioflow); }
    wechatFile.close();

    ui->pushButton_wechat->setEnabled(false);
}

// 下面的代码用于实现：将 QTableWidget 输出为 Excel 文件
// 偷懒了，抄的 https://blog.csdn.net/FairyStepWGL/article/details/54576372
//第一个参数是页面上的表格，第二个是导出文件的表头数据

//void MainWindow::Table2ExcelByHtml(QTableWidget *table,QString title){
//    QString fileName = QFileDialog::getSaveFileName(table, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xls *.xlsx)");
//    if (fileName!=""){
//        QAxObject *excel = new QAxObject;
//        if (excel->setControl("Excel.Application")) {   //连接Excel控件
//            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
//            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
//            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
//            workbooks->dynamicCall("Add");//新建一个工作簿
//            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
//            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", );

//            int i,j;
//            //QTablewidget 获取数据的列数
//            int colcount=table->columnCount();
//             //QTablewidget 获取数据的行数
//            int rowscount=table->rowCount();

//            //QTableView 获取列数
//       //int colount=ui->tableview->model->columnCount();
//            //QTableView 获取行数
//       //int rowcount=ui->tableview->model->rowCount();

//            QAxObject *cell,*col;
//            //标题行
//            cell=worksheet->querySubObject("Cells(int,int)", , );
//            cell->dynamicCall("SetValue(const QString&)", title);
//            cell->querySubObject("Font")->setProperty("Size", );
//            //调整行高
//            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", );
//            //合并标题行
//            QString cellTitle;
//            cellTitle.append("A1:");
//            cellTitle.append(QChar(colcount -  + 'A'));
//            cellTitle.append(QString::number());
//            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
//            range->setProperty("WrapText", true);
//            range->setProperty("MergeCells", true);
//            range->setProperty("HorizontalAlignment", -);//xlCenter
//            range->setProperty("VerticalAlignment", -);//xlCenter
//            //列标题
//            for(i=;i<colcount;i++)
//            {
//                QString columnName;
//                columnName.append(QChar(i  + 'A'));
//                columnName.append(":");
//                columnName.append(QChar(i + 'A'));
//                col = worksheet->querySubObject("Columns(const QString&)", columnName);
//                col->setProperty("ColumnWidth", table->columnWidth(i)/);
//                cell=worksheet->querySubObject("Cells(int,int)", , i+);
//                //QTableWidget 获取表格头部文字信息
//                columnName=table->horizontalHeaderItem(i)->text();
//                //QTableView 获取表格头部文字信息
//                // columnName=ui->tableView_right->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
//                cell->dynamicCall("SetValue(const QString&)", columnName);
//                cell->querySubObject("Font")->setProperty("Bold", true);
//                cell->setProperty("HorizontalAlignment", -);//xlCenter
//                cell->setProperty("VerticalAlignment", -);//xlCenter
//            }

//            //数据区

//            //QTableWidget 获取表格数据部分
//            for(i=;i<rowcount;i++){
//                for (j=;j<colcount;j++)
//                {
//                    worksheet->querySubObject("Cells(int,int)", i+, j+)->dynamicCall("SetValue(const QString&)", table->item(i,j)?table->item(i,j)->text():"");
//                }
//            }

//            //QTableView 获取表格数据部分
//            //  for(i=0;i<rowcount;i++) //行数
//            //     {
//            //         for (j=0;j<colcount;j++)   //列数
//            //         {
//            //             QModelIndex index = ui->tableView_right->model()->index(i, j);
//            //             QString strdata=ui->tableView_right->model()->data(index).toString();
//            //             worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
//            //         }
//            //     }

//            //画框线
//            QString lrange;
//            lrange.append("A2:");
//            lrange.append(colcount -  + 'A');
//            lrange.append(QString::number(table->rowCount() + ));
//            range = worksheet->querySubObject("Range(const QString&)", lrange);
//            range->querySubObject("Borders")->setProperty("LineStyle", QString::number());
//            //调整数据区行高
//            QString rowsName;
//            rowsName.append("2:");
//            rowsName.append(QString::number(table->rowCount() + ));
//            range = worksheet->querySubObject("Range(const QString&)", rowsName);
//            range->setProperty("RowHeight", );
//            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
//            workbook->dynamicCall("Close()");//关闭工作簿
//            excel->dynamicCall("Quit()");//关闭excel
//            delete excel;
//            excel=NULL;
//            if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
//            {
//                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
//            }
//        }
//        else
//        {
//            QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
//        }
//    }
//}

