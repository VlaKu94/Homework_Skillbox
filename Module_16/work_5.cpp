/*
Разработайте упрощённую модель умного дома для дачи. Выполните симуляцию его работы на протяжении двух дней.
Стартовое время для симуляции умного дома 00:00. Есть несколько датчиков: датчик температуры снаружи, датчик температуры внутри дома.
В доме расположен электронный умный щиток с автоматами.
 */


#include <iostream>
#include <string>
#include <sstream>

enum switches
{
    LIGHTS_OUTSIDE = 1,
    HEATERS = 2,
    WATER_PIPE_HEATING = 4,
    CONDITIONER = 8,
    MOVEMENT = 16,
    LIGHTS_INSIDE = 32
};

int main() {
    int current_hour = 0;
    int temperature_inside = 0;
    int temperature_outside = 0;
    std::string movement = "no";
    std::string light = "no";
    int light_intensity = 5000;
    int switches_state = 0;

    while(current_hour <= 24){
        int temp_state = switches_state;
        std::string buffer;
        std::cout << "Input info(temp_inside, temp_outside, movement, light: ";
        std::getline(std::cin, buffer);

        std::stringstream buffer_stream(buffer);
        buffer_stream >> temperature_inside >> temperature_outside >> movement >> light;

        if (temperature_outside < 0){
            if (temp_state != (switches_state |= WATER_PIPE_HEATING)){
                std::cout << "WATER_PIPE_HEATING - " << "ON" << std::endl;
                temp_state = switches_state;
            }
        } else if(temperature_outside > 5){
            if (temp_state != (switches_state &= ~WATER_PIPE_HEATING)){
                std::cout << "WATER_PIPE_HEATING - " << "OFF" << std::endl;
                temp_state = switches_state;
            }
        }

        if (movement == "yes" && (current_hour > 16 || current_hour < 5)){
            if (temp_state != (switches_state |= LIGHTS_OUTSIDE)){
                std::cout << "LIGHTS_OUTSIDE - " << "ON" << std::endl;
                temp_state = switches_state;
            }
        } else {
            if (temp_state != (switches_state &= ~LIGHTS_OUTSIDE)){
                std::cout << "LIGHTS_OUTSIDE - " << "OFF" << std::endl;
                temp_state = switches_state;
            }
        }

        if (temperature_inside < 22) {
            if (temp_state != (switches_state |= HEATERS)){
                std::cout << "HEATERS - " << "ON" << std::endl;
                temp_state = switches_state;
            }
        } else if (temperature_inside >= 25) {
            if (temp_state != (switches_state &= ~HEATERS)){
                std::cout << "HEATERS - " << "OFF" << std::endl;
                temp_state = switches_state;
            }
        }

        if  (temperature_inside > 30) {
            if (temp_state != (switches_state |= CONDITIONER)){
                std::cout << "CONDITIONER - " << "ON" << std::endl;
                temp_state = switches_state;
            }
        } else if (temperature_inside <= 25) {
            if (temp_state != (switches_state &= ~CONDITIONER)){
                std::cout << "CONDITIONER - " << "OFF" << std::endl;
                temp_state = switches_state;
            }
        }

        if (light == "yes") {
            if (temp_state != (switches_state |= LIGHTS_INSIDE)){
                std::cout << "LIGHTS_INSIDE - " << "ON" << std::endl;
                temp_state = switches_state;
            }
        } else {
            if (temp_state != (switches_state &= ~LIGHTS_INSIDE)){
                std::cout << "LIGHTS_INSIDE - " << "OFF" << std::endl;
                temp_state = switches_state;
            }
        }

        if (movement == "yes") {
            if (temp_state != (switches_state |= MOVEMENT)){
                std::cout << "MOVEMENT - " << "YES" << std::endl;
                temp_state = switches_state;
            }
        } else {
            if (temp_state != (switches_state &= ~MOVEMENT)){
                std::cout << "MOVEMENT - " << "NO" << std::endl;
                temp_state = switches_state;
            }
        }

        if (light == "yes"){
            if (current_hour >= 16 && current_hour <= 20) {
                light_intensity = 5000 - ((current_hour - 16) * ((5000-2700) / (20 - 16)));
            } else if( current_hour == 23) {
                light_intensity = 5000;
            }
            std::cout << "Color temperature: " << light_intensity << "K" << std::endl;
        }

        std::cout << current_hour << std::endl;

        ++current_hour;
    }

}















