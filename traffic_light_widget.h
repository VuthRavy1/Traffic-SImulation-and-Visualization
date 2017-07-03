#ifndef TRAFFIC_LIGHT_WIDGET_H
#define TRAFFIC_LIGHT_WIDGET_H

#include <QtWidgets>
#include "trafficlight.h"
class Traffic_Light_widget :public QWidget
{
public:
    Traffic_Light_widget(QWidget *parent=0);
    void set_duration(int red,int yello,int green);
    void set_up();
    void start();
private:
    QState *make_light_state(LightWidget *light, int duration, QState *parent = 0);
    int m_red_duration;
    int m_yellow_duration;
    int m_green_duration;
    QStateMachine *m_machine;
    TrafficLight *m_traffic_light;
};

#endif // TRAFFIC_LIGHT_WIDGET_H
