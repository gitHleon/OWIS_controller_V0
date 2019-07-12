#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <iostream>
#include <QPushButton>
#include <windows.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <conio.h>
#include <QTimer>

//function to write in appropriate way exadecimal number to ultimusV
QByteArray int_tohexQByteArray_UltimusV(int input){
    auto && oss = std::ostringstream();
    oss << std::hex << std::setw(2) << std::setfill('0')
        << input;
    auto && buf = oss.str();
    //add the stx
    QByteArray writeData = QByteArray(buf.c_str());
    for(int i=0;i<writeData.size();i++){
        switch (writeData[i]) {
        case 'a' : writeData[i] = 'A'; break;
        case 'b' : writeData[i] = 'B'; break;
        case 'c' : writeData[i] = 'C'; break;
        case 'd' : writeData[i] = 'D'; break;
        case 'e' : writeData[i] = 'E'; break;
        case 'f' : writeData[i] = 'F'; break;
        default: break;
        }
    }
    return writeData;
}


bool OWIS_controller::TalkSR232( const std::vector<std::string> &arguments){
    //    int stx = 2;
    //    int etx = 3;
    //    int eot = 4;
    //    int enq = 5;
    //    int ack = 6;
    //    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
    //            std::cout << "Name : " << info.portName().toLocal8Bit().constData()<<std::endl;
    //            std::cout << "Description : " << info.description().toLocal8Bit().constData()<<std::endl;
    //            std::cout << "Manufacturer: " << info.manufacturer().toLocal8Bit().constData()<<std::endl;
    //            // Example use QSerialPort
    //            QSerialPort serial;
    //            serial.setPort(info);
    //            if (serial.open(QIODevice::ReadWrite))
    //                serial.close();
    //        }
    bool debug = true;
    QByteArray readData;
    QByteArray writeData;
    QSerialPort serialPort;
    const QString serialPortName = "COM4"; //to modify according to the serial port used
    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(QSerialPort::Baud115200); // set BaudRate to 115200
    serialPort.setParity(QSerialPort::NoParity); //set Parity Bit to None
    serialPort.setStopBits(QSerialPort::OneStop); //set
    serialPort.setDataBits(QSerialPort::Data8); //DataBits to 8
    serialPort.setFlowControl(QSerialPort::NoFlowControl);
    serialPort.close();
    if (!serialPort.open(QIODevice::ReadWrite)) {
        std::cout<<"FAIL!!!!!"<<std::endl;
        qWarning("Failed to open port %s, error: %s",serialPortName.toLocal8Bit().constData(),serialPort.errorString().toLocal8Bit().constData());
        return false;
    }else {
        if (debug)
            std::cout<<"Port opened successfully"<<std::endl;
    }

    writeData = QByteArrayLiteral("\x05"); //sending enquiry command
    long long int output = 0;
    output = serialPort.write(writeData);
    if (debug)
        std::cout<<"Log >> bytes written   : "<<output<<" : operation : "<<writeData.toStdString()<<std::endl;
    if(output == -1){
        std::cout<<"Error write operation : "<<writeData.toStdString()
                << " => " << serialPort.errorString().toStdString()<<std::endl;
        return false;
    }

    readData.clear();
    int control = 0;
    while(serialPort.isOpen()){ // READING BYTES FROM SERIAL PORT
        control += 1;
        //https://stackoverflow.com/questions/42576537/qt-serial-port-reading
        if(!serialPort.waitForReadyRead(100)) //block until new data arrives, dangerous, need a fix
            std::cout << "Read error: " << serialPort.errorString().toStdString()<<std::endl;
        else{
            if (debug)
                std::cout << "New data available: " << serialPort.bytesAvailable()<<std::endl;
            readData = serialPort.readAll();
            if (debug)
                std::cout << readData.toStdString()<<std::endl;
            break;
        }
        if (control > 10){
            std::cout << "Time out read error"<<std::endl;
            return false;
        }

    }// END READING BYTES FROM SERIAL PORT

    if(readData.size() != 0){
        if (debug)
            std::cout<<"Read operation ok : "<<readData.toStdString()<<std::endl;
        if(readData.at(0) != 6){ //expecting acknowledge command (0x06)
            std::cout<<"Wrong read : "<<readData.toStdString()<<std::endl;
            return false;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////
    // Composing message in an appropriate way for the Ultimis V (Sec1 of appB of manual)
    int checksum = 0;
    int N_bytes = 4*arguments.size();
    writeData = QByteArrayLiteral("\x02"); //https://stackoverflow.com/questions/36327327/is-there-a-shorter-way-to-initialize-a-qbytearray
    QByteArray temp_writeData = int_tohexQByteArray_UltimusV(N_bytes);

    for(unsigned int i=0;i<arguments.size();i++)
        temp_writeData.append(QByteArray(arguments[i].c_str()));

    for(int i=0;i<temp_writeData.size();i++)// evauating checksum quantity
        checksum -= temp_writeData[i];

    writeData.append(temp_writeData);

    //take tha least significant byte of checksum, i.e. checksum & 0x000000ff
    temp_writeData.clear();
    temp_writeData = int_tohexQByteArray_UltimusV(checksum & 0x000000ff);
    QByteArray qb_checksum;
    qb_checksum.clear();
    if(temp_writeData.size() > 2){
        if (debug)
            std::cout<<"here : "<<temp_writeData.size()<<"  :  "<<temp_writeData.toStdString();
        qb_checksum = temp_writeData.remove(0,(temp_writeData.size()-2));
        if (debug)
            std::cout<<"CS  :  "<<qb_checksum.toStdString()<<std::endl;
    } else {
        qb_checksum = temp_writeData;
        if (debug)
            std::cout<<"CS  :  "<<qb_checksum.toStdString()<<std::endl;
    }

    writeData.append(qb_checksum);
    writeData.append(QByteArrayLiteral("\x03"));
    writeData.append(QByteArrayLiteral("\x04"));
    //// END OF COMMAND CONSTRUCTION

    output = serialPort.write(writeData);// SENDING MESSAGE TO ULTIMUS V
    if (debug)
        std::cout<<"Log >> bytes written   : "<<output<<" : "<<writeData.toStdString()<<std::endl;
    if(output == -1){
        std::cout<<"Error write operation : "<<writeData.toStdString()<<std::endl;
        std::cout << "error: " << serialPort.errorString().toStdString()<<std::endl;
        return false;
    }
    //////////// End sending UltimusV command
 sleep(200);

    readData.clear();
    control = 0;
    while(serialPort.isOpen()){ //dangerous, may freez the GUI
        control += 1;
        if(!serialPort.waitForReadyRead(100)) //block until new data arrives
            std::cout << "error: " << serialPort.errorString().toStdString()<<std::endl;
        else{
            if (debug)
                std::cout << "2 New data available: " << serialPort.bytesAvailable()<<std::endl;
            readData.append(serialPort.readAll());
            if (debug)
                std::cout << readData.toStdString()<<std::endl;
            if(readData.at(0) == 2 && readData.at(readData.size()-1) == 3) //expectin A0 command, may add controls on checksum in future
                break;
        }
        if (control > 10){
            std::cout << "Time out read error"<<std::endl;
            return false;
        }
    }
    //////////////////////////////////
    serialPort.close(); //closing serial port comunication
    return true;
}


void OWIS_controller::dispense_order()

{
std::vector<std::string> arguments;
//char command[];
//arguments=ui->dispenserCommand->text();
//QString aux=ui->dispenserCommand->text();
//arguments.push_back(aux.toStdString());
arguments.push_back("DI ");
TalkSR232(arguments);

}

