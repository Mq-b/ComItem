#ifndef COMTHEMEATTACHED_H
#define COMTHEMEATTACHED_H

#include "comitem_global.h"
#include <QObject>
#include <QColor>
#include <QQmlEngine>
#include <qtmetamacros.h>

// ComThemeAttached - 附加属性类
class COMITEM_EXPORT ComThemeAttached : public QObject
{
    Q_OBJECT
    QML_ANONYMOUS

    // 主色调
    Q_PROPERTY(QColor primary READ primary CONSTANT)
    Q_PROPERTY(QColor primaryHover READ primaryHover CONSTANT)
    Q_PROPERTY(QColor primaryPressed READ primaryPressed CONSTANT)
    Q_PROPERTY(QColor primaryLight READ primaryLight CONSTANT)

    // 文字颜色
    Q_PROPERTY(QColor textPrimary READ textPrimary CONSTANT)
    Q_PROPERTY(QColor textSecondary READ textSecondary CONSTANT)
    Q_PROPERTY(QColor textDisabled READ textDisabled CONSTANT)
    Q_PROPERTY(QColor textOnPrimary READ textOnPrimary CONSTANT)

    // 背景颜色
    Q_PROPERTY(QColor background READ background CONSTANT)
    Q_PROPERTY(QColor backgroundHover READ backgroundHover CONSTANT)
    Q_PROPERTY(QColor backgroundDisabled READ backgroundDisabled CONSTANT)

    // 边框颜色
    Q_PROPERTY(QColor border READ border CONSTANT)
    Q_PROPERTY(QColor borderFocus READ borderFocus CONSTANT)
    Q_PROPERTY(QColor borderError READ borderError CONSTANT)

    // 状态颜色
    Q_PROPERTY(QColor success READ success CONSTANT)
    Q_PROPERTY(QColor warning READ warning CONSTANT)
    Q_PROPERTY(QColor error READ error CONSTANT)

    // 阴影
    Q_PROPERTY(QColor shadow READ shadow CONSTANT)

    // 通用属性
    Q_PROPERTY(int radiusSmall READ radiusSmall CONSTANT)
    Q_PROPERTY(int radiusMedium READ radiusMedium CONSTANT)
    Q_PROPERTY(int radiusLarge READ radiusLarge CONSTANT)
    Q_PROPERTY(int radiusCombo READ radiusCombo CONSTANT)

    Q_PROPERTY(int fontSizeSmall READ fontSizeSmall CONSTANT)
    Q_PROPERTY(int fontSizeMedium READ fontSizeMedium CONSTANT)
    Q_PROPERTY(int fontSizeLarge READ fontSizeLarge CONSTANT)

    Q_PROPERTY(int spacingSmall READ spacingSmall CONSTANT)
    Q_PROPERTY(int spacingMedium READ spacingMedium CONSTANT)
    Q_PROPERTY(int spacingLarge READ spacingLarge CONSTANT)

    Q_PROPERTY(int animationDuration READ animationDuration CONSTANT)

public:
    explicit ComThemeAttached(QObject *parent = nullptr);

    // Getters
    QColor primary() const { return QColor("#0E97A7"); }
    QColor primaryHover() const { return QColor("#0B8492"); }
    QColor primaryPressed() const { return QColor("#096B76"); }
    QColor primaryLight() const { return QColor("#E7F5F7"); }

    QColor textPrimary() const { return QColor("#3E4F63"); }
    QColor textSecondary() const { return QColor("#6F7C88"); }
    QColor textDisabled() const { return QColor("#A0AAB3"); }
    QColor textOnPrimary() const { return QColor("#FFFFFF"); }

    QColor background() const { return QColor("#FFFFFF"); }
    QColor backgroundHover() const { return QColor("#F2F2F2"); }
    QColor backgroundDisabled() const { return QColor("#F1F1F1"); }

    QColor border() const { return QColor("#D4D4D4"); }
    QColor borderFocus() const { return QColor("#0E97A7"); }
    QColor borderError() const { return QColor("#C94A2F"); }

    QColor success() const { return QColor("#17A84B"); }
    QColor warning() const { return QColor("#EF7432"); }
    QColor error() const { return QColor("#C94A2F"); }

    QColor shadow() const { return QColor("#00000014"); }

    int radiusSmall() const { return 2; }
    int radiusMedium() const { return 4; }
    int radiusLarge() const { return 6; }
    int radiusCombo() const { return 1; }

    int fontSizeSmall() const { return 12; }
    int fontSizeMedium() const { return 14; }
    int fontSizeLarge() const { return 16; }

    int spacingSmall() const { return 4; }
    int spacingMedium() const { return 8; }
    int spacingLarge() const { return 12; }

    int animationDuration() const { return 120; }
};

// ComTheme - 提供附加属性的类
class COMITEM_EXPORT ComTheme : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_ATTACHED(ComThemeAttached)
    QML_UNCREATABLE("ComTheme is an attached property")

public:
    explicit ComTheme(QObject *parent = nullptr) : QObject(parent) {}

    static ComThemeAttached *qmlAttachedProperties(QObject *object)
    {
        return new ComThemeAttached(object);
    }
};

#endif // COMTHEMEATTACHED_H
