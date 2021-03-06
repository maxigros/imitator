#ifndef PARAMSRAW_H
#define PARAMSRAW_H

#include <QObject>
#include "jsonparser.h"

class ParamsRaw : public QObject
{
    Q_OBJECT
public:
    explicit ParamsRaw(QString configFilePath = DEFAULTPATH);

    // Для TABLE_SIGNAL
    QList<QString> getParam(QString paramName, QString confirm);
    // Для составных параметров
    QString getParam(QString kitName, int pos, QString paramName);
    int getArraySize(QString kitName);
    QMap<QString, QString> getItemFromArray(QString kitName, int pos);
    // Для простых параметров
    QString getParam(QString paramName);
    bool ifContainsSimple(QString name);
    QMap<QString, QString> getAllSimpleParams();

private:
    JsonParser *parser;
};

#endif // PARAMSRAW_H
