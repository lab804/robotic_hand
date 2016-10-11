# -*- coding: utf-8 -*-

# importando as bibliotecas necessarias para rodar o servidor
# e criar a comunicacal serial para enviar dados para o arduino.
from flask import Flask, render_template
import serial

app = Flask(__name__)

# definindo a porta na qual o arduino esta conectado
# isso pode variar de sistema para sistema
# e o baundrate para 9600
ser_interface = serial.Serial('/dev/ttyACM0', 9600)


# caso o usuario acesse o path "/" o metodo renderiza a template main.html
@app.route('/')
def main():
    return render_template("main.html")


# caso o usuario clique em um botao da template main.html sera enviado o dado
# pela serial, o dado é convertido para bytes
@app.route('/move/<thinger>', methods=['GET'])
def move_hand(thinger):
    ser_interface.write(bytes(thinger[0]))
    return render_template("main.html")

if __name__ == '__main__':
    # rodando o servidor web na pora 5000
    app.run(debug=True, host="0.0.0.0", port=5000)
