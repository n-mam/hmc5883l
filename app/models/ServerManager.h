#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class ServerManager : public QObject {

    Q_OBJECT

    public:

    ServerManager(QObject *parent = nullptr);
    ~ServerManager();

    void logToQml(const std::string&);
    virtual void transportSink(const std::string& data) = 0;

    Q_INVOKABLE void resetMCU();
    Q_INVOKABLE void stopWorkflowLoop();
    Q_INVOKABLE void sendMessage(QString);
    Q_INVOKABLE void sendKeyValue(uint32_t, float);

    Q_PROPERTY(bool encode READ getEncode WRITE setEncode NOTIFY encodeChanged);
    Q_PROPERTY(bool decode READ getDecode WRITE setDecode NOTIFY decodeChanged);

    bool getEncode();
    bool getDecode();
    void setEncode(bool);
    void setDecode(bool);
    QString getLocalIPAddress();
    void processData(QByteArray&);

    signals:

    void encodeChanged();
    void decodeChanged();
    void qmlLog(QString);
    void linkStatus(bool);

    private:

    void writeDataA();
    void writeDataB();
    void writeDataC();

    // these control if the inbound/outbound
    // messages are nanopb encoded or decoded
    bool m_decode = false;
    bool m_encode = false;
};

#endif // SERVER_H
