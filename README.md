# vlcs-arduino

## Transmisor

Para el transmisor se usan un microcontrolador que en este caso es un Arduino UNO, un LED y un resistor para limitar la corriente

### Esquemáticos

![Esquematico del transmisor](/images/tx_schematic.png)

### Fotografía

![Foto del transmisor](/images/tx_photo.jpeg)

## Receptor

Para el receptor usamos un microcontrolador, un LDR, y un OPAM LM393. Estos dos ultimos componentes se encuentran en un módulo para arduino.

### Esquemáticos

![Esquematico del receptor](/images/rx_schematic.png)

### Fotografía

![Fotor del receptor](/images/rx_photo.jpeg)

## Transmisión

Para visualizar la transmision sin necesidad de un osciloscopio se envia el valor recibido al puerto UART para que sea visible desde cualquier Serial Plotter. Posteriormente se agregará la función de imprimir la frecuencia actual a la que se está transmitiendo.

![Screenshot de la transmisión](/images/serial_monitor.png)
