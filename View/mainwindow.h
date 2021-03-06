#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QGroupBox>
#include <QStackedWidget>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QButtonGroup>
#include <QLineEdit>

#include "soundwavewidget.h"
#include "fftbarswidget.h"
#include "fftcirclewidget.h"
#include "overtimefftwidget.h"
#include "metadatawidget.h"
#include "filemanagerwidget.h"
#include "mediapropertieswidget.h"

class Controller;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller*);

private:

    //widget
    SoundWaveWidget* m_soundWaveWidget;
    FFTBarsWidget* m_FFTBarsWidget;
    OvertimeFFTWidget* m_OvertimeFFTWidget;
    FFTCircleWidget* m_FFTCircleWidget;
    MetaDataWidget* m_MetaDataWidget;
    FileManagerWidget* m_FileManagerWidget;
    MediaPropertiesWidget* m_MediaPropertiesWidget;
    QListWidget* mediaList;

    //layout
    QHBoxLayout* mainLayout;
    QVBoxLayout* controlsLayout;
    QVBoxLayout* graphicsLayout;
    QStackedWidget* stackedGLWidget;
    QGroupBox* groupBox;
    QHBoxLayout* playerButtonsLayout;
    QWidget* controlsLayoutPlaceHolder;

    //buttons
    QPushButton* fileManagerButton;
    QPushButton* playButton;
    QPushButton* pauseButton;
    QPushButton* nextButton;
    QPushButton* prevButton;
    QSlider* progSlider;
    QSlider* volumeSlider;

    QHBoxLayout* mediaButtonsLayout;
    QPushButton* removeButton;
    QPushButton* propertiesButton;


    //SoundWave Settings
    QWidget* soundWaveSettingsPlaceHolder;
    QVBoxLayout* soundWaveSettingsLayout;
    QPushButton *soundWaveSettings;
    QSlider* soundWaveRemapFactorSlider;

    //FFTBars Settings
    QWidget* FFTBarsSettingsPlaceHolder;
    QVBoxLayout* FFTBarsSettingsLayout;
    QPushButton* FFTBarsSettings;
    QSlider* FFTBarsSensitivitySlider;
    QButtonGroup* FFTBarsSmoothingGroup;
    QRadioButton* FFTBarsStandardSmoothing;
    QRadioButton* FFTBarsEnhancedSmoothing;

    //FFTCircle Settings
    QWidget* FFTCircleSettingsPlaceHolder;
    QVBoxLayout* FFTCircleSettingsLayout;
    QPushButton* FFTCircleSettings;
    QSlider* FFTCircleSensitivitySlider;

    //OvertimeFFT Settings
    QWidget* OvertimeFFTSettingsPlaceHolder;
    QVBoxLayout* OvertimeFFTSettingsLayout;
    QPushButton* OvertimeFFTSettings;
    QButtonGroup* OvertimeFFTSmoothingGroup;
    QRadioButton* OvertimeFFTNoTimeSmoothing;
    QRadioButton* OvertimeFFTStandardTimeSmoothing;
    QRadioButton* OvertimeFFTDynamicFadeTimeSmoothing;
    QSlider* OvertimeFFTDynamicSmoothLimitSlider;
    QSlider* OvertimeFFTAlphaBlendingSlider;
    QLineEdit* OvertimeFFTUpdateFrequencyEditor;

    QHBoxLayout* rgbStartGradientLayout;
    QHBoxLayout* rgbEndGradientLayout;
    QHBoxLayout* rgbIncrementLayout;

    QSlider* startRedValueEdit;
    QSlider* startGreenValueEdit;
    QSlider* startBlueValueEdit;

    QSlider* endRedValueEdit;
    QSlider* endGreenValueEdit;
    QSlider* endBlueValueEdit;

    QLineEdit* redIncrementSpeedEdit;
    QLineEdit* greenIncrementSpeedEdit;
    QLineEdit* blueIncrementSpeedEdit;

    QPushButton* applyRGBIncrementButton;


    QRadioButton* SoundWaveButton;
    QRadioButton* FFTBarsButton;
    QRadioButton* FFTCircleButton;
    QRadioButton* OvertimeFFTButton;
    QButtonGroup* buttonGroup;


    //controller
    Controller* c;

    int idchecked;

signals:

    void widgetSelected(int);
    void sendHeights(std::vector<double>);
    void sendRadiuses(std::vector<double>);
    void replacePoints(std::vector<double>);
    void sendBuffers(std::vector<double>,  std::vector<std::vector<double>>);
    void sendToMediaVector(std::string);
    void updateOvertimeFFTTimer(unsigned int);
    void sendFFTBarsSmoothing(int);
    void sendOvertimeFFTSmoothing(int);
    void selectedMediaItem(unsigned int);
    void updateTitleInWidget(std::string);
    void previousMedia(unsigned int);
    void nextMedia(unsigned int);
    void updateImageInWidget(const QImage&);
    void updateOvertimeFFTAlphaBlending(float);
    void progSliderPositionChanged(qint64);
    void removeMedia(unsigned int);
    void sendPalette(float,float,float,float,float,float);
    void changeIncrementSpeed(float, float, float);
    void sendIncrementSpeed(float, float, float);
    void updateProperties(std::string, std::string, std::string, bool, std::string, std::string, unsigned int, unsigned int, unsigned int, unsigned int);

public slots:

    void onSoundWaveButtonClicked(bool);
    void onFFTBarsButtonClicked(bool);
    void onFFTCircleButtonClicked(bool);
    void onOvertimeFFTButtonClicked(bool);
    void onPushUpdateList(const std::string&);
    void onUpdateOvertimeFFTTimer();
    void identifyFFTBarsSmoothing();
    void identifyOvertimeFFTSmoothing();
    void onItemDoubleClicked(QListWidgetItem*);
    void onPrevButtonPressed();
    void onNextButtonPressed();
    void onUpdateCurrentRow(unsigned int);
    void onPositionChanged(qint64);
    void onUpdateProgSliderRange(int);
    void helper_progSliderPositionChanged(int);
    void onRemoveButtonPressed();
    void onPaletteSliderMoved();
    void onApplyRGBIncrementButtonClicked();
    void onFormatNotValid();
    void onOutOfRangeTimer();
    void onFileDoesNotExist();
    void onPropertiesButtonClicked();
    void onDurationError();

private slots:

    void identifyButton();

};

#endif // MAINWINDOW_H
