# Fan Faker

[![GitHub release](http://img.shields.io/badge/Version-1.0-brightgreen.svg?style=flat)][release]
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)][license] 
[![Arduino](https://img.shields.io/badge/Arduino-Nano-red.svg?style=flat)][Arduino]


[release]: https://github.com/lordzurp/Fan_Faker/releases
[license]: https://raw.githubusercontent.com/lordzurp/DishWarrior/master/LICENSE
[arduino]: https://www.arduino.cc/en/Guide/ArduinoNano

## Principe de fonctionnement
Un ventilateur PC a un tachymètre qui envoie 2 pulses par tour
Pour le simuler, il suffit d'envoyer un signal carré à la fréquence correspondante

#####exemple : on veut simuler un ventilateur tournant à 6000 rpm à 12V
- on mesure la tension d'alimentation du ventilo, via un pont diviseur 1/3 : on passe de 0-15V à 0-5V
- un map la valeur sur une echelle de 0 à 10.000 (vitesse max théorique à 15V)
- on passe en Hertz : 10.000 / 60 = 166.67 Hz
- on veut 2 pulses par tour, donc on multiplie par 2 -> 333 pulses / seconde
- on utilise la librairie Tone() pour génerer un signal carré à la fréquence souhaitée

### Historique

#### v1.0 - 12/2018

##### Initial release